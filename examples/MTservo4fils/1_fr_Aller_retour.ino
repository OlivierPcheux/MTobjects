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

// Ce programme fait bouger un servo 4 fils. Un appui sur RESET ne fait pas
// de saut brusque

#include <MTobjects.h> // V1.1.0 Voir http://arduino.dansetrad.fr/MTobjects

const uint8_t PIN_SERVO = 9; // Sur Uno les broches commandes utilisables sont: 9, 10
                            // Sur Mega: 2, 3, 5, 6, 7, 8, 11, 12, 13, 44, 45, 46
const uint8_t POTENTIOMETRE = A0;


void inversion(void); // Pré-définition

MTservo4fils Servo(PIN_SERVO, POTENTIOMETRE, 
                   can_pour_0_degree 606, can_pour_180_degree 39, // Ces deux valeurs sont à mesurer pour chaque servo
                   5000 milli_secondes_pour_aller_de_0_a_180, inversion);

void inversion(void) // Inversion de la position 0° <-> 180°
{
  if (Servo.readDegree() < 90) Servo.writeDegree(180); else Servo.writeDegree(0);
}


void setup(){}

void loop(){}
