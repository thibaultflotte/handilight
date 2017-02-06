#include "lumiere.h"

static uint8_t lumiref;
extern char TabDatas[15];



void lumiere_reference(){ // Permet de recuperer la donnee de référence qui servira a la comparaison avec la donnee dynamique


//----------------------------------------------------

/* Capteur de Luminosite */
 (void)AD2_Measure(TRUE);	// initialise le convertisseur analogique-numerique
 (void)AD2_GetValue8(&lumiref); // recupere la donnee du convertisseur et la stocke dans lumiref. Cette donnee servira donc de reference
}
//----------------------------------------------------

void lumiere_initialisation(char TabDatas[]){ //fonction permettant d'initialiser les LEDs.

uint16_t freq;

 freq=(( (TabDatas[1]) <<8 | (TabDatas[2]) )); 	//recuperation de la donnee frequence et stockage dans frequence
   				WAIT1_Waitms(1);

   				//test pour savoir quelle LED l'utilisateur a selectionne

   				if(TabDatas[0]==0x00){ //LED Rouge
   					LEDRouge_Enable(); //Active l'utilisaton de la LED Rouge
   					LEDRouge_SetRatio8(255 - ((TabDatas[3]*255)/100)); //Initialise son Ratio
   					LEDRouge_SetFreqHz(freq); // Initialise la Frequence
  					LED1_On();
   				 }
   				 if(TabDatas[0]==0x02){ //LED Verte
   					LEDVerte_Enable();
   					LEDVerte_SetRatio8(255 - ((TabDatas[3]*255)/100));
   					LEDVerte_SetFreqHz(freq);
   					LED1_On();
   				 }
   				 if(TabDatas[0]==0x03){ //LED Blanche
   					LEDBlanche_Enable();
   					LEDBlanche_SetRatio8(255 - ((TabDatas[3]*255)/100));
   					LEDBlanche_SetFreqHz(freq);
   					LED1_On();
   				 }
}
//----------------------------------------------------------

void lumiere_gestion(char TabDatas[]){ //Permet la modification dynamique de la luminosite en fonction de la luminosite exterieure
uint16_t intensity; //stocke la donnee finale pour gerer le ratio
short inten; //sert à effectuer des test pour la donnee finale
uint8_t lumi; //  donnee dynamique

(void)AD2_Measure(TRUE);
   				  	  (void)AD2_GetValue8(&lumi); // recupere la donne dynamique et la stocke dans lumi
   				  	  inten = 255 - ((TabDatas[3]*255)/100)+(lumi-lumiref); //transformation de la donnee pour la mettre sur 255
   				  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	//puis stockage dans inten

   				  	  //Test sur la valeur de inten puis stockage de la donne finale dans intensity
   				  	  if (inten <= 0){
   				  		  intensity = 0;
   				  	  }
   				  	  else if (inten > 0 && inten<255){
   				  		  intensity = inten;
   				  	  }
   				  	  else intensity= 255;

   				  	  //2eme test pour savoir quelle LED voit sa luminosite modifiee
   				  	  	if(TabDatas[0]==0x00){
   				  	  	  	LEDRouge_Enable();
   				  	  	  	LEDRouge_SetRatio8(intensity); //modification dynamique du ratio avec la nouvelle valeur, intensity
   				  	  	  	LED1_On();
   				  	  	}
   				  	  	if(TabDatas[0]==0x02){
   				  	  		LEDVerte_Enable();
   				  	  		LEDVerte_SetRatio8(intensity);
   				  	  		LED1_On();
   				  	  	}
   				  	  	if(TabDatas[0]==0x03){
   				  	  		LEDBlanche_Enable();
   				  	  		LEDBlanche_SetRatio8(intensity);
   				  	  		LED1_On();
   				  	  	}
   				  	  	WAIT1_Waitms(1);

}
