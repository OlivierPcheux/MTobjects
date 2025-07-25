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


// This program will flash LED_BUILTIN controled by a button on/off

#include <MTobjects.h> // V1.0.6 See http://arduino.dansetrad.fr/MTobjects

const uint8_t PIN_BUTTON = A0; // Button wired between A0 and GND


// Fast flashs
MTsoftPWM Flash(LED_BUILTIN, inpulses_width 500000 micro_seconds, periods_width 1000000 micro_seconds, start_with LOW, MT_INFINI, NO_ACTION, MT_OFF);


// Global operation with a on/off button
void flashsOn(void) // Start the flashs
{
  Flash.start();
}

void flashsOff(void) // Stop the flashs
{
  Flash.stop();
  digitalWrite(LED_BUILTIN, LOW); // We don't know when we stop it
}

MTcheckButton Button(PIN_BUTTON, flashsOn, flashsOff);


void setup(){}

void loop(){}