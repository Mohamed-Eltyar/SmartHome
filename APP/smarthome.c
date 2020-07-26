#include "../LIB/STD_TYPES.h"
#include "../LIB/BIT_MATH.h"
#include "../MCAL/DIO/DIO_Interface.h"
#include "../HAL/Sensors/Sensors.h"
#include "../HAL/Motors/Motor.h"
#include "../HAL/KeyPad/KeyPad_Interface.h"
#include "../MCAL/Timer_Counter/Timer_Count1_Interface.h"

void smarthome(void)
{
	Motors();
	Sensors();
	KeyPad_VidInit(PRTC);	//Initialization of Keypad and Set Its Direction



while (1)
{




}
}
