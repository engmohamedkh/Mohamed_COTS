/**************************************************************************************************************/
/***********************     Author : Mohamed khaled     *****************************************************/
/***********************     Layer :  HAL                *****************************************************/
/***********************     SWC :    KEYPAD                  *****************************************************/
/***********************     Version : 1                    *****************************************************/
/***************************************************************************************************************//



#include  "STD_TYPES.h"
#include"PORT_interface.h"
#include"DIO_interface.h"
#include "KEYPAD_config.h"
#include "KEYPAD_private.h"
#include"KEYPAD_interface.h"



u8 KEYPAD_u8GetPreesdKey(void)
{
	u8 local_u8column_indx;
	u8 local_u8PINstate;
	u8 local_u8row_indx;
	u8 local_u8PressedKey=NO_KEYPAD_PRESSED;

	/*to save memory of stack define as static*/
	 u8 local_u8KPA_ARR[ROW_NUM][COL_NUM]=KEYPAD_ARR_VAL;
	 u8 local_u8KPA_COL_ARR[4]={KEYPAD_COL0_PIN,KEYPAD_COL1_PIN,KEYPAD_COL2_PIN,KEYPAD_COL3_PIN};
	 u8 local_u8KPA_ROW_ARR[4]={KEYPAD_ROW0_PIN,KEYPAD_ROW1_PIN,KEYPAD_ROW2_PIN,KEYPAD_ROW3_PIN};
	for(local_u8column_indx=0;local_u8column_indx<ROW_NUM;local_u8column_indx++)
	{
		DIO_SetPinValue(KEYPAD_PORT,local_u8KPA_COL_ARR[local_u8column_indx],DIO_U8PIN_LOW);


		for(local_u8row_indx=0;local_u8row_indx<COL_NUM;local_u8row_indx++)
		{
			DIO_GetPinValue(KEYPAD_PORT,local_u8KPA_ROW_ARR[local_u8row_indx],&local_u8PINstate);
			if(DIO_U8PIN_LOW==local_u8PINstate)
			{
				local_u8PressedKey=local_u8KPA_ARR[local_u8row_indx][local_u8column_indx];
				while(DIO_U8PIN_LOW==local_u8PINstate)
				{
					DIO_GetPinValue(KEYPAD_PORT,local_u8KPA_ROW_ARR[local_u8row_indx],&local_u8PINstate);
				}
				return local_u8PressedKey;
			}

		}

		DIO_SetPinValue(KEYPAD_PORT,local_u8KPA_COL_ARR[local_u8column_indx],DIO_U8PIN_HIGH);

	}

	return local_u8PressedKey;
}

