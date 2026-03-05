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


// This program sends the letter 'A' to the series console

#include <MTobjects.h> // V1.1.0 See http://arduino.dansetrad.fr/en/MTobjects

const uint8_t PIN_BUTTON = A0; // Button wired between A0 and GND


void send(void)
{
  Serial.print('A'); // Called when you just press the button
}

MTbutton Bouton(PIN_BUTTON, send); // Implementation of the button



void setup()
{
  Serial.begin(115200); // Also put the console on 115200 Bauds
}

void loop(){}