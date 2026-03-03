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

// Quand on appuie sur un bouton un moteur pas à pas fait un tour, une fois
// sur deux dans un sens, une fois sur deux dans l'autre sens.

#include <MTobjects.h> // V1.1.0 Voir http://arduino.dansetrad.fr/MTobjects

const uint8_t PIN_BOUTON = A0;

MTstepStepper Stepper(pin_Step 2, pin_Dir 5, pin_EN 8);

void aller(void) // Un tour commplet
{
  Stepper.move(Stepper.getMicroStepsPerTurn());
}

void retour(void) // Retour à la position d'origine
{
  Stepper.moveTo();
}

MTcheckButton Bouton(PIN_BOUTON, aller, retour);

void setup(){}

void loop(){}
