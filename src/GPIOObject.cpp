#include "GPIOObject.h"
#include <fstream>
#include "Exceptions.h"

using namespace std;

GPIOObject::GPIOObject(
    string gpioNum, 
    GPIODirection gpioDirection)
    : gpioNum(gpioNum),
    gpioDirection(gpioDirection)
{
    _locker.init();
    exported = false;
}

GPIOInObject::GPIOInObject(string gpioNum): GPIOObject(gpioNum, IN)
{

}

GPIOOutObject::GPIOOutObject(string gpioNum): GPIOObject(gpioNum, OUT)
{

}

GPIOObject::~GPIOObject()
{
    if (exported)
    {
        unexportGPIO();    
    }

    _locker.destroy();
}

GPIOInObject::~GPIOInObject()
{

}

GPIOOutObject::~GPIOOutObject()
{
    
}

void GPIOObject::exportGPIO()
{
    const char* export_str = "/sys/class/gpio/export";
	ofstream exportgpio(export_str);

	if (!exportgpio)
	{
        throw DomainException(GPIO0001, gpioNum);
	}

	exportgpio << gpioNum ;
	exportgpio.close();
}

void GPIOObject::unexportGPIO()
{
    const char* unexport_str = "/sys/class/gpio/unexport";
	ofstream unexportgpio(unexport_str);
	
	if (!unexportgpio)
	{
		throw DomainException(GPIO0002, gpioNum);
	}

	unexportgpio << gpioNum;
	unexportgpio.close();
}

void GPIOObject::setDirection()
{
    string setdir_str = "/sys/class/gpio/gpio" + gpioNum + "/direction";
	ofstream setdirgpio(setdir_str.c_str());

	if (!setdirgpio)
	{
        throw DomainException(GPIO0003, gpioNum);
	}

    string dir = gpio_direction_to_string(gpioDirection);
	setdirgpio << dir;
	setdirgpio.close();
}

void GPIOObject::setup()
{
    _locker.lock();

    try
    {
        if (exported)
        {
            return;
        }

        exportGPIO();
        setDirection();
    }
    catch(const exception& e)
    {
        _locker.unlock();
        throw e;
    }

    _locker.unlock();
}

void GPIOObject::setValue(GPIOValue value)
{
    if (gpioDirection == IN)
    {
        throw DomainException(GPIO0006, gpioNum);
    }
    

    _locker.lock();

    try
    {
        string setval_str = "/sys/class/gpio/gpio" + gpioNum + "/value";
        ofstream setvalgpio(setval_str.c_str());

        if (!setvalgpio)
        {
            throw DomainException(GPIO0004, gpioNum);
        }

        string val = gpio_value_to_string(value);
        setvalgpio << val;
        setvalgpio.close();
    }
    catch(const exception& e)
    {
        _locker.unlock();
        throw e;
    }

    _locker.unlock();
}

GPIOValue GPIOObject::getValue()
{
    if (gpioDirection == OUT)
    {
        throw DomainException(GPIO0006, gpioNum);
    }

    _locker.lock();

    try
    {
        string getval_str = "/sys/class/gpio/gpio" + gpioNum + "/value";
        ifstream getvalgpio(getval_str.c_str());

        if (!getvalgpio)
        {
            throw DomainException(GPIO0005, gpioNum);
        }

        string val;
        getvalgpio >> val;

        GPIOValue value = gpio_value_from_string(val);
        getvalgpio.close();
        return value;
    }
    catch(const std::exception& e)
    {
        _locker.unlock();
        throw e;
    }

    _locker.unlock();
}

GPIOValue GPIOInObject::get()
{
    return getValue();
}

void GPIOOutObject::set(GPIOValue value)
{
    setValue(value);
}

GPIODirection gpio_direction_from_string(string direction)
{
    if (direction == "in")
    {
        return IN;
    }
    return OUT;
}

string gpio_direction_to_string(GPIODirection direction)
{
    switch (direction)
    {
    case IN:
        return "in";
    
    default:
        return "out";
    }
}

GPIOValue gpio_value_from_string(string value)
{
    if (value == "1")
    {
        return GPIOValue::GPIO_HIGH;
    }
    return GPIOValue::GPIO_LOW;
}

string gpio_value_to_string(GPIOValue value)
{
    switch (value)
    {
    case GPIOValue::GPIO_HIGH:
        return "1";
    
    default:
        return "0";
    }
}
