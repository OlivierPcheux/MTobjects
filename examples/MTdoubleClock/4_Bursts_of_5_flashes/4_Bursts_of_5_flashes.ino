// Version 1.0.6

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


// This program is flashing 5 times an LED

#include <MTobjects.h> // V1.0.6 See http://arduino.dansetrad.fr/MTobjects


// Implementation of 5 fast flashes
void lights(void)
{
  digitalWrite(LED_BUILTIN, HIGH);
}

void extinct(void)
{
  digitalWrite(LED_BUILTIN, LOW);
}

MTdoubleClock FiveFlash(100 milli_seconds, 50 milli_seconds, lights, extinct, 10 actions_and_stop, MT_OFF);


// Regular launch of 5 flashes
void flashes(void)
{
  FiveFlash.start();
}

MTclock Metronome(2000 milli_seconds, flashes);

void setup()
{
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop(){}
