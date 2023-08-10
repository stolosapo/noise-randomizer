#include "RandomPattern.h"
#include "random.h"

RandomPattern::RandomPattern(
    bool randomState, 
    int minNOMilliSec, 
    int maxNOMilliSec, 
    int minNCMilliSec, 
    int maxNCMilliSec)
    : Pattern(),
    randomState(randomState),
    minNOMilliSec(minNOMilliSec),
    maxNOMilliSec(maxNOMilliSec),
    minNCMilliSec(minNCMilliSec),
    maxNCMilliSec(maxNCMilliSec)
{
    _locker.init();
    counter = 0;
}

RandomPattern::~RandomPattern()
{
    _locker.destroy();
}

int RandomPattern::incrementCounter()
{
    _locker.lock();
    counter++;
    int c = counter;
    _locker.unlock();
    return c;
}

StateInterval RandomPattern::getNextStateInterval()
{
    StateInterval interval;
    interval.state = NO;

    int s = 0;
    if (randomState)
    {
        s = randomBetween(0, 1 + 1);
    }
    else 
    {
        s = incrementCounter();
    }
    
    if (s % 2  == 0)
    {
        interval.state = NC;
    }

    if (s == NO)
    {
        interval.millisec = randomBetween(minNOMilliSec, maxNOMilliSec + 1);
    }
    else 
    {
        interval.millisec = randomBetween(minNCMilliSec, maxNCMilliSec + 1);
    }

    return interval;
}