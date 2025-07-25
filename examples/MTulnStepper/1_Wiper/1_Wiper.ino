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

// This program goes back and forth continuously for a stepper

#include <MTobjects.h> // V1.0.6 See http://arduino.dansetrad.fr/MTobjects

void inversion(void); // Pre-define

MTulnStepper Stepper(pin_A1 2, pin_B1 3, pin_A2 4, pin_B2 5, ONE_PHASE, accelerations_of 2048 step_or_micro_step, 0.5 RPS, DEFAULT_SENSE, inversion);

void inversion(void) // Sens inversion
{
  delay(1000); // Wait a bit before leaving in the other direction
  if (Stepper.getPosition() == 0) // If it is in the reference position
	  Stepper.move(Stepper.getStepsPerTurn()); // We take a turn
  else Stepper.moveTo(); // Otherwise we come back in the reference position
}


void setup(){}

void loop(){}