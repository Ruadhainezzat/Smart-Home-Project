#ifndef EXTI_CONFIG_H_
#define EXTI_CONFIG_H_


/* set the required sense control for EXTI INT0 Pin
Options:  1- EXTI_u8_RISING_EDGE	
          2- EXTI_u8_FALLING_EDGE
          3- EXTI_u8_ON_CHANGE	
          4- EXTI_u8_LOW_LEVEL	
*/
#define EXTI_u8_INT0_SENSE				EXTI_u8_RISING_EDGE

/* set the required Initial state for EXTI INT0 Pin
Options: 1- ENABLED
		 2- DISABLED
*/
#define EXTI_u8_INT0_INITIAL_STATE		ENABLED

/*
=======================================================================================
 set the required sense control for EXTI INT1 Pin
Options:  1- EXTI_u8_RISING_EDGE	
          2- EXTI_u8_FALLING_EDGE
          3- EXTI_u8_ON_CHANGE	
          4- EXTI_u8_LOW_LEVEL	
*/
#define EXTI_u8_INT1_SENSE				EXTI_u8_FALLING_EDGE

/* set the required Initial state for EXTI INT1 Pin
Options: 1- ENABLED
		 2- DISABLED
*/
#define EXTI_u8_INT1_INITIAL_STATE		ENABLED

/*
========================================================================================

 set the required sense control for EXTI INT2 Pin
Options:  1- EXTI_u8_RISING_EDGE	
          2- EXTI_u8_FALLING_EDGE
*/
#define EXTI_u8_INT2_SENSE				EXTI_u8_FALLING_EDGE

/* set the required Initial state for EXTI INT2 Pin
Options: 1- ENABLED
		 2- DISABLED
*/
#define EXTI_u8_INT2_INITIAL_STATE		ENABLED

#endif
