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


// Ce programme teste le MTlongButton et donne les informations sur la console

#include <MTobjects.h> // V1.1.0 Voir http://arduino.dansetrad.fr/MTobjects

const uint8_t PIN_BUTTON = A0; // Bouton câblé entre GND et A0


void appuiLong(void) // Appelée quand on vient d'appuyer longtemps sur le bouton
{
  Serial.println("  Début de l'appui long"); 
}

void appui(void) // Appelée quand on vient d'appuyer sur le bouton
{
  Serial.println("Début de l'appui");
}

void relache(void) // Appelée quand on vient de relâcher le bouton
{
  Serial.println("  Fin de l'appui");
}

MTlongButton Bouton(PIN_BUTTON, 3000 milli_secondes, appuiLong, appui, relache); // Mise en place du bouton



void setup()
{
  Serial.begin(115200); // Il faut aussi régler la console sur 115200 bauds
}

void loop(){}