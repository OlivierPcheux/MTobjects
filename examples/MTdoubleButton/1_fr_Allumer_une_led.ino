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


// Ce programme allume une led si on fait un double clic sur le bouton et
// éteint la led sur un simple clic. 

#include <MTobjects.h> // V1.1.0 Voir http://arduino.dansetrad.fr/MTobjects

const uint8_t PIN_BUTTON = A0; // Bouton câblé entre GND et A0


void allume(void) // Appelée sur double-clic
{
  digitalWrite(LED_BUILTIN, HIGH); // On allume
}

void eteint(void) // Appelée sur simple-clic
{
  digitalWrite(LED_BUILTIN, LOW); // On éteint
}

MTdoubleButton Bouton(PIN_BUTTON, allume, eteint); // Mise en place du bouton



void setup()
{
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop(){}  
