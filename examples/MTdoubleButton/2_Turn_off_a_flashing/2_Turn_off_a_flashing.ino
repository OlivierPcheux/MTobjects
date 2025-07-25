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


// The program will flash the LED_BUILTIN LED on double click and turn
// it off on a single click.

#include <MTobjects.h> // V1.0.6 See http://arduino.dansetrad.fr/MTobjects

const uint8_t PIN_BUTTON = A0; // Button wired between A0 and GND


// Flashing is made with a PWM
MTsoftPWM Led(LED_BUILTIN, inpulses_width 100000 micro_seconds, periods_width 200000 micro_seconds, start_with LOW, MT_INFINI, NO_ACTION, MT_OFF);


//Button definition
void flash(void) // Call on double click
{
  Led.start(); // Start
}

void turnOff(void) // Call on simple click
{
  Led.stop(); // End flashing
}

MTdoubleButton Bouton(PIN_BUTTON, flash, turnOff);



void setup(){}

void loop(){}