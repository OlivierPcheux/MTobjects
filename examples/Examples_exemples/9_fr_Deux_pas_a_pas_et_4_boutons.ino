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

// 2 moteurs pas à pas et 4 boutons. Pour chaque moteur on a un bouton pour
// le faire tourner dans un sens et un bouton pour le faire tourner dans
// l'autre. Les deux moteurs sont indépendants.
// Un potentiomètre règle la vitesse entre 0 et 200tr/mn
// Voir https://forum.arduino.cc/t/2-moteur-pas-a-pas-4-boutons/1384039

#include <MTobjects.h> // V1.1.0 Voir http://arduino.dansetrad.fr/MTobjects


const uint8_t sensHoraireMoteur1 = A1; // Numéro de la broche du bouton senshoraire
const uint8_t sensAntihoraireMoteur1 = A2; // Numéro de la broche du bouton sensantihoraire
const uint8_t sensHoraireMoteur2 = A3; // Numéro de la broche du bouton senshoraire
const uint8_t sensAntihoraireMoteur2 = A4; // Numéro de la broche du bouton sensantihoraire


// *************************** Pour le premier moteur *************************************
MTstepStepper Moteur1(pin_Step 2, pin_Dir 5, pin_EN 8, accelerations_sur 0 pas_ou_micro_pas);

void rotationSensHoraireMoteur1(void)
{
  Moteur1.setSpeed((analogRead(A0) / 5) RPM);
  Moteur1.move(CONTINUE);
}
void rotationSensAntihoraireMoteur1(void)
{
  Moteur1.setSpeed((analogRead(A0) / 5) RPM);
  Moteur1.move(-CONTINUE);
}
void arretMoteur1(void)
{
  Moteur1.stop();
}

MTbutton boutonSensHoraireMoteur1(sensHoraireMoteur1, rotationSensHoraireMoteur1, arretMoteur1);
MTbutton boutonSensAntihoraireMoteur1(sensAntihoraireMoteur1, rotationSensAntihoraireMoteur1, arretMoteur1);


// *************************** Pour le deuxième moteur ************************************
MTstepStepper Moteur2(pin_Step 3, pin_Dir 6, pin_EN 8, accelerations_sur 0 pas_ou_micro_pas);

void rotationSensHoraireMoteur2(void)
{
  Moteur2.setSpeed((analogRead(A0) / 5) RPM);
  Moteur2.move(CONTINUE);
}
void rotationSensAntihoraireMoteur2(void)
{
  Moteur2.setSpeed((analogRead(A0) / 5) RPM);
  Moteur2.move(-CONTINUE);
}
void arretMoteur2(void)
{
  Moteur2.stop();
}

MTbutton boutonSensHoraireMoteur2(sensHoraireMoteur2, rotationSensHoraireMoteur2, arretMoteur2);
MTbutton boutonSensAntihoraireMoteur2(sensAntihoraireMoteur2, rotationSensAntihoraireMoteur2, arretMoteur2);


// Pour mettre autre chose?

void setup(){}

void loop(){}
