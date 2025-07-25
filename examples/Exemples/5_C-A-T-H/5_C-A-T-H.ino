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


/// See https://github.com/Phildem/Cath/blob/main/Cat-exemple_Schematic.GIF
// https://forum.arduino.cc/t/c-a-t-h-petit-systeme-multi-taches-cooperatif-pour-arduino/1379077


// *********************** SlowBlink ***********************
// On 1s, off 1s

const uint8_t LED_SLOW_BLINK = 4;

#include "MTobjects.h" // See http://arduino.dansetrad.fr/MTobjects

MTsoftPWM SlowBlink(LED_SLOW_BLINK, inpulses_width 1000000L micro_seconds, periods_width 2000000L micro_seconds);



// *********************** FastBlink ***********************
// On 0,11s, off 0,1s

const uint8_t LED_FAST_BLINK = 5;

#include "MTobjects.h" // See http://arduino.dansetrad.fr/MTobjects

MTsoftPWM FastBlink(LED_FAST_BLINK, inpulses_width 110000L micro_seconds, periods_width 210000L micro_seconds);



// *********************** Assymetric ***********************
// On 50ms, Off 1,11s

const uint8_t LED_ASSYMANDRIC = 6;

#include "MTobjects.h" // See http://arduino.dansetrad.fr/MTobjects

MTsoftPWM Assymetric(LED_ASSYMANDRIC, inpulses_width 50000L micro_seconds, periods_width 1110000L micro_seconds);



// *********************** A OR B ***********************

const uint8_t LED_A_OR_B = 7;
const uint8_t BUTTON_A_OU = 2;
const uint8_t BUTTON_B_OU = 3;

#include "MTobjects.h" // See http://arduino.dansetrad.fr/MTobjects

void OR(void);

MTbutton ButtonAor(BUTTON_A_OU, OR, OR);

MTbutton ButtonBor(BUTTON_B_OU, OR, OR);

void OR(void)
{
  pinMode(LED_A_OR_B, OUTPUT);
  digitalWrite(LED_A_OR_B, ButtonAor.getSelect() | ButtonBor.getSelect() ? HIGH : LOW);
}


// *********************** A AND B **********************

const uint8_t LED_A_AND_B = 8;
const uint8_t BUTTON_A_AND = 2;
const uint8_t BUTTON_B_AND = 3;

#include "MTobjects.h" // See http://arduino.dansetrad.fr/MTobjects

void AND(void);

MTbutton ButtonAand(BUTTON_A_AND, AND, AND);

MTbutton ButtonBand(BUTTON_B_AND, AND, AND);

void AND(void)
{
  pinMode(LED_A_AND_B, OUTPUT);
  digitalWrite(LED_A_AND_B, ButtonAand.getSelect() & ButtonBand.getSelect() ? HIGH : LOW);
}



// *********************** A XOR B ***********************

const uint8_t LED_A_XOR_B = 9;
const uint8_t BUTTON_A_XOR = 2;
const uint8_t BUTTON_B_XOR = 3;

#include "MTobjects.h" // See http://arduino.dansetrad.fr/MTobjects

void XOR(void);

MTbutton ButtonAxor(BUTTON_A_XOR, XOR, XOR);

MTbutton ButtonBxor(BUTTON_B_XOR, XOR, XOR);

void XOR(void)
{
  pinMode(LED_A_XOR_B, OUTPUT);
  digitalWrite(LED_A_XOR_B, ButtonAxor.getSelect() ^ ButtonBxor.getSelect() ? HIGH : LOW);
}



// *********************** To do something else *************************

void setup(){}

void loop(){}