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

// Essuie-glace: ce programme utilise un servomoteur qui fait des
// allers-retours en continu.
// Un appui sur RESET peut faire un saut brusque.

#include <MTobjects.h> // V1.0.6 See http://arduino.dansetrad.fr/MTobjects

const uint8_t PIN_SERVO = 9; // Sur Uno les broches commandes utilisables sont: 9, 10
                            // Sur Mega: 2, 3, 5, 6, 7, 8, 11, 12, 13, 44, 45, 46


void inversion(void); // Prédéfinition

MTservo Servo(PIN_SERVO, 5000 milli_seconds_for_go_from_0_to_180, inversion, 0 degree_initially);

void inversion(void) // Inversion de la position 0° <-> 180°
{
  if (Servo.readDegree() < 90) Servo.writeDegree(180); else Servo.writeDegree(0);
}


void setup(){}

void loop(){}
