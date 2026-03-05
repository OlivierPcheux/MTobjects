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

// Ce programme fait faire un tour quand on appuie sur un bouton

#include <MTobjects.h> // V1.1.0 Voir http://arduino.dansetrad.fr/MTobjects

const uint8_t PIN_BOUTON = A0;

MTulnStepper Stepper(pin_A1 2, pin_B1 3, pin_A2 4, pin_B2 5);

void tourne(void) // Un tour complet
{
  Stepper.move(Stepper.getStepsPerTurn());
}

MTbutton Bouton(PIN_BOUTON, tourne);

void setup(){}

void loop(){}
