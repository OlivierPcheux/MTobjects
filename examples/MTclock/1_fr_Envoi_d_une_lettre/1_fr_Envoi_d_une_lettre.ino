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


// Ce programme envoie régulièrement sur la liaison série la lettre 'A'

#include <MTobjects.h> // V1.1.0 Voir http://arduino.dansetrad.fr/MTobjects

void envoi(void)
{
  Serial.print('A');
}

MTclock Metronome(1000 milli_secondes, envoi);



void setup()
{
  Serial.begin(115200);
}

void loop(){}  
