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


// See https://forum.arduino.cc/t/faire-clignoter-3-led-avec-3-boutons-poussoirs/1124797

#include "MTobjects.h" // V1.0.6 See http://arduino.dansetrad.fr/MTobjects

const byte LED_1 = 2;
const byte LED_2 = 3;
const byte LED_3 = 4;
const byte BUTTON_1 = A0;
const byte BUTTON_2 = A1;
const byte BUTTON_3 = A2;


MTsoftPWM Flash1(LED_1, inpulses_width 500000 micro_seconds, periods_width 1000000 micro_seconds, start_with LOW, MT_INFINI, NO_ACTION, MT_OFF);
MTsoftPWM Flash2(LED_2, inpulses_width 500000 micro_seconds, periods_width 1000000 micro_seconds, start_with LOW, MT_INFINI, NO_ACTION, MT_OFF);
MTsoftPWM Flash3(LED_3, inpulses_width 500000 micro_seconds, periods_width 1000000 micro_seconds, start_with LOW, MT_INFINI, NO_ACTION, MT_OFF);


void flashsOn1(void)
{
  Flash1.start();
  if (Flash2.getActive()) Flash2.start();
  if (Flash3.getActive()) Flash3.start();
}
void flashsOn2(void)
{
  Flash2.start();
  if (Flash1.getActive()) Flash1.start();
  if (Flash3.getActive()) Flash3.start();
}
void flashsOn3(void)
{
  Flash3.start();
  if (Flash1.getActive()) Flash1.start();
  if (Flash2.getActive()) Flash2.start();
}

void flashsOff1(void)
{
  Flash1.stop();
  digitalWrite(LED_1, LOW); // We don't know when we stop it
}
void flashsOff2(void)
{
  Flash2.stop();
  digitalWrite(LED_2, LOW); // We don't know when we stop it
}
void flashsOff3(void)
{
  Flash3.stop();
  digitalWrite(LED_3, LOW); // We don't know when we stop it
}


MTcheckButton Bouton1(BUTTON_1, flashsOn1, flashsOff1);
MTcheckButton Bouton2(BUTTON_2, flashsOn2, flashsOff2);
MTcheckButton Bouton3(BUTTON_3, flashsOn3, flashsOff3);


void setup(){}

void loop(){}