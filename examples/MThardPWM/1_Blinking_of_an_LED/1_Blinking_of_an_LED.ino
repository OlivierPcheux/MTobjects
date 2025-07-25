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

// This program makes the LED_BUILTIN blink. A wire is needed between the
// pin 9 and 13 for a Uno/Nano

#include <MTobjects.h> // V1.0.6 See http://arduino.dansetrad.fr/MTobjects

// On Uno/Nano the usable pins are: 9, 10. wHere we have to put a wire between pin 9 and pin 13
MThardPWM Blink(9, inpulses_width 500000 micro_seconds, periods_width 1000000 micro_seconds);
// On Mega the usable pins are: 2, 3, 5, 6, 7, 8, 11, 12, 13, 44, 45, 46
//MThardPWM Blink(LED_BUILTIN, inpulses_width 500000 micro_seconds, periods_width 1000000 micro_seconds);


void setup(){}

void loop(){}