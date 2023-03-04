/**********************************************************/
/* Author  : Anwar Ahmad                                  */
/* Version : 01                                           */
/* Date    : 9/5/2020                                     */
/**********************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "STK_interface.h"
#include "OS_interface.h"
#include "OS_private.h"
#include "OS_config.h"

void OS_voidCreateTask(u8 Copy_u8ID ,u16 Copy_u16Periodicity ,void(*Copy_voidPtr)(void) ,u16 Copy_u16firstDelay ){
	OS_Tasks[Copy_u8ID].periodicity = Copy_u16Periodicity;
	OS_Tasks[Copy_u8ID].TaskHandler = Copy_voidPtr;
	OS_Tasks[Copy_u8ID].firstDelay = Copy_u16firstDelay;
	OS_Tasks[Copy_u8ID].state = TASK_READY;
}
void OS_voidStartTask(void){
	/*  Initialization  */
	STK_voidInit();
	/*  Tick 1 msec     */
	STK_voidSetIntervalPeriodic(1000,Scheduler);
}
void OS_voidSuspendTask(u8 Copy_u8ID){
	OS_Tasks[Copy_u8ID].state = TASK_SUSPENDED;
}
void OS_voidResumeTask(u8 Copy_u8ID){
	OS_Tasks[Copy_u8ID].state = TASK_READY;	
}
void OS_voidDeleteTask(u8 Copy_u8ID){
	OS_Tasks[Copy_u8ID].TaskHandler = NULL;

}
static void Scheduler(void){
	//static u16 Local_u16TickCounter=0;
	u8 Local_u8TaskCounter;
	/*Increment of Scheduler tick counter*/

		/*Loop on the tasks*/
		for(Local_u8TaskCounter=0;Local_u8TaskCounter<NUMBER_OF_TASKS;Local_u8TaskCounter++)
		{
			/*chack that task isn't deleted or suspended */
			if((OS_Tasks[Local_u8TaskCounter].TaskHandler != NULL) && (OS_Tasks[Local_u8TaskCounter].state == TASK_READY) )
			{
				/*Check until the first delay equal to zero*/
				if(OS_Tasks[Local_u8TaskCounter].firstDelay == 0)
				{
					OS_Tasks[Local_u8TaskCounter].firstDelay=OS_Tasks[Local_u8TaskCounter].periodicity-1;
					/*Invoke the task function*/
					OS_Tasks[Local_u8TaskCounter].TaskHandler();
				}
				else
				{
					/*Decrement the first delay*/
					OS_Tasks[Local_u8TaskCounter].firstDelay--;
				}
			}
			else
			{
				/*Do nothing*/
			}
		}

}