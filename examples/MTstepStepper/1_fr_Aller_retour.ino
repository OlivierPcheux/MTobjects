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

MTstepStepper Stepper(pin_Step 2, pin_Dir 5, pin_EN 8, accelerations_sur 16*200 pas_ou_micro_pas, 16 pas_ou_micro_pas, 1 RPS, SENS_PAR_DEFAUT, inversion);

void inversion(void) // Inversion du sens
{
  delay(1000); // Attendre un peu avant de repartir dans l'autre sens
  if (Stepper.getPosition() == 0) // Si il est en position de référence
	  Stepper.move(Stepper.getMicroStepsPerTurn()); // On fait un tour
  else Stepper.moveTo(); // Sinon on revient en position de référence
}


void setup(){}

void loop(){}
