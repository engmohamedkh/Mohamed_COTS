
/**************************************************************************************************************/
/***********************     Author : Mohamed khaled     *****************************************************/
/***********************     Layer :  HAL                *****************************************************/
/***********************     SWC :    DC MOTOR                  *****************************************************/
/***********************     Version : 1                    *****************************************************/
/***************************************************************************************************************/


#include "STD_TYPES.h"
#include "PORT_interface.h"
#include "DIO_interface.h"
#include "DC_MOTOR_interface.h"


u8 DC_MOTOR_U8CW(DC_MOT_CONF *COPY_CONFIG)
{
	u8 Error_state=0;
	if(COPY_CONFIG!=NULL)
	{
		DIO_SetPinValue(COPY_CONFIG->port,COPY_CONFIG->sw_pin_2,DIO_U8PIN_LOW);
		DIO_SetPinValue(COPY_CONFIG->port,COPY_CONFIG->sw_pin_1,DIO_U8PIN_HIGH);

	}else
	{
		Error_state=1;
	}
	return Error_state;
}
u8 DC_MOTOR_U8CCW(DC_MOT_CONF *COPY_CONFIG)
{
	u8 Error_state=0;

	if(COPY_CONFIG!=NULL)
	{
		DIO_SetPinValue(COPY_CONFIG->port,COPY_CONFIG->sw_pin_1,DIO_U8PIN_LOW);
		DIO_SetPinValue(COPY_CONFIG->port,COPY_CONFIG->sw_pin_2,DIO_U8PIN_HIGH);

	}else
	{
		Error_state=1;
	}
	return Error_state;
}


u8 DC_MOTOR_U8BRAKE(DC_MOT_CONF *COPY_CONFIG)
{
	u8 Error_state=0;

	if(COPY_CONFIG!=NULL)
	{

		DIO_SetPinValue(COPY_CONFIG->port,COPY_CONFIG->sw_pin_1,DIO_U8PIN_LOW);
		DIO_SetPinValue(COPY_CONFIG->port,COPY_CONFIG->sw_pin_2,DIO_U8PIN_LOW);

#if BRAKE == ENABLE

		DIO_SetPinValue(COPY_CONFIG->port,COPY_CONFIG->sw_pin_1,DIO_U8PIN_HIGH);
		DIO_SetPinValue(COPY_CONFIG->port,COPY_CONFIG->sw_pin_2,DIO_U8PIN_HIGH);
#endif

	}else
	{
		Error_state=1;
	}
	return Error_state;
}
