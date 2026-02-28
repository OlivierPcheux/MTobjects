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

// Ce programme fait clignoter la led LED_BUILTIN. Il faut un pontage (fil) entre la
// broche 9 et 13 pour une Uno/Nano

#include <MTobjects.h> // V1.1.0 Voir http://arduino.dansetrad.fr/MTobjects

// Sur Uno/Nano les broches utilisables sont: 9, 10 et le pontage 9-13
MThardPWM Clignotant(9, impulsions_de 500000 micro_secondes, periodes_de 1000000 micro_secondes);
// Sur Mega: 2, 3, 5, 6, 7, 8, 11, 12, 13, 44, 45, 46
//MThardPWM CinqFlash(LED_BUILTIN, impulsions_de 500000 micro_secondes, periodes_de 1000000 micro_secondes);


void setup(){}

void loop(){}