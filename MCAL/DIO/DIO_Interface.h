#ifndef SMARTHOME_MCAL_DIO_DIO_INTERFACE_H_
#define SMARTHOME_MCAL_DIO_DIO_INTERFACE_H_

#define PIN0 0
#define PIN1 1
#define PIN2 2
#define PIN3 3
#define PIN4 4
#define PIN5 5
#define PIN6 6
#define PIN7 7

#define PRTA 0
#define PRTB 1
#define PRTC 2
#define PRTD 3

#define OUTPUT 1
#define INPUT  0

//--------------------
/* Set Direction of Pin in Port*/
void DIO_VidSetPinDirection (u8 LOC_u8Port, u8 LOC_u8Pin, u8 LOC_u8State );

void DIO_VidSetPinValue (u8 LOC_u8Port, u8 LOC_u8Pin, u8 LOC_u8Value);

void DIO_VidSetPortDirection (u8 LOC_u8Port, u8 LOC_u8value );

void DIO_VidSetPortValue (u8 LOC_u8Port, u8 LOC_u8value);

u8   DIO_u8GitPinValue (u8 LOC_u8Port, u8 LOC_u8Pin);
//-------------------------------------------------------
void DIO_VidOutLED(u8 LOC_u8LEDs);
#define FUll_LED		0
#define Three_Quarters_LED	1
#define Half_LED			2
#define NO_LED			3



#endif   /* SMARTHOME_MCAL_DIO_DIO_INTERFACE_H_ */
