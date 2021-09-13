#include "ConnectedHouse.hpp"

int main()
{
	House::ConnectedHouse house(0);
	
	house.lightOff();
	house.lcdOff();
	
	house.tempRead();
	
	return 0;
}
