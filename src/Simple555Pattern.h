#ifndef Simple555Pattern_h__
#define Simple555Pattern_h__

#include <string>
#include <noisekernel/Thread.h>
#include "Pattern.h"

using namespace std;
using namespace NoiseKernel;

class Simple555Pattern: public Pattern
{
private:
    Locker _locker;
    int counter;
    int noSec;
    int ncSec;

    int incrementCounter();

public:
    Simple555Pattern(int noSec, int ncSec);
    virtual ~Simple555Pattern();

    virtual StateInterval getNextStateInterval();
};

#endif // Simple555Pattern_h__
