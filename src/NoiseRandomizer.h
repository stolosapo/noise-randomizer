#ifndef NoiseRandomizer_h__
#define NoiseRandomizer_h__

#include <string>
#include <noisekernel/Logger.h>
#include <noisekernel/Signal.h>
#include <noisekernel/Thread.h>

using namespace std;
using namespace NoiseKernel;

class NoiseRandomizer
{
private:

public:
    NoiseRandomizer(
        LogService *logSrv,
        SignalAdapter* sigAdapter);
    virtual ~NoiseRandomizer();
};

#endif // NoiseRandomizer_h__
