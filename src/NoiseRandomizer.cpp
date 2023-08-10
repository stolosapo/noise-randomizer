#include "NoiseRandomizer.h"
#include <unistd.h>
#include "StringHelper.h"

using namespace NoiseKernel;

NoiseRandomizer::NoiseRandomizer(
    LogService *logSrv,
    SignalAdapter* sigAdapter,
    vector<Pattern*> patterns,
    StateApplier* applier)
    : logSrv(logSrv),
    sigAdapter(sigAdapter),
    patterns(patterns),
    applier(applier)
{
    _locker.init();
}

NoiseRandomizer::~NoiseRandomizer()
{
    _locker.destroy();
}

void NoiseRandomizer::run()
{
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
    if (patterns.size() == 0)
    {
        return NULL;
    }

    _locker.lock();
    Pattern* p = patterns.at(0);
    _locker.unlock();

    return p;
}