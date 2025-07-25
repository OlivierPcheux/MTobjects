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

// once in two in the other direction.

#include <MTobjects.h> // V1.0.6 See http://arduino.dansetrad.fr/MTobjects

const uint8_t PIN_BOUTON = A0;

MTulnStepper Stepper(pin_A1 2, pin_B1 3, pin_A2 4, pin_B2 5, ONE_PHASE);

void front(void) // One full turn
{
  Stepper.move(Stepper.getStepsPerTurn());
}

void back(void) // Back to the original position
{
  Stepper.moveTo();
}

MTcheckButton Bouton(PIN_BOUTON, front, back);

void setup(){}

void loop(){}