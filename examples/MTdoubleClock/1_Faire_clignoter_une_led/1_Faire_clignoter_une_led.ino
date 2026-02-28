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


// Ce programme fait clignoter une led

#include <MTobjects.h> // V1.1.0 Voir http://arduino.dansetrad.fr/MTobjects

void allume(void)
{
  digitalWrite(LED_BUILTIN, HIGH);
}

void eteint(void)
{
  digitalWrite(LED_BUILTIN, LOW);
}

MTdoubleClock Metronome(500 milli_secondes, 100 milli_secondes, allume, eteint);



void setup()
{
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop(){}  
