/**************************************************************************************************************/
/***********************     Author : Mohamed khaled     *****************************************************/
/***********************     Layer :  HAL                *****************************************************/
/***********************     SWC :    CLCD                  *****************************************************/
/***********************     Version : 1                    *****************************************************/
/***************************************************************************************************************/




#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include <util/delay.h>
#include "CLCD_interface.h"
#include"CLCD_config.h"
#include "CLCD_private.h"

#include "DIO_interface.h"

#define lcd_FunctionSet8bit 0x38          // 8-bit data, 2-line display, 5 x 7 font
#define lcd_DisplayOn       0x0C          // display on, cursor off, don't blink character
#define lcd_Clear           0x01          /* replace all characters with ASCII 'space' */


static void voidSendEnablePulse(void)
{
	/*enable pulse for 1ms*/
	DIO_SetPinValue(CLCD_CTRL_PORT,CLCD_E_PIN,DIO_U8PIN_HIGH);

	_delay_ms(2);

	DIO_SetPinValue(CLCD_CTRL_PORT,CLCD_E_PIN,DIO_U8PIN_LOW);
}
static void voidSetLCDHalfDataPort(u8 Copy_u8Nipple)
{
	DIO_SetPinValue(CLCD_DATA_PORT,CLCD_D4_PIN,GET_BIT(Copy_u8Nipple,0));
	DIO_SetPinValue(CLCD_DATA_PORT,CLCD_D5_PIN,GET_BIT(Copy_u8Nipple,1));
	DIO_SetPinValue(CLCD_DATA_PORT,CLCD_D6_PIN,GET_BIT(Copy_u8Nipple,2));
	DIO_SetPinValue(CLCD_DATA_PORT,CLCD_D7_PIN,GET_BIT(Copy_u8Nipple,3));


}

void CLCD_voidsendcommend(u8 copy_u8commend)
{

	DIO_SetPinValue(CLCD_CTRL_PORT,CLCD_RS_PIN,DIO_U8PIN_LOW);

#if CLCD_RW_CTRL_EN == ENABLED
	DIO_SetPinValue(CLCD_CTRL_PORT,CLCD_RW_PIN,DIO_U8PIN_LOW);
#endif

#if CLCD_OP_MODE == EIGHT_BIT_MODE
	DIO_SetPortValue(CLCD_DATA_PORT,copy_u8commend);
	/*enable pulse for 1ms*/
	voidSendEnablePulse();
	/*write pin by pin*/
#elif CLCD_OP_MODE == FOUR_BIT_MODE
	/*4 higher order bits*/
	voidSetLCDHalfDataPort(copy_u8commend>>4);
	/*enable pulse for 1ms*/
	voidSendEnablePulse();
	/*4 lower order bits*/
	voidSetLCDHalfDataPort(copy_u8commend);
	/*enable pulse for 1ms*/
	voidSendEnablePulse();
#endif
}

void  CLCD_voidsenddata(u8 copy_u8data)
{

	DIO_SetPinValue(CLCD_CTRL_PORT,CLCD_RS_PIN,DIO_U8PIN_HIGH);

#if CLCD_RW_CTRL_EN == ENABLED
	DIO_SetPinValue(CLCD_CTRL_PORT,CLCD_RW_PIN,DIO_U8PIN_LOW);
#endif

#if CLCD_OP_MODE == EIGHT_BIT_MODE
	DIO_SetPortValue(CLCD_DATA_PORT,copy_u8data);
	voidSendEnablePulse();
	/*write pin by pin*/
#elif CLCD_OP_MODE == FOUR_BIT_MODE
	/*4 higher order bits*/
	voidSetLCDHalfDataPort(copy_u8data>>4);
	voidSendEnablePulse();
	/*4 lower order bits*/
	voidSetLCDHalfDataPort(copy_u8data);
	voidSendEnablePulse();
#endif

}





void CLCD_voidclcdinti(void)
{
	_delay_ms(20);

#if CLCD_OP_MODE == EIGHT_BIT_MODE

	CLCD_voidsendcommend(lcd_FunctionSet8bit);

	/*set functoion send by three commend */
	/*write pin by pin*/
#elif CLCD_OP_MODE == FOUR_BIT_MODE
	voidSetLCDHalfDataPort(0b0010);
	voidSendEnablePulse();
	voidSetLCDHalfDataPort(0b0010);
	voidSendEnablePulse();
	voidSetLCDHalfDataPort(0b1000);
	voidSendEnablePulse();
#endif

	CLCD_voidsendcommend(lcd_DisplayOn);
	CLCD_voidsendcommend(lcd_Clear);
}

void CLCD_voidsendstring(char *copy_charstring)
{
	u8 local_u8counter=0;

	while(copy_charstring[local_u8counter]!='\0')
	{
		CLCD_voidsenddata(copy_charstring[local_u8counter]);
		local_u8counter++;
	}

}
void CLCD_voidGOTOXY(u8 copy_u8x,u8 copy_u8y)
{
	u8 local_u8address;
	if(copy_u8x==0)
	{
		local_u8address=copy_u8y;
	}else if(copy_u8x==1)
	{
		local_u8address=copy_u8y+0x40;
	}
	/*Set bit 7 for Set DDRAM address command
		Local_u8DDRamAdd |= 1<<7u;*/
	CLCD_voidsendcommend(128+local_u8address);
}


void CLCD_voidwritespecialchar(u8 *copy_pu8pattern,u8 copy_u8patternNum,u8 copy_u8posx,u8 copy_u8posy)
{
	u8 local_u8CGRAMAddress=0;
	u8 local_u8Iteration;

	/*calculate CGRAM ADDRESS WHOSE EACH BLOCK HAVE 8 BYTES*/
	local_u8CGRAMAddress=copy_u8patternNum*8;

	/*SEND CG COMMEND FOR LCD BY SET THE SIX BIT ONE THROUGH DATA SHEET */
	CLCD_voidsendcommend(local_u8CGRAMAddress+64);
	/*Set bit number 6 for Set CGRAM address command
		Local_u8CGRAMAdd |= 1<<6u;

		/*Set CGRAM address
		CLCD_voidSendCmd(Local_u8CGRAMAdd);*/

	for(local_u8Iteration=0;local_u8Iteration<8;local_u8Iteration++)
	{
		/*ACCESS EACH BITS FROM ARRAY WHICH REPERESENT USER DATA */
		CLCD_voidsenddata(copy_pu8pattern[local_u8Iteration]);
	}
	/*GO BACK TO DDRAM TO DISPLAY BATTERN*/
	CLCD_voidGOTOXY(copy_u8posx,copy_u8posy);
	/*DISPLAY BATTERN WHICH WRITTEN IN TO GCRAM BY ENTER INPURT FROM 0:7 WHICH REPRESENT A LOCATION OF DATA */
	CLCD_voidsenddata(copy_u8patternNum);
}

void CLCD_voidwritenumber(u32 copy_u32number)
{

	if(copy_u32number==0)
	{
		CLCD_voidsenddata('0');
		return;  /*will out of fuction and finish it*/

	}
	u8 local_u8numCounter=0;
	u8 local_num[10];
	u32 number=copy_u32number;
	/*to get number of digit of entering num*/
	while(copy_u32number!=0)
	{
		copy_u32number/=10;
		local_u8numCounter++;
	}

	/*convert number to array of digits-*/
	for(u8 i=0;i<local_u8numCounter;i++)
	{
		local_num[i]=(number%10);
		number/=10;
	}
	/*display each digit as asci */
	CLCD_voidGOTOXY(0,0);
	for(u8 i=1;i<=local_u8numCounter;i++)
	{

		CLCD_voidsenddata(local_num[local_u8numCounter-i]+'0');

	}


}
