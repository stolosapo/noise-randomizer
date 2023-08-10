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
    usleep(1000 * state.millisec);
}