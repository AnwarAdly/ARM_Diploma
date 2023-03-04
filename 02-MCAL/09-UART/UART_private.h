/**********************************************************/
/* Author  : Anwar Ahmad                                  */
/* Version : 01                                           */
/* Date    : 9/20/2020                                     */
/**********************************************************/
#ifndef UART_PRIVATE_H
#define UART_PRIVATE_H

/*  Register Definitions    */
typedef struct {
	volatile u32 SR;
	volatile u32 DR;
	volatile u32 BRR;
	volatile u32 CR1;
	volatile u32 CR2;
	volatile u32 CR3;
	volatile u32 GTPR;
}UART_t;
#define UART_Ptr ((UART_t *)0x40013800)

#endif