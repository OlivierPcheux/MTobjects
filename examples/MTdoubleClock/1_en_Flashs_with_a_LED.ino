// Version 1.1.0

//###########################################################################
//###########################################################################
//####                                                                   ####
//####                          Olivier Pécheux                          ####
//####                        Olivier@Dansetrad.fr                       ####
//####                        (33) +6 69 77 82 58                        ####
//####              http://arduino.dansetrad.fr/en/MTobjects             ####
//####                                                                   ####
//###########################################################################
//###########################################################################


// This program will flashs a LED

#include <MTobjects.h> // V1.1.0 See http://arduino.dansetrad.fr/en/MTobjects

void lightOn(void)
{
  digitalWrite(LED_BUILTIN, HIGH);
}

void lightOff(void)
{
  digitalWrite(LED_BUILTIN, LOW);
}

MTdoubleClock Metronome(500 milli_seconds, 100 milli_seconds, lightOn, lightOff);



void setup()
{
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop(){}