/**********************************************************/
/* Author  : Anwar Ahmad                                  */
/* Version : 01                                           */
/* Date    : 8/22/2020                                    */
/**********************************************************/
#ifndef NVIC_PRIVATE_H
#define NVIC_PRIVATE_H

/* Register Definitions */
#define NVIC_ISER0      *((u32*)0xE000E100)
#define NVIC_ISER1      *((u32*)0xE000E104)
#define NVIC_ICER0      *((u32*)0xE000E180)
#define NVIC_ICER1      *((u32*)0xE000E184)
#define NVIC_ISPR0      *((u32*)0xE000E200)
#define NVIC_ISPR1      *((u32*)0xE000E204)
#define NVIC_ICPR0      *((u32*)0xE000E280)
#define NVIC_ICPR1      *((u32*)0xE000E284)
#define NVIC_IABR0      *((volatile u32*)0xE000E300)
#define NVIC_IABR1      *((volatile u32*)0xE000E304)
#define NVIC_IPR        ((u8*)0xE000E400) //Pointer to register becuase it byte accessable

#define SCB_AIRCR       *((u32*)0xE000ED0C) 

#endif