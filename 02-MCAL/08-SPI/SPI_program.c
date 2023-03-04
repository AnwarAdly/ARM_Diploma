/**********************************************************/
/* Author  : Anwar Ahmad                                  */
/* Version : 01                                           */
/* Date    : 9/16/2020                                     */
/**********************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "STK_interface.h"
#include "GPIO_interface.h"
#include "SPI_interface.h"
#include "SPI_private.h"
#include "SPI_config.h"

void SPI_voidInit(void){
	SPI_Ptr -> CR1 = 0x0347; // CPOL=1 , CPHA=1 , Prescaler = CLK/2 , SPI enable , MSB first
}
void SPI_voidSendReceiveSynch(u8 Copy_u8DataToTransmit , u8 *Copy_u8DataToReceive){
	GPIO_voidSetPinValue(SPI_SLAVE_PIN,LOW); // Clear for slave select pin 
	SPI_Ptr -> DR = Copy_u8DataToTransmit;   // Send data
	while(GET_BIT(SPI_Ptr -> SR,PIN7)== 1);  // Wait busy flag to finish
	*Copy_u8DataToReceive = SPI_Ptr -> DR;   // Return to the received data
	GPIO_voidSetPinValue(SPI_SLAVE_PIN,HIGH);// Set for slave select pin 
}
void SPI_voidSendReceiveAsynch(u8 Copy_u8DataToTransmit , void (*CallBack)(u8 Copy_u8DataToReceive));
void SPI1_IRQHandler(void){
	CallBack(SPI_Ptr -> DR);
}