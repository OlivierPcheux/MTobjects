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


// Clignotement d'une led qui flash avec un marche/arrêt

#include <MTobjects.h> // V1.1.0 Voir http://arduino.dansetrad.fr/MTobjects

const uint8_t PIN_BUTTON = A0; // Bouton câblé entre GND et A0



// CinqFlash est la partie qui fait flasher la led
void allume(void)
{
  digitalWrite(LED_BUILTIN, HIGH);
}

void eteint(void)
{
  digitalWrite(LED_BUILTIN, LOW);
}

MTdoubleClock CinqFlash(100 milli_secondes, 50 milli_secondes, allume, eteint, 10 actions_et_arret, MT_OFF);


// Metronome est responsable du clignotement général
void flash(void)
{
  CinqFlash.start();
}

MTclock Metronome(2000 milli_secondes, flash, MT_INFINI, MT_OFF);


//Bouton permet la marche ou l'arrêt général
void marche(void)
{
  CinqFlash.start(); // Pour flasher dès la mise en marche
  Metronome.start();
}

void arret(void)
{
  Metronome.stop();
}

MTcheckButton Bouton(PIN_BUTTON, marche, arret);



void setup()
{
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop(){}  
