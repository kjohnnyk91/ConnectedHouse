#include "GPIOUtilities.hpp"

namespace GPIOUtils
{
	int GPIOModeStatus(int gpio, int mode, int status)
	{
		switch(status)
		{
			case 0:
			{
				std::cout << "GPIO " << gpio << " mode set to " << mode;
				
				break;
			}
			
			case PI_BAD_GPIO:
			{
				std::cout << "GPIO " << gpio << " doesn't exist";
				
				break;
			}
			
			case PI_BAD_MODE:
			{
				std::cout << "Mode " << mode << " doesn't exist for the GPIO " << gpio;
				
				break;
			}
		}
		
		std::cout << std::endl;
		
		return status;
	}

	int GPIOPUDStatus(int gpio, int pud, int status)
	{
		switch(status)
		{
			case 0:
			{
				std::cout << "GPIO " << gpio << " PUD set to " << pud;
				
				break;
			}
			
			case PI_BAD_GPIO:
			{
				std::cout << "GPIO " << gpio << " doesn't exist";
				
				break;
			}
			
			case PI_BAD_PUD:
			{
				std::cout << "PUD " << pud << " doesn't exist for the GPIO " << gpio;
				
				break;
			}
		}
		
		std::cout << std::endl;
		
		return status;
	}

	void i2cOpenStatus(int status, std::string dev)
	{
		std::cout << "i2c device : " << dev << std::endl;
		
		if(status >= 0)
		{
			std::cout << "i2c device " << dev << " has been opened" << std::endl;
		}
		else
		{
			std::cout << "i2c error : ";
			
			switch(status)
			{
				case PI_BAD_I2C_BUS:
				{
					std::cout << "bad i2c bus";
					
					break;
				}
				
				case PI_BAD_I2C_ADDR:
				{
					std::cout << "bad i2c address";
					
					break;
				}
				
				case PI_BAD_FLAGS:
				{
					std::cout << "bad flags";
					
					break;
				}
				
				case PI_NO_HANDLE:
				{
					std::cout << "no handle";
					
					break;
				}
				
				case PI_I2C_OPEN_FAILED:
				{
					std::cout << "open failed";
					
					break;
				}
				
				default:
				{
					std::cout << "unknown";
					
					break;
				}
			}
			
			std::cout << std::endl;
		}
	}

	void i2cCloseStatus(int status, std::string dev)
	{
		if(status == 0)
		{
			std::cout << "i2c device " << dev << " has been closed";
		}
		else
		{
			std::cout << "i2c close error : bad handle";
		}
		
		std::cout << std::endl;
	}
	
	void i2cWriteStatus(int status)
	{
		std::cout << "Sending data" << std::endl;
		
		switch(status)
		{
			case 0:
			{
				std::cout << "Data sent";

				break;
			}

			case PI_BAD_HANDLE:
			{
				std::cout << "Error write: Bad handle";

				break;
			}

			case PI_BAD_PARAM:
			{
				std::cout << "Error write: Bad param";

				break;
			}

			case PI_I2C_WRITE_FAILED:
			{
				std::cout << "Error write: I2C write failed";

				break;
			}

			default:
			{
				printf("Error write: Unknown error\n");

				break;
			}
		}
		
		std::cout << std::endl;
	}
	
	void i2cReadStatus(int status)
	{
		if(status >= 0)
		{
			printf("Byte read\n");
		}
		else
		{
			printf("I2C Error read: ");

			switch(status)
			{
				case PI_BAD_HANDLE:
				{
					printf("Bad handle");

					break;
				}

				case PI_I2C_READ_FAILED:
				{
					printf("Read failed");

					break;
				}

				default:
				{
					printf("Unknown");

					break;
				}
			}

			printf("\n");
		}
	}
}
