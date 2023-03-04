/**********************************************************/
/* Author  : Anwar Ahmad                                  */
/* Version : 01                                           */
/* Date    : 9/14/2020                                     */
/**********************************************************/
#ifndef DMA_PRIVATE_H
#define DMA_PRIVATE_H

/*  Register Definitions  */
typedef struct {
	volatile u32 ISR;
	volatile u32 IFCR;
	volatile u32 CCR[7];
	volatile u32 CNDTR[7];
	volatile u32 CPAR[7];
	volatile u32 CMAR[7];
	volatile u32 Reserved[7];
}DMA_t;
#define DMA_Ptr ((DMA_t *)0x40020000)

#endif