#ifndef State_h__
#define State_h__

enum State
{
    LOW = 0,

    HIGH = 1
};

struct StateInterval
{
    State state;
    int millisec;
};

#endif // State_h__
