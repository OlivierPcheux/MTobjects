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


// Ce programme envoie 5 lettres en boucle sur la voie série

#include <MTobjects.h> // V1.1.0 Voir http://arduino.dansetrad.fr/MTobjects

void envoiE(void); // Prédéfinition car elle contient référence à MonostableA
MTclock MonostableE(1000 milli_secondes, envoiE, 1 action_et_arret, MT_OFF);

void envoiD(void) { Serial.print('D'); MonostableE.start(); }
MTclock MonostableD(1000 milli_secondes, envoiD, 1 action_et_arret, MT_OFF);

void envoiC(void) { Serial.print('C'); MonostableD.start(); }
MTclock MonostableC(1000 milli_secondes, envoiC, 1 action_et_arret, MT_OFF);

void envoiB(void) { Serial.print('B'); MonostableC.start(); }
MTclock MonostableB(1000 milli_secondes, envoiB, 1 action_et_arret, MT_OFF);

void envoiA(void) { Serial.print('A'); MonostableB.start(); }
MTclock MonostableA(1000 milli_secondes, envoiA, 1 action_et_arret, MT_ON);

void envoiE(void) { Serial.println('E'); MonostableA.start(); }


void setup()
{
  Serial.begin(115200);
}

void loop(){}  
