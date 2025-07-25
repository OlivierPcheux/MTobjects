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

// Ce programme fait faire un tour quand on appuie sur un bouton

#include <MTobjects.h> // V1.0.6 See http://arduino.dansetrad.fr/MTobjects

const uint8_t PIN_BOUTON = A0;

MTstepStepper Stepper(pin_Step 2, pin_Dir 5, pin_EN 8);

void tourne(void) // Un tour commplet
{
  Stepper.move(Stepper.getMicroStepsPerTurn());
}

MTbutton Bouton(PIN_BOUTON, tourne);

void setup(){}

void loop(){}
