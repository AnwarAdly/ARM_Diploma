/**********************************************************/
/* Author  : Anwar Ahmad                                  */
/* Version : 01                                           */
/* Date    : 9/16/2020                                     */
/**********************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "STK_interface.h"
#include "GPIO_interface.h"
#include "ESP_interface.h"
#include "ESP_private.h"
#include "ESP_config.h"

void ESP_voidInit(void){
	u8 Local_u8Result=0;
	while(Local_u8Result==0){
		UART_voidTransmit("ATE0\r\n");
		Local_u8Result=ESPValidateCmd();
	}
	Local_u8Result=0;
	while(Local_u8Result==0){
		UART_voidTransmit("AT+CWMODE=1\r\n");
		Local_u8Result=ESPValidateCmd();
	}

}
u8 ESPValidateCmd(void){
	u8 Response[100]={0};
	u8 i=0;
	u8 Result=0;
	while(Response[i-1]!=255){
		Response[i]=UART_u8Receive();
		i++;
	}
	if (Response[0]=='O' && Response[1]=='K'){
		Result=1;
	}
	return Result;
}