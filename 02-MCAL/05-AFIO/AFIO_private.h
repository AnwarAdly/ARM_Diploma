/**********************************************************/
/* Author  : Anwar Ahmad                                  */
/* Version : 01                                           */
/* Date    : 8/24/2020                                    */
/**********************************************************/
#ifndef AFIO_PRIVATE_H
#define AFIO_PRIVATE_H

/* Register Definitions */
typedef struct {
	u32 EVCR;
	u32 MAPR;
	u32 EXTICR[4];
	u32 MAPR2;
}AFIO_t;
#define AFIO_Ptr ((volatile AFIO_t*) 0x40010000)

#endif