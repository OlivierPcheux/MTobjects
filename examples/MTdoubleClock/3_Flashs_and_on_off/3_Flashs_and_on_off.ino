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

// Flashing LED_BUILTIN with on/off button

#include <MTobjects.h> // V1.0.6 See http://arduino.dansetrad.fr/MTobjects

const uint8_t PIN_BUTTON = A0; // Button wired between A0 and GND



void lightOn(void)
{
  digitalWrite(LED_BUILTIN, HIGH);
}

void lightOff(void)
{
  digitalWrite(LED_BUILTIN, LOW);
}

MTdoubleClock Metronome(500 milli_seconds, 100 milli_seconds, lightOn, lightOff, MT_INFINI, MT_OFF);



void flashOn(void)
{
  Metronome.start();
}

void flashOff(void)
{
  Metronome.stop();
  lightOff();
}

MTcheckButton Bouton(PIN_BUTTON, flashOn, flashOff);



void setup()
{
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop(){}
