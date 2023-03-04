/**********************************************************/
/* Author  : Anwar Ahmad                                  */
/* Version : 01                                           */
/* Date    : 9/20/2020                                     */
/**********************************************************/
#ifndef UART_INTERFACE_H
#define UART_INTERFACE_H

/* Function Prototypes  */
void UART_voidInit(void);
void UART_voidTransmit(u8 arr[]);
u8   UART_u8Receive(void);

#endif