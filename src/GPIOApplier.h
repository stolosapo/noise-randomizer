#ifndef GPIOApplier_h__
#define GPIOApplier_h__

#include <iostream>
#include "StateApplier.h"
#include "GPIOObject.h"

using namespace std;

GPIOValue state_to_gpio_value(State state);

class GPIOApplier: public StateApplier
{
private:
    GPIOOutObject *gpioOut;

public:
    GPIOApplier(GPIOOutObject *gpioOut);
    virtual ~GPIOApplier();

    virtual void apply(StateInterval state);
};

#endif // GPIOApplier_h__
