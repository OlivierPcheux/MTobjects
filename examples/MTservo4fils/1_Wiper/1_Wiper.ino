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

// Wiper: this program uses a servomotor that goes back and forth continuously.
// A reset does not suddenly change the position of the servo, even during a trip.


#include <MTobjects.h> // V1.0.6 See http://arduino.dansetrad.fr/MTobjects

const uint8_t PIN_SERVO = 9; // On Uno the usable commands pins are: 9, 10
                             // On Mega: 2, 3, 5, 6, 7, 8, 11, 12, 13, 44, 45, 46
const uint8_t POTENTIOMETER = A0;


void inversion(void); // Predefinition

MTservo4wires Servo(PIN_SERVO, POTENTIOMETER, 
                   cad_for_0_degree 574, cad_for_180_degree 35, // These two values are to be measured for each servo
                   5000 milli_seconds_for_go_from_0_to_180, inversion);

void inversion(void) // Inversion of the position 0° <-> 180°
{
  if (Servo.readDegree() < 90) Servo.writeDegree(180); else Servo.writeDegree(0);
}


void setup(){}

void loop(){}
