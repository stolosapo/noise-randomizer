#include "StateApplier.h"

StateApplier::StateApplier()
{
    _locker.init();
}

StateApplier::~StateApplier()
{
    _locker.destroy();
}