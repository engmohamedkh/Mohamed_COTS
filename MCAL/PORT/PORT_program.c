/**************************************************************************************************************/
/***********************     Author : Mohamed khaled     *****************************************************/
/***********************     Layer :  MCAL                *****************************************************/
/***********************     SWC :    PORT                  *****************************************************/
/***********************     Version : 1                    *****************************************************/
/***************************************************************************************************************/

#include  "STD_TYPES.h"
/*AS private.h is dependant onto config.h so set it first*/
#include "PORT_cofig.h"
#include "PORT_private.h"
#include"PORT_interface.h"
#include "PORT_register.h"


void PORT_voidinit(void)
{
	/*ACCESS OUR MC REGISTER BY VALUE WHICH DEFIND IN DEEFAULT AND PRIVATE FILE */
DDRA_Register=PORTA_DIR;
DDRB_Register=PORTB_DIR;
DDRC_Register=PORTC_DIR;
DDRD_Register=PORTD_DIR;



PORTA_Register=PORTA_INTIAL_VAL;
PORTB_Register=PORTB_INTIAL_VAL;
PORTC_Register=PORTC_INTIAL_VAL;
PORTD_Register=PORTD_INTIAL_VAL;
}
