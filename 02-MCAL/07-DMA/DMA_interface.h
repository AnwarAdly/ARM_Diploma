/**********************************************************/
/* Author  : Anwar Ahmad                                  */
/* Version : 01                                           */
/* Date    : 9/14/2020                                     */
/**********************************************************/
#ifndef DMA_INTERFACE_H
#define DMA_INTERFACE_H

/* Function Prototypes  */
void DMA_voidInit(void);
void DMA_voidStartChannel(u32 * Copy_u32SourceAddress , u32 * Copy_u32DestinationAddress , u16 Copy_u16BlockLength );

#endif