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


// Je veux piloter 6 leds avec 6 boutons poussoirs via une carte Uno, Nano ou
// Mega. Lorsque j’appuie sur un bouton et que je le relâche, la LED
// correspondante au bouton s’allume. Lorsque je refait une pression sur le
// même bouton, la LED correspondante s’éteint. Un septième bouton poussoir
// sert à éteindre d'une seule pression toutes les leds qui ont été allumées.


#include "MTobjects.h" // V1.0.6 See http://arduino.dansetrad.fr/MTobjects

const uint8_t PIN_BUTTON_ETEINT = 2; // Bouton câblé entre GND et 2
const uint8_t PIN_BUTTON_0 = 3;
const uint8_t PIN_BUTTON_1 = 4;
const uint8_t PIN_BUTTON_2 = 5;
const uint8_t PIN_BUTTON_3 = 6;
const uint8_t PIN_BUTTON_4 = 7;
const uint8_t PIN_BUTTON_5 = 8;

const uint8_t PIN_LED_0 = 9; // Led câblée entre 9 et GND
const uint8_t PIN_LED_1 = 10;
const uint8_t PIN_LED_2 = 11;
const uint8_t PIN_LED_3 = 12;
const uint8_t PIN_LED_4 = 13;
const uint8_t PIN_LED_5 = 14; // 14 c'est aussi A0


// Pour le bouton 0
void allume0(void)
{
  digitalWrite(PIN_LED_0, HIGH);
}
void eteint0(void)
{
  digitalWrite(PIN_LED_0, LOW);
}
MTcheckButton Bouton0(PIN_BUTTON_0, allume0, eteint0);


// Pour le bouton 1
void allume1(void)
{
  digitalWrite(PIN_LED_1, HIGH);
}
void eteint1(void)
{
  digitalWrite(PIN_LED_1, LOW);
}
MTcheckButton Bouton1(PIN_BUTTON_1, allume1, eteint1);


// Pour le bouton 2
void allume2(void)
{
  digitalWrite(PIN_LED_2, HIGH);
}
void eteint2(void)
{
  digitalWrite(PIN_LED_2, LOW);
}
MTcheckButton Bouton2(PIN_BUTTON_2, allume2, eteint2);


// Pour le bouton 3
void allume3(void)
{
  digitalWrite(PIN_LED_3, HIGH);
}
void eteint3(void)
{
  digitalWrite(PIN_LED_3, LOW);
}
MTcheckButton Bouton3(PIN_BUTTON_3, allume3, eteint3);


// Pour le bouton 4
void allume4(void)
{
  digitalWrite(PIN_LED_4, HIGH);
}
void eteint4(void)
{
  digitalWrite(PIN_LED_4, LOW);
}
MTcheckButton Bouton4(PIN_BUTTON_4, allume4, eteint4);


// Pour le bouton 5
void allume5(void)
{
  digitalWrite(PIN_LED_5, HIGH);
}
void eteint5(void)
{
  digitalWrite(PIN_LED_5, LOW);
}
MTcheckButton Bouton5(PIN_BUTTON_5, allume5, eteint5);


// Pour le dernier bouton
void eteintTout(void)
{
  Bouton0.unselect(); // Eteint la led 0
  Bouton1.unselect(); // Eteint la led 1
  Bouton2.unselect();
  Bouton3.unselect();
  Bouton4.unselect();
  Bouton5.unselect();
}
MTbutton BoutonEteint(PIN_BUTTON_ETEINT, eteintTout);


void setup()
{
  pinMode(PIN_LED_0, OUTPUT);
  pinMode(PIN_LED_1, OUTPUT);
  pinMode(PIN_LED_2, OUTPUT);
  pinMode(PIN_LED_3, OUTPUT);
  pinMode(PIN_LED_4, OUTPUT);
  pinMode(PIN_LED_5, OUTPUT);
}

void loop(){}