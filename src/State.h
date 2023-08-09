#ifndef State_h__
#define State_h__

enum State
{
    NO = 0,
    
    NC = 1
};

struct StateInterval
{
    State state;
    int seconds;
};

#endif // State_h__
