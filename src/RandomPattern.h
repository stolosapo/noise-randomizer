#ifndef RandomPattern_h__
#define RandomPattern_h__

#include <string>
#include <noisekernel/Thread.h>
#include "Pattern.h"

using namespace std;
using namespace NoiseKernel;

class RandomPattern: public Pattern
{
private:
    Locker _locker;
    int counter;

    bool randomState;
    int minNOMilliSec;
    int maxNOMilliSec;
    int minNCMilliSec;
    int maxNCMilliSec;

    int incrementCounter();

public:
    RandomPattern(bool randoState, int minNOMilliSec, int maxNOMilliSec, int minNCMilliSec, int maxNCMilliSec);
    virtual ~RandomPattern();

    virtual StateInterval getNextStateInterval();
};

#endif // RandomPattern_h__
