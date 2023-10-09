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
    gpioOut->set(state_to_gpio_value(state.state));
    usleep(1000 * state.millisec);
}

GPIOValue state_to_gpio_value(State state)
{
    switch (state)
    {
    case State::HIGH:
        return GPIOValue::GPIO_HIGH;
    
    default:
        return GPIOValue::GPIO_LOW;
    }
}
