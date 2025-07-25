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

// This program runs an stepper at 41000 micro-steps/s

#include <MTobjects.h> // V1.0.6 See http://arduino.dansetrad.fr/MTobjects

void inversion(void); // Pre-define

MTstepStepper Stepper(pin_Step 2, pin_Dir 5, pin_EN 8, accelerations_of 50L*16*200 step_or_micro_step, 16 step_or_micro_step, 1 RPS, DEFAULT_SENSE, inversion);

void inversion(void) // Sens inversion
{
  if (Stepper.getPosition() == 0) // If it is in the reference position
	  Stepper.move(Stepper.getMicroStepsPerTurn()*150L); // Acceleration on 50 revolutions, constant speed for 50 revolutions, deceleration on 50 revolutions
  else Stepper.moveTo(); // Otherwise we come back in the reference position
}


void setup()
{
  MTtimeBase(24 micro_seconds);
  Stepper.setSpeed(24 micro_second_per_step);
}

void loop(){}