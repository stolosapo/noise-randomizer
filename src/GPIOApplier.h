#ifndef GPIOApplier_h__
#define GPIOApplier_h__

#include <iostream>
#include "StateApplier.h"

using namespace std;

class GPIOApplier: public StateApplier
{
public:
    GPIOApplier();
    virtual ~GPIOApplier();

    virtual void apply(StateInterval state);
};

#endif // GPIOApplier_h__
