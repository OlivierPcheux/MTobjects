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


// This program will turn on/off an LED

#include <MTobjects.h> // V1.1.0 See http://arduino.dansetrad.fr/en/MTobjects

const uint8_t PIN_BUTTON = A0; // Button wired between A0 and GND


void light(void) // Call when press the button the first time
{
  digitalWrite(LED_BUILTIN, HIGH); // Light the LED
}

void turnOff(void) // Call when press the button the second time
{
  digitalWrite(LED_BUILTIN, LOW); // Turn off the LED
}

MTcheckButton Bouton(PIN_BUTTON, light, turnOff);



void setup()
{
  pinMode(LED_BUILTIN, OUTPUT); // LED initialization
}

void loop(){}