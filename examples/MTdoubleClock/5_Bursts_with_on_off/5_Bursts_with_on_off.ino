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


// Slavs with on/off

#include <MTobjects.h> // V1.0.6 See http://arduino.dansetrad.fr/MTobjects

const uint8_t PIN_BUTTON = A0; // Button wired between A0 and GND



// FiveFlashes is the part that makes the LED flash
void lights(void)
{
  digitalWrite(LED_BUILTIN, HIGH);
}

void extinct(void)
{
  digitalWrite(LED_BUILTIN, LOW);
}

MTdoubleClock FiveFlashes(100 milli_seconds, 50 milli_seconds, lights, extinct, 10 actions_and_stop, MT_OFF);



// Metronome is responsible for the general flashing
void flashes(void)
{
  FiveFlashes.start();
}

MTclock Metronome(2000 milli_seconds, flashes, MT_INFINI, MT_OFF);



// Button allows general run or stop
void run(void)
{
  FiveFlashes.start(); // To flash upon starting
  Metronome.start();
}

void stop(void)
{
  Metronome.stop();
}

MTcheckButton Bouton(PIN_BUTTON, run, stop);



void setup()
{
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop(){}
