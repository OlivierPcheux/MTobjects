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

// Ce programme fait faire un tour dans un sens un tour dans l'autre à un pas à pas

#include <MTobjects.h> // V1.1.0 Voir http://arduino.dansetrad.fr/MTobjects

void inversion(void); // Pré-définition

MTulnStepper Stepper(pin_A1 2, pin_B1 3, pin_A2 4, pin_B2 5, UNE_PHASE, accelerations_sur 2048 pas_ou_micro_pas, 0.5 RPS, SENS_PAR_DEFAUT, inversion);

void inversion(void) // Inversion du sens
{
  if (Stepper.getPosition() == 0) // Si il est en position de référence
	  Stepper.move(Stepper.getStepsPerTurn()); // On fait un tour
  else Stepper.moveTo(); // Sinon on revient en position de référence
}


void setup(){}

void loop(){}
