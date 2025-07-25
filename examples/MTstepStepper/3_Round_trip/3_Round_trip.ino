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

// When you press a button an stepper turn, once in two in one direction,
// once in two in the other direction.

#include <MTobjects.h> // V1.0.6 See http://arduino.dansetrad.fr/MTobjects

const uint8_t PIN_BOUTON = A0;

MTstepStepper Stepper(pin_Step 2, pin_Dir 5, pin_EN 8);

void front(void) // One full turn
{
  Stepper.move(Stepper.getMicroStepsPerTurn());
}

void back(void) // Back to the original position
{
  Stepper.moveTo();
}

MTcheckButton Bouton(PIN_BOUTON, front, back);

void setup(){}

void loop(){}