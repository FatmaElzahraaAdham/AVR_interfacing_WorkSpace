

#ifndef TIMERS_H_
#define TIMERS_H_

void (*Timer0_PFun)(void);

void Timers_VidTimer0Init(void);

void Timers_VidTimer0SetCallBack( void (*Timer0_Ptr)(void) );


#endif
