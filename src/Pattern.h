#ifndef Pattern_h__
#define Pattern_h__

#include "State.h"

class Pattern
{
private:

public:
    Pattern();
    virtual ~Pattern();

    virtual StateInterval getNextStateInterval() = 0;
};

#endif // Pattern_h__
