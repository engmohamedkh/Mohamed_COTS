/**************************************************************************************************************/
/***********************     Author : Mohamed khaled     *****************************************************/
/***********************     Layer :  HAL                *****************************************************/
/***********************     SWC :    KEYPAD                  *****************************************************/
/***********************     Version : 1                    *****************************************************/
/***************************************************************************************************************/



#ifndef _KEYPAD_CONFIG_H
#define _KEYPAD_CONFIG_H

/*KEYOAD USED PORT*/
#define KEYPAD_PORT DIO_U8PORTC

/*KEYOAD USED PINS FOR COL*/

#define KEYPAD_COL0_PIN  DIO_U8PIN4
#define KEYPAD_COL1_PIN  DIO_U8PIN5
#define KEYPAD_COL2_PIN  DIO_U8PIN6
#define KEYPAD_COL3_PIN  DIO_U8PIN7



/*KEYOAD USED PINS FOR ROW */

#define KEYPAD_ROW0_PIN  DIO_U8PIN0
#define KEYPAD_ROW1_PIN  DIO_U8PIN1
#define KEYPAD_ROW2_PIN  DIO_U8PIN2
#define KEYPAD_ROW3_PIN  DIO_U8PIN3

/*KEYPAD RETARN VALUES FOR EACH PRESSED ACTION */
#define KEYPAD_ARR_VAL  {{7,8,9,4},{4,5,6,8},{1,2,3,4},{13,0,15,16}}


#define NO_KEYPAD_PRESSED    0xff

#endif
