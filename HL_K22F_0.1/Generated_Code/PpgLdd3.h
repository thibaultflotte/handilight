/* ###################################################################
**     This component module is generated by Processor Expert. Do not modify it.
**     Filename    : PpgLdd3.h
**     Project     : HL_K22F_0.1
**     Processor   : MK22FN512VDC12
**     Component   : PPG_LDD
**     Version     : Component 01.015, Driver 01.03, CPU db: 3.00.000
**     Repository  : Kinetis
**     Compiler    : GNU C Compiler
**     Date/Time   : 2016-12-14, 15:24, # CodeGen: 25
**     Abstract    :
**          This component implements a programmable pulse generator that
**          generates signal with variable duty and variable cycle (period).
**     Settings    :
**          Component name                                 : PpgLdd3
**          Module name                                    : FTM2
**          Counter                                        : FTM2_CNT
**          Period device                                  : FTM2_MOD
**          Duty device                                    : FTM2_C1V
**          Output pin                                     : PTB19/FTM2_CH1/I2S0_TX_FS/FBa_OE_b/FTM2_QD_PHB
**          Interrupt service/event                        : Enabled
**            Interrupt                                    : INT_FTM2
**            Interrupt priority                           : medium priority
**            Iterations before action/event               : 1
**          Period                                         : 60 Hz
**          Starting pulse width                           : 16.666412 ms
**          Initial polarity                               : high
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
**         Init            - LDD_TDeviceData* PpgLdd3_Init(LDD_TUserData *UserDataPtr);
**         Enable          - LDD_TError PpgLdd3_Enable(LDD_TDeviceData *DeviceDataPtr);
**         Disable         - LDD_TError PpgLdd3_Disable(LDD_TDeviceData *DeviceDataPtr);
**         SetPeriodUS     - LDD_TError PpgLdd3_SetPeriodUS(LDD_TDeviceData *DeviceDataPtr, uint16_t Time);
**         SetPeriodMS     - LDD_TError PpgLdd3_SetPeriodMS(LDD_TDeviceData *DeviceDataPtr, uint16_t Time);
**         SetPeriodSec    - LDD_TError PpgLdd3_SetPeriodSec(LDD_TDeviceData *DeviceDataPtr, uint16_t Time);
**         SetPeriodReal   - LDD_TError PpgLdd3_SetPeriodReal(LDD_TDeviceData *DeviceDataPtr,...
**         SetFrequencyHz  - LDD_TError PpgLdd3_SetFrequencyHz(LDD_TDeviceData *DeviceDataPtr, uint16_t...
**         SetFrequencykHz - LDD_TError PpgLdd3_SetFrequencykHz(LDD_TDeviceData *DeviceDataPtr, uint16_t...
**         SetFrequencyMHz - LDD_TError PpgLdd3_SetFrequencyMHz(LDD_TDeviceData *DeviceDataPtr, uint16_t...
**         SetRatio8       - LDD_TError PpgLdd3_SetRatio8(LDD_TDeviceData *DeviceDataPtr, uint8_t Ratio);
**         SetRatio16      - LDD_TError PpgLdd3_SetRatio16(LDD_TDeviceData *DeviceDataPtr, uint16_t Ratio);
**         SetDutyUS       - LDD_TError PpgLdd3_SetDutyUS(LDD_TDeviceData *DeviceDataPtr, uint16_t Time);
**         SetDutyMS       - LDD_TError PpgLdd3_SetDutyMS(LDD_TDeviceData *DeviceDataPtr, uint16_t Time);
**         ClearValue      - LDD_TError PpgLdd3_ClearValue(LDD_TDeviceData *DeviceDataPtr);
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
** @file PpgLdd3.h
** @version 01.03
** @brief
**          This component implements a programmable pulse generator that
**          generates signal with variable duty and variable cycle (period).
*/         
/*!
**  @addtogroup PpgLdd3_module PpgLdd3 module documentation
**  @{
*/         

#ifndef __PpgLdd3_H
#define __PpgLdd3_H

/* MODULE PpgLdd3. */

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

#define PpgLdd3_PERIOD_TICKS 0xAAABUL  /* Initial period value in ticks of the timer. */
#define PpgLdd3_PERIOD_TICKS_0 0xAAABUL /* Period value in ticks of the timer in clock configuration 0. */
#define PpgLdd3_SPUS_MIN   0x01F5U     /* Lower bound of interval for parameter of method SetPeriodUS */
#define PpgLdd3_SPUS_MAX   0x411AU     /* Upper bound of interval for parameter of method SetPeriodUS */
#define PpgLdd3_SPMS_MIN   0x01U       /* Lower bound of interval for parameter of method SetPeriodMS */
#define PpgLdd3_SPMS_MAX   0x10U       /* Upper bound of interval for parameter of method SetPeriodMS */
#define PpgLdd3_SPREAL_MIN 0.000500106812F /* Lower bound of interval for parameter of method SetPeriodReal */
#define PpgLdd3_SPREAL_MAX 0.016666793823F /* Upper bound of interval for parameter of method SetPeriodReal */
#define PpgLdd3_SFREQ_HZ_MIN 0x3CU     /* Lower bound of interval for parameter of method SetFrequencyHz */
#define PpgLdd3_SFREQ_HZ_MAX 0x07CFU   /* Upper bound of interval for parameter of method SetFrequencyHz */
#define PpgLdd3_SFREQ_KHZ_MIN 0x01U    /* Lower bound of interval for parameter of method SetFrequencykHz */
#define PpgLdd3_SFREQ_KHZ_MAX 0x01U    /* Upper bound of interval for parameter of method SetFrequencykHz */
/*! Peripheral base address of a device allocated by the component. This constant can be used directly in PDD macros. */
#define PpgLdd3_PRPH_BASE_ADDRESS  0x4003A000U
  
/*! Device data structure pointer used when auto initialization property is enabled. This constant can be passed as a first parameter to all component's methods. */
#define PpgLdd3_DeviceData  ((LDD_TDeviceData *)PE_LDD_GetDeviceStructure(PE_LDD_COMPONENT_PpgLdd3_ID))

/* Methods configuration constants - generated for all enabled component's methods */
#define PpgLdd3_Init_METHOD_ENABLED    /*!< Init method of the component PpgLdd3 is enabled (generated) */
#define PpgLdd3_Enable_METHOD_ENABLED  /*!< Enable method of the component PpgLdd3 is enabled (generated) */
#define PpgLdd3_Disable_METHOD_ENABLED /*!< Disable method of the component PpgLdd3 is enabled (generated) */
#define PpgLdd3_SetPeriodUS_METHOD_ENABLED /*!< SetPeriodUS method of the component PpgLdd3 is enabled (generated) */
#define PpgLdd3_SetPeriodMS_METHOD_ENABLED /*!< SetPeriodMS method of the component PpgLdd3 is enabled (generated) */
#define PpgLdd3_SetPeriodSec_METHOD_ENABLED /*!< SetPeriodSec method of the component PpgLdd3 is enabled (generated) */
#define PpgLdd3_SetPeriodReal_METHOD_ENABLED /*!< SetPeriodReal method of the component PpgLdd3 is enabled (generated) */
#define PpgLdd3_SetFrequencyHz_METHOD_ENABLED /*!< SetFrequencyHz method of the component PpgLdd3 is enabled (generated) */
#define PpgLdd3_SetFrequencykHz_METHOD_ENABLED /*!< SetFrequencykHz method of the component PpgLdd3 is enabled (generated) */
#define PpgLdd3_SetFrequencyMHz_METHOD_ENABLED /*!< SetFrequencyMHz method of the component PpgLdd3 is enabled (generated) */
#define PpgLdd3_SetRatio8_METHOD_ENABLED /*!< SetRatio8 method of the component PpgLdd3 is enabled (generated) */
#define PpgLdd3_SetRatio16_METHOD_ENABLED /*!< SetRatio16 method of the component PpgLdd3 is enabled (generated) */
#define PpgLdd3_SetDutyUS_METHOD_ENABLED /*!< SetDutyUS method of the component PpgLdd3 is enabled (generated) */
#define PpgLdd3_SetDutyMS_METHOD_ENABLED /*!< SetDutyMS method of the component PpgLdd3 is enabled (generated) */
#define PpgLdd3_ClearValue_METHOD_ENABLED /*!< ClearValue method of the component PpgLdd3 is enabled (generated) */

/* Events configuration constants - generated for all enabled component's events */
#define PpgLdd3_OnEnd_EVENT_ENABLED    /*!< OnEnd event of the component PpgLdd3 is enabled (generated) */



/*
** ===================================================================
**     Method      :  PpgLdd3_Init (component PPG_LDD)
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
LDD_TDeviceData* PpgLdd3_Init(LDD_TUserData *UserDataPtr);

/*
** ===================================================================
**     Method      :  PpgLdd3_Enable (component PPG_LDD)
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
LDD_TError PpgLdd3_Enable(LDD_TDeviceData *DeviceDataPtr);

/*
** ===================================================================
**     Method      :  PpgLdd3_Disable (component PPG_LDD)
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
LDD_TError PpgLdd3_Disable(LDD_TDeviceData *DeviceDataPtr);

/*
** ===================================================================
**     Method      :  PpgLdd3_SetPeriodUS (component PPG_LDD)
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
LDD_TError PpgLdd3_SetPeriodUS(LDD_TDeviceData *DeviceDataPtr, uint16_t Time);

/*
** ===================================================================
**     Method      :  PpgLdd3_SetPeriodMS (component PPG_LDD)
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
LDD_TError PpgLdd3_SetPeriodMS(LDD_TDeviceData *DeviceDataPtr, uint16_t Time);

/*
** ===================================================================
**     Method      :  PpgLdd3_SetPeriodSec (component PPG_LDD)
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
LDD_TError PpgLdd3_SetPeriodSec(LDD_TDeviceData *DeviceDataPtr, uint16_t Time);

/*
** ===================================================================
**     Method      :  PpgLdd3_SetPeriodReal (component PPG_LDD)
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
LDD_TError PpgLdd3_SetPeriodReal(LDD_TDeviceData *DeviceDataPtr, LDD_PPG_Tfloat Time);

/*
** ===================================================================
**     Method      :  PpgLdd3_SetFrequencyHz (component PPG_LDD)
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
LDD_TError PpgLdd3_SetFrequencyHz(LDD_TDeviceData *DeviceDataPtr, uint16_t Frequency);

/*
** ===================================================================
**     Method      :  PpgLdd3_SetFrequencykHz (component PPG_LDD)
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
LDD_TError PpgLdd3_SetFrequencykHz(LDD_TDeviceData *DeviceDataPtr, uint16_t Frequency);

/*
** ===================================================================
**     Method      :  PpgLdd3_SetFrequencyMHz (component PPG_LDD)
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
LDD_TError PpgLdd3_SetFrequencyMHz(LDD_TDeviceData *DeviceDataPtr, uint16_t Frequency);

/*
** ===================================================================
**     Method      :  PpgLdd3_SetRatio8 (component PPG_LDD)
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
LDD_TError PpgLdd3_SetRatio8(LDD_TDeviceData *DeviceDataPtr, uint8_t Ratio);

/*
** ===================================================================
**     Method      :  PpgLdd3_SetRatio16 (component PPG_LDD)
*/
/*!
**     @brief
**         This method sets a new duty-cycle ratio. Ratio is expressed
**         as a 16-bit unsigned integer number. 0 - FFFF value is
**         proportional to ratio 0 - 100%. The method is available
**         only if it is not selected list of predefined values in
**         [Starting pulse width] property. 
**         Note: Calculated duty depends on the timer possibilities and
**         on the selected period.
**     @param
**         DeviceDataPtr   - Device data structure
**                           pointer returned by [Init] method.
**     @param
**         Ratio           - Ratio to set. 0 - 65535 value is
**                           proportional to ratio 0 - 100%
**     @return
**                         - Error code, possible codes:
**                           ERR_OK - OK
**                           ERR_SPEED - The component does not work in
**                           the active clock configuration
*/
/* ===================================================================*/
LDD_TError PpgLdd3_SetRatio16(LDD_TDeviceData *DeviceDataPtr, uint16_t Ratio);

/*
** ===================================================================
**     Method      :  PpgLdd3_SetDutyUS (component PPG_LDD)
*/
/*!
**     @brief
**         This method sets the new duty value of the output signal.
**         The duty is expressed in microseconds as a 16-bit unsigned
**         integer number. The method is available only if it is not
**         selected list of predefined values in [Starting pulse width]
**         property.
**     @param
**         DeviceDataPtr   - Device data structure
**                           pointer returned by [Init] method.
**     @param
**         Time            - Duty to set [in microseconds]
**     @return
**                         - Error code, possible codes:
**                           ERR_OK - OK
**                           ERR_SPEED - The component does not work in
**                           the active clock configuration
**                           ERR_MATH - Overflow during evaluation
**                           ERR_PARAM_RANGE - Parameter out of range
*/
/* ===================================================================*/
LDD_TError PpgLdd3_SetDutyUS(LDD_TDeviceData *DeviceDataPtr, uint16_t Time);

/*
** ===================================================================
**     Method      :  PpgLdd3_SetDutyMS (component PPG_LDD)
*/
/*!
**     @brief
**         This method sets the new duty value of the output signal.
**         The duty is expressed in milliseconds as a 16-bit unsigned
**         integer number. The method is available only if it is not
**         selected list of predefined values in [Starting pulse width]
**         property.
**     @param
**         DeviceDataPtr   - Device data structure
**                           pointer returned by [Init] method.
**     @param
**         Time            - Duty to set [in milliseconds]
**     @return
**                         - Error code, possible codes:
**                           ERR_OK - OK
**                           ERR_SPEED - The component does not work in
**                           the active clock configuration
**                           ERR_MATH - Overflow during evaluation
**                           ERR_PARAM_RANGE - Parameter out of range
*/
/* ===================================================================*/
LDD_TError PpgLdd3_SetDutyMS(LDD_TDeviceData *DeviceDataPtr, uint16_t Time);

/*
** ===================================================================
**     Method      :  PpgLdd3_ClearValue (component PPG_LDD)
*/
/*!
**     @brief
**         This method clears (set to "0" = "Low") timer flip-flop
**         output signal level. It allows to the user to directly set
**         the output pin value (=flip-flop state), and can set the
**         signal polarity. This method only works when the timer is
**         disabled ([Disable] otherwise it returns the error code.
**         [ClearValue] and [SetValue] methods are used for setting the
**         initial state.
**     @param
**         DeviceDataPtr   - Device data structure
**                           pointer returned by [Init] method.
**     @return
**                         - Error code, possible codes:
**                           ERR_OK - OK
**                           ERR_SPEED - The component does not work in
**                           the active clock configuration
**                           ERR_ENABLED - Component is enabled.
**                           Component must be disabled (see "Disable
**                           method")
*/
/* ===================================================================*/
LDD_TError PpgLdd3_ClearValue(LDD_TDeviceData *DeviceDataPtr);

/*
** ===================================================================
**     Method      :  PpgLdd3_Interrupt (component PPG_LDD)
**
**     Description :
**         The method services the interrupt of the selected peripheral(s)
**         and eventually invokes event(s) of the component.
**         This method is internal. It is used by Processor Expert only.
** ===================================================================
*/
/* {Default RTOS Adapter} ISR function prototype */
PE_ISR(PpgLdd3_Interrupt);

/* END PpgLdd3. */

#ifdef __cplusplus
}  /* extern "C" */
#endif 

#endif 
/* ifndef __PpgLdd3_H */
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