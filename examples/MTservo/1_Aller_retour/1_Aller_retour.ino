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

// Essuie-glace: ce programme utilise un servomoteur qui fait des
// allers-retours en continu.
// Un appui sur RESET peut faire un saut brusque.

#include <MTobjects.h> // V1.1.0 Voir http://arduino.dansetrad.fr/MTobjects

const uint8_t PIN_SERVO = 9; // Sur Uno les broches commandes utilisables sont: 9, 10
                            // Sur Mega: 2, 3, 5, 6, 7, 8, 11, 12, 13, 44, 45, 46


void inversion(void); // Prédéfinition

MTservo Servo(PIN_SERVO, 5000 milli_secondes_pour_aller_de_0_a_180, inversion, 0 degres_initialement);

void inversion(void) // Inversion de la position 0° <-> 180°
{
  if (Servo.readDegree() < 90) Servo.writeDegree(180); else Servo.writeDegree(0);
}


void setup(){}

void loop(){}
