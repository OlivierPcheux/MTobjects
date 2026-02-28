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


// Ce programme redéfinit des boutons pour envoyer des caractères. Ici on va
// dériver une nouvelle classe pour éviter de redéfinir plein de fonctions

#include <MTobjects.h> // V1.1.0 Voir http://arduino.dansetrad.fr/MTobjects

const uint8_t PIN_BUTTON_A = A0; // Bouton câblé entre GND et A0
const uint8_t PIN_BUTTON_B = A1;
const uint8_t PIN_BUTTON_C = A2;
const uint8_t PIN_BUTTON_D = A3;
const uint8_t PIN_BUTTON_E = A4;
const uint8_t PIN_BUTTON_F = A5;


// Définition d'une nouvelle classe qui surcharge onSelect
class MonBouton: public MTbutton
{
 public:
  MonBouton (uint8_t pin, char lettre) // Nouveau constructeur
  :MTbutton(pin), lettre(lettre) 
  {};
 private:
  char lettre; // Lettre qui sera envoyée sur la voie série
  virtual void onSelect(void) // Fonction à surcharger qui envoie une lettre
  {
    Serial.print(lettre);
  }
};


// Définition des boutons
MonBouton BoutonA(PIN_BUTTON_A, 'A'); // Ce bouton va donc envoyer la lettre 'A'
MonBouton BoutonB(PIN_BUTTON_B, 'B');
MonBouton BoutonC(PIN_BUTTON_C, 'C');
MonBouton BoutonD(PIN_BUTTON_D, 'D');
MonBouton BoutonE(PIN_BUTTON_E, 'E');
MonBouton BoutonF(PIN_BUTTON_F, 'F');


void setup()
{
  Serial.begin(115200); // Initialisation de la console
}

void loop(){}  
