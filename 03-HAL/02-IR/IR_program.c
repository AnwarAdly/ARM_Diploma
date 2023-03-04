/**********************************************************/
/* Author  : Anwar Ahmad                                  */
/* Version : 01                                           */
/* Date    : 9/11/2020                                     */
/**********************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "STK_interface.h"
#include "GPIO_interface.h"
#include "IR_interface.h"
#include "IR_private.h"
#include "IR_config.h"

/*  Global Variables  
volatile u8   u8StartFlag       = 0;
volatile u32  u32FrameData[50]  = {0};
volatile u8   u8EdgeCounter     = 0;
volatile u8   u8Data            = 0;		 */

void IR_voidGetFrame(void){
	if (u8StartFlag==0){
		STK_voidSetIntervalSingle(1000000,IR_voidTakeAction);
		u8StartFlag=1;
	}
	else{
		u32FrameData[u8EdgeCounter]=STK_u32GetElapsedTime();
		STK_voidSetIntervalSingle(1000000,IR_voidTakeAction);
		u8EdgeCounter++;
	}
}
void IR_voidTakeAction(void){
	u8 i;
	u8Data = 0;
	if ( (u32FrameData[0] >= 10000) && (u32FrameData[0] <= 14000) ){			 // Check that start bit is already come
		for (i=0;i<8;i++){
			if (  (u32FrameData[17+i] >= 2000) && (u32FrameData[17+i] <=2300) ){ // Check that bit is one or zero
				SET_BIT(u8Data,i);
			}

			else{
				CLR_BIT(u8Data,i);
			}
		}
		IR_voidPlay();
	}
	// Cleared to be ready for another push at button
	u8StartFlag     = 0;
	u32FrameData[0] = 0;
	u8EdgeCounter   = 0;	
}
void IR_voidPlay(void){
	switch(u8Data){
		case 70: GPIO_voidSetPinValue(GPIOA,PIN0,HIGH);  break;
		case 69: GPIO_voidSetPinValue(GPIOA,PIN0,LOW) ;  break;		
	}
}
