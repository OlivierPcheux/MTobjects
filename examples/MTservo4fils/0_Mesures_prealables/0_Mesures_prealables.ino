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

// Ce programme permet de mesurer les deux valeurs pour passer en paramètres
// pour un servo 4 fils

#include <MTobjects.h> // V1.1.0 Voir http://arduino.dansetrad.fr/MTobjects

const uint8_t PIN_SERVO = 9; // Sur Uno les broches commandes utilisables sont: 9, 10
                            // Sur Mega: 2, 3, 5, 6, 7, 8, 11, 12, 13, 44, 45, 46
const uint8_t POTENTIOMETRE = A0; // Info sur la position du servo


MTservo4fils Servo(PIN_SERVO, POTENTIOMETRE, 
                   can_pour_0_degree 0, can_pour_180_degree 1023); // Ces deux valeurs sont à mesurer pour chaque servo

void setup()
{
  Serial.begin(115200); // Préparation de la console
}

void loop()
{
  Servo.writeDegree(0);
  Serial.print(F("can_pour_0_degree : "));
  delay(2000 milli_secondes); // Il faut attendre que le servo soit bien en place
  Serial.print(analogRead(POTENTIOMETRE));

  Serial.print(F(",  can_pour_180_degree : "));
  Servo.writeDegree(180);
  delay(2000 milli_secondes); // Il faut attendre que le servo soit bien en place
  Serial.println(analogRead(POTENTIOMETRE));
}
