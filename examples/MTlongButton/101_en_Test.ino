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


// This program test the MTlongButton and write informations

#include <MTobjects.h> // V1.1.0 See http://arduino.dansetrad.fr/MTobjects

const uint8_t PIN_BUTTON = A0; // Button wired between A0 and GND


void longPress(void) // Call on a long press
{
  Serial.println("  Start of a long press"); 
}

void press(void) // Call on a press
{
  Serial.println("Start of a press");
}

void release(void) // Call on release the button
{
  Serial.println("  End of the press");
}

MTlongButton Button(PIN_BUTTON, 3000 milli_seconds, longPress, press, release); // Implementation of the button



void setup()
{
  Serial.begin(115200); // The console must also be adjusted to 115,200 bauds
}

void loop(){}