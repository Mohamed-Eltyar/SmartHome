#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include "../../MCAL/DIO/DIO_Interface.h"
#include "../../MCAL/Timer_Counter/Timer_Count1_Interface.h"
#include "../../HAL/KeyPad/KeyPad_Interface.h"
void Motors(void)
{
	DIO_VidSetPinDirection(PRTD,PIN5,OUTPUT);
	KeyPad_VidInit(PRTC);
	Tim1_VidInit();
	Tim1_VidOutCompare();
	Tim1_VidICR(625);


}


