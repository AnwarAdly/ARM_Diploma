/**********************************************************/
/* Author  : Anwar Ahmad                                  */
/* Version : 01                                           */
/* Date    : 9/14/2020                                     */
/**********************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "STK_interface.h"
#include "GPIO_interface.h"
#include "S2P_interface.h"
#include "S2P_private.h"
#include "S2P_config.h"

void S2P_voidSendSynch(u8 Copy_u8DataToSend){ // Function to send data bit by bit by MSb
	s8 Local_s8Counter; // Signed variable becuase if it unsigned when it will be 0 , the variable will be 255 (Infinite loop)
	u8 Local_u8Bit;
	for (Local_s8Counter=7;Local_s8Counter>=0;Local_s8Counter--){
		Local_u8Bit=GET_BIT(Copy_u8DataToSend,Local_s8Counter);
		GPIO_voidSetPinValue(S2P_SERIAL_DATA,Local_u8Bit);
		/* Send pulse to shift register  */
		GPIO_voidSetPinValue(S2P_SHIFT_CLOCK,HIGH);
		STK_voidSetBusyWait(1);
		GPIO_voidSetPinValue(S2P_SHIFT_CLOCK,LOW);
		STK_voidSetBusyWait(1);
		
	}
	/* Send pulse to storage register  */
	GPIO_voidSetPinValue(S2P_STORAGE_CLOCK,HIGH);
	STK_voidSetBusyWait(1);
	GPIO_voidSetPinValue(S2P_STORAGE_CLOCK,LOW);
	STK_voidSetBusyWait(1);	
}
