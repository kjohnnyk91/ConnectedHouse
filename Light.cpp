#include "Light.hpp"

namespace House
{
	Light::Light(House::ConnectedHouse* house, int pin):
		house_(house),
		pin_(pin),
		light_(false),
		intensity_(0)
	{}
	
	Light::~Light()
	{}
	
	bool Light::setting()
	{
		if(GPIOUtils::GPIOModeStatus(pin_, PI_INPUT, gpioSetMode(pin_, PI_INPUT)) != 0)
		{
			std::cout << "Failed to set the light" << std::endl;
			
			return false;
		}
		
		if(GPIOUtils::GPIOPUDStatus(LED_GPIO_PIN, PI_PUD_DOWN, gpioSetPullUpDown(LED_GPIO_PIN, PI_PUD_DOWN)) != 0)
		{
			std::cout << "Failed to set the pull up/down resistor" << std::endl;
			
			return false;
		}
		
		return true;
	}
	
	bool Light::setHouse(ConnectedHouse* house)
	{
		if(house != nullptr)
		{
			std::cout << "The House pointer is nullptr" << std::endl;
			
			return false;
		}
		else
		{
			house_ = house;
			
			house-> setLight(this);
			
			return true;
		}
	}
	
	void Light::setLight(bool light)
	{
		light_ = light;
		
		gpioWrite(pin_, light);
	}
	
	void Light::setIntensity(unsigned int intensity)
	{
		intensity_ = intensity_;
	}
}
