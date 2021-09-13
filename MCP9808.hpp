#ifndef HPP_MCP9808
#define HPP_MCP9808

#define MCP9808_NAME "MCP9808"
#define MCP9808_BUS 1

#define MCP9808_I2C_ADDRESS 0x18
#define MCP9808_A0 0
#define MCP9808_A1 0
#define MCP9808_A2 0

#define CONFIG_REGISTER 0x01
#define UPPER_TEMP_REGISTER 0x02
#define LOWER_TEMP_REGISTER 0x03
#define CRIT_TEMP_REGISTER 0x04
#define TEMP_REGISTER 0x05

#include <iostream>
#include <string>
#include <pigpio.h>
#include "GPIOUtilities.hpp"
#include "ConnectedHouse.hpp"

namespace House
{
	class ConnectedHouse;
	
	class MCP9808
	{
		private:
			ConnectedHouse* house_;
			bool A0_;
			bool A1_;
			bool A2_;
			int handle_;
			
			bool MCP9808_i2cOpen();
			bool MCP9808_i2cClose();
		
		public:
			MCP9808(ConnectedHouse* house, bool A0 = MCP9808_A0, bool A1 = MCP9808_A1, bool A2 = MCP9808_A2);
			MCP9808(ConnectedHouse* house, uint8_t suffix);
			~MCP9808();
			
			inline ConnectedHouse* house();
			inline bool A0() const;
			inline bool A1() const;
			inline bool A2() const;
			inline int handle() const;
			
			bool setHouse(ConnectedHouse* house);
			inline void setA0(bool A0);
			inline void setA1(bool A2);
			inline void setA2(bool A2);
			
			float readTemp();
			bool displayTemp();
	};
	
	inline ConnectedHouse* MCP9808::house()
	{
		return house_;
	}
	
	inline bool MCP9808::A0() const
	{
		return A0_;
	}
	
	inline bool MCP9808::A1() const
	{
		return A1_;
	}
	
	inline bool MCP9808::A2() const
	{
		return A2_;
	}
	
	inline int MCP9808::handle() const
	{
		return handle_;
	}
	
	inline void MCP9808::setA0(bool A0)
	{
		A0_ = A0;
	}
	
	inline void MCP9808::setA1(bool A1)
	{
		A1_ = A1;
	}
	
	inline void MCP9808::setA2(bool A2)
	{
		A2_ = A2;
	}
}

#endif
