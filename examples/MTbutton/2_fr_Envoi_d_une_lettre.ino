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


// Ce programme envoie sur la liaison série la lettre 'A' chaque fois que
// l'on appuie sur le bouton

#include <MTobjects.h> // V1.1.0 Voir http://arduino.dansetrad.fr/MTobjects

const uint8_t PIN_BUTTON = A0; // Bouton câblé entre GND et A0


void envoi(void) // Appelée quand on vient d'appuyer sur le bouton
{
  Serial.print('A');
}

MTbutton Bouton(PIN_BUTTON, envoi); // Mise en place du bouton



void setup()
{
  Serial.begin(115200); // Initialisation de la console
}

void loop(){}  
