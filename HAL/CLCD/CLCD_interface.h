/**************************************************************************************************************/
/***********************     Author : Mohamed khaled     *****************************************************/
/***********************     Layer :  HAL                *****************************************************/
/***********************     SWC :    CLCD                  *****************************************************/
/***********************     Version : 1                    *****************************************************/
/***************************************************************************************************************/






#ifndef  CLCD_INTERFACE_H_
#define  CLCD_INTERFACE_H_


void CLCD_voidsendcommend(u8 copy_u8commend);

void CLCD_voidsenddata(u8 copy_u8data);
void CLCD_voidclcdinti(void);

void CLCD_voidsendstring(char *copy_charstring);
void CLCD_voidGOTOXY(u8 copy_u8x,u8 copy_u8y);
void CLCD_voidwritespecialchar(u8 *copy_pu8pattern,u8 copy_u8patternNum,u8 copy_u8posx,u8 copy_u8posy);
void CLCD_voidwritenumber(u32 copy_u32number);
#endif
