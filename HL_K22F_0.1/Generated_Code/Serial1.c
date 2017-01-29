/* ###################################################################
**     This component module is generated by Processor Expert. Do not modify it.
**     Filename    : Serial1.c
**     Project     : HL_K22F_0.1
**     Processor   : MK22FN512VDC12
**     Component   : AsynchroSerial
**     Version     : Component 02.611, Driver 01.01, CPU db: 3.00.000
**     Repository  : Kinetis
**     Compiler    : GNU C Compiler
**     Date/Time   : 2016-12-08, 18:56, # CodeGen: 3
**     Abstract    :
**         This component "AsynchroSerial" implements an asynchronous serial
**         communication. The component supports different settings of
**         parity, word width, stop-bit and communication speed,
**         user can select interrupt or polling handler.
**         Communication speed can be changed also in runtime.
**         The component requires one on-chip asynchronous serial channel.
**     Settings    :
**          Component name                                 : Serial1
**          Channel                                        : UART2
**          Interrupt service/event                        : Enabled
**            Interrupt RxD                                : INT_UART2_RX_TX
**            Interrupt RxD priority                       : medium priority
**            Interrupt TxD                                : INT_UART2_RX_TX
**            Interrupt TxD priority                       : medium priority
**            Interrupt Error                              : INT_UART2_ERR
**            Interrupt Error priority                     : medium priority
**            Input buffer size                            : 64
**            Output buffer size                           : 64
**            Handshake                                    : 
**              CTS                                        : Disabled
**              RTS                                        : Disabled
**          Settings                                       : 
**            Parity                                       : none
**            Width                                        : 8 bits
**            Stop bit                                     : 1
**            Receiver                                     : Enabled
**              RxD                                        : PTD2/LLWU_P13/SPI0_SOUT/UART2_RX/FTM3_CH2/FBa_AD4/LPUART0_RX/I2C0_SCL
**            Transmitter                                  : Enabled
**              TxD                                        : PTD3/SPI0_SIN/UART2_TX/FTM3_CH3/FBa_AD3/LPUART0_TX/I2C0_SDA
**            Baud rate                                    : 9600 baud
**            Break signal                                 : Disabled
**            Wakeup condition                             : Idle line wakeup
**            Transmitter output                           : Not inverted
**            Receiver input                               : Not inverted
**            Stop in wait mode                            : no
**            Idle line mode                               : starts after start bit
**            Break generation length                      : Short
**          Initialization                                 : 
**            Enabled in init. code                        : yes
**            Events enabled in init.                      : yes
**          CPU clock/speed selection                      : 
**            High speed mode                              : This component enabled
**            Low speed mode                               : This component disabled
**            Slow speed mode                              : This component disabled
**          Referenced components                          : 
**            Serial_LDD                                   : Serial_LDD
**     Contents    :
**         RecvChar        - byte Serial1_RecvChar(Serial1_TComData *Chr);
**         SendChar        - byte Serial1_SendChar(Serial1_TComData Chr);
**         RecvBlock       - byte Serial1_RecvBlock(Serial1_TComData *Ptr, word Size, word *Rcv);
**         SendBlock       - byte Serial1_SendBlock(Serial1_TComData *Ptr, word Size, word *Snd);
**         ClearRxBuf      - byte Serial1_ClearRxBuf(void);
**         ClearTxBuf      - byte Serial1_ClearTxBuf(void);
**         GetCharsInRxBuf - word Serial1_GetCharsInRxBuf(void);
**         GetCharsInTxBuf - word Serial1_GetCharsInTxBuf(void);
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
** @file Serial1.c
** @version 01.01
** @brief
**         This component "AsynchroSerial" implements an asynchronous serial
**         communication. The component supports different settings of
**         parity, word width, stop-bit and communication speed,
**         user can select interrupt or polling handler.
**         Communication speed can be changed also in runtime.
**         The component requires one on-chip asynchronous serial channel.
*/         
/*!
**  @addtogroup Serial1_module Serial1 module documentation
**  @{
*/         

/* MODULE Serial1. */

#include "Serial1.h"

#ifdef __cplusplus
extern "C" {
#endif 


#define OVERRUN_ERR      0x01U         /* Overrun error flag bit    */
#define FRAMING_ERR      0x02U         /* Framing error flag bit    */
#define PARITY_ERR       0x04U         /* Parity error flag bit     */
#define CHAR_IN_RX       0x08U         /* Char is in RX buffer      */
#define FULL_TX          0x10U         /* Full transmit buffer      */
#define RUNINT_FROM_TX   0x20U         /* Interrupt is in progress  */
#define FULL_RX          0x40U         /* Full receive buffer       */
#define NOISE_ERR        0x80U         /* Noise error flag bit      */
#define IDLE_ERR         0x0100U       /* Idle character flag bit   */
#define BREAK_ERR        0x0200U       /* Break detect              */
#define COMMON_ERR       0x0800U       /* Common error of RX       */

LDD_TDeviceData *ASerialLdd1_DeviceDataPtr; /* Device data pointer */
static word SerFlag;                   /* Flags for serial communication */
                                       /* Bits: 0 - OverRun error */
                                       /*       1 - Framing error */
                                       /*       2 - Parity error */
                                       /*       3 - Char in RX buffer */
                                       /*       4 - Full TX buffer */
                                       /*       5 - Running int from TX */
                                       /*       6 - Full RX buffer */
                                       /*       7 - Noise error */
                                       /*       8 - Idle character  */
                                       /*       9 - Break detected  */
                                       /*      10 - Unused */
                                       /*      11 - Unused */
static word Serial1_InpLen;            /* Length of input buffer's content */
static word InpIndexR;                 /* Index for reading from input buffer */
static word InpIndexW;                 /* Index for writing to input buffer */
static Serial1_TComData InpBuffer[Serial1_INP_BUF_SIZE]; /* Input buffer for SCI communication */
static Serial1_TComData BufferRead;    /* Input char for SCI communication */
static word Serial1_OutLen;            /* Length of output bufer's content */
static word OutIndexR;                 /* Index for reading from output buffer */
static word OutIndexW;                 /* Index for writing to output buffer */
static Serial1_TComData OutBuffer[Serial1_OUT_BUF_SIZE]; /* Output buffer for SCI communication */

/*
** ===================================================================
**     Method      :  HWEnDi (component AsynchroSerial)
**
**     Description :
**         Enables or disables the peripheral(s) associated with the bean.
**         The method is called automatically as a part of the Enable and 
**         Disable methods and several internal methods.
**         This method is internal. It is used by Processor Expert only.
** ===================================================================
*/
static void HWEnDi(void)
{
  (void)ASerialLdd1_ReceiveBlock(ASerialLdd1_DeviceDataPtr, &BufferRead, 1U); /* Receive one data byte */
}

/*
** ===================================================================
**     Method      :  Serial1_RecvChar (component AsynchroSerial)
**     Description :
**         If any data is received, this method returns one character,
**         otherwise it returns an error code (it does not wait for
**         data). This method is enabled only if the receiver property
**         is enabled.
**         [Note:] Because the preferred method to handle error and
**         break exception in the interrupt mode is to use events
**         <OnError> and <OnBreak> the return value ERR_RXEMPTY has
**         higher priority than other error codes. As a consequence the
**         information about an exception in interrupt mode is returned
**         only if there is a valid character ready to be read.
**     Parameters  :
**         NAME            - DESCRIPTION
**       * Chr             - Pointer to a received character
**     Returns     :
**         ---             - Error code, possible codes:
**                           ERR_OK - OK
**                           ERR_SPEED - This device does not work in
**                           the active speed mode
**                           ERR_RXEMPTY - No data in receiver
**                           ERR_BREAK - Break character is detected
**                           (only when the <Interrupt service> property
**                           is disabled and the <Break signal> property
**                           is enabled)
**                           ERR_COMMON - common error occurred (the
**                           <GetError> method can be used for error
**                           specification)
** ===================================================================
*/
byte Serial1_RecvChar(Serial1_TComData *Chr)
{
  byte Result = ERR_OK;                /* Return error code */

  if (Serial1_InpLen > 0x00U) {        /* Is number of received chars greater than 0? */
    EnterCritical();                   /* Disable global interrupts */
    Serial1_InpLen--;                  /* Decrease number of received chars */
    *Chr = InpBuffer[InpIndexR++];     /* Received char */
    if (InpIndexR >= Serial1_INP_BUF_SIZE) { /* Is the index out of the receive buffer? */
      InpIndexR = 0x00U;               /* Set index to the first item into the receive buffer */
    }
    Result = (byte)((SerFlag & (OVERRUN_ERR|COMMON_ERR|FULL_RX))? ERR_COMMON : ERR_OK);
    SerFlag &= (word)~(word)(OVERRUN_ERR|COMMON_ERR|FULL_RX|CHAR_IN_RX); /* Clear all errors in the status variable */
    ExitCritical();                    /* Enable global interrupts */
  } else {
    return ERR_RXEMPTY;                /* Receiver is empty */
  }
  return Result;                       /* Return error code */
}

/*
** ===================================================================
**     Method      :  Serial1_SendChar (component AsynchroSerial)
**     Description :
**         Sends one character to the channel. If the component is
**         temporarily disabled (Disable method) SendChar method only
**         stores data into an output buffer. In case of a zero output
**         buffer size, only one character can be stored. Enabling the
**         component (Enable method) starts the transmission of the
**         stored data. This method is available only if the
**         transmitter property is enabled.
**     Parameters  :
**         NAME            - DESCRIPTION
**         Chr             - Character to send
**     Returns     :
**         ---             - Error code, possible codes:
**                           ERR_OK - OK
**                           ERR_SPEED - This device does not work in
**                           the active speed mode
**                           ERR_TXFULL - Transmitter is full
** ===================================================================
*/
byte Serial1_SendChar(Serial1_TComData Chr)
{
  if (Serial1_OutLen == Serial1_OUT_BUF_SIZE) { /* Is number of chars in buffer is the same as a size of the transmit buffer */
    return ERR_TXFULL;                 /* If yes then error */
  }
  EnterCritical();                     /* Disable global interrupts */
  Serial1_OutLen++;                    /* Increase number of bytes in the transmit buffer */
  OutBuffer[OutIndexW++] = Chr;        /* Store char to buffer */
  if (OutIndexW >= Serial1_OUT_BUF_SIZE) { /* Is the pointer out of the transmit buffer */
    OutIndexW = 0x00U;                 /* Set index to first item in the transmit buffer */
  }
  if ((SerFlag & RUNINT_FROM_TX) == 0U) {
    SerFlag |= RUNINT_FROM_TX;         /* Set flag "running int from TX"? */
    (void)ASerialLdd1_SendBlock(ASerialLdd1_DeviceDataPtr, (LDD_TData *)&OutBuffer[OutIndexR], 1U); /* Send one data byte */
  }
  ExitCritical();                      /* Enable global interrupts */
  return ERR_OK;                       /* OK */
}

/*
** ===================================================================
**     Method      :  Serial1_RecvBlock (component AsynchroSerial)
**     Description :
**         If any data is received, this method returns the block of
**         the data and its length (and incidental error), otherwise it
**         returns an error code (it does not wait for data).
**         This method is available only if non-zero length of the
**         input buffer is defined and the receiver property is enabled.
**         If less than requested number of characters is received only
**         the available data is copied from the receive buffer to the
**         user specified destination. The value ERR_EXEMPTY is
**         returned and the value of variable pointed by the Rcv
**         parameter is set to the number of received characters.
**     Parameters  :
**         NAME            - DESCRIPTION
**       * Ptr             - Pointer to the block of received data
**         Size            - Size of the block
**       * Rcv             - Pointer to real number of the received data
**     Returns     :
**         ---             - Error code, possible codes:
**                           ERR_OK - OK
**                           ERR_SPEED - This device does not work in
**                           the active speed mode
**                           ERR_RXEMPTY - The receive buffer didn't
**                           contain the requested number of data. Only
**                           available data has been returned.
**                           ERR_COMMON - common error occurred (the
**                           GetError method can be used for error
**                           specification)
** ===================================================================
*/
byte Serial1_RecvBlock(Serial1_TComData *Ptr, word Size, word *Rcv)
{
  register word count;                 /* Number of received chars */
  register byte result = ERR_OK;       /* Last error */

  for (count = 0x00U; count < Size; count++) {
    switch (Serial1_RecvChar(Ptr++)) { /* Receive data and test the return value*/
    case ERR_RXEMPTY:                  /* No data in the buffer */
      if (result == ERR_OK) {          /* If no receiver error reported */
        result = ERR_RXEMPTY;          /* Return info that requested number of data is not available */
      }
     *Rcv = count;                     /* Return number of received chars */
      return result;
    case ERR_COMMON:                   /* Receiver error reported */
      result = ERR_COMMON;             /* Return info that an error was detected */
      break;
    default:
      break;
    }
  }
  *Rcv = count;                        /* Return number of received chars */
  return result;                       /* OK */
}

/*
** ===================================================================
**     Method      :  Serial1_SendBlock (component AsynchroSerial)
**     Description :
**         Sends a block of characters to the channel.
**         This method is available only if non-zero length of the
**         output buffer is defined and the transmitter property is
**         enabled.
**     Parameters  :
**         NAME            - DESCRIPTION
**       * Ptr             - Pointer to the block of data to send
**         Size            - Size of the block
**       * Snd             - Pointer to number of data that are sent
**                           (moved to buffer)
**     Returns     :
**         ---             - Error code, possible codes:
**                           ERR_OK - OK
**                           ERR_SPEED - This device does not work in
**                           the active speed mode
**                           ERR_TXFULL - It was not possible to send
**                           requested number of bytes
** ===================================================================
*/
byte Serial1_SendBlock(Serial1_TComData *Ptr, word Size, word *Snd)
{
  word count = 0x00U;                  /* Number of sent chars */
  Serial1_TComData *TmpPtr = Ptr;      /* Temporary output buffer pointer */

  while ((count < Size) && (Serial1_OutLen < Serial1_OUT_BUF_SIZE)) { /* While there is some char desired to send left and output buffer is not full do */
    EnterCritical();                   /* Enter the critical section */
    Serial1_OutLen++;                  /* Increase number of bytes in the transmit buffer */
    OutBuffer[OutIndexW++] = *TmpPtr++; /* Store char to buffer */
    if (OutIndexW >= Serial1_OUT_BUF_SIZE) { /* Is the index out of the transmit buffer? */
      OutIndexW = 0x00U;               /* Set index to the first item in the transmit buffer */
    }
    count++;                           /* Increase the count of sent data */
    if ((SerFlag & RUNINT_FROM_TX) == 0U) {
      SerFlag |= RUNINT_FROM_TX;       /* Set flag "running int from TX"? */
      (void)ASerialLdd1_SendBlock(ASerialLdd1_DeviceDataPtr, (LDD_TData *)&OutBuffer[OutIndexR], 1U); /* Send one data byte */
    }
    ExitCritical();                    /* Exit the critical section */
  }
  *Snd = count;                        /* Return number of sent chars */
  if (count != Size) {                 /* Is the number of sent chars less then desired number of chars */
    return ERR_TXFULL;                 /* If yes then error */
  }
  return ERR_OK;                       /* OK */
}

/*
** ===================================================================
**     Method      :  Serial1_ClearRxBuf (component AsynchroSerial)
**     Description :
**         Clears the receive buffer.
**         This method is available only if non-zero length of the
**         input buffer is defined and the receiver property is enabled.
**     Parameters  : None
**     Returns     :
**         ---             - Error code, possible codes:
**                           ERR_OK - OK
**                           ERR_SPEED - This device does not work in
**                           the active speed mode
** ===================================================================
*/
byte Serial1_ClearRxBuf(void)
{
  EnterCritical();                     /* Disable global interrupts */
  Serial1_InpLen = 0x00U;              /* Set number of chars in the transmit buffer to 0 */
  InpIndexW = 0x00U;                   /* Set index on the first item in the transmit buffer */
  InpIndexR = 0x00U;
  ExitCritical();                      /* Enable global interrupts */
  return ERR_OK;                       /* OK */
}

/*
** ===================================================================
**     Method      :  Serial1_ClearTxBuf (component AsynchroSerial)
**     Description :
**         Clears the transmit buffer.
**         This method is available only if non-zero length of the
**         output buffer is defined and the receiver property is
**         enabled.
**     Parameters  : None
**     Returns     :
**         ---             - Error code, possible codes:
**                           ERR_OK - OK
**                           ERR_SPEED - This device does not work in
**                           the active speed mode
** ===================================================================
*/
byte Serial1_ClearTxBuf(void)
{
  EnterCritical();                     /* Disable global interrupts */
  Serial1_OutLen = 0x00U;              /* Set number of chars in the receive buffer to 0 */
  OutIndexW = 0x00U;                   /* Set index on the first item in the receive buffer */
  OutIndexR = 0x00U;
  ExitCritical();                      /* Enable global interrupts */
  return ERR_OK;                       /* OK */
}

/*
** ===================================================================
**     Method      :  Serial1_GetCharsInRxBuf (component AsynchroSerial)
**     Description :
**         Returns the number of characters in the input buffer. This
**         method is available only if the receiver property is enabled.
**     Parameters  : None
**     Returns     :
**         ---             - The number of characters in the input
**                           buffer.
** ===================================================================
*/
word Serial1_GetCharsInRxBuf(void)
{
  return Serial1_InpLen;               /* Return number of chars in receive buffer */
}

/*
** ===================================================================
**     Method      :  Serial1_GetCharsInTxBuf (component AsynchroSerial)
**     Description :
**         Returns the number of characters in the output buffer. This
**         method is available only if the transmitter property is
**         enabled.
**     Parameters  : None
**     Returns     :
**         ---             - The number of characters in the output
**                           buffer.
** ===================================================================
*/
word Serial1_GetCharsInTxBuf(void)
{
  return Serial1_OutLen;               /* Return number of chars in the transmitter buffer */
}

/*
** ===================================================================
**     Method      :  Serial1_Init (component AsynchroSerial)
**
**     Description :
**         Initializes the associated peripheral(s) and the bean internal 
**         variables. The method is called automatically as a part of the 
**         application initialization code.
**         This method is internal. It is used by Processor Expert only.
** ===================================================================
*/
void Serial1_Init(void)
{
  SerFlag = 0x00U;                     /* Reset flags */
  Serial1_InpLen = 0x00U;              /* No char in the receive buffer */
  InpIndexR = 0x00U;                   /* Set index on the first item in the receive buffer */
  InpIndexW = 0x00U;
  Serial1_OutLen = 0x00U;              /* No char in the transmit buffer */
  OutIndexR = 0x00U;                   /* Set index on the first item in the transmit buffer */
  OutIndexW = 0x00U;
  ASerialLdd1_DeviceDataPtr = ASerialLdd1_Init(NULL); /* Calling init method of the inherited component */
  HWEnDi();                            /* Enable/disable device according to status flags */
}

#define ON_ERROR    0x01U
#define ON_FULL_RX  0x02U
#define ON_RX_CHAR  0x04U
/*
** ===================================================================
**     Method      :  Serial1_ASerialLdd1_OnBlockReceived (component AsynchroSerial)
**
**     Description :
**         This event is called when the requested number of data is 
**         moved to the input buffer.
**         This method is internal. It is used by Processor Expert only.
** ===================================================================
*/
void ASerialLdd1_OnBlockReceived(LDD_TUserData *UserDataPtr)
{

  (void)UserDataPtr;                   /* Parameter is not used, suppress unused argument warning */
  if (Serial1_InpLen < Serial1_INP_BUF_SIZE) { /* Is number of bytes in the receive buffer lower than size of buffer? */
    Serial1_InpLen++;                  /* Increase number of chars in the receive buffer */
    InpBuffer[InpIndexW++] = (Serial1_TComData)BufferRead; /* Save received char to the receive buffer */
    if (InpIndexW >= Serial1_INP_BUF_SIZE) { /* Is the index out of the receive buffer? */
      InpIndexW = 0x00U;               /* Set index on the first item into the receive buffer */
    }
  } else {
    SerFlag |= FULL_RX;                /* Set flag "full RX buffer" */
  }
  (void)ASerialLdd1_ReceiveBlock(ASerialLdd1_DeviceDataPtr, &BufferRead, 1U); /* Receive one data byte */
}

#define ON_FREE_TX  0x01U
#define ON_TX_CHAR  0x02U
/*
** ===================================================================
**     Method      :  Serial1_ASerialLdd1_OnBlockSent (component AsynchroSerial)
**
**     Description :
**         This event is called after the last character from the output 
**         buffer is moved to the transmitter.
**         This method is internal. It is used by Processor Expert only.
** ===================================================================
*/
void ASerialLdd1_OnBlockSent(LDD_TUserData *UserDataPtr)
{
  (void)UserDataPtr;                   /* Parameter is not used, suppress unused argument warning */
  OutIndexR++;
  if (OutIndexR >= Serial1_OUT_BUF_SIZE) { /* Is the index out of the transmit buffer? */
    OutIndexR = 0x00U;                 /* Set index on the first item into the transmit buffer */
  }
  Serial1_OutLen--;                    /* Decrease number of chars in the transmit buffer */
  if (Serial1_OutLen != 0U) {          /* Is number of bytes in the transmit buffer greater then 0? */
    SerFlag |= RUNINT_FROM_TX;         /* Set flag "running int from TX"? */
    (void)ASerialLdd1_SendBlock(ASerialLdd1_DeviceDataPtr, (LDD_TData *)&OutBuffer[OutIndexR], 1U); /* Send one data byte */
  } else {
    SerFlag &= (byte)~(RUNINT_FROM_TX); /* Clear "running int from TX" and "full TX buff" flags */
  }
}

/*
** ===================================================================
**     Method      :  Serial1_ASerialLdd1_OnError (component AsynchroSerial)
**
**     Description :
**         This event is called when a channel error (not the error 
**         returned by a given method) occurs.
**         This method is internal. It is used by Processor Expert only.
** ===================================================================
*/
void ASerialLdd1_OnError(LDD_TUserData *UserDataPtr)
{
  LDD_SERIAL_TError SerialErrorMask;   /* Serial error mask variable */

  (void)UserDataPtr;                   /* Parameter is not used, suppress unused argument warning */
  (void)ASerialLdd1_GetError(ASerialLdd1_DeviceDataPtr, &SerialErrorMask); /* Get error state */
  if (SerialErrorMask != 0U) {
    SerFlag |= (((SerialErrorMask & LDD_SERIAL_PARITY_ERROR) != 0U ) ? PARITY_ERR : 0U);
    SerFlag |= (((SerialErrorMask & LDD_SERIAL_NOISE_ERROR) != 0U ) ? NOISE_ERR : 0U);
    SerFlag |= (((SerialErrorMask & LDD_SERIAL_RX_OVERRUN) != 0U ) ? OVERRUN_ERR : 0U);
    SerFlag |= (((SerialErrorMask & LDD_SERIAL_FRAMING_ERROR) != 0U ) ? FRAMING_ERR : 0U);
  }
}

/*
** ===================================================================
**     Method      :  Serial1_ASerialLdd1_OnBreak (component AsynchroSerial)
**
**     Description :
**         This event is called when a break occurs on the input channel.
**         This method is internal. It is used by Processor Expert only.
** ===================================================================
*/
void ASerialLdd1_OnBreak(LDD_TUserData *UserDataPtr)
{
  (void)UserDataPtr;                   /* Parameter is not used, suppress unused argument warning */
  SerFlag |= FRAMING_ERR;              /* Set framing error flag */
}


/* END Serial1. */

#ifdef __cplusplus
}  /* extern "C" */
#endif 

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
