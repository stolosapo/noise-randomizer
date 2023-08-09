#ifndef NoiseRandomizer_h__
#define NoiseRandomizer_h__

#include <string>
#include <vector>
#include <noisekernel/Logger.h>
#include <noisekernel/Signal.h>
#include <noisekernel/Thread.h>
#include "Pattern.h"

using namespace std;
using namespace NoiseKernel;

class NoiseRandomizer
{
private:
    LogService *logSrv;
    SignalAdapter* sigAdapter;

    vector<Pattern*> patterns;

public:
    NoiseRandomizer(
        LogService *logSrv,
        SignalAdapter* sigAdapter,
        vector<Pattern*> patterns);
    virtual ~NoiseRandomizer();

    void run();
};

#endif // NoiseRandomizer_h__
