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


// Ce programme allume une led si on appuie sur un bouton. 

#include <MTobjects.h> // V1.1.0 Voir http://arduino.dansetrad.fr/MTobjects

const uint8_t PIN_BUTTON = A0; // Bouton câblé entre GND et A0

MTbutton Bouton(PIN_BUTTON); // Mise en place du bouton



void setup()
{
  pinMode(LED_BUILTIN, OUTPUT); // Initialisation de la led
}

void loop()
{
  digitalWrite(LED_BUILTIN, Bouton.getSelect()); // Copie l'état du bouton dans la led
  // digitalWrite(LED_BUILTIN, Bouton.getSelect()? HIGH : LOW) ; // Plus correct!
}