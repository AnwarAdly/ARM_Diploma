/**********************************************************/
/* Author  : Anwar Ahmad                                  */
/* Version : 01                                           */
/* Date    : 8/22/2020                                    */
/**********************************************************/
#ifndef NVIC_INTERFACE_H
#define NVIC_INTERFACE_H

/* Functions Prototypes */
void NVIC_voidEnableInterrupt(u8 Copy_u8IntNumber);
void NVIC_voidDisableInterrupt(u8 Copy_u8IntNumber);
void NVIC_voidSetPendingFlag(u8 Copy_u8IntNumber);
void NVIC_voidClearPendingFlag(u8 Copy_u8IntNumber);
u8 NVIC_u8GetActiveBit(u8 Copy_u8IntNumber);
void NVIC_voidSetPriority(s8 Copy_s8IntID , u8 Copy_u8GroupPriority , u8 Copy_u8SubPriority , u32 Copy_u32PriorityMode);

/*  Priority Modes      */
#define GROUP3 0x05FA0300 //4 bits for group and 0 bit  for sub
#define GROUP4 0x05FA0400 //3 bits for group and 1 bit  for sub 
#define GROUP5 0x05FA0500 //2 bits for group and 2 bits for sub
#define GROUP6 0x05FA0600 //1 bit  for group and 3 bits for sub
#define GROUP7 0x05FA0700 //0 bit  for group and 4 bits for sub

#endif