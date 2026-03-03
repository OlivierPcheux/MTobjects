// Version 1.1.0

//###########################################################################
//###########################################################################
//####                                                                   ####
//####                          Olivier Pécheux                          ####
//####                        Olivier@Dansetrad.fr                       ####
//####                        (33) +6 69 77 82 58                        ####
//####               http://arduino.dansetrad.fr/MTobjects               ####
//####                                                                   ####
//###########################################################################
//###########################################################################


// Ce programme fait clignoter une led si on fait un double clic  et éteint
// la led sur un simple clic. 

#include <MTobjects.h> // V1.1.0 Voir http://arduino.dansetrad.fr/MTobjects

const uint8_t PIN_BUTTON = A0; // Bouton câblé entre GND et A0


// Le clignotement est fait par un PWM
MTsoftPWM Led(LED_BUILTIN, impulsions_de 100000 micro_secondes, periodes_de 200000 micro_secondes, on_commence_par LOW, MT_INFINI, PAS_D_ACTION, MT_OFF);


//Puis définition du bouton
void clignote(void) // Appelée sur double clic
{
  Led.start(); // Début du clignotement
}

void eteint(void) // Appelée sur simple clic
{
  Led.stop(); // Fin du clignotement
}

MTdoubleButton Bouton(PIN_BUTTON, clignote, eteint);



void setup(){}

void loop(){}  
