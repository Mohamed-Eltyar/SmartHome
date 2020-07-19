#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include "GIE_Register.h"


void SREG_VidEnable(void)
{
	SET_BIT(SREG,7);
	
}
void SREG_VidDisble(void)
{
	CLR_BIT(SREG,7);
	
}
