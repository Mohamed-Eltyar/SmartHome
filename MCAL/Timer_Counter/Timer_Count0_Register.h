#ifndef SMARTHOME_MCAL_TIMER_COUNTER_TIMER0_COUNT_REGISTER_H_
#define SMARTHOME_MCAL_TIMER_COUNTER_TIMER0_COUNT_REGISTER_H_

#include "../../LIB/STD_TYPES.h"

#define  TIMSK		*((volatile u8*)0x59)
#define  TIFR		*((volatile u8*)0x58)
#define  TCCR0		*((volatile u8*)0x53)
#define  TCNT0		*((volatile u8*)0x52)
#define  OCR0		*((volatile u8*)0x5C)


#endif  /*SMARTHOME_MCAL_TIMER_COUNTER_TIMER0_COUNT_REGISTER_H_*/
