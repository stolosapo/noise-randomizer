#include "NoiseRandomizer.h"

using namespace NoiseKernel;

NoiseRandomizer::NoiseRandomizer(
    LogService *logSrv,
    SignalAdapter* sigAdapter,
    vector<Pattern*> patterns)
    : logSrv(logSrv),
    sigAdapter(sigAdapter),
    patterns(patterns)
{

}

NoiseRandomizer::~NoiseRandomizer()
{
    
}

void NoiseRandomizer::run()
{
    
}