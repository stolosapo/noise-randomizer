#include "GPIOApplier.h"
#include <unistd.h>

GPIOApplier::GPIOApplier(GPIOOutObject *gpioOut): StateApplier(), gpioOut(gpioOut)
{

}

GPIOApplier::~GPIOApplier()
{

}

void GPIOApplier::apply(StateInterval state)
{
    gpioOut->setValue(state_to_gpio_value(state.state));
    usleep(1000 * state.millisec);
}

GPIOValue state_to_gpio_value(State state)
{
    switch (state)
    {
    case NC:
        return HIGH;
    
    default:
        return LOW;
    }
}
