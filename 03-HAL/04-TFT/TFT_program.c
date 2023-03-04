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
#include "TFT_interface.h"
#include "TFT_private.h"
#include "TFT_config.h"

void TFT_voidInit(void){
	ResetPulse();
	WriteCommand(0x11); // Sleep Out Command
	STK_voidSetBusyWait(150000);
	WriteCommand(0x3A); // Color Mode Command
	WriteData(0x05);    // Use RGB565
	WriteCommand(0x29); // Display ON Command
}
void TFT_voidDisplayImage(const u16* Copy_u16Image ){
	/* Set X Address  */
	WriteCommand(0x2A); // X Address Command
	WriteData(0); // Start X
	WriteData(0);  
	WriteData(0); // End X
	WriteData(127); 
	/* Set Y Address  */
	WriteCommand(0x2B); // Y Address Command
	WriteData(0); // Start X
	WriteData(0);  
	WriteData(0); // End X
	WriteData(159); 
	/* To Draw in TFT */
	WriteCommand(0x2C); // RAM Write Command
	u16 counter;
	for (counter=0;counter<20480;counter++){
		WriteData(Copy_u16Image[counter] >> 8);     // Write the High Byte 
		WriteData(Copy_u16Image[counter] & 0x00FF); // Write the Low Byte	
	}
}
void TFT_voidFillColor(u16 Copy_u16Color ){
	/* Set X Address  */
	WriteCommand(0x2A); // X Address Command
	WriteData(0); // Start X
	WriteData(0);  
	WriteData(0); // End X
	WriteData(127); 
	/* Set Y Address  */
	WriteCommand(0x2B); // Y Address Command
	WriteData(0); // Start X
	WriteData(0);  
	WriteData(0); // End X
	WriteData(159); 
	/* To Draw in TFT */
	WriteCommand(0x2C); // RAM Write Command
	u16 counter;
	for (counter=0;counter<20480;counter++){
		WriteData(Copy_u16Color >> 8);     // Write the High Byte 
		WriteData(Copy_u16Color & 0x00FF); // Write the Low Byte
	}
}
void TFT_voidDrawRectangle(u8 x1 , u8 x2 , u8 y1 , u8 y2 , u16 Copy_u16Color){
	u16 size = (x2 - x1)*(y2 - y1);
	/* Set X Address  */
	WriteCommand(0x2A); // X Address Command
	WriteData(0); // Start X High Byte
	WriteData(x1);  // Low Byte
	WriteData(0); // End X
	WriteData(x2); // Low Byte
	/* Set Y Address  */
	WriteCommand(0x2B); // Y Address Command
	WriteData(0); // Start X
	WriteData(y1);  
	WriteData(0); // End X
	WriteData(y2); 
	/* To Draw in TFT */
	WriteCommand(0x2C); // RAM Write Command
	u16 counter;
	for (counter=0;counter<size;counter++){
		WriteData(Copy_u16Color >> 8);     // Write the High Byte 
		WriteData(Copy_u16Color & 0x00FF); // Write the Low Byte
	}
}

static void WriteCommand(u8 Command){ // For commands
	u8 TempVar;
	// Set A0 pin low
	GPIO_voidSetPinValue(TFT_A0_PIN,LOW);
	SPI_voidSendReceiveSynch(Command,&TempVar);
}
static void WriteData(u8 Data){ // For Parameters of commands
	u8 TempVar;
	// Set A0 pin High
	GPIO_voidSetPinValue(TFT_A0_PIN,HIGH);	
	SPI_voidSendReceiveSynch(Data,&TempVar);
}
static void ResetPulse(void){
	GPIO_voidSetPinValue(TFT_RST_PIN,HIGH);
	STK_voidSetBusyWait(100);
	GPIO_voidSetPinValue(TFT_RST_PIN,LOW);
	STK_voidSetBusyWait(1);
	GPIO_voidSetPinValue(TFT_RST_PIN,HIGH);
	STK_voidSetBusyWait(100);
	GPIO_voidSetPinValue(TFT_RST_PIN,LOW);
	STK_voidSetBusyWait(100);
	GPIO_voidSetPinValue(TFT_RST_PIN,HIGH);
	STK_voidSetBusyWait(120000);
}