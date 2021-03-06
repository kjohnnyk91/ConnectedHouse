#include "HouseLCD.hpp"

namespace House
{
	HouseLCD::HouseLCD(ConnectedHouse* house, const uint8_t bus, uint8_t addr, uint8_t width, bool backlight_on):
		LCD(bus, addr, width, backlight_on),
		house_(house),
		temp_(0),
		persons_(0)
	{}
	
	HouseLCD::~HouseLCD()
	{}
	
	bool HouseLCD::getTemp()
	{
		MCP9808* tempSensor(nullptr);
		
		if(house_)
		{
			tempSensor = house_-> tempSensor();
		}
		else
		{
			return false;
		}
		
		if((temp_ = tempSensor-> readTemp()) < -273.15)
		{
			temp_ = 0;
			
			std::cerr << "HouseLCD : An error occured while getting the temperature" << std::endl;
			
			return false;
		}
		else
		{
			display();
			
			return true;
		}
	}
	
	bool HouseLCD::getPersons()
	{
		if(house_ != nullptr)
		{
			persons_ = (house_-> persons());
			
			display();
			
			return true;
		}
		else
		{
			std::cerr << "HouseLCD : An error occured while getting the number of persons" << std::endl;
			
			return false;
		}
	}
	
	void HouseLCD::display()
	{
		clear();
		setPosition(0,0);
		printf("Presence : %d", persons_);
		setPosition(0,1);
		printf("Temp : %f", temp_);
	}
}
