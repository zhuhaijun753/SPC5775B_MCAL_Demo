/*
 * Switch_SJA1105.c
 *
 *  Created on: 2019��10��23��
 *      Author: admin
 */

#include <stdlib.h>
#include <string.h>
#include "Switch_SJA1105.h"
#include "Spi.h"



uint8_t r_data[65*4] = {0};

/* General Config */
static uint8_t configBurst0_0[65*4] = {0x80,0x20,0x00,0x00, 0xAF,0x00,0x03,0x0E, 0x05,0x00,0x00,0x00, 0x00,0x00,0x00,0x05, 0x9A,0x1C,0xA0,0x2B, 0x26,0x42,0x00,0x00, 0x04,0x25,0x00,0x00, 0xFF,0xF8,0x00,0x00, 0xFF,0xFF,0xFF,0xFF, 0x00,0x00,0xFF,0xFF, 0x00,0xF1,0xAB,0x13, 0x06,0x00,0x00,0x00, 0x00,0x00,0x00,0x5A, 0x4E,0xD2,0xC5,0x0F, 0xFE,0xFB,0x00,0x00, 0x03,0xFF,0xFF,0xFF, 0xFE,0xFB,0x00,0x00, 0x03,0xFF,0xFF,0xFF, 0xFE,0xFB,0x00,0x00, 0x03,0xFF,0xFF,0xFF, 0xFE,0xFB,0x00,0x00, 0x03,0xFF,0xFF,0xFF, 0xFE,0xFB,0x00,0x00, 0x03,0xFF,0xFF,0xFF, 0xFE,0xFB,0x00,0x00, 0x03,0xFF,0xFF,0xFF, 0xFE,0xFB,0x00,0x00, 0x03,0xFF,0xFF,0xFF, 0xFE,0xFB,0x00,0x00, 0x03,0xFF,0xFF,0xFF, 0xFE,0xFB,0x00,0x00, 0x07,0xFF,0xFF,0xFF, 0xFE,0xFB,0x00,0x00, 0x07,0xFF,0xFF,0xFF, 0xFE,0xFB,0x00,0x00, 0x07,0xFF,0xFF,0xFF, 0xFE,0xFB,0x00,0x00, 0x07,0xFF,0xFF,0xFF, 0xFE,0xFB,0x00,0x00, 0x07,0xFF,0xFF,0xFF, 0xFE,0xFB,0x00,0x00, 0x07,0xFF,0xFF,0xFF, 0xFE,0xFB,0x00,0x00, 0x07,0xFF,0xFF,0xFF, 0xFE,0xFB,0x00,0x00, 0x07,0xFF,0xFF,0xFF, 0xFE,0xFB,0x00,0x00, 0x0B,0xFF,0xFF,0xFF, 0xFE,0xFB,0x00,0x00, 0x0B,0xFF,0xFF,0xFF, 0xFE,0xFB,0x00,0x00, 0x0B,0xFF,0xFF,0xFF, 0xFE,0xFB,0x00,0x00, 0x0B,0xFF,0xFF,0xFF, 0xFE,0xFB,0x00,0x00, 0x0B,0xFF,0xFF,0xFF, 0xFE,0xFB,0x00,0x00, 0x0B,0xFF,0xFF,0xFF, 0xFE,0xFB,0x00,0x00, 0x0B,0xFF,0xFF,0xFF, 0xFE,0xFB,0x00,0x00, 0x0B,0xFF,0xFF,0xFF, 0xFE,0xFB,0x00,0x00, 0x0F,0xFF,0xFF,0xFF, 0xFE,0xFB,0x00,0x00};
static uint8_t configBurst0_1[65*4] = {0x80,0x20,0x04,0x00, 0x0F,0xFF,0xFF,0xFF, 0xFE,0xFB,0x00,0x00, 0x0F,0xFF,0xFF,0xFF, 0xFE,0xFB,0x00,0x00, 0x0F,0xFF,0xFF,0xFF, 0xFE,0xFB,0x00,0x00, 0x0F,0xFF,0xFF,0xFF, 0xFE,0xFB,0x00,0x00, 0x0F,0xFF,0xFF,0xFF, 0xFE,0xFB,0x00,0x00, 0x0F,0xFF,0xFF,0xFF, 0xFE,0xFB,0x00,0x00, 0x0F,0xFF,0xFF,0xFF, 0xFE,0xFB,0x00,0x00, 0x13,0xFF,0xFF,0xFF, 0xFE,0xFB,0x00,0x00, 0x13,0xFF,0xFF,0xFF, 0xFE,0xFB,0x00,0x00, 0x13,0xFF,0xFF,0xFF, 0xFE,0xFB,0x00,0x00, 0x13,0xFF,0xFF,0xFF, 0xFE,0xFB,0x00,0x00, 0x13,0xFF,0xFF,0xFF, 0xFE,0xFB,0x00,0x00, 0x13,0xFF,0xFF,0xFF, 0xFE,0xFB,0x00,0x00, 0x13,0xFF,0xFF,0xFF, 0xFE,0xFB,0x00,0x00, 0x13,0xFF,0xFF,0xFF, 0xFE,0xFB,0x00,0x00, 0xA3,0xFF,0xFF,0xFF, 0xFE,0xFB,0x00,0x00, 0xA7,0xFF,0xFF,0xFF, 0xFE,0xFB,0x00,0x00, 0xAB,0xFF,0xFF,0xFF, 0xFE,0xFB,0x00,0x00, 0xAF,0xFF,0xFF,0xFF, 0xFE,0xFB,0x00,0x00, 0xB3,0xFF,0xFF,0xFF, 0x99,0xCE,0x35,0xDC, 0x07,0x00,0x00,0x00, 0x00,0x00,0x00,0x02, 0x7D,0x0B,0xCB,0xF2, 0x00,0x00,0x00,0x00, 0x00,0x3F,0xF0,0x00, 0x88,0x38,0x86,0x85, 0x08,0x00,0x00,0x00, 0x00,0x00,0x00,0x1A, 0x6A,0xF6,0x23,0x53, 0x10,0x00,0x00,0x00, 0xF7,0xBD,0xF5,0x8D, 0x10,0x00,0x00,0x00, 0xEF,0x7B,0xF5,0x8D, 0x10,0x00,0x00,0x00, 0xDE,0xF7,0xF5,0x8D, 0x10,0x00,0x00,0x00, 0xBD,0xEF,0xF5,0x8D, 0x10,0x00,0x00,0x00, 0x7B,0xDF,0xF5,0x8D, 0x00,0x00,0x00,0x00, 0x00,0x00,0x00,0x00, 0x00,0x00,0x00,0x00, 0x00,0x00,0x00,0x00, 0x00,0x00,0x00,0x00};
static uint8_t configBurst0_2[65*4] = {0x80,0x20,0x08,0x00, 0x00,0x00,0x00,0x00, 0x00,0x00,0x00,0x00, 0x00,0x00,0x00,0x00, 0x00,0x00,0x00,0x00, 0x00,0x00,0x00,0x00, 0x00,0x00,0x00,0x00, 0x00,0x00,0x00,0x00, 0x00,0x00,0x00,0x00, 0x00,0x00,0x00,0x00, 0x00,0x00,0x00,0x00, 0x00,0x00,0x00,0x00, 0xC0,0x04,0xA6,0x06, 0x09,0x00,0x00,0x00, 0x00,0x00,0x00,0x28, 0x0D,0xB4,0x3A,0xC9, 0x80,0x00,0x00,0x00, 0xFE,0x00,0x00,0x03, 0x00,0x00,0x00,0x01, 0x07,0xFC,0x01,0x04, 0x00,0x00,0x00,0x00, 0x00,0x00,0x00,0x00, 0x00,0x00,0x00,0x00, 0x00,0x00,0x00,0x00, 0x80,0x00,0x00,0x00, 0xFE,0x00,0x00,0x03, 0x00,0x00,0x00,0x01, 0x07,0xFC,0x01,0x04, 0x00,0x00,0x00,0x00, 0x00,0x00,0x00,0x00, 0x00,0x00,0x00,0x00, 0x00,0x00,0x00,0x00, 0x80,0x00,0x00,0x00, 0xFE,0x00,0x00,0x03, 0x00,0x00,0x00,0x01, 0x07,0xFC,0x01,0x04, 0x00,0x00,0x00,0x00, 0x00,0x00,0x00,0x00, 0x00,0x00,0x00,0x00, 0x00,0x00,0x00,0x00, 0x80,0x00,0x00,0x00, 0xFE,0x00,0x00,0x03, 0x00,0x00,0x00,0x01, 0x07,0xFC,0x01,0x04, 0x00,0x00,0x00,0x00, 0x00,0x00,0x00,0x00, 0x00,0x00,0x00,0x00, 0x00,0x00,0x00,0x00, 0x80,0x00,0x00,0x00, 0xFE,0x00,0x00,0x03, 0x00,0x00,0x00,0x01, 0x07,0xFC,0x01,0x04, 0x00,0x00,0x00,0x00, 0x00,0x00,0x00,0x00, 0x00,0x00,0x00,0x00, 0x00,0x00,0x00,0x00, 0x21,0x3D,0xEC,0xEF, 0x0D,0x00,0x00,0x00, 0x00,0x00,0x00,0x04, 0x12,0xD0,0x8C,0x8F, 0x02,0x00,0x00,0x00, 0x00,0x00,0x00,0x00, 0x04,0x00,0x80,0x10, 0x00,0x01,0x00,0x20, 0x34,0xE3,0x1D,0x78};
static uint8_t configBurst0_3[39*4] = {0x80,0x20,0x0C,0x00, 0x0E,0x00,0x00,0x00, 0x00,0x00,0x00,0x03, 0xC8,0xA7,0xCE,0xE6, 0x00,0x71,0xC0,0x00, 0x00,0x00,0x00,0x00, 0x00,0x00,0x00,0x00, 0xC3,0xF7,0x04,0xB9, 0x10,0x00,0x00,0x00, 0x00,0x00,0x00,0x04, 0x8A,0xA0,0xDF,0xBC, 0x80,0x00,0x00,0x00, 0x0D,0xF0,0x3F,0xFB, 0xB2,0xB7,0x80,0x98, 0x40,0x98,0x0D,0xF7, 0xE6,0xC9,0x31,0x8C, 0x11,0x00,0x00,0x00, 0x00,0x00,0x00,0x0B, 0xEF,0xA3,0xE6,0x5A, 0x01,0xC0,0x00,0x00, 0x42,0x04,0x00,0x00, 0xFF,0xFF,0xFC,0x45, 0xFF,0xFF,0xFF,0xFF, 0xFF,0xDD,0x37,0xFF, 0xFF,0xFF,0x00,0x00, 0x00,0x00,0xFF,0xFF, 0x0E,0xFF,0xFF,0xFF, 0x80,0xC2,0x00,0x00, 0x00,0x00,0x03,0x01, 0x45,0x01,0x80,0xC2, 0xD7,0xC6,0x8C,0x8D, 0x4E,0x00,0x00,0x00, 0x00,0x00,0x00,0x01, 0x3A,0x5D,0x5E,0x24, 0x80,0x00,0x00,0x00, 0xCC,0xFC,0x5C,0x3C, 0x00,0x00,0x00,0x00, 0x00,0x00,0x00,0x00, 0x9D,0xB7,0xE6,0xFD};


/* Configure CFG_PAD_MII4_RX[CTRL_IPUD], Pull down MII4_RX_ER */
/* In MII setting all interface pins must be connected.If unused,RX_ER must be connected to GND
 * or the internal pull up/down must be configured.
 */
uint8_t tmp[8] = {0x01|0x80,0x00,0x80,0x90,0x02,0x02,0x03,0x12};

//MII 100M clock for port0 (100Mbps MAC)
static const uint8_t port0_idiv0[] =      {0x01|0x80,0x00,0x00,0xb0,0x0a,0x00,0x00,0x01};
static const uint8_t port0_mii_tx_clk[] = {0x01|0x80,0x00,0x01,0x30,0x00,0x00,0x08,0x00};
static const uint8_t port0_mii_rx_clk[] = {0x01|0x80,0x00,0x01,0x40,0x01,0x00,0x08,0x00};

//MII clock for port1 (100Mbps MAC)
static const uint8_t port1_idiv1[] =      {0x01|0x80,0x00,0x00,0xc0,0x0a,0x00,0x00,0x01};
static const uint8_t port1_mii_tx_clk[] = {0x01|0x80,0x00,0x01,0x90,0x02,0x00,0x08,0x00};
static const uint8_t port1_mii_rx_clk[] = {0x01|0x80,0x00,0x01,0xa0,0x03,0x00,0x08,0x00};

//MII clock for port2 (100Mbps MAC)
static const uint8_t port2_idiv2[] =      {0x01|0x80,0x00,0x00,0xd0,0x0a,0x00,0x00,0x01};
static const uint8_t port2_mii_tx_clk[] = {0x01|0x80,0x00,0x01,0xf0,0x04,0x00,0x08,0x00};
static const uint8_t port2_mii_rx_clk[] = {0x01|0x80,0x00,0x02,0x00,0x05,0x00,0x08,0x00};

//MII clock for port3 (100Mbps MAC)
static const uint8_t port3_idiv3[] =      {0x01|0x80,0x00,0x00,0xe0,0x0a,0x00,0x00,0x01};
static const uint8_t port3_mii_tx_clk[] = {0x01|0x80,0x00,0x02,0x50,0x06,0x00,0x08,0x00};
static const uint8_t port3_mii_rx_clk[] = {0x01|0x80,0x00,0x02,0x60,0x07,0x00,0x08,0x00};

//MII clock for port4 (100Mbps PHY)
static const uint8_t port4_idiv4[] =      {0x01|0x80,0x00,0x00,0xf0,0x0a,0x00,0x00,0x00};
static const uint8_t port4_mii_tx_clk[] = {0x01|0x80,0x00,0x02,0xb0,0x15,0x00,0x08,0x00};
static const uint8_t port4_mii_rx_clk[] = {0x01|0x80,0x00,0x02,0xc0,0x09,0x00,0x08,0x00};
static const uint8_t port4_ext_tx_clk[] = {0x01|0x80,0x00,0x02,0xf0,0x15,0x00,0x08,0x00};
static const uint8_t port4_ext_rx_clk[] = {0x01|0x80,0x00,0x03,0x00,0x15,0x00,0x08,0x00};


/*
@brief
@details
@para
@return
*/
static void SysDelay(uint32_t cnt)
{
	while (cnt--){;}
}


#if (DRIVER_USE_MCAL == 1)
/*
@brief
@details
@para
@return
*/
int SPI_TransferDataBlocking(const uint8_t* pSrcBuf, uint8_t* pDestBuf, uint16_t Size, uint32_t timeout)
{
	Std_ReturnType ret;
	Spi_SeqResultType result;
	uint8_t dummyCnt;
	uint32_t delayCount;

	dummyCnt = 0;
	delayCount = 0;

	ret = Spi_SetupEB(SpiConf_SpiChannel_SJA1105Channel, (Spi_DataType*)pSrcBuf, (Spi_DataType*)pDestBuf, (Spi_NumberOfDataType)Size);

	if (ret == E_OK)
	{
		ret = Spi_AsyncTransmit(SpiConf_SpiSequence_SJA1105Command);

		do
		{
			Spi_MainFunction_Handling();

			result = Spi_GetSequenceResult(SpiConf_SpiSequence_SJA1105Command);

			delayCount++;
		}
		while ((result != SPI_SEQ_OK) && (delayCount <= (timeout * 100)));

		if (result != SPI_SEQ_OK)
		{
			while (dummyCnt < 5U)dummyCnt++;
			return (0);
		}

		while (dummyCnt < 5U)dummyCnt++;
		return (1);
	}
	else
	{
		while (dummyCnt < 5U)dummyCnt++;
		return (0);
	}
}
#endif


/*
@brief
@details
@para
@return
*/
void Switch_SJA1105_Init(void)
{
	int res = -1;

	SWITCH_SJA1105_RESET_LOW();
	SysDelay(2000);
	SWITCH_SJA1105_RESET_HIGH();

	Spi_Init((Spi_ConfigType *)&SpiDriver);
	Spi_SetAsyncMode(SPI_POLLING_MODE);

	/*------------------------------ SWITCH AND ENET PHY - MAC0 -------------------------*/
	res = SPI_TransferDataBlocking(tmp, r_data, 8, 1000U);

	/*****************************************port0**************************************************/
	//port0 port0_idiv0 MII-MAC
	SPI_TransferDataBlocking(port0_idiv0, r_data, 8, 1000U);

	//port0 port0_mii_tx_clk MII-MAC
	SPI_TransferDataBlocking(port0_mii_tx_clk, r_data, 8, 1000U);

	//port0 port0_mii_rx_clk MII-MAC
	SPI_TransferDataBlocking(port0_mii_rx_clk, r_data, 8, 1000U);

	/*****************************************port1**************************************************/
	//port1 port1_idiv1 MII-MAC
	SPI_TransferDataBlocking(port1_idiv1, r_data, 8, 1000U);

	//port1 port1_mii_tx_clk MII-MAC
	SPI_TransferDataBlocking(port1_mii_tx_clk, r_data, 8, 1000U);

	//port1 port1_mii_rx_clk MII-MAC
	SPI_TransferDataBlocking(port1_mii_rx_clk, r_data, 8, 1000U);

	/*****************************************port2**************************************************/
	//port2 port2_idiv2 MII-MAC
	SPI_TransferDataBlocking(port2_idiv2, r_data, 8, 1000U);

	//port2 port2_mii_tx_clk MII-MAC
	SPI_TransferDataBlocking(port2_mii_tx_clk, r_data, 8, 1000U);

	//port2 port2_mii_rx_clk MII-MAC
	SPI_TransferDataBlocking(port2_mii_rx_clk, r_data, 8, 1000U);

	/*****************************************port3**************************************************/
	//port3 port3_idiv3 MII-MAC
	SPI_TransferDataBlocking(port3_idiv3, r_data, 8, 1000U);

	//port3 port3_mii_tx_clk MII-MAC
	SPI_TransferDataBlocking(port3_mii_tx_clk, r_data, 8, 1000U);

	//port3 port3_mii_rx_clk MII-MAC
	SPI_TransferDataBlocking(port3_mii_rx_clk, r_data, 8, 1000U);

	/*****************************************port4**************************************************/
	//port4 port4_idiv4 MII-PHY
	SPI_TransferDataBlocking(port4_idiv4, r_data, 8, 1000U);

	//port4 port4_mii_tx_clk MII-PHY
	SPI_TransferDataBlocking(port4_mii_tx_clk, r_data, 8, 1000U);

	//port4 port4_mii_rx_clk MII-PHY
	SPI_TransferDataBlocking(port4_mii_rx_clk, r_data, 8, 1000U);

	//port4 port4_ext_tx_clk MII-PHY
	SPI_TransferDataBlocking(port4_ext_tx_clk, r_data, 8, 1000U);

	//port4 port4_ext_rx_clk MII-PHY
	SPI_TransferDataBlocking(port4_ext_rx_clk, r_data, 8, 1000U);

	/*****************************************static configuration**************************************************/
	SPI_TransferDataBlocking(configBurst0_0, r_data, sizeof(configBurst0_0), 1000U);

	SPI_TransferDataBlocking(configBurst0_1, r_data, sizeof(configBurst0_1), 1000U);

	SPI_TransferDataBlocking(configBurst0_2, r_data, sizeof(configBurst0_2), 1000U);

	SPI_TransferDataBlocking(configBurst0_3, r_data, sizeof(configBurst0_3), 1000U);
}


/*
@brief Write data to the specified registers in SJA1105 chip.
@details This function is called by users to configure or set the register's value in SJA1105 chip.
@para regAddr, register address in SJA1105 chip.
@para *pWtData, a pointer which point the write data buffer.
@para u8WtDataLen, write data length.The unit of the length is bytes.
@return 0, success; -1, failed;
*/
int SJA1105_WriteData(const uint32_t regAddr, const uint8_t* pWtData, const uint16_t u8WtDataLen)
{
	uint8_t txBuf[65*4], rxBuf[65*4];
	uint16_t length = 0;
#if (DRIVER_USE_SDK == 1)
	status_t retVal;
#elif (DRIVER_USE_MCAL == 1)
	int retVal;
#endif

	txBuf[length++] = (uint8_t)((regAddr >> 20) & 0x000000FFU) | 0x80U;
	txBuf[length++] = (uint8_t)((regAddr >> 12) & 0x000000FFU);
	txBuf[length++] = (uint8_t)((regAddr >> 4)  & 0x000000FFU);
	txBuf[length++] = (uint8_t)((regAddr << 4)  & 0x000000F0U);

	memcpy((uint8_t*)&txBuf[length], (uint8_t*)pWtData, (u8WtDataLen * sizeof(uint8_t)));

	length += (u8WtDataLen * sizeof(uint8_t));

#if (DRIVER_USE_SDK == 1)
	retVal = SPI_MasterTransferBlocking(&spi1Instance, txBuf, rxBuf, length, 1000U);
#elif (DRIVER_USE_MCAL == 1)
	retVal = SPI_TransferDataBlocking(txBuf, rxBuf, length, 1000U);
#endif

#if (DRIVER_USE_SDK == 1)
	if (retVal == STATUS_SUCCESS)
#elif (DRIVER_USE_MCAL == 1)
	if (retVal != 0)
#endif
	{
		return (0);
	}
	else
	{
		return (-1);
	}
}

/*
@brief Read data from the specified registers in SJA1105 chip.
@details This function is called by users to get the register value in SJA1105 chip.
@para regAddr, register address in SJA1105 chip.
@para *pRdData, a pointer which point the read data buffer from SJA1105 chip.
@para u8RdDataLen, read data buffer length.As the register data is 32-bit double words,the length is 4 bytes multiple.
@return 0, success; -1, failed;
*/
int SJA1105_ReadData(const uint32_t regAddr, uint8_t* pRdData, const uint16_t u8RdDataLen)
{
	uint8_t txBuf[65*4], rxBuf[65*4];
	uint16_t length = 0;
	uint8_t size;
#if (DRIVER_USE_SDK == 1)
	status_t retVal;
#elif (DRIVER_USE_MCAL == 1)
	int retVal;
#endif

	size = (uint8_t)(u8RdDataLen / 4);

	txBuf[length++] = (uint8_t)((regAddr >> 20) & 0x000000FFU) | (size << 1);
	txBuf[length++] = (uint8_t)((regAddr >> 12) & 0x000000FFU);
	txBuf[length++] = (uint8_t)((regAddr >> 4)  & 0x000000FFU);
	txBuf[length++] = (uint8_t)((regAddr << 4)  & 0x000000F0U);

	memset((uint8_t*)&txBuf[length], 0, (u8RdDataLen * sizeof(uint8_t)));

	length += (u8RdDataLen * sizeof(uint8_t));

#if (DRIVER_USE_SDK == 1)
	retVal = SPI_MasterTransferBlocking(&spi1Instance, txBuf, rxBuf, length, 1000U);
#elif (DRIVER_USE_MCAL == 1)
	retVal = SPI_TransferDataBlocking(txBuf, rxBuf, length, 1000U);
#endif

#if (DRIVER_USE_SDK == 1)
	if (retVal == STATUS_SUCCESS)
#elif (DRIVER_USE_MCAL == 1)
	if (retVal != 0)
#endif
	{
		memcpy((uint8_t*)pRdData, (uint8_t*)&rxBuf[4], (u8RdDataLen * sizeof(uint8_t)));

		return (0);
	}
	else
	{
		memset((uint8_t*)pRdData, 0, (u8RdDataLen * sizeof(uint8_t)));

		return (-1);
	}
}



