#include "../LIB/STD_TYPES.h"
#include "../LIB/BIT_MATH.h"
#include "../MCAL/DIO/DIO_Interface.h"
#include "../HAL/Sensors/Sensors.h"
#include "../HAL/Motors/Motor.h"
#include "Display.h"
#include "../HAL/LCD_4BIT/LCD_4BIT_Interface.h"
#include "../HAL/KeyPad/KeyPad_Interface.h"
#include "../MCAL/Timer_Counter/Timer_Count1_Interface.h"
#include "avr/delay.h"

void smarthome(void)
{
	u8 username[3];
	u8 arrindx=0;
	u8 password[3];
	u8 arrindx_pass=0;
	u8 i=0;
	u8 j=0;
	u8 key_pad_ret_value=0;
	Motors();
	Sensors();
	KeyPad_VidInit(PRTC);	//Initialization of Keypad and Set Its Direction
	LCD_Vid4Initialization();
	LCD_VidWrite4Cmd(Clear_Display);
	LCD_Write4String("user name=",0,0);
while (1)
{
	key_pad_ret_value= GetPressedKey;
		if(key_pad_ret_value)
		{
			LCD_VidDisp4Number(key_pad_ret_value);
			username[arrindx]=key_pad_ret_value;
			arrindx++;
			if(arrindx==3)
			{
				if((username[0]==1) && (username[1]==2)&& (username[2]==3))
				{
					LCD_VidWrite4Cmd(Clear_Display);
					LCD_Write4String("user name is correct",0,0);
					_delay_ms(1000);
					LCD_VidWrite4Cmd(Clear_Display);
					LCD_Write4String("password=",0,0);
														while(1)
															{
																key_pad_ret_value= GetPressedKey;
																if (key_pad_ret_value)
																	{
															//	/*
																	LCD_VidDisp4Number(key_pad_ret_value);
																	password[arrindx_pass]=key_pad_ret_value;
																	arrindx_pass++;
																	if(arrindx_pass==3)
																	{
																		if((password[0]==3) && (password[1]==2)&& (password[2]==1))
																		{
																			Display();    //displaz function system

																		}
																		else
																		{
																			LCD_VidWrite4Cmd(Clear_Display);
																			LCD_Write4String("password is wrong",0,0);
																			_delay_ms(1000);
																			arrindx_pass=0;
																			j++;
																			LCD_VidWrite4Cmd(Clear_Display);
																			if(j==3)
																			{
																				LCD_Write4String("no more try",0,0);
																				while(1)
																				{
																					key_pad_ret_value= GetPressedKey;
																					if (key_pad_ret_value==99)
																					{
																						LCD_VidWrite4Cmd(Clear_Display);
																						j=0;
																						arrindx_pass=0;
																						LCD_Write4String("password=",0,0);
																						break;
																					}
																				}
																			}
																			else if(j<3)
																			{
																			LCD_Write4String("password=",0,0);}
																			}
																	}
												}
											}
				}
				else
				{
					LCD_VidWrite4Cmd(Clear_Display);
					LCD_Write4String("user name is wrong",0,0);
					_delay_ms(1000);
					arrindx=0;
					i++;
					LCD_VidWrite4Cmd(Clear_Display);
					if(i==3)
					{
						LCD_Write4String("no more try",0,0);
						while(1)
						{
							key_pad_ret_value= GetPressedKey;
							if (key_pad_ret_value==99)
							{
								LCD_VidWrite4Cmd(Clear_Display);
								i=0;
								arrindx=0;
								LCD_Write4String("user name=",0,0);
								break;
							}
						}
					}
					else if(i<3)
					{
					LCD_Write4String("user name=",0,0);}
					}

			}
		}
}
}
