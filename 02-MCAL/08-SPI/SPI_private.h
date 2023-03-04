/**********************************************************/
/* Author  : Anwar Ahmad                                  */
/* Version : 01                                           */
/* Date    : 9/16/2020                                     */
/**********************************************************/
#ifndef SPI_PRIVATE_H
#define SPI_PRIVATE_H

/*  Register Definitions    */
typedef struct {
	volatile u32 CR1;
	volatile u32 CR2;
	volatile u32 SR;
	volatile u32 DR;
	volatile u32 CRCPR;
	volatile u32 RXCRCR;
	volatile u32 TXCRCR;
	volatile u32 I2SCFGR;
	volatile u32 I2SPR;
}SPI_t;
#define SPI_Ptr ((SPI_t *)0x40013000)

#endif