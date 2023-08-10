#include "random.h"
#include <algorithm>
#include <stdlib.h>

int randomUpTo(int max)
{
    return randomBetween(0, max);
}

int randomBetween(int min, int max)
{
    return min + rand() % max;
}