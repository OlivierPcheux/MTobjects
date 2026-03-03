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


// Ce programme fait flasher la led LED_BUILTIN. Il faut un pontage
// (fil) entre la broche 9 et 13 pour une Uno/Nano


#include <MTobjects.h> // V1.1.0 Voir http://arduino.dansetrad.fr/MTobjects


// Mise en place des flashs
// Sur Uno/Nano les broches utilisables sont: 9, 10 et le pontage 9-13
MThardPWM CinqFlash(9, impulsions_de 500000 micro_secondes, periodes_de 1000000 micro_secondes);
// Sur Mega: 2, 3, 5, 6, 7, 8, 11, 12, 13, 44, 45, 46
//MThardPWM CinqFlash(LED_BUILTIN, impulsions_de 500000 micro_secondes, periodes_de 1000000 micro_secondes);


// Clignotement global
void marche(void) // Démarrer les flashs
{
  CinqFlash.attach();
}

void arret(void) // Arrêter les flashs
{
  CinqFlash.detach();
  pinMode(9, OUTPUT); // Après unn detach, la broche est en INPUT, et la BUITLIN_LED s'allume alors
}

MTdoubleClock Metronome(5000 milli_secondes, 5000 milli_secondes, arret, marche);


void setup(){}

void loop(){}  
