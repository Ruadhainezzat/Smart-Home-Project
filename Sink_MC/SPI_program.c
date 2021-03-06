#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "SPI_register.h"
#include "SPI_config.h"
#include "SPI_private.h"
#include "SPI_interface.h"
#include "DIO_interface.h"

void SPI_voidInitialize(u8 Copy_u8Role)
{
#if SPI_u8_DATA_ORDER == SPI_u8_MSB_FIRST
	CLR_BIT(SPCR,SPCR_DORD);
#elif SPI_u8_DATA_ORDER == SPI_u8_LSB_FIRST
	SETBIT(SPCR,SPCR_DORD);
#endif

if (Copy_u8Role == SPI_u8_MASTER)
{
	SET_BIT(SPCR,SPCR_MSTR);

}
else if( Copy_u8Role == SPI_u8_SLAVE)
{
	CLR_BIT(SPCR,SPCR_MSTR);

}

#if SPI_u8_CLOCK_POLARITY == SPI_u8_LEADING_RISING
	CLR_BIT(SPCR,SPCR_CPOL);
#elif SPI_u8_CLOCK_POLARITY == SPI_u8_LEADING_FALLING
	SET_BIT(SPCR,SPCR_CPOL);
#endif

#if SPI_u8_CLOCK_PHASE == SPI_u8_LEADING_SAMPLE
	CLR_BIT(SPCR,SPCR_CPHA);
#elif SPI_u8_CLOCK_PHASE == SPI_u8_LEADING_SETUP
	SET_BIT(SPCR,SPCR_CPHA);
#endif


	 /* Enable SPI Pripheral*/
	SET_BIT(SPCR,SPCR_SPE);
}

u8 SPI_u8Transiver(u8 Copy_u8Data)
{
	SPDR=Copy_u8Data;
	while((GET_BIT(SPSR,SPSR_SPIF)==0));
	return SPDR;
}
