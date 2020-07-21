#include "../LIB/STD_TYPES.h"
#include "../LIB/BIT_MATH.h"
#include "../MCAL/DIO/DIO_Interface.h"
#include "../HAL/Sensors/Sensors.h"
#include "../HAL/Motors/Motor.h"
#include "../HAL/KeyPad/KeyPad_Interface.h"
#include "../MCAL/Timer_Counter/Timer_Count1_Interface.h"
volatile u8 arr[16]={0};
void smarthome(void)
{
	Motors();
	Sensors();
//	u8 GetPressedLockDoor=0;

while (1)
{



//	GetPressedLockDoor=GetPressedKey(PRTC);
	if(arr[1]==1)
	{
		DIO_VidSetPinValue(PRTD,PIN0,HIGH);

		Tim1_VidOCRA(62);
	}
	else if (arr[2]==2)
	{
		DIO_VidSetPinValue(PRTD,PIN0,LOW);

		Tim1_VidOCRA(31);
	}
}
}
