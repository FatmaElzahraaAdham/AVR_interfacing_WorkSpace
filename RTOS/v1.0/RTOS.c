#include "Timers.h"
#include"STD_Lib.h"
#include "RTOS.h"

typedef struct {
	u8 TaskPriority;
	u16 TaskPeriodicity;
	void (*P_TaskAction)(void);
}Task_t;
Task_t SysTasks[4]={{0}};




void RTOS_StartOS(void (*Timer0_Ptr)(void)){
	Timers_VidTimer0SetCallBack(Timer0_Ptr);
	Timers_VidTimer0Init();
}

void RTOS_CreateTask(void (*Timer0_Ptr)(void), u16 A_Periodicity,u8 A_priority){
	SysTasks[A_Periodicity].TaskPeriodicity=A_Periodicity;
	SysTasks[A_Periodicity].P_TaskAction=Timer0_Ptr;
}
void Scheduler(void){
	static u16 counter=0;
	counter++;
	for(u8 i=0;i<4;i++){
		if(counter % SysTasks[i].TaskPeriodicity==0){
			SysTasks[i].P_TaskAction();
		}
	}
	if(counter==6300){
		counter=0;
	}
}

