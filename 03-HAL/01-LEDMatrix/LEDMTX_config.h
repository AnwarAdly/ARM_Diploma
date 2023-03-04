/**********************************************************/
/* Author  : Anwar Ahmad                                  */
/* Version : 01                                           */
/* Date    : 8/31/2020                                    */
/**********************************************************/
#ifndef LEDMTX_CONFIG_H
#define LEDMTX_CONFIG_H

/* Please write pin pair  PORT ,PIN */
#define LEDMTX_ROW0_PIN   GPIOA,PIN0
#define LEDMTX_ROW1_PIN   GPIOA,PIN1
#define LEDMTX_ROW2_PIN   GPIOA,PIN2
#define LEDMTX_ROW3_PIN   GPIOA,PIN3
#define LEDMTX_ROW4_PIN   GPIOA,PIN4
#define LEDMTX_ROW5_PIN   GPIOA,PIN5
#define LEDMTX_ROW6_PIN   GPIOA,PIN6
#define LEDMTX_ROW7_PIN   GPIOA,PIN7

/* Please write pin pair  PORT ,PIN */
#define LEDMTX_COL0_PIN   GPIOB,PIN0
#define LEDMTX_COL1_PIN   GPIOB,PIN1 // PIN2 not found , PIN3 & PIN4 are for JTAG 
#define LEDMTX_COL2_PIN   GPIOB,PIN5
#define LEDMTX_COL3_PIN   GPIOB,PIN6
#define LEDMTX_COL4_PIN   GPIOB,PIN7
#define LEDMTX_COL5_PIN   GPIOB,PIN8
#define LEDMTX_COL6_PIN   GPIOB,PIN9
#define LEDMTX_COL7_PIN   GPIOB,PIN10

#endif