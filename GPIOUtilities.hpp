#ifndef HPP_GPIOUTILITIES
#define HPP_GPIOUTILITIES

#include <iostream>
#include <pigpio.h>

namespace GPIOUtils
{
	int GPIOModeStatus(int gpioPin, int mode, int status);
	int GPIOPUDStatus(int gpio, int pud, int status);

	void i2cOpenStatus(int status, std::string dev);
	void i2cCloseStatus(int status, std::string dev);
	void i2cWriteStatus(int status);
	void i2CReadStatus(int status);
}

#endif
