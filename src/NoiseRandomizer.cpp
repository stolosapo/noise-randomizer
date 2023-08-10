#include "NoiseRandomizer.h"
#include <unistd.h>
#include "StringHelper.h"
#include "random.h"

using namespace NoiseKernel;

NoiseRandomizer::NoiseRandomizer(
    LogService *logSrv,
    SignalAdapter* sigAdapter,
    vector<Pattern*> patterns,
    StateApplier* applier,
    NoiseRandomizerConfig config)
    : logSrv(logSrv),
    sigAdapter(sigAdapter),
    patterns(patterns),
    applier(applier),
    config(config)
{
    _locker.init();
    
    currentPatternIdx = 0;
    patternThread = NULL;
}

NoiseRandomizer::~NoiseRandomizer()
{
    _locker.destroy();

    if (patternThread != NULL)
    {
        patternThread->wait();
        delete patternThread;
    }
}

void* NoiseRandomizer::changePatternAsync(void* noiseRandomizer)
{
    NoiseRandomizer* self = (NoiseRandomizer*) noiseRandomizer;
    
    if (self->config.changePatternMsFreq <= 0)
    {
        return NULL;
    }

    while (!self->sigAdapter->gotSigInt())
    {
        usleep(1000 * self->config.changePatternMsFreq);
        self->loadNextPattern();
    }

    return NULL;
}

void NoiseRandomizer::run()
{
    // Start Change Patterns Thread
    patternThread = new Thread;
    patternThread->attachDelegate(&NoiseRandomizer::changePatternAsync);
    patternThread->start(this);

    while (!sigAdapter->gotSigInt())
    {
        // Get Pattern
        Pattern* p = getPattern();
        if (p == NULL)
        {
            logSrv->error("No pattern found");
            break;
        }

        // Get Next State Interval
        StateInterval s = p->getNextStateInterval();

        // Apply it!
        applier->apply(s);

        logSrv->info("State applied: " + numberToString<State>(s.state) + ", ms: " + numberToString<int>(s.millisec));
    }
}

Pattern* NoiseRandomizer::getPattern()
{
    if (patterns.size() <= currentPatternIdx)
    {
        return NULL;
    }

    _locker.lock();
    Pattern* p = patterns.at(currentPatternIdx);     
    _locker.unlock();

    return p;
}

void NoiseRandomizer::loadNextPattern()
{
    _locker.lock();

    int nextIdx;
    if (patterns.size() == 1)
    {
        nextIdx = 0;
    }
    else if (config.useRandomPattern)
    {
        nextIdx = randomBetween(0, patterns.size() - 1);
    }
    else 
    {
        nextIdx = currentPatternIdx + 1;
        if (nextIdx >= patterns.size())
        {
            nextIdx = 0;
        }
    }

    currentPatternIdx = nextIdx;

    _locker.unlock();

    logSrv->info("Loaded pattern index: " + numberToString<int>(nextIdx));
}