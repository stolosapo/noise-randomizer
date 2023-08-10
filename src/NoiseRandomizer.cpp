#include "NoiseRandomizer.h"
#include <unistd.h>

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
            logSrv->debug("No pattern found");
            break;
        }

        // Get Next State Interval
        StateInterval s = p->getNextStateInterval();

        // Apply it!
        applier->apply(s);
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