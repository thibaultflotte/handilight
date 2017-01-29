/*
 * MMA8451.h
 *
 *  Created on: 13 déc. 2016
 *      Author: Thibault
 */

#ifndef SOURCES_MMA8451_H_
#define SOURCES_MMA8451_H_

#include "PE_Types.h"
#include "PE_LDD.h"

typedef struct {
  volatile bool dataReceivedFlg; /* set to TRUE by the interrupt if we have received data */
  volatile bool dataTransmittedFlg; /* set to TRUE by the interrupt if we have set data */
  LDD_TDeviceData *handle; /* pointer to the device handle */
} MMA8451_TDataState;

/* \brief Run the demo application */
void MMA8451_Run(void);
void tempo(void);



#endif /* SOURCES_MMA8451_H_ */
