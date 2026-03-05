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

// Quand on appuie sur un bouton un moteur pas à as fait un tour, une fois sur
// deux dans un sens, une fois sur deux dans l'autre sens.

#include <MTobjects.h> // V1.1.0 Voir http://arduino.dansetrad.fr/MTobjects

const uint8_t PIN_BOUTON = A0;

MTulnStepper Stepper(pin_A1 2, pin_B1 3, pin_A2 4, pin_B2 5, UNE_PHASE);
// MTulnStepper Stepper(pin_A1 2, pin_B1 3, NON_CONNECTEE, NON_CONNECTEE, PAS_ENTIERS);

void aller(void) // Un tour complet
{
  Stepper.move(Stepper.getStepsPerTurn());
}

void retour(void) // Retour à la position d'origine
{
  Stepper.moveTo();
}

MTcheckButton Bouton(PIN_BOUTON, aller, retour);

void setup(){}

void loop(){}
