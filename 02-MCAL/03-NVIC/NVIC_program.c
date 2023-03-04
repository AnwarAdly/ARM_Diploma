/**********************************************************/
/* Author  : Anwar Ahmad                                  */
/* Version : 01                                           */
/* Date    : 8/22/2020                                    */
/**********************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "NVIC_interface.h"
#include "NVIC_private.h"
#include "NVIC_config.h"

void NVIC_voidEnableInterrupt(u8 Copy_u8IntNumber){
	if(Copy_u8IntNumber<=31){
		SET_BIT(NVIC_ISER0,Copy_u8IntNumber); //NVIC_ISER0=(1<<Copy_u8IntNumber);
	}
	else if(Copy_u8IntNumber<=59){
		Copy_u8IntNumber -= 32;
		SET_BIT(NVIC_ISER1,Copy_u8IntNumber);
	}
}
void NVIC_voidDisableInterrupt(u8 Copy_u8IntNumber){
	if(Copy_u8IntNumber<=31){
		SET_BIT(NVIC_ICER0,Copy_u8IntNumber); 
	}
	else if(Copy_u8IntNumber<=59){
		Copy_u8IntNumber -= 32;
		SET_BIT(NVIC_ICER1,Copy_u8IntNumber);
	}
}
void NVIC_voidSetPendingFlag(u8 Copy_u8IntNumber){
	if(Copy_u8IntNumber<=31){
		NVIC_ISPR0=(1<<Copy_u8IntNumber);
	}
	else if(Copy_u8IntNumber<=59){
		Copy_u8IntNumber -= 32;
		NVIC_ISPR1=(1<<Copy_u8IntNumber);
	}	
}
void NVIC_voidClearPendingFlag(u8 Copy_u8IntNumber){
	if(Copy_u8IntNumber<=31){
		NVIC_ICPR0=(1<<Copy_u8IntNumber);
	}
	else if(Copy_u8IntNumber<=59){
		Copy_u8IntNumber -= 32;
		NVIC_ICPR1=(1<<Copy_u8IntNumber);
	}	
}
u8 NVIC_u8GetActiveBit(u8 Copy_u8IntNumber){
	u8 Local_u8Result=0;
	if(Copy_u8IntNumber<=31){
		Local_u8Result=GET_BIT(NVIC_IABR0,Copy_u8IntNumber);
	}
	else if(Copy_u8IntNumber<=59){
		Copy_u8IntNumber -= 32;
		Local_u8Result=GET_BIT(NVIC_IABR1,Copy_u8IntNumber);
	}
	return Local_u8Result;
}
void NVIC_voidSetPriority(s8 Copy_s8IntID , u8 Copy_u8GroupPriority , u8 Copy_u8SubPriority , u32 Copy_u32PriorityMode){
	/*Example1 : 		write in 00??0000	write in ??000000	   0x05FA0400(3G & 1sub)-0x05FA0300=0x100=256/256=1		*/
	/*Example2 : 		write in 00??0000	write in ??000000	   0x05FA0500(2G & 2sub)-0x05FA0300=0x200=512/256=2		*/
	u8 Local_u8Priority=(Copy_u8SubPriority|(Copy_u8GroupPriority<<((Copy_u32PriorityMode-0x05FA0300)/256))); //256=0x100
	/*Core Peripheral*/
	
	/*External Peripheral*/
	if(Copy_s8IntID>=0){
		NVIC_IPR[Copy_s8IntID]=(Local_u8Priority<<4); //To put bits in MSBs
	}
	SCB_AIRCR=Copy_u32PriorityMode;
}
