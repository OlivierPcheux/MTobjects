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


// This program will send continusly 5 letters

#include <MTobjects.h> // V1.0.6 See http://arduino.dansetrad.fr/MTobjects

void sendE(void); // Predefinition because it contains reference to MonostableA
MTclock MonostableE(1000 milli_seconds, sendE, 1 action_and_stop, MT_OFF);

void sendD(void) { Serial.print('D'); MonostableE.start(); }
MTclock MonostableD(1000 milli_seconds, sendD, 1 action_and_stop, MT_OFF);

void sendC(void) { Serial.print('C'); MonostableD.start(); }
MTclock MonostableC(1000 milli_seconds, sendC, 1 action_and_stop, MT_OFF);

void sendB(void) { Serial.print('B'); MonostableC.start(); }
MTclock MonostableB(1000 milli_seconds, sendB, 1 action_and_stop, MT_OFF);

void sendA(void) { Serial.print('A'); MonostableB.start(); }
MTclock MonostableA(1000 milli_seconds, sendA, 1 action_and_stop, MT_ON);

void sendE(void) { Serial.println('E'); MonostableA.start(); }


void setup()
{
  Serial.begin(115200);
}

void loop(){}