#ifndef EXTI_INTERFACE_H_
#define EXTI_INTERFACE_H_

#define EXTI_u8_INT0			0
#define EXTI_u8_INT1			1
#define EXTI_u8_INT2			2

#define EXTI_u8_RISING_EDGE		1
#define EXTI_u8_FALLING_EDGE	2
#define EXTI_u8_ON_CHANGE		3
#define EXTI_u8_LOW_LEVEL		4

void EXTI_voidINT0Init(void);
void EXTI_voidINT1Init(void);
void EXTI_voidINT2Init(void);

u8 EXTI_u8SetSenseControl(u8 Copy_u8IntNum, u8 Copy_u8Sense);

u8 EXTI_u8EnableInt(u8 Copy_u8IntNum);
u8 EXTI_u8DisableInt(u8 Copy_u8IntNum);

u8 EXTI_u8SetCallBack(void (*Copy_pvCallBack)(void),u8 Copy_u8IntNum);


#endif
