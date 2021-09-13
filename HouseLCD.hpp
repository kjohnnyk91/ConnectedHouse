#ifndef HPP_HOUSELCD
#define HPP_HOUSELCD

#include "LCD.hpp"
#include "ConnectedHouse.hpp"
// #include "MCP9808.hpp"

namespace House
{
	class ConnectedHouse;
	
	class HouseLCD : public LCD
	{
		protected:
			ConnectedHouse* house_;
			float temp_;				// The temperature being displayed on the LCD screen
			uint8_t persons_;			// The number of persons displayed on the LCD screen
			
		public:
			HouseLCD(ConnectedHouse* house, const uint8_t bus, uint8_t addr, uint8_t width = 16, bool backlight_on = true);
			~HouseLCD();
			
			inline ConnectedHouse* house();
			inline float temp() const;
			inline uint8_t persons() const;
			
			bool getTemp();
			bool getPersons();
			
			void display();
	};
	
	inline ConnectedHouse* HouseLCD::house()
	{
		return house_;
	}
	
	inline float HouseLCD::temp() const
	{
		return temp_;
	}
	
	inline uint8_t HouseLCD::persons() const
	{
		return persons_;
	}
}

#endif
