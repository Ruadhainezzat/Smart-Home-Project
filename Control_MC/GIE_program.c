#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "GIE_interface.h"
#include "GIE_register.h"

void GIE_voidEnableGlobal(void)
{
	/*1- By C language*/
	SET_BIT(SREG,SREG_I);			
	
	/*2- By assembly*/
	/*  __asm volatile("SEI");  */
}

void GIE_voidDisableGlobal(void)
{
	/*1- By C language*/
	CLR_BIT(SREG,SREG_I);
	
	/*2- By assembly*/
	/*  __asm volatile("CLI");  */
}
