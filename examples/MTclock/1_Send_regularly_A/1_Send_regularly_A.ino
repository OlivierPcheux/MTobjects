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


// This program regularly sends the letter 'A' on the console

#include <MTobjects.h> // V1.0.6 See http://arduino.dansetrad.fr/MTobjects  

void send(void)
{
  Serial.print('A');
}

MTclock Metronme(1000 milli_seconds, send);



void setup()
{
  Serial.begin(115200);
}

void loop(){}
