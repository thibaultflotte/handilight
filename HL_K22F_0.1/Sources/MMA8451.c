/*
 * MMA8451.c
 *
 *  Created on: 13 déc. 2016
 *      Author: Thibault
 */

#include "MMA8451.h"
#include "LED1.h"
#include "LEDpin1.h"
#include "BitIoLdd1.h"


/* \brief Run the demo application */
#define ENABLE_X_AXIS 0x01
#define ENABLE_Y_AXIS 0x02
#define ENABLE_Z_AXIS 0x04
#define WHO_AM_I 0x0F
#define POWER_MODE 	0x08

/* External 3-axis accelerometer data register addresses */
#define MMA8451_OUT_X_MSB 0x29
#define MMA8451_OUT_X_LSB 0x28
#define MMA8451_OUT_Y_MSB 0x2B
#define MMA8451_OUT_Y_LSB 0x2A
#define MMA8451_OUT_Z_MSB 0x2D
#define MMA8451_OUT_Z_LSB 0x2C

#define CTRL_REG1 0x20
#define CTRL_REG2 0x21
#define CTRL_REG3 0x22
#define CTRL_REG4 0x23
#define CTRL_REG5 0x24

#define SLAVE_ADRESS 0x68

static MMA8451_TDataState deviceData;
int16_t x_gyro = 0, y_gyro = 0, z_gyro = 0;

void tempo(void){
	int i;
	for (i=100000; i>0; i--){

	}
}
void L3G4200D_init()
{
	  GI2C1_Init();
	  GI2C1_WriteByteAddress8(SLAVE_ADRESS, CTRL_REG1, ENABLE_X_AXIS|ENABLE_Y_AXIS|ENABLE_Z_AXIS|POWER_MODE);
	  GI2C1_WriteByteAddress8(SLAVE_ADRESS, CTRL_REG2, 0b00000000);
	  GI2C1_WriteByteAddress8(SLAVE_ADRESS, CTRL_REG3, 0b00001000);
	  GI2C1_WriteByteAddress8(SLAVE_ADRESS, CTRL_REG4, 0b00000000);
	  GI2C1_WriteByteAddress8(SLAVE_ADRESS, CTRL_REG5, 0b00110000);
}

char L3G4200D_getX_MSB()
{
	unsigned char X_MSB = 0;
	GI2C1_ReadByteAddress8(SLAVE_ADRESS, MMA8451_OUT_X_MSB, &X_MSB);
	return X_MSB;
}

char L3G4200D_getX_LSB()
{
	unsigned char X_LSB = 0;
	GI2C1_ReadByteAddress8(SLAVE_ADRESS, MMA8451_OUT_X_LSB, &X_LSB);
	return X_LSB;
}

char L3G4200D_getY_MSB()
{
	unsigned char Y_MSB = 0;
	GI2C1_ReadByteAddress8(SLAVE_ADRESS, MMA8451_OUT_Y_MSB, &Y_MSB);
	return Y_MSB;
}

char L3G4200D_getY_LSB()
{
	unsigned char Y_LSB = 0;
	GI2C1_ReadByteAddress8(SLAVE_ADRESS, MMA8451_OUT_Y_LSB, &Y_LSB);
	return Y_LSB;
}

char L3G4200D_getZ_MSB()
{
	unsigned char Z_MSB = 0;
	GI2C1_ReadByteAddress8(SLAVE_ADRESS, MMA8451_OUT_Z_MSB, &Z_MSB);
	return Z_MSB;
}

char L3G4200D_getZ_LSB()
{
	unsigned char Z_LSB = 0;
	GI2C1_ReadByteAddress8(SLAVE_ADRESS, MMA8451_OUT_Z_LSB, &Z_LSB);
	return Z_LSB;
}



void MMA8451_Run(void) {

	uint8_t res;

  /* L3G4200D */
  	int8_t xMSB = 0, xLSB = 0;
  	int8_t yMSB = 0, yLSB = 0;
  	int8_t zMSB = 0, zLSB = 0;
  	//int16_t x_gyro = 0, y_gyro = 0, z_gyro = 0;

  	L3G4200D_init();

  	/* L3G4200D */
  	xMSB = L3G4200D_getX_MSB();
  	xLSB = L3G4200D_getX_LSB();
  	x_gyro = ((xMSB << 8) | xLSB);
  	WAIT1_Waitms(100);
  	yMSB = L3G4200D_getY_MSB();
  	yLSB = L3G4200D_getY_LSB();
  	y_gyro = ((yMSB << 8) | yLSB);
  	WAIT1_Waitms(100);
  	zMSB = L3G4200D_getZ_MSB();
  	zLSB = L3G4200D_getZ_LSB();
  	z_gyro = ((zMSB << 8) | zLSB);
  	WAIT1_Waitms(100);
}






