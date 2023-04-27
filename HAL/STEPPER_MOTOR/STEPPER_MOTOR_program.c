/**************************************************************************************************************/
/***********************     Author : Mohamed khaled     *****************************************************/
/***********************     Layer :  HAL                *****************************************************/
/***********************     SWC :    STEPPER MOTOR                  *****************************************************/
/***********************     Version : 1                    *****************************************************/
/***************************************************************************************************************/


#include "STD_TYPES.h"
#include <util/delay.h>
#include "PORT_interface.h"
#include "DIO_interface.h"
#include "STEPPER_MOTOR_interface.h"



u8 STEPPER_MOTOR_U8ROTATE(STEP_MOT_CONF * COPY_CONFIG,u16 copy_angle,u8 copy_direct)
{
	u8 Error_state=0;
	u16 steps=(u16)(((u32)copy_angle*2048)/360);
	if(COPY_CONFIG!=NULL)
	{
		DIO_SetPinValue(COPY_CONFIG->port,COPY_CONFIG->red_pin,DIO_U8PIN_HIGH);

		for(u16 i=0;i<steps;i++)
		{
			if(i%4==1)
			{
				DIO_SetPinValue(COPY_CONFIG->port,COPY_CONFIG->blue_pin,DIO_U8PIN_LOW);
				DIO_SetPinValue(COPY_CONFIG->port,COPY_CONFIG->pink_pin,DIO_U8PIN_HIGH);
				DIO_SetPinValue(COPY_CONFIG->port,COPY_CONFIG->yellow_pin,DIO_U8PIN_HIGH);
				DIO_SetPinValue(COPY_CONFIG->port,COPY_CONFIG->orange_pin,DIO_U8PIN_HIGH);
			_delay_ms(2);

			}else if (i%4==2)
			{
				DIO_SetPinValue(COPY_CONFIG->port,COPY_CONFIG->blue_pin,DIO_U8PIN_HIGH);
				DIO_SetPinValue(COPY_CONFIG->port,COPY_CONFIG->pink_pin,DIO_U8PIN_LOW);
				DIO_SetPinValue(COPY_CONFIG->port,COPY_CONFIG->yellow_pin,DIO_U8PIN_HIGH);
				DIO_SetPinValue(COPY_CONFIG->port,COPY_CONFIG->orange_pin,DIO_U8PIN_HIGH);
				_delay_ms(2);

			}else if (i%4==3)
			{
				DIO_SetPinValue(COPY_CONFIG->port,COPY_CONFIG->blue_pin,DIO_U8PIN_HIGH);
				DIO_SetPinValue(COPY_CONFIG->port,COPY_CONFIG->pink_pin,DIO_U8PIN_HIGH);
				DIO_SetPinValue(COPY_CONFIG->port,COPY_CONFIG->yellow_pin,DIO_U8PIN_LOW);
				DIO_SetPinValue(COPY_CONFIG->port,COPY_CONFIG->orange_pin,DIO_U8PIN_HIGH);
				_delay_ms(2);

			}else if (i%4==4)
			{
				DIO_SetPinValue(COPY_CONFIG->port,COPY_CONFIG->blue_pin,DIO_U8PIN_HIGH);
				DIO_SetPinValue(COPY_CONFIG->port,COPY_CONFIG->pink_pin,DIO_U8PIN_HIGH);
				DIO_SetPinValue(COPY_CONFIG->port,COPY_CONFIG->yellow_pin,DIO_U8PIN_HIGH);
				DIO_SetPinValue(COPY_CONFIG->port,COPY_CONFIG->orange_pin,DIO_U8PIN_LOW);
				_delay_ms(2);

			}

		}

	}else
	{
		Error_state=1;
	}
	return Error_state;
}
