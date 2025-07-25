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

// This program takes a turn when you press a button

#include <MTobjects.h> // V1.0.6 See http://arduino.dansetrad.fr/MTobjects

const uint8_t PIN_BOUTON = A0;

MTulnStepper Stepper(pin_A1 2, pin_B1 3, pin_A2 4, pin_B2 5, ONE_PHASE);

void turn(void) // A full tour
{
  Stepper.move(Stepper.getStepsPerTurn());
}

MTbutton Bouton(PIN_BOUTON, turn);

void setup(){}

void loop(){}