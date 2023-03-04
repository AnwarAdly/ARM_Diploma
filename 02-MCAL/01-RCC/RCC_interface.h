/**********************************************************/
/* Author  : Anwar Ahmad                                  */
/* Version : 01                                           */
/* Date    : 8/12/2020                                    */
/**********************************************************/
#ifndef RCC_INTERFACE_H
#define RCC_INTERFACE_H

#define RCC_AHB   0
#define RCC_APB1  1
#define RCC_APB2  2

/* Functions Prototypes */
void RCC_voidInitClock();
void RCC_voidEnableClock(u8 Copy_u8BusId , u8 Copy_u8PerId);
void RCC_voidDisableClock(u8 Copy_u8BusId , u8 Copy_u8PerId);

#endif