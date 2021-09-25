#ifndef SPI_CONFIG_H_
#define SPI_CONFIG_H_

/*	Options: SPI_u8_MSB_FIRST
 * 			 SPI_u8_LSB_FIRST
 */
#define SPI_u8_DATA_ORDER		SPI_u8_MSB_FIRST



/*	Options: SPI_u8_LEADING_RISING
 * 			 SPI_u8_LEADING_FALLING
 */
#define SPI_u8_CLOCK_POLARITY	SPI_u8_LEADING_FALLING

/*	Options: SPI_u8_LEADING_SAMPLE
 * 			 SPI_u8_LEADING_SETUP
 */
#define SPI_u8_CLOCK_PHASE		SPI_u8_LEADING_SETUP

/*	Options: SPI_u8_DIV_4
 *			 SPI_u8_DIV_16
 *			 SPI_u8_DIV_64
 *			 SPI_u8_DIV_128
 */
#define SPI_u8_CLOCK_SELECT		SPI_u8_DIV_4



#endif /* SPI_CONFIG_H_ */