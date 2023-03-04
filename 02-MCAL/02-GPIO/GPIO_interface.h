/**********************************************************/
/* Author  : Anwar Ahmad                                  */
/* Version : 01                                           */
/* Date    : 8/15/2020                                    */
/**********************************************************/
#ifndef GPIO_INTERFACE_H
#define GPIO_INTERFACE_H

/*     Modes            */
#define LOW         0
#define HIGH        1

/*     GPIO Ports       */
#define GPIOA       0
#define GPIOB       1
#define GPIOC       2

/*     GPIO Pins        */
#define PIN0        0
#define PIN1        1
#define PIN2        2
#define PIN3        3
#define PIN4        4
#define PIN5        5
#define PIN6        6
#define PIN7        7
#define PIN8        8
#define PIN9        9
#define PIN10       10
#define PIN11       11
#define PIN12       12
#define PIN13       13
#define PIN14       14
#define PIN15       15

/*     GPIO Modes       */
#define INPUT_ADC                     0b0000
#define INPUT_FLOATING                0b0100
#define INPUT_PULLUP_PULLDOWN         0b1000

#define OUTPUT_SPEED_10MHZ_PUSHPULL   0b0001
#define OUTPUT_SPEED_10MHZ_OPENDRAIN  0b0101
#define OUTPUT_SPEED_10MHZ_AF_PP      0b1001
#define OUTPUT_SPEED_10MHZ_AF_OD      0b1101

#define OUTPUT_SPEED_2MHZ_PUSHPULL    0b0010
#define OUTPUT_SPEED_2MHZ_OPENDRAIN   0b0110
#define OUTPUT_SPEED_2MHZ_AF_PP       0b1010
#define OUTPUT_SPEED_2MHZ_AF_OD       0b1110

#define OUTPUT_SPEED_50MHZ_PUSHPULL   0b0011
#define OUTPUT_SPEED_50MHZ_OPENDRAIN  0b0111
#define OUTPUT_SPEED_50MHZ_AF_PP      0b1011
#define OUTPUT_SPEED_50MHZ_AF_OD      0b1111

/* Functions Prototypes */
void GPIO_voidSetPinDirection(u8 Copy_u8PORT , u8 Copy_u8PIN ,  u8 Copy_u8Mode);
void GPIO_voidSetPinValue(u8 Copy_u8PORT , u8 Copy_u8PIN ,  u8 Copy_u8Value);
u8 GPIO_u8GetPinValue(u8 Copy_u8PORT , u8 Copy_u8PIN );



#endif