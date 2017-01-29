/* ###################################################################
**     Filename    : main.c
**     Project     : Handilight_0.1
**     Processor   : MK20DX128VLH5
**     Version     : Driver 01.01
**     Compiler    : GNU C Compiler
**     Date/Time   : 2016-12-07, 17:29, # CodeGen: 0
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
#include "BT1.h"
#include "Serial1.h"
#include "ASerialLdd1.h"
#include "UTIL1.h"
#include "WAIT1.h"
#include "CLS1.h"
#include "KSDK1.h"
#include "CS1.h"
#include "LED1.h"
#include "LEDpin1.h"
#include "BitIoLdd1.h"
#include "LED2.h"
#include "LEDpin2.h"
#include "BitIoLdd2.h"
#include "PPG1.h"
#include "PpgLdd1.h"
/* Including shared modules, which are used for whole project */
#include "PE_Types.h"
#include "PE_Error.h"
#include "PE_Const.h"
#include "IO_Map.h"
/* User includes (#include below this line is not maintained by Processor Expert) */

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
  char testsensor[]="";
  unsigned char receiveChar = 0;
  while (receiveChar != 'W') {
	  BT1_RecvChar(&receiveChar);		//Tant qu'on a pas de W on essaye de recevoir
  }
/* contenu de la trame presence */
  char sensorInitial[] = "";
  sensorInitial[0] = 0x24;	//On définit les différents états des composants
  sensorInitial[1] = 0x48;
  sensorInitial[2] = 0x67;	//Pas câblé
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
	  BT1_RecvChar(&receiveChar);		//Tant qu'on a pas de W on essaye de recevoir
  }
  if(receiveChar == 'B')
  {
	  LED1_On(); //-> Turquoise
	  WAIT1_Waitms(1000);
	  LED1_Off();
  }
  while (receiveChar != 'S') {
	  BT1_RecvChar(&receiveChar);		//Tant qu'on a pas de W on essaye de recevoir
  }
  if(receiveChar == 'S')
  {
	  LED2_On(); //-> Violet
	  WAIT1_Waitms(1000);
	  LED2_Off();
  }
  for (i = 0; i < 15; i++)
  {
	  WAIT1_Waitms(1);
	  receiveChar = ERR_RXEMPTY;		//On nettoie le buffer pour avoir une réception simple et ne pas recevoir un char en plusieurs fois
	  while(receiveChar == ERR_RXEMPTY)
	  {		//Si rien de nouveau reçu on relance une réception
		  BT1_RecvChar(&receiveChar);
	  }
	  if (receiveChar == 'E')
	  {	//Si char E alors la réception est terminée
		  break; //On sort de la réception
	  }
	  inputDatas[i] = receiveChar;	//On met les données dans un buffer de données
  	}
  		/*if (inputDatas[9]==0x01){
  			  			LED1_On(); //-> Turquoise et j'ai une valeur ici
  		}*/
  	if (inputDatas[1]==0x01){ // LED Rouge dans la tablette
  		LED1_On(); //-> Turquoise et j'ai une valeur ici
  		while (receiveChar != 'X'){
  				  BT1_RecvChar(&receiveChar);
  			      PPG1_Enable();
  			  	  PPG1_SetDutyMS(16);
  			  	  WAIT1_Waitms(500);

  			  	  PPG1_SetDutyMS(14);
  			  	  WAIT1_Waitms(100);

  			  	  PPG1_SetDutyMS(12);
  			  	  WAIT1_Waitms(100);

  			  	  PPG1_SetDutyMS(10);
  			  	  WAIT1_Waitms(100);

  			  	  PPG1_SetDutyMS(8);
  			  	  WAIT1_Waitms(100);

  			  	  PPG1_SetDutyMS(6);
  			  	  WAIT1_Waitms(100);

  			  	  PPG1_SetDutyMS(4);
  			  	  WAIT1_Waitms(100);

  			  	  PPG1_SetDutyMS(2);
  			  	  WAIT1_Waitms(100);

  			  	  PPG1_SetDutyMS(1);
  			  	  WAIT1_Waitms(100);

  			  	  PPG1_SetDutyMS(2);
  			  	  WAIT1_Waitms(100);

  			  	  PPG1_SetDutyMS(4);
  			  	  WAIT1_Waitms(100);

  			  	  PPG1_SetDutyMS(6);
  			  	  WAIT1_Waitms(100);

  			  	  PPG1_SetDutyMS(8);
  			  	  WAIT1_Waitms(100);

  			  	  PPG1_SetDutyMS(10);
  			  	  WAIT1_Waitms(100);

  			  	  PPG1_SetDutyMS(12);
  			  	  WAIT1_Waitms(100);

  			  	  PPG1_SetDutyMS(14);
  			  	  WAIT1_Waitms(100);

  			  	  PPG1_SetDutyMS(16);
  			  	  WAIT1_Waitms(100);
  		}
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
