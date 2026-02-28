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


// Ce programme fait flasher 5 fois une led

#include <MTobjects.h> // V1.1.0 Voir http://arduino.dansetrad.fr/MTobjects


// Mise en place de 5 flashs rapides
void allume(void)
{
  digitalWrite(LED_BUILTIN, HIGH);
}

void eteint(void)
{
  digitalWrite(LED_BUILTIN, LOW);
}

MTdoubleClock CinqFlash(100 milli_secondes, 50 milli_secondes, allume, eteint, 10 actions_et_arret, MT_OFF);


// Lancement régulier des 5 flashs
void flash(void)
{
  CinqFlash.start();
}

MTclock Metronome(2000 milli_secondes, flash);



void setup()
{
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop(){}  
