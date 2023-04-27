/**************************************************************************************************************/
/***********************     Author : Mohamed khaled     *****************************************************/
/***********************     Layer :  HAL                *****************************************************/
/***********************     SWC :    CLCD                  *****************************************************/
/***********************     Version : 1                    *****************************************************/
/***************************************************************************************************************/



#ifndef CLCD_CONFIG_H_
#define CLCD_CONFIG_H_
/*choose option for lcd mode 1- eight bit mode
 *                           2- four bit mode  */

#define CLCD_OP_MODE   EIGHT_BIT_MODE

#define CLCD_DATA_PORT  DIO_U8PORTA

/*cofigure if the RW pin is controlled or not as need to connect to groud , options: 1- ENABLED
 * or connect to MC pin and control it 										      2- DISABLED */
#define CLCD_RW_CTRL_EN			DISABLED

/*please choose options for port and control pins used*/


#define CLCD_CTRL_PORT  DIO_U8PORTB
#define CLCD_RS_PIN     DIO_U8PIN0

#if CLCD_RW_CTRL_EN == ENABLED

#define CLCD_RW_PIN     DIO_U8PIN1

#endif

#define CLCD_E_PIN      DIO_U8PIN2

#if  CLCD_OP_MODE == FOUR_BIT_MODE

#define CLCD_D4_PIN     DIO_U8PIN4
#define CLCD_D5_PIN     DIO_U8PIN5
#define CLCD_D6_PIN     DIO_U8PIN6
#define CLCD_D7_PIN     DIO_U8PIN7
#endif

#endif
