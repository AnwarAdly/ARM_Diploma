/**********************************************************/
/* Author  : Anwar Ahmad                                  */
/* Version : 01                                           */
/* Date    : 8/24/2020                                    */
/**********************************************************/
#ifndef EXTI_INTERFACE_H
#define EXTI_INTERFACE_H

/* Functions Prototypes */
void EXTI_voidInit();
void EXTI_voidEnableExternalInterrupt(u8 Copy_u8Line);
void EXTI_voidDisableExternalInterrupt(u8 Copy_u8Line);
void EXTI_voidSoftwareTrigger(u8 Copy_u8Line);
void EXTI_voidSetSignalLatch(u8 Copy_u8Line , u8 Copy_u8Mode); /* Function is identical to init() 
																but it used to not use large numbers of #define 
																and to can change in runtime */			
void EXTI_voidSetCallBack(void (*Copy_Ptr) (void));																
#endif