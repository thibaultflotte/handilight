/* ###################################################################
**     Filename    : main.c
**     Project     : HL_K22F_0.1
**     Processor   : MK22FN512VDC12
**     Version     : Driver 01.01
**     Compiler    : GNU C Compiler
**     Date/Time   : 2016-12-08, 18:14, # CodeGen: 0
**     Abstract    :
**         Main module.
**         This module contains user's application code.
**     Settings    :
**     Contents    :
**         No public methods
**
** ###################################################################*/
/*!
** @file main.c
** @version 01.01
** @brief
**         Main module.
**         This module contains user's application code.
*/         
/*!
**  @addtogroup main_module main module documentation
**  @{
*/         
/* MODULE main */


/* Including needed modules to compile this module/procedure */
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
/* Including shared modules, which are used for whole project */
#include "PE_Types.h"
#include "PE_Error.h"
#include "PE_Const.h"
#include "IO_Map.h"
#include "PDD_Includes.h"
#include "Init_Config.h"
/* User includes (#include below this line is not maintained by Processor Expert) */
#include "SendData.h"

/*lint -save  -e970 Disable MISRA rule (6.3) checking. */
int main(void)
/*lint -restore Enable MISRA rule (6.3) checking. */
{
  /* Write your local variable definition here */

  /*** Processor Expert internal initialization. DON'T REMOVE THIS CODE!!! ***/
  PE_low_level_init();
  /*** End of Processor Expert internal initialization.                    ***/

  /* Write your code here */
  /* For example: for(;;) { } */

/************************* PARTIE BLUETOOTH ***********************************/
  char testsensor[]="";
  char dataSend[]="";
  unsigned char receiveChar = 0;
  uint16_t intensity;
  short inten;
  uint8_t lumiref;
  uint8_t lumi;
  uint16_t freq;
  LEDVerte_Disable();
  LEDBlanche_Disable();
  LEDRouge_Disable();
  while (receiveChar != 'W') {
	  BT1_RecvChar(&receiveChar);		//Tant qu'on a pas de W on essaye de recevoir
  }
  /* Capteur de Luminosite */
  (void)AD2_Measure(TRUE);
  (void)AD2_GetValue8(&lumiref);
/* contenu de la trame presence */
  char sensorInitial[] = "";
  sensorInitial[0] = 0x27;	//On définit les différents états des composants
  sensorInitial[1] = 0x4B;
  sensorInitial[2] = 0x64;	//Pas câblé
  sensorInitial[3] = 0x84;
  sensorInitial[4] = 0xA4;
  sensorInitial[5] = 0xC4;
  sensorInitial[6] = 0xF5;	//défectueux
  BT1_SendChar('S');		//On envoie la table de présence
  for (int l = 0; l < 7; l++) {
	  BT1_SendChar(sensorInitial[l]);
	  WAIT1_Waitms(1);
  }
  BT1_SendChar('E');
  WAIT1_Waitms(3000);
  char inputDatas[15];
  int i;
  while (receiveChar != 'B') {
	  BT1_RecvChar(&receiveChar);// La tablette envoie "B" -> Trame présence Bien reçu
  if(receiveChar == 'B')
  {
	  LED1_On();
	  WAIT1_Waitms(500);
	  LED1_Off();
  }
  while (receiveChar != 'X') {		//Si on a un X le programme s'arrête totalement
  		BT1_RecvChar(&receiveChar);
  		while (receiveChar != 'S') {
  			  BT1_RecvChar(&receiveChar);//Tant qu'on a pas de S on essaye de recevoir
  		}
  		if(receiveChar == 'S'){		//Si un S la trame commence
  			uint8_t lumi;
  			for (i = 0; i < 15; i++) {
  				WAIT1_Waitms(1);
  				receiveChar = ERR_RXEMPTY;		//On nettoie le buffer pour avoir une réception simple et ne pas recevoir un char en plusieurs fois
  				while(receiveChar == ERR_RXEMPTY){		//Si rien de nouveau reçu on relance une réception
  					BT1_RecvChar(&receiveChar);
  				}
  				if (receiveChar == 'E'){	//Si char E alors la réception est terminée
  					break; //On sort de la réception
  				}
  				inputDatas[i] = receiveChar;	//On met les données dans un buffer de données
  				freq=(( (inputDatas[1]) <<8 | (inputDatas[2]) ));
  				WAIT1_Waitms(1);

  				if(inputDatas[0]==0x00){
  					LEDRouge_Enable();
  					LEDRouge_SetRatio8(255 - ((inputDatas[3]*255)/100));
  					LEDRouge_SetFreqHz(freq);
 					LED1_On();
  				 }
  				 if(inputDatas[0]==0x02){
  					LEDVerte_Enable();
  					LEDVerte_SetRatio8(255 - ((inputDatas[3]*255)/100));
  					LEDVerte_SetFreqHz(freq);
  					LED1_On();
  				 }
  				 if(inputDatas[0]==0x03){
  					LEDBlanche_Enable();
  					LEDBlanche_SetRatio8(255 - ((inputDatas[3]*255)/100));
  					LEDBlanche_SetFreqHz(freq);
  					LED1_On();
  				 }
  			}
  		}
  		for(int i=0; i<500; i++){
  	  		sendData();
  	  	(void)AD2_Measure(TRUE);
  	  	(void)AD2_GetValue8(&lumi);
  	  inten = 255 - ((inputDatas[3]*255)/100)+(lumi-lumiref);
  	  if (inten <= 0){
  		  intensity = 0;
  	  }
  	  else if (inten > 0 && inten<255){
  		  intensity = inten;
  	  }
  	  else intensity= 255;

  	  	if(inputDatas[0]==0x00){
  	  	  	LEDRouge_Enable();
  	  	  	LEDRouge_SetRatio8(intensity);
  	  	  	LED1_On();
  	  	}
  	  	if(inputDatas[0]==0x02){
  	  		LEDVerte_Enable();
  	  		LEDVerte_SetRatio8(intensity);
  	  		LED1_On();
  	  	}
  	  	if(inputDatas[0]==0x03){
  	  		LEDBlanche_Enable();
  	  		LEDBlanche_SetRatio8(intensity);
  	  		LED1_On();
  	  	}
  	  	WAIT1_Waitms(1);
  		}
  }
  LEDVerte_Disable();
  LED1_Off();
  }
  /*** Don't write any code pass this line, or it will be deleted during code generation. ***/
  /*** RTOS startup code. Macro PEX_RTOS_START is defined by the RTOS component. DON'T MODIFY THIS CODE!!! ***/
  #ifdef PEX_RTOS_START
    PEX_RTOS_START();                  /* Startup of the selected RTOS. Macro is defined by the RTOS component. */
  #endif
  /*** End of RTOS startup code.  ***/
  /*** Processor Expert end of main routine. DON'T MODIFY THIS CODE!!! ***/
  for(;;){}
  /*** Processor Expert end of main routine. DON'T WRITE CODE BELOW!!! ***/
} /*** End of main routine. DO NOT MODIFY THIS TEXT!!! ***/

/* END main */
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
