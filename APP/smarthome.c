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

u8 Flag_ReturnHome=0;

void smarthome(void)
{
	u8 username[3];
	u8 arrindx=0;
	u8 password[3];
	u8 arrindx_pass=0;
	u8 i=0;
	u8 j=0;
	u8 key_pad_ret_value=0;
	u8 flag_1=0;

	Motors();
	Sensors();
	KeyPad_VidInit(PRTC);	//Initialization of Keypad and Set Its Direction
	LCD_Vid4Initialization();
	LCD_VidWrite4Cmd(Clear_Display);
	LCD_Write4String("User name=",0,0);


while (1)
{
	flag_1=0;

	while(1)
	{
		flag_1=0;
		Flag_ReturnHome=0;

	key_pad_ret_value= GetPressedKey(PRTC);
		if(key_pad_ret_value !=0 )
		{
			LCD_VidDisp4Number(key_pad_ret_value);
			username[arrindx]=key_pad_ret_value;
			arrindx++;
			if(arrindx==3)
			{
				if((username[0]==1) && (username[1]==3)&& (username[2]==3))
				{

					LCD_VidWrite4Cmd(Clear_Display);
					LCD_Write4String("user name is correct",0,0);
					_delay_ms(1000);
					LCD_VidWrite4Cmd(Clear_Display);
					LCD_Write4String("password=",0,0);
					while(1)
					{
						key_pad_ret_value= GetPressedKey(PRTC);
						if (key_pad_ret_value)
						{
					//
					LCD_VidDisp4Number(key_pad_ret_value);
					password[arrindx_pass]=key_pad_ret_value;
					arrindx_pass++;
					if(arrindx_pass==3)
					{
						if((password[0]==3) && (password[1]==3)&& (password[2]==1))
						{
								Display();    //display function system
								if (Flag_ReturnHome==1)
								{
									username[0]=0;
									username[1]=0;
									username[2]=0;
									arrindx=0;
									i=0;
									j=0;
									arrindx_pass=0;
									password[0]=0;
									password[1]=0;
									password[2]=0;
									LCD_VidWrite4Cmd(Clear_Display);
									LCD_Write4String("user name=",0,0);
									key_pad_ret_value=0;
									break;
								}
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

										key_pad_ret_value= GetPressedKey(PRTC);
										if (key_pad_ret_value==14)
										{
											flag_1=1;
											LCD_VidWrite4Cmd(Clear_Display);
																						j=0;
																						arrindx_pass=0;

																						break;
																					}
																				}
									if (flag_1==1)
										{break;}
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
							key_pad_ret_value= GetPressedKey(PRTC);
							if (key_pad_ret_value==14)
							{
								LCD_VidWrite4Cmd(Clear_Display);
								i=0;
								arrindx=0;
								LCD_Write4String("user name=",0,0);
								flag_1=1;
								break;
							}
						}
					}
					else if(i<3)
					{
						LCD_VidWrite4Cmd(Clear_Display);
					LCD_Write4String("user name=",0,0);
					}
					}

			}
		}


									if (flag_1==1)
									{
										username[0]=0;
										username[1]=0;
										username[2]=0;
										arrindx=0;
										i=0;
										j=0;
										arrindx_pass=0;
										password[0]=0;
										password[1]=0;
										password[2]=0;
										LCD_VidWrite4Cmd(Clear_Display);
										LCD_Write4String("user name=",0,0);
										key_pad_ret_value=0;
										break;
									}
				if (Flag_ReturnHome==1)
				{
					break;
				}
	}


}
}
