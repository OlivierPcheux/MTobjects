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


// The program will light LED_BUILTIN LED on a long press and turn
// it off on a click.

#include <MTobjects.h> // V1.1.0 See http://arduino.dansetrad.fr/en/MTobjects

const uint8_t PIN_BUTTON = A0; // Button wired between A0 and GND

void lightOn(void) // Call on simple press
{
  digitalWrite(LED_BUILTIN, HIGH); // Light on
}

void lightOff(void) // Call on a long press
{
  digitalWrite(LED_BUILTIN, LOW); // Light off
}

MTlongButton Button(PIN_BUTTON, 2000 milli_seconds, lightOn, lightOff); // Implementation of the button



void setup()
{
  pinMode(LED_BUILTIN, OUTPUT);  // LED initialization
}

void loop(){}
