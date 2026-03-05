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


// Clignotement d'une led avec un marche/arrêt

#include <MTobjects.h> // V1.1.0 Voir http://arduino.dansetrad.fr/MTobjects

const uint8_t PIN_BUTTON = A0; // Bouton câblé entre GND et A0



void allume(void)
{
  digitalWrite(LED_BUILTIN, HIGH);
}

void eteint(void)
{
  digitalWrite(LED_BUILTIN, LOW);
}

MTdoubleClock Metronome(500 milli_secondes, 100 milli_secondes, allume, eteint, MT_INFINI, MT_OFF);



void marche(void)
{
  Metronome.start();
}

void arret(void)
{
  Metronome.stop();
  eteint();
}

MTcheckButton Bouton(PIN_BUTTON, marche, arret);



void setup()
{
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop(){}  
