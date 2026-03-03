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


// Ce programme fait clignoter LED_BUILTIN quand un bouton est appuyé

#include <MTobjects.h> // V1.1.0 Voir http://arduino.dansetrad.fr/MTobjects

const uint8_t PIN_BUTTON = A0; // Bouton câblé entre GND et A0


// Le métronome fait clignotter la led
void allume(void)
{
  digitalWrite(LED_BUILTIN, HIGH);
}

void eteint(void)
{
  digitalWrite(LED_BUILTIN, LOW);
}

MTdoubleClock Metronome(100 milli_secondes, 10 milli_secondes, allume, eteint, MT_INFINI, MT_OFF);


// Le bouton active ou désactive le métronome
void marche(void)
{
  Metronome.start();
}

void arret(void)
{
  Metronome.stop();
  eteint();
}

MTbutton Bouton(PIN_BUTTON, marche, arret);



void setup()
{
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop(){}