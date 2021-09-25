#ifndef TIMER_INTERFACE_H_
#define TIMER_INTERFACE_H_

void Timer0_voidInit(void);

u8 Timer0_u8ovSetCallback(void (*Copy_pvCallBackFunc)(void));

void Timer0_voidSetPreloadValue(u8 Copy_u8PreloadValue);

void Timer1_voidInit(void);
void Timer1_voidSetCompareValue(u16 Copy_u8CompareValue);
void Timer1_voidInitNormalMode(void);

#endif
