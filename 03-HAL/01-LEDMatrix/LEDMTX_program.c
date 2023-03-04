/**********************************************************/
/* Author  : Anwar Ahmad                                  */
/* Version : 01                                           */
/* Date    : 8/31/2020                                    */
/**********************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "GPIO_interface.h"
#include "STK_interface.h"
#include "LEDMTX_interface.h"
#include "LEDMTX_private.h"
#include "LEDMTX_config.h"


void LEDMTX_voidInit(void){
	GPIO_voidSetPinDirection(LEDMTX_ROW0_PIN,OUTPUT_SPEED_2MHZ_PUSHPULL);
	GPIO_voidSetPinDirection(LEDMTX_ROW1_PIN,OUTPUT_SPEED_2MHZ_PUSHPULL);
	GPIO_voidSetPinDirection(LEDMTX_ROW2_PIN,OUTPUT_SPEED_2MHZ_PUSHPULL);
	GPIO_voidSetPinDirection(LEDMTX_ROW3_PIN,OUTPUT_SPEED_2MHZ_PUSHPULL);
	GPIO_voidSetPinDirection(LEDMTX_ROW4_PIN,OUTPUT_SPEED_2MHZ_PUSHPULL);
	GPIO_voidSetPinDirection(LEDMTX_ROW5_PIN,OUTPUT_SPEED_2MHZ_PUSHPULL);
	GPIO_voidSetPinDirection(LEDMTX_ROW6_PIN,OUTPUT_SPEED_2MHZ_PUSHPULL);
	GPIO_voidSetPinDirection(LEDMTX_ROW7_PIN,OUTPUT_SPEED_2MHZ_PUSHPULL);
	
	GPIO_voidSetPinDirection(LEDMTX_COL0_PIN,OUTPUT_SPEED_2MHZ_PUSHPULL);
	GPIO_voidSetPinDirection(LEDMTX_COL1_PIN,OUTPUT_SPEED_2MHZ_PUSHPULL);
	GPIO_voidSetPinDirection(LEDMTX_COL2_PIN,OUTPUT_SPEED_2MHZ_PUSHPULL);
	GPIO_voidSetPinDirection(LEDMTX_COL3_PIN,OUTPUT_SPEED_2MHZ_PUSHPULL);
	GPIO_voidSetPinDirection(LEDMTX_COL4_PIN,OUTPUT_SPEED_2MHZ_PUSHPULL);
	GPIO_voidSetPinDirection(LEDMTX_COL5_PIN,OUTPUT_SPEED_2MHZ_PUSHPULL);
	GPIO_voidSetPinDirection(LEDMTX_COL6_PIN,OUTPUT_SPEED_2MHZ_PUSHPULL);
	GPIO_voidSetPinDirection(LEDMTX_COL7_PIN,OUTPUT_SPEED_2MHZ_PUSHPULL);
}
void LEDMTX_voidDisplay(u8 *Copy_u8Data){ // Array thet have values of rows when each column is enable
	while(1){
		/* Column 0 */
		LEDMTX_voidDisableAllColumns(); 		   // Disable all columns
		LEDMTX_voidSetRowsValues(Copy_u8Data[0]);  // Get value of 8 rows for first column
		GPIO_voidSetPinValue(LEDMTX_COL0_PIN,LOW); // Enable Column 0 
		STK_voidSetBusyWait(2500); 				   // Delay 2.5 msec
		/* Column 1 */
		LEDMTX_voidDisableAllColumns(); 
		LEDMTX_voidSetRowsValues(Copy_u8Data[1]); 
		GPIO_voidSetPinValue(LEDMTX_COL1_PIN,LOW); 
		STK_voidSetBusyWait(2500); 
		/* Column 2 */
		LEDMTX_voidDisableAllColumns(); 
		LEDMTX_voidSetRowsValues(Copy_u8Data[2]); 
		GPIO_voidSetPinValue(LEDMTX_COL2_PIN,LOW);  
		STK_voidSetBusyWait(2500); 
		/* Column 3 */
		LEDMTX_voidDisableAllColumns(); 
		LEDMTX_voidSetRowsValues(Copy_u8Data[3]); 
		GPIO_voidSetPinValue(LEDMTX_COL3_PIN,LOW); 
		STK_voidSetBusyWait(2500); 
		/* Column 4 */
		LEDMTX_voidDisableAllColumns(); 
		LEDMTX_voidSetRowsValues(Copy_u8Data[4]); 
		GPIO_voidSetPinValue(LEDMTX_COL4_PIN,LOW);  
		STK_voidSetBusyWait(2500); 
		/* Column 5 */
		LEDMTX_voidDisableAllColumns();
		LEDMTX_voidSetRowsValues(Copy_u8Data[5]); 
		GPIO_voidSetPinValue(LEDMTX_COL5_PIN,LOW); 
		STK_voidSetBusyWait(2500); 
		/* Column 6 */
		LEDMTX_voidDisableAllColumns(); 
		LEDMTX_voidSetRowsValues(Copy_u8Data[6]); 
		GPIO_voidSetPinValue(LEDMTX_COL6_PIN,LOW);  
		STK_voidSetBusyWait(2500); 
		/* Column 7 */
		LEDMTX_voidDisableAllColumns(); 
		LEDMTX_voidSetRowsValues(Copy_u8Data[7]); 
		GPIO_voidSetPinValue(LEDMTX_COL7_PIN,LOW);  
		STK_voidSetBusyWait(2500); 
	}
}
/* Private functions(becuase it internal used in C , not used by user ) must be static(becuase it never call out C file ) and it's prototype in private  */
static void LEDMTX_voidDisableAllColumns(void){
	GPIO_voidSetPinValue(LEDMTX_COL0_PIN,HIGH);
	GPIO_voidSetPinValue(LEDMTX_COL1_PIN,HIGH);
	GPIO_voidSetPinValue(LEDMTX_COL2_PIN,HIGH);
	GPIO_voidSetPinValue(LEDMTX_COL3_PIN,HIGH);
	GPIO_voidSetPinValue(LEDMTX_COL4_PIN,HIGH);
	GPIO_voidSetPinValue(LEDMTX_COL5_PIN,HIGH);
	GPIO_voidSetPinValue(LEDMTX_COL6_PIN,HIGH);
	GPIO_voidSetPinValue(LEDMTX_COL7_PIN,HIGH);
}
static void LEDMTX_voidSetRowsValues(u8 Copy_u8Value){
	u8 Local_u8Bit=0;
	Local_u8Bit = GET_BIT(Copy_u8Value,0);
	GPIO_voidSetPinValue(LEDMTX_ROW0_PIN,Local_u8Bit);
	Local_u8Bit = GET_BIT(Copy_u8Value,1);
	GPIO_voidSetPinValue(LEDMTX_ROW1_PIN,Local_u8Bit);
	Local_u8Bit = GET_BIT(Copy_u8Value,2);
	GPIO_voidSetPinValue(LEDMTX_ROW2_PIN,Local_u8Bit);
	Local_u8Bit = GET_BIT(Copy_u8Value,3);
	GPIO_voidSetPinValue(LEDMTX_ROW3_PIN,Local_u8Bit);
	Local_u8Bit = GET_BIT(Copy_u8Value,4);
	GPIO_voidSetPinValue(LEDMTX_ROW4_PIN,Local_u8Bit);
	Local_u8Bit = GET_BIT(Copy_u8Value,5);
	GPIO_voidSetPinValue(LEDMTX_ROW5_PIN,Local_u8Bit);
	Local_u8Bit = GET_BIT(Copy_u8Value,6);
	GPIO_voidSetPinValue(LEDMTX_ROW6_PIN,Local_u8Bit);
	Local_u8Bit = GET_BIT(Copy_u8Value,7);
	GPIO_voidSetPinValue(LEDMTX_ROW7_PIN,Local_u8Bit);
}