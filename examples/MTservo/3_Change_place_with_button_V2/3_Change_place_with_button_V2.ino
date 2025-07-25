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

// This program moves a 3-wires servo. Each press on the button changes position


// This program moves a 3-wires servo. Each press on the button changes position


#include <MTobjects.h> // V1.0.6 See http://arduino.dansetrad.fr/MTobjects

const uint8_t PIN_BOUTON = A0; // Connected between A0 and GND

const uint8_t PIN_SERVO = 9; // On Uno the usable commands pins are: 9, 10
                             // On Mega: 2, 3, 5, 6, 7, 8, 11, 12, 13, 44, 45, 46


MTservo Servo(PIN_SERVO, 2000 milli_seconds_for_go_from_0_to_180, NO_ACTION, 0 degree_initially);


void oneHundredAndEightyDegrees(void) // For position 180°
{
  Servo.writeDegree(180);
}

void zeroDegree(void) // For position 0°
{
  Servo.writeDegree(0);
}

MTcheckButton Bouton(PIN_BOUTON, oneHundredAndEightyDegrees, zeroDegree);


void setup(){}

void loop(){}