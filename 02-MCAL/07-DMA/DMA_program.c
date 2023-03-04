/**********************************************************/
/* Author  : Anwar Ahmad                                  */
/* Version : 01                                           */
/* Date    : 9/14/2020                                     */
/**********************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DMA_interface.h"
#include "DMA_private.h"
#include "DMA_config.h"

void DMA_voidInit(void){
	/* Example : Mem to Mem 
				 Very High 
				 Source & destination = 4 Bytes
				 MINC & PINC Enabled 
				 No Circular 
				 Transfer Interrupt Enabled			*/
	#if CHANNEL_ID == 1
	DMA_Ptr -> CCR[0];
	#endif
}
void DMA_voidStartChannel(u32 * Copy_u32SourceAddress , u32 * Copy_u32DestinationAddress , u16 Copy_u16BlockLength ){
	CLR_BIT(DMA_Ptr -> CCR[0],0); 					// Make sure that channel is disabled
	DMA_Ptr -> CPAR[0]  = Copy_u32SourceAddress; 		// Write source address
	DMA_Ptr -> CMAR[0]  = Copy_u32DestinationAddress; 	// Write destination address
	DMA_Ptr -> CNDTR[0] = Copy_u16BlockLength; 		    // Write Block Length
	SET_BIT(DMA_Ptr -> CCR[0],0); 					// Make sure that channel is enabled
}