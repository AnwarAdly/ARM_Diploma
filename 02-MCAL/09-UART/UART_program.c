/**********************************************************/
/* Author  : Anwar Ahmad                                  */
/* Version : 01                                           */
/* Date    : 9/20/2020                                     */
/**********************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "GPIO_interface.h"
#include "UART_interface.h"
#include "UART_private.h"
#include "UART_config.h"

void UART_voidInit(void){
	// BaudRate = 9600 ->  BRR= 0x0000 0341
	UART_Ptr -> BRR = 0x00000341;
	// Enable RX & TX & UART Bits
	SET_BIT(UART_Ptr -> CR1 , PIN2);
	SET_BIT(UART_Ptr -> CR1 , PIN3);
	SET_BIT(UART_Ptr -> CR1 , PIN13);
	// Clear status register
	UART_Ptr -> SR =0 ;
}
void UART_voidTransmit(u8 arr[]){
	u8 i=0;
	while (arr[i]!='\0'){
		UART_Ptr -> DR = arr[i];
		while((GET_BIT(UART_Ptr -> SR , PIN6))==0); // Wait till transmission is finished
		i++;
	}
}
u8   UART_u8Receive(void){
	u16 TimeOut=0;
	while((GET_BIT(UART_Ptr -> SR , PIN5))==0){ // Wait till receiving is finished
		TimeOut++;
		if(TimeOut == 10000){
			return 255;
			break;
		}
	}
	return (0xFF & (UART_Ptr -> DR)); // Anding with 0xFF to assure it return u8 not u32 (Masking)
}
