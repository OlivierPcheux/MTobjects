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


// The program will turn on the LED_BUILTIN led when pressing a button.

// Ce programme allume une led si on appuie sur un bouton.

#include <MTobjects.h> // V1.1.0 Voir http://arduino.dansetrad.fr/MTobjects

const uint8_t PIN_BUTTON = A0; // Bouton câblé entre GND et A0


void allume(void) // Appelée quand on vient d'appuyer sur le bouton
{
  digitalWrite(LED_BUILTIN, HIGH); // Allumer la led
}

void eteint(void) // Appelée quand on vient de relâcher le bouton
{
  digitalWrite(LED_BUILTIN, LOW); // Éteindre la led
}

MTbutton Bouton(PIN_BUTTON, allume, eteint); // Mise en place du bouton



void setup()
{
  pinMode(LED_BUILTIN, OUTPUT); // Initialisation de la led
}

void loop(){}