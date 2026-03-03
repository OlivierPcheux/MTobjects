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


// Voir https://forum.arduino.cc/t/faire-clignoter-3-led-avec-3-boutons-poussoirs/1124797

#include <MTobjects.h> // V1.1.0 Voir http://arduino.dansetrad.fr/MTobjects

const byte LED_1 = 2;
const byte LED_2 = 3;
const byte LED_3 = 4;
const byte BOUTON_1 = A0;
const byte BOUTON_2 = A1;
const byte BOUTON_3 = A2;


MTsoftPWM Clignotant1(LED_1, impulsions_de 500000 micro_secondes, periodes_de 1000000 micro_secondes, on_commence_par LOW, MT_INFINI, PAS_D_ACTION, MT_OFF);
MTsoftPWM Clignotant2(LED_2, impulsions_de 500000 micro_secondes, periodes_de 1000000 micro_secondes, on_commence_par LOW, MT_INFINI, PAS_D_ACTION, MT_OFF);
MTsoftPWM Clignotant3(LED_3, impulsions_de 500000 micro_secondes, periodes_de 1000000 micro_secondes, on_commence_par LOW, MT_INFINI, PAS_D_ACTION, MT_OFF);


void allume1(void)
{
  Clignotant1.start();
  if (Clignotant2.getActive()) Clignotant2.start();
  if (Clignotant3.getActive()) Clignotant3.start();
}
void allume2(void)
{
  Clignotant2.start();
  if (Clignotant1.getActive()) Clignotant1.start();
  if (Clignotant3.getActive()) Clignotant3.start();
}
void allume3(void)
{
  Clignotant3.start();
  if (Clignotant1.getActive()) Clignotant1.start();
  if (Clignotant2.getActive()) Clignotant2.start();
}

void eteint1(void)
{
  Clignotant1.stop();
  digitalWrite(LED_1, LOW); // On ne sait pas quand on l'arrête
}
void eteint2(void)
{
  Clignotant2.stop();
  digitalWrite(LED_2, LOW); // On ne sait pas quand on l'arrête
}
void eteint3(void)
{
  Clignotant3.stop();
  digitalWrite(LED_3, LOW); // On ne sait pas quand on l'arrête
}


MTcheckButton Bouton1(BOUTON_1, allume1, eteint1);
MTcheckButton Bouton2(BOUTON_2, allume2, eteint2);
MTcheckButton Bouton3(BOUTON_3, allume3, eteint3);


void setup(){}

void loop(){}