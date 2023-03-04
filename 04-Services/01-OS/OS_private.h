/**********************************************************/
/* Author  : Anwar Ahmad                                  */
/* Version : 01                                           */
/* Date    : 9/5/2020                                     */
/**********************************************************/
#ifndef OS_PRIVATE_H
#define OS_PRIVATE_H

#define NULL 			(void*)0
#define	TASK_SUSPENDED		   1
#define	TASK_READY			   2

typedef struct {
	u16 periodicity;
	void (*TaskHandler)(void);
	u16 firstDelay;
	u8 state;
}Task;

 /* Array of tasks(structure) */
static Task OS_Tasks [NUMBER_OF_TASKS]={NULL};

/* Global function prototypes */
static void Scheduler(void);

#endif