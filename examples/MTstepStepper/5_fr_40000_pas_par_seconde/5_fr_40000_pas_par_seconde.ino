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

// Ce programme fait tourner un moteur à 41000 pas/s

#include <MTobjects.h> // V1.1.0 Voir http://arduino.dansetrad.fr/MTobjects

void inversion(void); // Pré-définition

MTstepStepper Stepper(pin_Step 2, pin_Dir 5, pin_EN 8, accelerations_sur 50L*16*200 pas_ou_micro_pas, 16 pas_ou_micro_pas, 1 RPS, SENS_PAR_DEFAUT, inversion);

void inversion(void) // Inversion du sens
{
  if (Stepper.getPosition() == 0) // Si il est en position de référence
	  Stepper.move(Stepper.getMicroStepsPerTurn()*150L); // Accélération sur 50 tours, vitesse constante pendant 50 tours, décélération sur 50 tours
  else Stepper.moveTo(); // Sinon on revient en position de référence
}


void setup()
{
  MTtimeBase(24 micro_secondes);
  Stepper.setSpeed(24 micro_secondes_par_pas);
}

void loop(){}
