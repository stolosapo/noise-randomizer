#include "Simple555Pattern.h"

Simple555Pattern::Simple555Pattern(int noSec, int ncSec): Pattern()
{
    _locker.init();
    counter = 0;
    this->noSec = noSec;
    this->ncSec = ncSec;
}

Simple555Pattern::~Simple555Pattern()
{
    _locker.destroy();
}

int Simple555Pattern::incrementCounter()
{
    _locker.lock();
    counter++;
    int c = counter;
    _locker.unlock();
    return c;
}

StateInterval Simple555Pattern::getNextStateInterval()
{
    int c = incrementCounter();
    
    StateInterval interval;
    interval.state = NO;
    interval.seconds = noSec;
    if (c % 2 == 0) 
    {
        interval.state = NC;
        interval.seconds = ncSec;
    }

    return interval;
}