#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include "../../MCAL/DIO/DIO_Interface.h"
#include "../../MCAL/Timer_Counter/Timer_Count1_Interface.h"

#define ICR_Value 625

void Motors(void)
{
	DIO_VidSetPinDirection(PRTD,PIN5,OUTPUT);	//Direction of Servo Motor
	DIO_VidSetPinDirection(PRTD,PIN2,OUTPUT);	//Direction of  Buzzer

	Tim1_VidInit();			//Initialization of Timer 1
	Tim1_VidOutCompare();	// Output Mode Of Fast PWM ICR As Non-Inverted Mode
	Tim1_VidICR(ICR_Value);

}


void Buzzr_Process(u8 LOC_Value) // To Enable Buzzer send 1 or Disable send 0
{
	if (LOC_Value==Disable)
	{
		DIO_VidSetPinValue(PRTD,PIN2,LOW); // Buzzer OFF
	}
	else if (LOC_Value==Enable)
	{
		DIO_VidSetPinValue(PRTD,PIN2,HIGH); // Buzzer ON
	}

}
