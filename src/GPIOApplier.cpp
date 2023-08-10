#include "GPIOApplier.h"
#include <unistd.h>

GPIOApplier::GPIOApplier(): StateApplier()
{

}

GPIOApplier::~GPIOApplier()
{

}

void GPIOApplier::apply(StateInterval state)
{
    cout << "STATE: " << state.state << " SEC: " << state.seconds << endl;
    usleep(1000 * 1000 * state.seconds);
}