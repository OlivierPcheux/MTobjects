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

// Ce programme fait bouger un servo 3 fils. Chaque appui sur le bouton le
// fait changer de position

#include <MTobjects.h> // V1.1.0 Voir http://arduino.dansetrad.fr/MTobjects

const uint8_t PIN_BOUTON = A0; // Branché entre A0 et GND

const uint8_t PIN_SERVO = 9; // Sur Uno les broches commandes utilisables sont: 9, 10
                             // Sur Mega: 2, 3, 5, 6, 7, 8, 11, 12, 13, 44, 45, 46


MTservo Servo(PIN_SERVO, 2000 milli_secondes_pour_aller_de_0_a_180, PAS_D_ACTION, 0 degres_initialement);


void centQuatreVingts(void) // Pour la position 180°
{
  Servo.writeDegree(180);
}

void zero(void) // Pour la position 0°
{
  Servo.writeDegree(0);
}

MTcheckButton Bouton(PIN_BOUTON, centQuatreVingts, zero);


void setup(){}

void loop(){}