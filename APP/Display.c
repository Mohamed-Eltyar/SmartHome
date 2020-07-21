
#include "../HAL/LCD_4BIT/LCD_4BIT_Interface.h"

u8 Display_Cursor[8]={0x10,0x18,0x1E,0x1F,0x1F,0x1E,0x18,0x10};
void Display(void)
{

}

void Position_Cursor(u8 LOC_u8ROW,u8 LOC_u8COL)
{
	LCD_GoToPosition(LOC_u8ROW,LOC_u8COL);
	LCD_StoreCustomChr(Display_Cursor,0);
}
