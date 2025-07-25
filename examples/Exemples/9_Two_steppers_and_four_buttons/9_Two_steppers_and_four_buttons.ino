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

// 2 stepper motors and 4 buttons. For each motor we have a button for
// running in a direction and a button for runing it in the other. The two
// motors are independents.
// A potentiometer sets the speed between 0 and 200 RPM
// See https://forum.arduino.cc/t/2-moteur-pas-a-pas-4-boutons/1384039

#include "MTobjects.h" // V1.0.6 See http://arduino.dansetrad.fr/MTobjects


const uint8_t clockwiseMotor1 = A1; // Clockwise button pin number
const uint8_t antiClockwiseMotor1 = A2; // Anti-clockwise button pin number
const uint8_t clockwiseMotor2 = A3; // Clockwise button pin number
const uint8_t antiClockwiseMotor2 = A4; // Anti-clockwise button pin number


// *************************** For the first motor *************************************
MTstepStepper Motor1(pin_Step 2, pin_Dir 5, pin_EN 8, accelerations_of 0 step_or_micro_step);

void clockwiseMotorRotation1(void)
{
  Motor1.setSpeed((analogRead(A0) / 5) RPM);
  Motor1.move(CONTINUE);
}
void antiClockwiseMotorRotation1(void)
{
  Motor1.setSpeed((analogRead(A0) / 5) RPM);
  Motor1.move(-CONTINUE);
}
void stopMotor1(void)
{
  Motor1.stop();
}

MTbutton clockwiseMotorButton1(clockwiseMotor1, clockwiseMotorRotation1, stopMotor1);
MTbutton antiClockwiseMotorButton1(antiClockwiseMotor1, antiClockwiseMotorRotation1, stopMotor1);


// *************************** For the second motor ************************************
MTstepStepper Motor2(pin_Step 3, pin_Dir 6, pin_EN 8, accelerations_of 0 step_or_micro_step);

void clockwiseMotorRotation2(void)
{
  Motor2.setSpeed((analogRead(A0) / 5) RPM);
  Motor2.move(CONTINUE);
}
void antiClockwiseMotorRotation2(void)
{
  Motor2.setSpeed((analogRead(A0) / 5) RPM);
  Motor2.move(-CONTINUE);
}
void stopMotor2(void)
{
  Motor2.stop();
}

MTbutton clockwiseMotorButton2(clockwiseMotor2, clockwiseMotorRotation2, stopMotor2);
MTbutton antiClockwiseMotorButton2(antiClockwiseMotor2, antiClockwiseMotorRotation2, stopMotor2);


// To put something else?

void setup(){}

void loop(){}