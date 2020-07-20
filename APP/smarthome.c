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
	u8 GetPressedLockDoor=0;

while (1)
{
	GetPressedLockDoor=GetPressedKey(PRTC);
	if(GetPressedLockDoor==1)
	{
		Tim1_VidOCRA(62);
	}
	else if (GetPressedLockDoor==2)
	{
		Tim1_VidOCRA(31);
	}
}
}
