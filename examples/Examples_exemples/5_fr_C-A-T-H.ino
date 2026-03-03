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


/// voir https://github.com/Phildem/Cath/blob/main/Cat-exemple_Schematic.GIF
// https://forum.arduino.cc/t/c-a-t-h-petit-systeme-multi-taches-cooperatif-pour-arduino/1379077


// *********************** SlowBlink ***********************
// Allumée 1s, éteinte 1s

const uint8_t LED_SLOW_BLINK = 4;

#include <MTobjects.h> // V1.1.0 Voir http://arduino.dansetrad.fr/MTobjects

MTsoftPWM SlowBlink(LED_SLOW_BLINK, impulsions_de 1000000L micro_secondes, periodes_de 2000000L micro_secondes);



// *********************** FastBlink ***********************
// Allumée 0,11s, éteinte 0,1s

const uint8_t LED_FAST_BLINK = 5;

#include <MTobjects.h> // V1.1.0 Voir http://arduino.dansetrad.fr/MTobjects

MTsoftPWM FastBlink(LED_FAST_BLINK, impulsions_de 110000L micro_secondes, periodes_de 210000L micro_secondes);



// *********************** Assymetric ***********************
// Allumée 50ms, période 1,11s

const uint8_t LED_ASSYMETRIC = 6;

#include <MTobjects.h> // V1.1.0 Voir http://arduino.dansetrad.fr/MTobjects

MTsoftPWM Assymetric(LED_ASSYMETRIC, impulsions_de 50000L micro_secondes, periodes_de 1110000L micro_secondes);



// *********************** A ou B ***********************

const uint8_t LED_A_OU_B = 7;
const uint8_t BOUTON_A_OU = 2;
const uint8_t BOUTON_B_OU = 3;

#include <MTobjects.h> // V1.1.0 Voir http://arduino.dansetrad.fr/MTobjects

void ou(void);

MTbutton BoutonAou(BOUTON_A_OU, ou, ou);

MTbutton BoutonBou(BOUTON_B_OU, ou, ou);

void ou(void)
{
  pinMode(LED_A_OU_B, OUTPUT);
  digitalWrite(LED_A_OU_B, BoutonAou.getSelect() | BoutonBou.getSelect() ? HIGH : LOW);
}


// *********************** A ET B ***********************

const uint8_t LED_A_ET_B = 8;
const uint8_t BOUTON_A_ET = 2;
const uint8_t BOUTON_B_ET = 3;

#include <MTobjects.h> // V1.1.0 Voir http://arduino.dansetrad.fr/MTobjects

void et(void);

MTbutton BoutonAet(BOUTON_A_ET, et, et);

MTbutton BoutonBet(BOUTON_B_ET, et, et);

void et(void)
{
  pinMode(LED_A_ET_B, OUTPUT);
  digitalWrite(LED_A_ET_B, BoutonAet.getSelect() & BoutonBet.getSelect() ? HIGH : LOW);
}



// *********************** A ouexclusif B ***********************

const uint8_t LED_A_OUEXCLUSIF_B = 9;
const uint8_t BOUTON_A_OUEXCLUSIF = 2;
const uint8_t BOUTON_B_OUEXCLUSIF = 3;

#include <MTobjects.h> // V1.1.0 Voir http://arduino.dansetrad.fr/MTobjects

void ouexclusif(void);

MTbutton BoutonAouexclusif(BOUTON_A_OUEXCLUSIF, ouexclusif, ouexclusif);

MTbutton BoutonBouexclusif(BOUTON_B_OUEXCLUSIF, ouexclusif, ouexclusif);

void ouexclusif(void)
{
  pinMode(LED_A_OUEXCLUSIF_B, OUTPUT);
  digitalWrite(LED_A_OUEXCLUSIF_B, BoutonAouexclusif.getSelect() ^ BoutonBouexclusif.getSelect() ? HIGH : LOW);
}



// *********************** Pour faire autre chose ***********************

void setup(){}

void loop(){}
