#ifndef HPP_LIGHT
#define HPP_LIGHT

#define LED_GPIO_PIN 17

#include <pigpio.h>
#include "GPIOUtilities.hpp"
#include "ConnectedHouse.hpp"

namespace House
{
	class ConnectedHouse;
	
	class Light
	{
		private:
			ConnectedHouse* house_;
			uint8_t pin_;
			bool light_;
			unsigned int intensity_;
			
			bool setting();
			
		public:
			Light(House::ConnectedHouse* house, int pin = LED_GPIO_PIN);
			~Light();
			
			inline ConnectedHouse* house();
			inline bool light() const;
			inline unsigned int intensity() const;
			
			bool setHouse(ConnectedHouse* house);
			void setLight(bool light);
			void setIntensity(unsigned int intensity);
	};
	
	inline ConnectedHouse* Light::house()
	{
		return house_;
	}
	
	inline bool Light::light() const
	{
		return light_;
	}
	
	inline unsigned int Light::intensity() const
	{
		return intensity_;
	}
	
	// inline void Light::setHandle(int handle)
	// {
	// 	handle_ = handle;
	// }
}

#endif 
