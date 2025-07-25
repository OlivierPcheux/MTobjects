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


// This program will make LED_BUILTIN flash when a button is pressed

#include <MTobjects.h> // V1.0.6 See http://arduino.dansetrad.fr/MTobjects

const uint8_t PIN_BUTTON = A0; // Button wired between A0 and GND


// The metronome make the Led flash
void lightOn(void)
{
  digitalWrite(LED_BUILTIN, HIGH);
}

void lightOff(void)
{
  digitalWrite(LED_BUILTIN, LOW);
}

MTdoubleClock Metronome(100 milli_seconds, 10 milli_seconds, lightOn, lightOff, MT_INFINI, MT_OFF);


// The button activates or deactivates metronome
void flashOn(void)
{
  Metronome.start();
}

void flashOff(void)
{
  Metronome.stop();
  lightOff();
}

MTbutton Bouton(PIN_BUTTON, flashOn, flashOff);



void setup()
{
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop(){}