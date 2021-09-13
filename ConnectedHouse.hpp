#ifndef HPP_CONNECTEDHOUSE
#define HPP_CONNECTEDHOUSE

#include <iostream>
#include <new>
#include <pigpio.h>
#include "GPIOUtilities.hpp"
#include "MCP9808.hpp"
#include "LCD.hpp"
#include "Light.hpp"

#define GPIO_LED 17
#define LCD_1602_I2C_ADDRESS 0x27
#define LCD_I2C_BUS 1

namespace House
{
	class Light;
	class MCP9808;
	
	class ConnectedHouse
	{
		private:
			int version_;
			uint8_t persons_;
			Light* light_;
			// Door* door_;
			LCD* lcd_;
			MCP9808* tempSensor_;
			// RFIDReader* RFIDReader_;
			// bool exitButton_;
			
			bool init();
			
		public:
			ConnectedHouse(uint8_t persons);
			~ConnectedHouse();
			
			inline int version() const;
			inline uint8_t persons() const;
			inline Light* light();
			// inline Door* door();
			inline LCD* lcd();
			inline MCP9808* tempSensor();
			// inline RFIDReader* RFIDReader();
			
			inline void setPersons(uint8_t persons);
			bool setLight(Light* light);
			// inline void setDoor(Door* door);
			inline void setLCD(LCD* lcd);
			bool setTempSensor(MCP9808* sensor);
			// inline void setRFIDReader(RFIDReader reader);
			
			inline void lightOff();
			inline void lightOn();
			inline void lcdOff();
			inline void lcdOn();
			inline void tempRead();
	};
	
	inline int ConnectedHouse::version() const
	{
		return version_;
	}
	
	inline uint8_t ConnectedHouse::persons() const
	{
		return persons_;
	}
	
	inline Light* ConnectedHouse::light()
	{
		return light_;
	}
	
	//	inline Door* ConnectedHouse::door()
	//	{
	//		return door_;
	//	}
	
	inline LCD* ConnectedHouse::lcd()
	{
		return lcd_;
	}
	
	inline MCP9808* ConnectedHouse::tempSensor()
	{
		return tempSensor_;
	}
	
	//	inline RFIDReader* ConnectedHouse::RFIDReader()
	//	{
	//		return RFIDReader_;
	//	}
	
	inline void ConnectedHouse::setPersons(uint8_t persons)
	{
		persons_ = persons;
	}
	
	//	inline void ConnectedHouse::setLCD(LCD* lcd)
	//	{
	//		lcd_ = lcd;
	//	}
	
	//	inline void ConnectedHouse::setRFIDReader(RFIDReader* RFIDReader)
	//	{
	//		RFIDReader_ = RFIDReader;
	//	}
	
	//	inline void ConnectedHouse::setPersons(uint8_t persons)
	//	{
	//		persons_ = persons;
	//	}
	
	inline void ConnectedHouse::lightOff()
	{
		light_-> setLight(false);
	}
	
	inline void ConnectedHouse::lightOn()
	{
		light_-> setLight(true);
	}
	
	inline void ConnectedHouse::lcdOff()
	{
		if(lcd_ != nullptr)
			lcd_-> enableBacklight(false);
	}
	
	inline void ConnectedHouse::lcdOn()
	{
		if(lcd_ != nullptr)
			lcd_-> enableBacklight(true);	
	}
}

#endif
