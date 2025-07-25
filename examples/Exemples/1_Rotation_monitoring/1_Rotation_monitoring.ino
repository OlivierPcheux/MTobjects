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

// An axis must run permanently. If it stops, the nano must send a
// signal indicating the stop.

#include <MTobjects.h> // V1.0.6 See http://arduino.dansetrad.fr/MTobjects

const byte CAPTEUR = 2;


void lights(void) // Called in the event of a stop of more than 3s
{
  digitalWrite(LED_BUILTIN, HIGH);
}
MTclock Timer(3000 milli_seconds, lights);


void lightOff(void) // Appelée pour chaque front du capteur
{
  pinMode(LED_BUILTIN, OUTPUT); // Can be put in the setup
  Timer.start(); // Reset the timer
  digitalWrite(LED_BUILTIN, LOW);
}
MTbutton Capteur(CAPTEUR, lightOff, lightOff);


void setup(){}
void loop(){}