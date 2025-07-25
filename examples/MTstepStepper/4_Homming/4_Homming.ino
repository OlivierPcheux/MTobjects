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

// This program initializes the position of a stepper, then has done
// a tour in one direction one tour in the other

#include MTobjects.h // V1.0.6 See http://arduino.dansetrad.fr/MTobjects

const float speed = 1 RPS;
const uint8_t eos = A0; // End of stroke; closed at rest
boolean initializing = false; // Before homming, true after


// Part making one tour in one direction, one tour in the other
void inversion(void); // Pre-define

MTstepStepper Stepper(pin_Step 2, pin_Dir 5, pin_EN 8, accelerations_of 16*200 step_or_micro_step, 16 step_or_micro_step, vitesse, DEFAULT_SENSE, inversion);

void inversion(void) // Sens inversion
{
  if (initializing)
  {
    delay(1000); // Wait a bit before leaving in the other direction
    if (Stepper.getPosition() == 0) // If it is in the reference position
      Stepper.move(Stepper.getMicroStepsPerTurn()); // We take a turn
    else Stepper.moveTo(); //  Otherwise we come back in the reference position
  }
}

// Initializing
void setup()
{
  // initializing end of stroke
  pinMode(eos, INPUT_PULLUP); // Between eos and Gnd

  // Mise à l'origine
  Stepper.setSpeed(speed / 10); // Doucement pendant la mise en référence
  Stepper.move(-CONTINUE); // Gently during reference
  while (!digitalRead(eos)); // Waiting for the original position
  Stepper.stop(); // We are at the origin; We stop
  Stepper.setOrigin(); // Locate
  initializing = true; // Allow normal operation

  // Normal cycle
  Stepper.setSpeed(speed); // Resumption of normal speed to work
  inversion();
}

void loop(){}
