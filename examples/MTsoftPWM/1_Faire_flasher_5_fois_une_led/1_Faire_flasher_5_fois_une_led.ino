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


// Ce programme fait clignoter une led avec des flashs.

#include <MTobjects.h> // V1.1.0 Voir http://arduino.dansetrad.fr/MTobjects


// 5 flashs rapides
MTsoftPWM CinqFlash(LED_BUILTIN, impulsions_de 50000 micro_secondes, periodes_de 100000 micro_secondes, on_commence_par HIGH, 10 niveaux_et_arret);


// Lancement des flashs toutes les 2 secondes
void flash(void)
{
  CinqFlash.start(); // Relance du PWM
}

MTclock Metronome(2000 milli_secondes, flash);


void setup(){}

void loop(){}