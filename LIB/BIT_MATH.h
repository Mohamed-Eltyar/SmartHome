#ifndef SMARTHOME_LIB_BIT_MATH_H_
#define SMARTHOME_LIB_BIT_MATH_H_


#define SET_BIT(VAR,BITNO) (VAR) |=  (1 << (BITNO))
#define CLR_BIT(VAR,BITNO) (VAR) &= ~(1 << (BITNO))
#define TOG_BIT(VAR,BITNO) (VAR) ^=  (1 << (BITNO))
#define GET_BIT(VAR,BITNO) (((VAR) >> (BITNO)) & 0x01)


#define HIGH 1
#define LOW 0

#include <avr/delay.h>


#endif /*SMARTHOME_LIB_BIT_MATH_H_*/
