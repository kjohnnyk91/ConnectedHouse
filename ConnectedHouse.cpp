#include "ConnectedHouse.hpp"

namespace House
{
	bool ConnectedHouse::init()
	{
		if(version_ = gpioInitialise() > 0)
		{
			std::cout << "PI GPIOs version " << version_ << " have been initialised." << std::endl;
		}
		else
		{
			std::cout << "Failed to initialise PI GPIOs" << std::endl;
			
			return version_;
		}
		
		try
		{
			light_ = new Light(this, GPIO_LED);
			// door_ = new Door();
			lcd_ = new HouseLCD(this,LCD_I2C_BUS, LCD_1602_I2C_ADDRESS);
			tempSensor_ = new MCP9808(this);
			// RFIDReader_ = new RFIDReader;
		}
		catch(std::bad_alloc& ba)
		{
			std::cerr << "ConnectedHouse:: A bad memory allocation occured : " << ba.what() << std::endl;
			
			return false;
		}
		
		return true;
	}
	
	ConnectedHouse::ConnectedHouse(uint8_t persons):
		version_(0),
		persons_(persons),
		light_(nullptr),
		// door_(nullptr),
		// lcd_(nullptr),
		tempSensor_(nullptr)
		// RFIDReader_(nullptr)
	{
		if(!init())
		{
			std::cerr << "ConnectedHouse::Something went wrong in the initialisation" << std::endl;
		}
	}
	
	ConnectedHouse::~ConnectedHouse()
	{
		delete light_;
		// delete door_;
		delete lcd_;
		delete tempSensor_;
		// delete RFIDReader_;
		
		gpioTerminate();
	}
	
	bool ConnectedHouse::setLight(Light* light)
	{
		if(light != nullptr)
		{
			light_ = light;
			
			light_ -> setHouse(this);
			
			return true;
		}
		else
		{
			return false;
		}
	}
		
	bool ConnectedHouse::setTempSensor(MCP9808* tempSensor)
	{
		if(tempSensor != nullptr)
		{
			tempSensor_ = tempSensor;
			
			tempSensor_ -> setHouse(this);
			
			return true;
		}
		else
		{
			return false;
		}
	}

	bool ConnectedHouse::lightOff()
	{
		if(light_)
		{
			light_-> setLight(false);
			
			return true;
		}
		else
		{
			return false;
		}
	}
	
	bool ConnectedHouse::lightOn()
	{
		if(light_)
		{
			light_-> setLight(true);
			
			return true;
		}
		else
		{
			return false;
		}
	}
	
	bool ConnectedHouse::lcdOff()
	{
		if(lcd_ != nullptr)
		{
			lcd_-> enableBacklight(false);
			
			return true;
		}
		else
		{
			return false;
		}
	}
	
	bool ConnectedHouse::lcdOn()
	{
		if(lcd_ != nullptr)
		{
			lcd_-> enableBacklight(true);
			
			return true;
		}
		else
		{
			return false;
		}
	}
	
	bool ConnectedHouse::tempRead()
	{
		if(tempSensor_ && lcd_)
		{
			ConnectedHouse* tempSensorHouse(tempSensor_-> house());
			ConnectedHouse* lcdHouse(lcd_-> house());
			
			if(tempSensorHouse != lcdHouse)
			{
				return false;
			}
		}
		else
		{
			return false;
		}
		
		if(lcd_-> getTemp())
		{
			return true;
		}
		else
		{
			std::cerr << "ConnectedHouse : Failed to get the temperature" << std::endl;
			return false;
		}
	}
}
