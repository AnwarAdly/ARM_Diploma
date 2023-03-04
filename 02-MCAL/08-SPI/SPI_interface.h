/**********************************************************/
/* Author  : Anwar Ahmad                                  */
/* Version : 01                                           */
/* Date    : 9/16/2020                                     */
/**********************************************************/
#ifndef SPI_INTERFACE_H
#define SPI_INTERFACE_H

/* Function Prototypes  */
void SPI_voidInit(void);
void SPI_voidSendReceiveSynch(u8 Copy_u8DataToTransmit , u8 *Copy_u8DataToReceive);
void SPI_voidSendReceiveAsynch(u8 Copy_u8DataToTransmit , void (*CallBack)(u8 Copy_u8DataToReceive));

#endif