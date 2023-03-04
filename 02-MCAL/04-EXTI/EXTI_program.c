/**********************************************************/
/* Author  : Anwar Ahmad                                  */
/* Version : 01                                           */
/* Date    : 8/24/2020                                    */
/**********************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "EXTI_interface.h"
#include "EXTI_private.h"
#include "EXTI_config.h"

void EXTI_voidInit(void){
	#if   EXTI_MODE == RISING 
	SET_BIT(EXTI_Ptr ->RTSR,EXTI_LINE);
	#elif EXTI_MODE == FALLING 
	SET_BIT(EXTI_Ptr ->FTSR,EXTI_LINE);
	#elif EXTI_MODE == ON_CHANGE 
	SET_BIT(EXTI_Ptr ->RTSR,EXTI_LINE);	
	SET_BIT(EXTI_Ptr ->FTSR,EXTI_LINE);
	#elif #error "Wrong Mode or Line choice"
	#endif
}
void EXTI_voidEnableExternalInterrupt(u8 Copy_u8Line){
	SET_BIT(EXTI_Ptr ->IMR,Copy_u8Line);
}
void EXTI_voidDisableExternalInterrupt(u8 Copy_u8Line){
	CLR_BIT(EXTI_Ptr ->IMR,Copy_u8Line);
}
void EXTI_voidSoftwareTrigger(u8 Copy_u8Line){
	SET_BIT(EXTI_Ptr ->SWIER,Copy_u8Line);
}
void EXTI_voidSetSignalLatch(u8 Copy_u8Line , u8 Copy_u8Mode){
	switch (Copy_u8Mode){
		case RISING    : SET_BIT(EXTI_Ptr ->RTSR,EXTI_LINE); break;
		case FALLING   : SET_BIT(EXTI_Ptr ->FTSR,EXTI_LINE); break;
		case ON_CHANGE : SET_BIT(EXTI_Ptr ->RTSR,EXTI_LINE); 
						 SET_BIT(EXTI_Ptr ->FTSR,EXTI_LINE); break;
		default        :                                     break;
	}
	SET_BIT(EXTI_Ptr ->IMR,Copy_u8Line);
}
void EXTI_voidSetCallBack(void (*Copy_Ptr) (void)){
	EXTI_CallBack = Copy_Ptr;
}
void EXTI_IRQHandler(void){
	EXTI_CallBack();
	SET_BIT(EXTI_Ptr ->PR,Copy_u8Line); // Clear Pending Bit
}
