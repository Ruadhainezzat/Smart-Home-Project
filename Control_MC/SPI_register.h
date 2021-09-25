#ifndef SPI_REGISTER_H_
#define SPI_REGISTER_H_


#define SPDR  				*((volatile u8*)0x2F)			/*SPI Data register*/


#define SPSR  				*((volatile u8*)0x2E)			/*SPI status register*/
#define SPSR_SPIF			7								/*SPI interrupt flag*/
#define SPSR_SPI2X			0								/*Prescaler bit 2*/


#define SPCR  				*((volatile u8*)0x2D)			/*SPI control register*/
#define SPCR_SPE			6                               /*SPI enable*/
#define SPCR_MSTR			4                               /*Master bit*/
#define SPCR_DORD           5                               /*Data order*/
#define SPCR_SPR1			1                               /*Prescaler bit 1*/
#define SPCR_SPR0			0                               /*prescaler bit 0*/
#define SPCR_CPHA			2                               /*Clock Phase*/
#define SPCR_CPOL			3                               /*Clock Polarity*/
#endif /* SPI_REGISTER_H_ */
