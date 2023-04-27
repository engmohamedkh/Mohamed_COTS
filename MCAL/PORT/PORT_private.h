/**************************************************************************************************************/
/***********************     Author : Mohamed khaled     *****************************************************/
/***********************     Layer :  MCAL                *****************************************************/
/***********************     SWC :    PORT                  *****************************************************/
/***********************     Version : 1                    *****************************************************/
/***************************************************************************************************************/


#ifndef _PORT_PRIVATE_H
#define _PORT_PRIVATE_H



#define OUTPUT    1
#define INPUT     0
#define PULLUP    1
#define FLOAT     0
#define HIGH    1
#define LOW     0




#define CONC(p7,p6,p5,p4,p3,p2,p1,p0)  CONC_HELPER(p7,p6,p5,p4,p3,p2,p1,p0)
#define CONC_HELPER(p7,p6,p5,p4,p3,p2,p1,p0)          0b##p7##p6##p5##p4##p3##p2##p1##p0


/* port direction function macro   */

#define PORTA_DIR   CONC(PORTA_PIN7_DIR,PORTA_PIN6_DIR,PORTA_PIN5_DIR,PORTA_PIN4_DIR,PORTA_PIN3_DIR,PORTA_PIN2_DIR,PORTA_PIN1_DIR,PORTA_PIN0_DIR)
#define PORTB_DIR   CONC(PORTB_PIN7_DIR,PORTB_PIN6_DIR,PORTB_PIN5_DIR,PORTB_PIN4_DIR,PORTB_PIN3_DIR,PORTB_PIN2_DIR,PORTB_PIN1_DIR,PORTB_PIN0_DIR)
#define PORTC_DIR   CONC(PORTC_PIN7_DIR,PORTC_PIN6_DIR,PORTC_PIN5_DIR,PORTC_PIN4_DIR,PORTC_PIN3_DIR,PORTC_PIN2_DIR,PORTC_PIN1_DIR,PORTC_PIN0_DIR)
#define PORTD_DIR   CONC(PORTD_PIN7_DIR,PORTD_PIN6_DIR,PORTD_PIN5_DIR,PORTD_PIN4_DIR,PORTD_PIN3_DIR,PORTD_PIN2_DIR,PORTD_PIN1_DIR,PORTD_PIN0_DIR)


/*intial port value function macro */

#define PORTA_INTIAL_VAL   CONC(PORTA_PIN7_INTIAL_VAL,PORTA_PIN6_INTIAL_VAL,PORTA_PIN5_INTIAL_VAL,PORTA_PIN4_INTIAL_VAL,PORTA_PIN3_INTIAL_VAL,PORTA_PIN2_INTIAL_VAL,PORTA_PIN1_INTIAL_VAL,PORTA_PIN0_INTIAL_VAL)
#define PORTB_INTIAL_VAL   CONC(PORTB_PIN7_INTIAL_VAL,PORTB_PIN6_INTIAL_VAL,PORTB_PIN5_INTIAL_VAL,PORTB_PIN4_INTIAL_VAL,PORTB_PIN3_INTIAL_VAL,PORTB_PIN2_INTIAL_VAL,PORTB_PIN1_INTIAL_VAL,PORTB_PIN0_INTIAL_VAL)
#define PORTC_INTIAL_VAL   CONC(PORTC_PIN7_INTIAL_VAL,PORTC_PIN6_INTIAL_VAL,PORTC_PIN5_INTIAL_VAL,PORTC_PIN4_INTIAL_VAL,PORTC_PIN3_INTIAL_VAL,PORTC_PIN2_INTIAL_VAL,PORTC_PIN1_INTIAL_VAL,PORTC_PIN0_INTIAL_VAL)
#define PORTD_INTIAL_VAL   CONC(PORTD_PIN7_INTIAL_VAL,PORTD_PIN6_INTIAL_VAL,PORTD_PIN5_INTIAL_VAL,PORTD_PIN4_INTIAL_VAL,PORTD_PIN3_INTIAL_VAL,PORTD_PIN2_INTIAL_VAL,PORTD_PIN1_INTIAL_VAL,PORTD_PIN0_INTIAL_VAL)

#endif
