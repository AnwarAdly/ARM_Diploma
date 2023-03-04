/**********************************************************/
/* Author  : Anwar Ahmad                                  */
/* Version : 01                                           */
/* Date    : 8/24/2020                                    */
/**********************************************************/
#ifndef EXTI_PRIVATE_H
#define EXTI_PRIVATE_H

/* Register Definitions           */
typedef struct{
	u32 IMR;
	u32 EMR;
	u32 RTSR;
	u32 FTSR;
	u32 SWIER;
	u32 PR;
}EXTI_t;
#define EXTI_Ptr  ((volatile EXTI_t*) 0x40010400) //Pointer to struct

/* External Interrupts Lines      */
#define LINE0		 0
#define LINE1		 1
#define LINE2		 2
#define LINE3		 3
#define LINE4		 4
#define LINE5		 5
#define LINE6		 6
#define LINE7		 7
#define LINE8		 8
#define LINE9		 9
#define LINE10 		 10
#define LINE11		 11
#define LINE12		 12
#define LINE13		 13
#define LINE14		 14
#define LINE15		 15

/* External Interrupts Modes       */
#define RISING		 0
#define FALLING		 1
#define ON_CHANGE	 2

/* Define CallBack Global Variable */
static void (*EXTI_CallBack)(void); 

/* Define Global Variable          */
volatile u8 Copy_u8Line=0;

#endif