/*
 * SendData.c
 *
 *  Created on: 12 déc. 2016
 *      Author: Thibault
 */
#include "Cpu.h"
#include "Events.h"
#include "Pins1.h"
#include "LED1.h"
#include "LEDpin1.h"
#include "BitIoLdd1.h"
#include "KSDK1.h"
#include "WAIT1.h"
#include "BT1.h"
#include "Serial1.h"
#include "ASerialLdd1.h"
#include "CLS1.h"
#include "UTIL1.h"
#include "CS1.h"
/* Including shared modules, which are used for whole project */
#include "PE_Types.h"
#include "PE_Error.h"
#include "PE_Const.h"
#include "IO_Map.h"
#include "PDD_Includes.h"
#include "Init_Config.h"
#include "SendData.h"
#include "AD1.h"
#include "AdcLdd1.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "MMA8451.h"
extern int16_t x_gyro, y_gyro, z_gyro;


void sendData(uint16_t references){	//Il faudra surement retourner quelque chose plus tard dans une fonction émission mais pour le moment nous n'avons qu'a gérer le "gyroscope" indépendamment des autres composants

	int j, k, m = 0;
	int gyrometerData[8];
	int8_t dataGyro = 0;
	uint8_t signe = 0;
	gyrometerData[1] = 'S';
	gyrometerData[7] = 'E';
	gyrometerData[2] =  0x3C;

	/************************* PARTIE Gyromètre ***********************************/
	MMA8451_Run();
	gyrometerData[4]= x_gyro;
	gyrometerData[5]= y_gyro;
	gyrometerData[6]= z_gyro;

	/************************* PARTIE ADC ACCELEROMETRE 1 AXE ***********************************/

	  uint16_t value;

	  (void)AD1_Measure(TRUE); /* do conversion and wait for the result */
	  (void)AD1_GetValue16(&value);
	  gyrometerData[3]= (value-references);

	for (j = 0; j < 8; j++) {
		BT1_SendChar(gyrometerData[j]);
		WAIT1_Waitms(1);
	}

}


