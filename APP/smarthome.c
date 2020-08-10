#include "../LIB/STD_TYPES.h"
#include "../LIB/BIT_MATH.h"
#include "../MCAL/DIO/DIO_Interface.h"
#include "../HAL/Sensors/Sensors.h"
#include "../HAL/Motors/Motor.h"
#include "Display.h"
#include "../HAL/LCD_4BIT/LCD_4BIT_Interface.h"
#include "../HAL/KeyPad/KeyPad_Interface.h"
#include "../MCAL/Timer_Counter/Timer_Count1_Interface.h"
#include "../MCAL/UART/UART_Interface.h"
#include "avr/delay.h"

u8 Flag_ReturnHome=0;
void KeyPadSystem(void);
void UARTSystem(void);
u8 System=0;
extern u8 Flag_UART;
void smarthome(void)
{

	u8 key_pad_ret_value=0;
	u8 UART_retValue=0;

Flag_UART=1;
	//BuadRate
	UART_VidInit(9600);
	Motors();
	Sensors();
	KeyPad_VidInit(PRTC);	//Initialization of Keypad and Set Its Direction
	LCD_Vid4Initialization();
	LCD_Write4String("Choose System",0,0);
	_delay_ms(2500);
	LCD_VidWrite4Cmd(Clear_Display);
	LCD_Write4String("1-UART",0,0);
	LCD_Write4String("2-KeyPad",0,7);

	while (1)
	{
		key_pad_ret_value=GetPressedKey(PRTC);
		UART_retValue=UART_u8ReadData();


		if (key_pad_ret_value==2)
		{
			System=2;
			break;
		}
		if (UART_retValue==1)
		{
			System=1;
			Flag_UART=0;
			break;
		}

	}
	LCD_VidWrite4Cmd(Clear_Display);
	LCD_Write4String("User Name:",0,0);

while (1)
{
	if (System==1)
	{
		UARTSystem();
	}
	else if (System==2)
	{
		KeyPadSystem();
	}


}
}

void KeyPadSystem(void)
{
	u8 username[3];
		u8 arrindx=0;
		u8 password[3];
		u8 arrindx_pass=0;
		u8 i=0;
		u8 j=0;
		u8 key_pad_ret_value=0;
		u8 flag_1=0;
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
						_delay_ms(500);
						LCD_VidWrite4Cmd(Clear_Display);
						LCD_Write4String("Correct ID",0,0);
						_delay_ms(1000);
						LCD_VidWrite4Cmd(Clear_Display);
						LCD_Write4String("Password:",0,0);
						while(1)
						{
							key_pad_ret_value= GetPressedKey(PRTC);
							if (key_pad_ret_value)
							{
						//
						//LCD_VidDisp4Number(key_pad_ret_value);
						LCD_VidWrite4Data('*');
						_delay_ms(200);
						password[arrindx_pass]=key_pad_ret_value;
						arrindx_pass++;
						if(arrindx_pass==3)
						{
							if((password[0]==3) && (password[1]==3)&& (password[2]==1))
							{
								LCD_Write4String("Correct Pass",0,0);
								_delay_ms(1000);
								LCD_Write4String("Welcome Smart",0,0);
								_delay_ms(1500);
								LCD_VidWrite4Cmd(Clear_Display);
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
										LCD_Write4String("User Name:",0,0);
										key_pad_ret_value=0;
										break;
									}
							}
							else
							{
								LCD_VidWrite4Cmd(Clear_Display);
								LCD_Write4String(" Wrong Pass",0,0);
								_delay_ms(1000);
								arrindx_pass=0;
								j++;
								LCD_VidWrite4Cmd(Clear_Display);
								if(j==3)
									{
										LCD_Write4String("No try Prs 14",0,0);
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
																				LCD_Write4String("Password:",0,0);}
																				}
																		}
													}
												}

					}

					else
					{
						LCD_VidWrite4Cmd(Clear_Display);
						LCD_Write4String("Wrong ID",0,0);
						_delay_ms(1000);
						arrindx=0;
						i++;
						LCD_VidWrite4Cmd(Clear_Display);
						if(i==3)
						{
							LCD_Write4String("No try Prs 14",0,0);
							while(1)
							{
								key_pad_ret_value= GetPressedKey(PRTC);
								if (key_pad_ret_value==14)
								{
									LCD_VidWrite4Cmd(Clear_Display);
									i=0;
									arrindx=0;
									LCD_Write4String("User Name:",0,0);
									flag_1=1;
									break;
								}
							}
						}
						else if(i<3)
						{
							LCD_VidWrite4Cmd(Clear_Display);
						LCD_Write4String("User Name:",0,0);
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
											LCD_Write4String("User Name:",0,0);
											key_pad_ret_value=0;
											break;
										}
					if (Flag_ReturnHome==1)
					{
						break;
					}
		}
}


void UARTSystem(void)
{
	u8 username[3];
			u8 arrindx=0;
			u8 password[3];
			u8 arrindx_pass=0;
			u8 i=0;
			u8 j=0;
			u8 flag_1=0;
			u8 UART_retValue=0;

		flag_1=0;

			while(1)
			{
				flag_1=0;
				Flag_ReturnHome=0;

				UART_retValue= UART_u8ReadData();
				if(UART_retValue !=0 )
				{
					LCD_VidDisp4Number(UART_retValue);
					username[arrindx]=UART_retValue;
					arrindx++;
					if(arrindx==3)
					{
						_delay_ms(200);
						if((username[0]==1) && (username[1]==3)&& (username[2]==3))
						{

							LCD_VidWrite4Cmd(Clear_Display);
							LCD_Write4String("Correct ID",0,0);
							_delay_ms(1000);
							LCD_VidWrite4Cmd(Clear_Display);
							LCD_Write4String("Password:",0,0);
							while(1)
							{
								UART_retValue= UART_u8ReadData();
								if (UART_retValue)
								{

							LCD_VidWrite4Data('*');
							_delay_ms(200);
							password[arrindx_pass]=UART_retValue;
							arrindx_pass++;
							if(arrindx_pass==3)
							{
								if((password[0]==3) && (password[1]==3)&& (password[2]==1))
								{
									LCD_Write4String("Correct Pass",0,0);
									_delay_ms(1000);
									LCD_Write4String("Welcome Smart",0,0);
									_delay_ms(1500);
									LCD_VidWrite4Cmd(Clear_Display);
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
											LCD_Write4String("User Name:",0,0);
											UART_retValue=0;
											break;
										}
								}
								else
								{
									LCD_VidWrite4Cmd(Clear_Display);
									LCD_Write4String(" Wrong Pass",0,0);
									_delay_ms(1000);
									arrindx_pass=0;
									j++;
									LCD_VidWrite4Cmd(Clear_Display);
									if(j==3)
										{
											LCD_Write4String("No try Prs 9",0,0);
											while(1)
											{

												UART_retValue=UART_u8ReadData();
												if (UART_retValue==9)
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
																					LCD_Write4String("Password:",0,0);}
																					}
																			}
														}
													}

						}

						else
						{
							LCD_VidWrite4Cmd(Clear_Display);
							LCD_Write4String("Wrong ID",0,0);
							_delay_ms(1000);
							arrindx=0;
							i++;
							LCD_VidWrite4Cmd(Clear_Display);
							if(i==3)
							{
								LCD_Write4String("No try Prs 9",0,0);
								while(1)
								{
									UART_retValue= UART_u8ReadData();
									if (UART_retValue==9)
									{
										LCD_VidWrite4Cmd(Clear_Display);
										i=0;
										arrindx=0;
										LCD_Write4String("User Name:",0,0);
										flag_1=1;
										break;
									}
								}
							}
							else if(i<3)
							{
								LCD_VidWrite4Cmd(Clear_Display);
							LCD_Write4String("User Name:",0,0);
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
												LCD_Write4String("User Name:",0,0);
												UART_retValue=0;
												break;
											}
						if (Flag_ReturnHome==1)
						{
							break;
						}
			}

}
