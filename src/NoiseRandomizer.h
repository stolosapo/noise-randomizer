#ifndef NoiseRandomizer_h__
#define NoiseRandomizer_h__

#include <iostream>
#include <string>
#include <vector>
#include <noisekernel/Logger.h>
#include <noisekernel/Signal.h>
#include <noisekernel/Thread.h>
#include "Pattern.h"
#include "StateApplier.h"

using namespace std;
using namespace NoiseKernel;

class NoiseRandomizer
{
private:
    Locker _locker;
    LogService *logSrv;
    SignalAdapter* sigAdapter;
    StateApplier* applier;

    vector<Pattern*> patterns;

    Pattern* getPattern();

public:
    NoiseRandomizer(
        LogService *logSrv,
        SignalAdapter* sigAdapter,
        vector<Pattern*> patterns,
        StateApplier* applier);
    virtual ~NoiseRandomizer();

    void run();
};

#endif // NoiseRandomizer_h__
