#ifndef StateApplier_h__
#define StateApplier_h__

#include <string>
#include <noisekernel/Thread.h>
#include "State.h"

using namespace std;
using namespace NoiseKernel;

class StateApplier
{
private:
    Locker _locker;

public:
    StateApplier();
    virtual ~StateApplier();

    virtual void apply(StateInterval state) = 0;
};

#endif // StateApplier_h__
