#include "MCP9808.hpp"

namespace House
{
	bool MCP9808::MCP9808_i2cOpen()
	{
		GPIOUtils::i2cOpenStatus(handle_ = i2cOpen(MCP9808_BUS, MCP9808_I2C_ADDRESS, 0), MCP9808_NAME);
		
		if(handle_ >= 0)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	
	bool MCP9808::MCP9808_i2cClose()
	{
		int close(i2cClose(handle_));
		
		GPIOUtils::i2cCloseStatus(close, MCP9808_NAME);
		
		if(close = 0)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	
	MCP9808::MCP9808(ConnectedHouse* house, bool A0, bool A1, bool A2):
		house_(house),
		A0_(A0),
		A1_(A1),
		A2_(A2),
		handle_(-1)
	{}
	
	MCP9808::MCP9808(ConnectedHouse* house, uint8_t suffix):
		house_(house),
		handle_(0)
	{
		A0_ = (suffix & 0b001);
		A1_ = (suffix & 0b010);
		A2_ = (suffix & 0b100);
	}
	
	MCP9808::~MCP9808()
	{}
	
	bool MCP9808::setHouse(ConnectedHouse* house)
	{
		if(house != nullptr)
		{
			house_ = house;
			house_ -> setTempSensor(this);
			
			return true;
		}
		else
		{
			return false;
		}
	}
	
	float MCP9808::readTemp()
	{
		handle_ = i2cOpen(1,MCP9808_I2C_ADDRESS,0);
		int tempRegister(-1);
		int upperTemp(0);
		int lowerTemp(0);

		GPIOUtils::i2cOpenStatus(handle_, "MCP9808");

		if(handle_ < 0)
		{
			return -273.16;
		}

		GPIOUtils::i2cWriteStatus(i2cWriteWordData(handle_, CONFIG_REGISTER, 0x0000));
		
		while(tempRegister < 0)
		{
			tempRegister = i2cReadWordData(handle_,TEMP_REGISTER);
		}
		
		upperTemp = (tempRegister & 0xFF00) >> 8;
		lowerTemp = (tempRegister & 0x00FF);
		
		// std::cout << upperTemp << std::endl;
		// std::cout << lowerTemp << std::endl;

		GPIOUtils::i2cCloseStatus(i2cClose(handle_), MCP9808_NAME);
		
		if(upperTemp & 0x80)
		{
			std::cout << "The temperature is greater than the critical temperature";
		}
		else
		{
			std::cout << "The temperature is lower than the critical temperature";
		}
		
		std::cout << std::endl;

		if(upperTemp & 0x40)
		{
			std::cout << "The temperature is greater than the upper temperature";
		}
		else
		{
			std::cout << "The temperature is lower than the upper temperature";
		}
		
		std::cout << std::endl;

		if(upperTemp & 0x20)
		{
			std::cout << "The temperature is lower than the lower temperature";
		}
		else
		{
			std::cout << "The temperature is greater than the lower temperature";
		}
		
		std::cout << std::endl;
		
		std::cout << "upperTemp = " << upperTemp << std::endl;
		std::cout << "lowerTemp = " << lowerTemp << std::endl;

		upperTemp &= 0x1F;

		std::cout << "upperTemp = " << upperTemp << std::endl;
		std::cout << "lowerTemp = " << lowerTemp << std::endl;

		if(upperTemp & 0x10)
		{
			std::cout << ("The temperature is below 0") << std::endl;

			upperTemp &= 0x0F;

			return 256 - (((float) upperTemp)*16 + (((float) lowerTemp)/16));
		}
		else
		{
			std::cout << "The temperature is above 0" << std::endl;

			return ((float) upperTemp)*16 + ((float) lowerTemp)/16;
		}
	}
}
