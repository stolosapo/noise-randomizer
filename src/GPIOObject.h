#ifndef GPIOObject_h__
#define GPIOObject_h__

#include <string>
#include <noisekernel/Logger.h>
#include <noisekernel/Thread.h>

using namespace std;
using namespace NoiseKernel;

enum GPIODirection
{
    IN = 0,

    OUT = 1
};

enum GPIOValue
{
    LOW = 0,

    HIGH = 1
};

GPIODirection gpio_direction_from_string(string direction);
string gpio_direction_to_string(GPIODirection direction);
GPIOValue gpio_value_from_string(string value);
string gpio_value_to_string(GPIOValue value);

class GPIOObject
{
private:
    Locker _locker;

    string gpioNum;
    GPIODirection gpioDirection;
    bool exported;

    void exportGPIO();
    void unexportGPIO();
    void setDirection();

public:
    GPIOObject(
        string gpioNum, 
        GPIODirection gpioDirection);
    virtual ~GPIOObject();

    void setup();
    void setValue(GPIOValue value);
    GPIOValue getValue();
};

class GPIOInObject: public GPIOObject
{
public:
    GPIOInObject(string gpioNum);
    virtual ~GPIOInObject();
};

class GPIOOutObject: public GPIOObject
{
public:
    GPIOOutObject(string gpioNum);
    virtual ~GPIOOutObject();
};

#endif // GPIOObject_h__
