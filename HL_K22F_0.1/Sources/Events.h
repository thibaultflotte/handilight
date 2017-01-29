/* ###################################################################
**     Filename    : Events.h
**     Project     : HL_K22F_0.1
**     Processor   : MK22FN512VDC12
**     Component   : Events
**     Version     : Driver 01.00
**     Compiler    : GNU C Compiler
**     Date/Time   : 2016-12-08, 18:14, # CodeGen: 0
**     Abstract    :
**         This is user's event module.
**         Put your event handler code here.
**     Contents    :
**         Cpu_OnNMI - void Cpu_OnNMI(void);
**
** ###################################################################*/
/*!
** @file Events.h
** @version 01.00
** @brief
**         This is user's event module.
**         Put your event handler code here.
*/         
/*!
**  @addtogroup Events_module Events module documentation
**  @{
*/         

#ifndef __Events_H
#define __Events_H
/* MODULE Events */

#include "PE_Types.h"
#include "PE_Error.h"
#include "PE_Const.h"
#include "IO_Map.h"
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
#include "LEDRouge.h"
#include "PpgLdd1.h"
#include "AD2.h"
#include "AdcLdd2.h"
#include "AD1.h"
#include "AdcLdd1.h"
#include "GI2C1.h"
#include "CI2C1.h"
#include "LEDVerte.h"
#include "PpgLdd3.h"
#include "LEDBlanche.h"
#include "PpgLdd2.h"

#ifdef __cplusplus
extern "C" {
#endif 

/*
** ===================================================================
**     Event       :  Cpu_OnNMI (module Events)
**
**     Component   :  Cpu [MK22FN512DC12]
*/
/*!
**     @brief
**         This event is called when the Non maskable interrupt had
**         occurred. This event is automatically enabled when the [NMI
**         interrupt] property is set to 'Enabled'.
*/
/* ===================================================================*/
void Cpu_OnNMI(void);


/*
** ===================================================================
**     Event       :  LEDRouge_OnEnd (module Events)
**
**     Component   :  LEDRouge [PPG]
**     Description :
**         This event is called when the specified number of iterations
**         is generated. (Only when the component is enabled - <Enable>
**         and the events are enabled - <EnableEvent>). The event is
**         available only when the peripheral supports an interrupt,
**         that is generated at the end of the PWM period.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/
void LEDRouge_OnEnd(void);

void AD1_OnEnd(void);
/*
** ===================================================================
**     Event       :  AD1_OnEnd (module Events)
**
**     Component   :  AD1 [ADC]
**     Description :
**         This event is called after the measurement (which consists
**         of <1 or more conversions>) is/are finished.
**         The event is available only when the <Interrupt
**         service/event> property is enabled.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/

void AD1_OnCalibrationEnd(void);
/*
** ===================================================================
**     Event       :  AD1_OnCalibrationEnd (module Events)
**
**     Component   :  AD1 [ADC]
**     Description :
**         This event is called when the calibration has been finished.
**         User should check if the calibration pass or fail by
**         Calibration status method./nThis event is enabled only if
**         the <Interrupt service/event> property is enabled.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/

/*
** ===================================================================
**     Event       :  LEDVerte_OnEnd (module Events)
**
**     Component   :  LEDVerte [PPG]
**     Description :
**         This event is called when the specified number of iterations
**         is generated. (Only when the component is enabled - <Enable>
**         and the events are enabled - <EnableEvent>). The event is
**         available only when the peripheral supports an interrupt,
**         that is generated at the end of the PWM period.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/
void LEDVerte_OnEnd(void);

void AD2_OnEnd(void);
/*
** ===================================================================
**     Event       :  AD2_OnEnd (module Events)
**
**     Component   :  AD2 [ADC]
**     Description :
**         This event is called after the measurement (which consists
**         of <1 or more conversions>) is/are finished.
**         The event is available only when the <Interrupt
**         service/event> property is enabled.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/

void AD2_OnCalibrationEnd(void);
/*
** ===================================================================
**     Event       :  AD2_OnCalibrationEnd (module Events)
**
**     Component   :  AD2 [ADC]
**     Description :
**         This event is called when the calibration has been finished.
**         User should check if the calibration pass or fail by
**         Calibration status method./nThis event is enabled only if
**         the <Interrupt service/event> property is enabled.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/

/* END Events */

#ifdef __cplusplus
}  /* extern "C" */
#endif 

#endif 
/* ifndef __Events_H*/
/*!
** @}
*/
/*
** ###################################################################
**
**     This file was created by Processor Expert 10.5 [05.21]
**     for the Freescale Kinetis series of microcontrollers.
**
** ###################################################################
*/
