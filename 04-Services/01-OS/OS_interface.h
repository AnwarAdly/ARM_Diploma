/**********************************************************/
/* Author  : Anwar Ahmad                                  */
/* Version : 01                                           */
/* Date    : 9/5/2020                                     */
/**********************************************************/
#ifndef OS_INTERFACE_H
#define OS_INTERFACE_H

/* Function Prototypes  */
void OS_voidCreateTask(u8 Copy_u8ID ,u16 Copy_u16Periodicity ,void(*Copy_voidPtr)(void) , u16 Copy_u16firstDelay);
void OS_voidStartTask(void);
void OS_voidSuspendTask(u8 Copy_u8ID);
void OS_voidResumeTask(u8 Copy_u8ID);
void OS_voidDeleteTask(u8 Copy_u8ID);

#endif