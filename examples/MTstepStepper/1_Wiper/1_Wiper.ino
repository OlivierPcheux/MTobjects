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

MTstepStepper Stepper(pin_Step 2, pin_Dir 5, pin_EN 8, accelerations_of 16*200 step_or_micro_step, 16 micro_pas, 1 RPS, DEFAULT_SENSE, inversion);

void inversion(void) // Sens inversion
{
  delay(1000); // Wait a bit before leaving in the other direction
  if (Stepper.getPosition() == 0) // If it is in the reference position
	  Stepper.move(Stepper.getMicroStepsPerTurn()); // We take a turn
  else Stepper.moveTo(); // Otherwise we come back in the reference position
}


void setup(){}

void loop(){}