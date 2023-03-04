/**********************************************************/
/* Author  : Anwar Ahmad                                  */
/* Version : 01                                           */
/* Date    : 9/21/2020                                     */
/**********************************************************/
#ifndef TFT_INTERFACE_H
#define TFT_INTERFACE_H

/* Function Prototypes  */
void TFT_voidInit(void);
void TFT_voidDisplayImage(const u16* Copy_u16Image );
void TFT_voidFillColor(u16 Copy_u16Color);
void TFT_voidDrawRectangle(u8 x1 , u8 x2 , u8 y1 , u8 y2 , u16 Copy_u16Color);

#endif