#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include "../../MCAL/DIO/DIO_Interface.h"
#include "../../MCAL/Timer_Counter/Timer_Count1_Interface.h"
#include "../../HAL/KeyPad/KeyPad_Interface.h"
void Motors(void)
{
	DIO_VidSetPinDirection(PRTD,PIN5,OUTPUT);
	DIO_VidSetPinDirection(PRTD,PIN2,OUTPUT);	//Direction of  Buzzer

	KeyPad_VidInit(PRTC);
	Tim1_VidInit();
	Tim1_VidOutCompare();
	Tim1_VidICR(625);


}


void Buzzr_Process(u8 LOC_Value) // To Enable Buzzer send 1 or Disable send 0
{
	if (LOC_Value==0)
	{
		DIO_VidSetPinValue(PRTD,PIN2,LOW); // Buzzer OFF
	}
	else if (LOC_Value==1)
	{
		DIO_VidSetPinValue(PRTD,PIN2,HIGH); // Buzzer ON
	}

}
