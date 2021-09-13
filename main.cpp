#include "ConnectedHouse.hpp"

int main()
{
	House::ConnectedHouse house(0);
	
	House::Light* light(house.light());
	LCD* lcd(house.lcd());
	light-> setLight(false);
	lcd-> enableBacklight(false);
	
	return 0;
}
