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


// This program lights an LED if you double click and turn off the LED
// on a single click.

#include <MTobjects.h> // V1.1.0 See http://arduino.dansetrad.fr/en/MTobjects

const uint8_t PIN_BUTTON = A0; // Button wired between A0 and GND


void turnOn(void) // Call on double-click
{
  digitalWrite(LED_BUILTIN, HIGH); // Turn on
}

void turnOff(void) // Call on simple-click
{
  digitalWrite(LED_BUILTIN, LOW); // Turn off
}

MTdoubleButton Bouton(PIN_BUTTON, turnOn, turnOff); // Implementation of the button



void setup()
{
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop(){}