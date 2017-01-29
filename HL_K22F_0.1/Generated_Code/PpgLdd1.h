/* ###################################################################
**     This component module is generated by Processor Expert. Do not modify it.
**     Filename    : PpgLdd1.h
**     Project     : HL_K22F_0.1
**     Processor   : MK22FN512VDC12
**     Component   : PPG_LDD
**     Version     : Component 01.015, Driver 01.03, CPU db: 3.00.000
**     Repository  : Kinetis
**     Compiler    : GNU C Compiler
**     Date/Time   : 2016-12-14, 14:48, # CodeGen: 22
**     Abstract    :
**          This component implements a programmable pulse generator that
**          generates signal with variable duty and variable cycle (period).
**     Settings    :
**          Component name                                 : PpgLdd1
**          Module name                                    : FTM0
**          Counter                                        : FTM0_CNT
**          Period device                                  : FTM0_MOD
**          Duty device                                    : FTM0_C4V
**          Output pin                                     : PTD4/LLWU_P14/SPI0_PCS1/UART0_RTS_b/FTM0_CH4/FBa_AD2/EWM_IN/SPI1_PCS0
**          Interrupt service/event                        : Enabled
**            Interrupt                                    : INT_FTM0
**            Interrupt priority                           : medium priority
**            Iterations before action/event               : 1
**          Period                                         : 60 Hz
**          Starting pulse width                           : 12.499809 ms
**          Initial polarity                               : low
**          Initialization                                 : 
**            Enabled in init. code                        : yes
**            Auto initialization                          : yes
**            Event mask                                   : 
**              OnEnd                                      : Enabled
**          CPU clock/configuration selection              : 
**            Clock configuration 0                        : This component enabled
**            Clock configuration 1                        : This component disabled
**            Clock configuration 2                        : This component disabled
**            Clock configuration 3                        : This component disabled
**            Clock configuration 4                        : This component disabled
**            Clock configuration 5                        : This component disabled
**            Clock configuration 6                        : This component disabled
**            Clock configuration 7                        : This component disabled
**     Contents    :
**         Init            - LDD_TDeviceData* PpgLdd1_Init(LDD_TUserData *UserDataPtr);
**         Enable          - LDD_TError PpgLdd1_Enable(LDD_TDeviceData *DeviceDataPtr);
**         Disable         - LDD_TError PpgLdd1_Disable(LDD_TDeviceData *DeviceDataPtr);
**         SetPeriodUS     - LDD_TError PpgLdd1_SetPeriodUS(LDD_TDeviceData *DeviceDataPtr, uint16_t Time);
**         SetPeriodMS     - LDD_TError PpgLdd1_SetPeriodMS(LDD_TDeviceData *DeviceDataPtr, uint16_t Time);
**         SetPeriodSec    - LDD_TError PpgLdd1_SetPeriodSec(LDD_TDeviceData *DeviceDataPtr, uint16_t Time);
**         SetPeriodReal   - LDD_TError PpgLdd1_SetPeriodReal(LDD_TDeviceData *DeviceDataPtr,...
**         SetFrequencyHz  - LDD_TError PpgLdd1_SetFrequencyHz(LDD_TDeviceData *DeviceDataPtr, uint16_t...
**         SetFrequencykHz - LDD_TError PpgLdd1_SetFrequencykHz(LDD_TDeviceData *DeviceDataPtr, uint16_t...
**         SetFrequencyMHz - LDD_TError PpgLdd1_SetFrequencyMHz(LDD_TDeviceData *DeviceDataPtr, uint16_t...
**         SetRatio8       - LDD_TError PpgLdd1_SetRatio8(LDD_TDeviceData *DeviceDataPtr, uint8_t Ratio);
**
**     Copyright : 1997 - 2015 Freescale Semiconductor, Inc. 
**     All Rights Reserved.
**     
**     Redistribution and use in source and binary forms, with or without modification,
**     are permitted provided that the following conditions are met:
**     
**     o Redistributions of source code must retain the above copyright notice, this list
**       of conditions and the following disclaimer.
**     
**     o Redistributions in binary form must reproduce the above copyright notice, this
**       list of conditions and the following disclaimer in the documentation and/or
**       other materials provided with the distribution.
**     
**     o Neither the name of Freescale Semiconductor, Inc. nor the names of its
**       contributors may be used to endorse or promote products derived from this
**       software without specific prior written permission.
**     
**     THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
**     ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
**     WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
**     DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR
**     ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
**     (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
**     LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
**     ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
**     (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
**     SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
**     
**     http: www.freescale.com
**     mail: support@freescale.com
** ###################################################################*/
/*!
** @file PpgLdd1.h
** @version 01.03
** @brief
**          This component implements a programmable pulse generator that
**          generates signal with variable duty and variable cycle (period).
*/         
/*!
**  @addtogroup PpgLdd1_module PpgLdd1 module documentation
**  @{
*/         

#ifndef __PpgLdd1_H
#define __PpgLdd1_H

/* MODULE PpgLdd1. */

/* Include shared modules, which are used for whole project */
#include "PE_Types.h"
#include "PE_Error.h"
#include "PE_Const.h"
#include "IO_Map.h"
/* Include inherited beans */

#include "FTM_PDD.h"
#include "Cpu.h"

#ifdef __cplusplus
extern "C" {
#endif 

#define PpgLdd1_PERIOD_TICKS 0xAAABUL  /* Initial period value in ticks of the timer. */
#define PpgLdd1_PERIOD_TICKS_0 0xAAABUL /* Period value in ticks of the timer in clock configuration 0. */
#define PpgLdd1_SPUS_MIN   0x01F5U     /* Lower bound of interval for parameter of method SetPeriodUS */
#define PpgLdd1_SPUS_MAX   0x411AU     /* Upper bound of interval for parameter of method SetPeriodUS */
#define PpgLdd1_SPMS_MIN   0x01U       /* Lower bound of interval for parameter of method SetPeriodMS */
#define PpgLdd1_SPMS_MAX   0x10U       /* Upper bound of interval for parameter of method SetPeriodMS */
#define PpgLdd1_SPREAL_MIN 0.000500106812F /* Lower bound of interval for parameter of method SetPeriodReal */
#define PpgLdd1_SPREAL_MAX 0.016666793823F /* Upper bound of interval for parameter of method SetPeriodReal */
#define PpgLdd1_SFREQ_HZ_MIN 0x3CU     /* Lower bound of interval for parameter of method SetFrequencyHz */
#define PpgLdd1_SFREQ_HZ_MAX 0x07CFU   /* Upper bound of interval for parameter of method SetFrequencyHz */
#define PpgLdd1_SFREQ_KHZ_MIN 0x01U    /* Lower bound of interval for parameter of method SetFrequencykHz */
#define PpgLdd1_SFREQ_KHZ_MAX 0x01U    /* Upper bound of interval for parameter of method SetFrequencykHz */
/*! Peripheral base address of a device allocated by the component. This constant can be used directly in PDD macros. */
#define PpgLdd1_PRPH_BASE_ADDRESS  0x40038000U
  
/*! Device data structure pointer used when auto initialization property is enabled. This constant can be passed as a first parameter to all component's methods. */
#define PpgLdd1_DeviceData  ((LDD_TDeviceData *)PE_LDD_GetDeviceStructure(PE_LDD_COMPONENT_PpgLdd1_ID))

/* Methods configuration constants - generated for all enabled component's methods */
#define PpgLdd1_Init_METHOD_ENABLED    /*!< Init method of the component PpgLdd1 is enabled (generated) */
#define PpgLdd1_Enable_METHOD_ENABLED  /*!< Enable method of the component PpgLdd1 is enabled (generated) */
#define PpgLdd1_Disable_METHOD_ENABLED /*!< Disable method of the component PpgLdd1 is enabled (generated) */
#define PpgLdd1_SetPeriodUS_METHOD_ENABLED /*!< SetPeriodUS method of the component PpgLdd1 is enabled (generated) */
#define PpgLdd1_SetPeriodMS_METHOD_ENABLED /*!< SetPeriodMS method of the component PpgLdd1 is enabled (generated) */
#define PpgLdd1_SetPeriodSec_METHOD_ENABLED /*!< SetPeriodSec method of the component PpgLdd1 is enabled (generated) */
#define PpgLdd1_SetPeriodReal_METHOD_ENABLED /*!< SetPeriodReal method of the component PpgLdd1 is enabled (generated) */
#define PpgLdd1_SetFrequencyHz_METHOD_ENABLED /*!< SetFrequencyHz method of the component PpgLdd1 is enabled (generated) */
#define PpgLdd1_SetFrequencykHz_METHOD_ENABLED /*!< SetFrequencykHz method of the component PpgLdd1 is enabled (generated) */
#define PpgLdd1_SetFrequencyMHz_METHOD_ENABLED /*!< SetFrequencyMHz method of the component PpgLdd1 is enabled (generated) */
#define PpgLdd1_SetRatio8_METHOD_ENABLED /*!< SetRatio8 method of the component PpgLdd1 is enabled (generated) */

/* Events configuration constants - generated for all enabled component's events */
#define PpgLdd1_OnEnd_EVENT_ENABLED    /*!< OnEnd event of the component PpgLdd1 is enabled (generated) */



/*
** ===================================================================
**     Method      :  PpgLdd1_Init (component PPG_LDD)
*/
/*!
**     @brief
**         Initializes the device. Allocates memory for the device data
**         structure, allocates interrupt vectors and sets interrupt
**         priority, sets pin routing, sets timing, etc. If the
**         property ["Enable in init. code"] is set to "yes" value then
**         the device is also enabled (see the description of the
**         [Enable] method). In this case the [Enable] method is not
**         necessary and needn't to be generated. This method can be
**         called only once. Before the second call of Init the [Deinit]
**         must be called first.
**     @param
**         UserDataPtr     - Pointer to the user or
**                           RTOS specific data. This pointer will be
**                           passed as an event or callback parameter.
**     @return
**                         - Pointer to the dynamically allocated private
**                           structure or NULL if there was an error.
*/
/* ===================================================================*/
LDD_TDeviceData* PpgLdd1_Init(LDD_TUserData *UserDataPtr);

/*
** ===================================================================
**     Method      :  PpgLdd1_Enable (component PPG_LDD)
*/
/*!
**     @brief
**         Enables the component - it starts the signal generation.
**         Events may be generated (see SetEventMask).
**     @param
**         DeviceDataPtr   - Device data structure
**                           pointer returned by [Init] method.
**     @return
**                         - Error code, possible codes:
**                           ERR_OK - OK
**                           ERR_SPEED - The component does not work in
**                           the active clock configuration
*/
/* ===================================================================*/
LDD_TError PpgLdd1_Enable(LDD_TDeviceData *DeviceDataPtr);

/*
** ===================================================================
**     Method      :  PpgLdd1_Disable (component PPG_LDD)
*/
/*!
**     @brief
**         Disables the component - it stops signal generation and
**         events calling.
**     @param
**         DeviceDataPtr   - Device data structure
**                           pointer returned by [Init] method.
**     @return
**                         - Error code, possible codes:
**                           ERR_OK - OK
**                           ERR_SPEED - The component does not work in
**                           the active clock configuration
*/
/* ===================================================================*/
LDD_TError PpgLdd1_Disable(LDD_TDeviceData *DeviceDataPtr);

/*
** ===================================================================
**     Method      :  PpgLdd1_SetPeriodUS (component PPG_LDD)
*/
/*!
**     @brief
**         This method sets the new period of the output signal. The
**         period is expressed in [microseconds] as a 16-bit unsigned
**         integer number. This method is available only if ["Runtime
**         setting type"] property is set to "interval" .
**     @param
**         DeviceDataPtr   - Device data structure
**                           pointer returned by [Init] method.
**     @param
**         Time            - Period to set [in microseconds]
**     @return
**                         - Error code, possible codes:
**                           ERR_OK - OK
**                           ERR_SPEED - This device does not work in
**                           the active clock configuration
**                           ERR_MATH - Overflow during evaluation
**                           ERR_PARAM_RANGE - Parameter Time out of
**                           range
*/
/* ===================================================================*/
LDD_TError PpgLdd1_SetPeriodUS(LDD_TDeviceData *DeviceDataPtr, uint16_t Time);

/*
** ===================================================================
**     Method      :  PpgLdd1_SetPeriodMS (component PPG_LDD)
*/
/*!
**     @brief
**         This method sets the new period of the output signal. The
**         period is expressed in [milliseconds] as a 16-bit unsigned
**         integer number. This method is available only if ["Runtime
**         setting type"] property is set to "interval" .
**     @param
**         DeviceDataPtr   - Device data structure
**                           pointer returned by [Init] method.
**     @param
**         Time            - Period to set [in milliseconds]
**     @return
**                         - Error code, possible codes:
**                           ERR_OK - OK
**                           ERR_SPEED - This device does not work in
**                           the active clock configuration
**                           ERR_MATH - Overflow during evaluation
**                           ERR_PARAM_RANGE - Parameter Time out of
**                           range
*/
/* ===================================================================*/
LDD_TError PpgLdd1_SetPeriodMS(LDD_TDeviceData *DeviceDataPtr, uint16_t Time);

/*
** ===================================================================
**     Method      :  PpgLdd1_SetPeriodSec (component PPG_LDD)
*/
/*!
**     @brief
**         This method sets the new period of the output signal. The
**         period is expressed in [seconds] as a 16-bit unsigned
**         integer number. This method is available only if ["Runtime
**         setting type"] property is set to "interval" .
**     @param
**         DeviceDataPtr   - Device data structure
**                           pointer returned by [Init] method.
**     @param
**         Time            - Period to set [in seconds]
**     @return
**                         - Error code, possible codes:
**                           ERR_OK - OK
**                           ERR_SPEED - This device does not work in
**                           the active clock configuration
**                           ERR_MATH - Overflow during evaluation
**                           ERR_PARAM_RANGE - Parameter Time out of
**                           range
*/
/* ===================================================================*/
LDD_TError PpgLdd1_SetPeriodSec(LDD_TDeviceData *DeviceDataPtr, uint16_t Time);

/*
** ===================================================================
**     Method      :  PpgLdd1_SetPeriodReal (component PPG_LDD)
*/
/*!
**     @brief
**         This method sets the new period of the output signal. The
**         period is expressed in [seconds] as a real number. To use
**         this method the compiler have to support floating point
**         operations. This method is available only if ["Runtime
**         setting type"] property is set to "interval" .
**     @param
**         DeviceDataPtr   - Device data structure
**                           pointer returned by [Init] method.
**     @param
**         Time            - Period to set [in seconds]
**     @return
**                         - Error code, possible codes:
**                           ERR_OK - OK
**                           ERR_SPEED - This device does not work in
**                           the active speed mode
**                           ERR_MATH - Overflow during evaluation
**                           ERR_PARAM_RANGE - Parameter out of range
*/
/* ===================================================================*/
LDD_TError PpgLdd1_SetPeriodReal(LDD_TDeviceData *DeviceDataPtr, LDD_PPG_Tfloat Time);

/*
** ===================================================================
**     Method      :  PpgLdd1_SetFrequencyHz (component PPG_LDD)
*/
/*!
**     @brief
**         This method sets the new frequency of the output signal. The
**         frequency is expressed in [Hz] as a 16-bit unsigned integer
**         number. This method is available only if ["Runtime setting
**         type"] property is set to "interval" .
**     @param
**         DeviceDataPtr   - Device data structure
**                           pointer returned by [Init] method.
**     @param
**         Frequency       - Frequency to set [in Hz]
**     @return
**                         - Error code, possible codes:
**                           ERR_OK - OK
**                           ERR_SPEED - This device does not work in
**                           the active clock configuration
**                           ERR_MATH - Overflow during evaluation
**                           ERR_PARAM_RANGE - Parameter Frequency is
**                           out of range
*/
/* ===================================================================*/
LDD_TError PpgLdd1_SetFrequencyHz(LDD_TDeviceData *DeviceDataPtr, uint16_t Frequency);

/*
** ===================================================================
**     Method      :  PpgLdd1_SetFrequencykHz (component PPG_LDD)
*/
/*!
**     @brief
**         This method sets the new frequency of the output signal. The
**         frequency is expressed in [kHz] as a 16-bit unsigned integer
**         number. This method is available only if ["Runtime setting
**         type"] property is set to "interval" .
**     @param
**         DeviceDataPtr   - Device data structure
**                           pointer returned by [Init] method.
**     @param
**         Frequency       - Frequency to set [in kHz]
**     @return
**                         - Error code, possible codes:
**                           ERR_OK - OK
**                           ERR_SPEED - This device does not work in
**                           the active clock configuration
**                           ERR_MATH - Overflow during evaluation
**                           ERR_PARAM_RANGE - Parameter Frequency is
**                           out of range
*/
/* ===================================================================*/
LDD_TError PpgLdd1_SetFrequencykHz(LDD_TDeviceData *DeviceDataPtr, uint16_t Frequency);

/*
** ===================================================================
**     Method      :  PpgLdd1_SetFrequencyMHz (component PPG_LDD)
*/
/*!
**     @brief
**         This method sets the new frequency of the output signal. The
**         frequency is expressed in [MHz] as a 16-bit unsigned integer
**         number. This method is available only if ["Runtime setting
**         type"] property is set to "interval" .
**     @param
**         DeviceDataPtr   - Device data structure
**                           pointer returned by [Init] method.
**     @param
**         Frequency       - Frequency to set [in MHz]
**     @return
**                         - Error code, possible codes:
**                           ERR_OK - OK
**                           ERR_SPEED - This device does not work in
**                           the active clock configuration
**                           ERR_MATH - Overflow during evaluation
**                           ERR_PARAM_RANGE - Parameter Frequency is
**                           out of range
*/
/* ===================================================================*/
LDD_TError PpgLdd1_SetFrequencyMHz(LDD_TDeviceData *DeviceDataPtr, uint16_t Frequency);

/*
** ===================================================================
**     Method      :  PpgLdd1_SetRatio8 (component PPG_LDD)
*/
/*!
**     @brief
**         This method sets a new duty-cycle ratio. Ratio is expressed
**         as an 8-bit unsigned integer number. 0 - FF value is
**         proportional to ratio 0 - 100%. The method is available
**         only if it is not selected list of predefined values in
**         [Starting pulse width] property. 
**         Note: Calculated duty depends on the timer capabilities and
**         on the selected period.
**     @param
**         DeviceDataPtr   - Device data structure
**                           pointer returned by [Init] method.
**     @param
**         Ratio           - Ratio to set. 0 - 255 value is
**                           proportional to ratio 0 - 100%
**     @return
**                         - Error code, possible codes:
**                           ERR_OK - OK
**                           ERR_SPEED - The component does not work in
**                           the active clock configuration
*/
/* ===================================================================*/
LDD_TError PpgLdd1_SetRatio8(LDD_TDeviceData *DeviceDataPtr, uint8_t Ratio);

/*
** ===================================================================
**     Method      :  PpgLdd1_Interrupt (component PPG_LDD)
**
**     Description :
**         The method services the interrupt of the selected peripheral(s)
**         and eventually invokes event(s) of the component.
**         This method is internal. It is used by Processor Expert only.
** ===================================================================
*/
/* {Default RTOS Adapter} ISR function prototype */
PE_ISR(PpgLdd1_Interrupt);

/* END PpgLdd1. */

#ifdef __cplusplus
}  /* extern "C" */
#endif 

#endif 
/* ifndef __PpgLdd1_H */
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
