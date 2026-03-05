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


// Ce programme fait clignoter une led avec un bouton marche arrêt

#include <MTobjects.h> // V1.1.0 Voir http://arduino.dansetrad.fr/MTobjects


// 5 flashs rapides
MTsoftPWM Clignotant(LED_BUILTIN, impulsions_de 50000 micro_secondes, periodes_de 100000 micro_secondes, on_commence_par LOW, MT_INFINI, PAS_D_ACTION, MT_OFF);


// Fonctionnement global avec un bouton M/A
void allume(void) // Démarre les flashs
{
  Clignotant.start();
}

void eteint(void) // Arrête les flashs
{
  Clignotant.stop();
  digitalWrite(LED_BUILTIN, LOW); // On ne sait pas quand on l'arrête
}

MTcheckButton Bouton(A0, allume, eteint);


void setup(){}

void loop(){}