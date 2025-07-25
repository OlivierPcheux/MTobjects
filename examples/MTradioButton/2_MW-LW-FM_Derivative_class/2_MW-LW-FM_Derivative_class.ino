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


// Ce programme va simuler un choix MW-LW-FM. On choisit la gamme par des
// boutons câblés sur A0, A1, et A2. La console nous indique les changements
// On va utiliser une classe dérivée de MTradioButton

#include <MTobjects.h> // V1.0.6 See http://arduino.dansetrad.fr/MTobjects

const uint8_t PIN_BUTTON_MW = A0; // Bouton câblé entre GND et A0
const uint8_t PIN_BUTTON_LW = A1; // Bouton câblé entre GND et A1
const uint8_t PIN_BUTTON_FM = A2; // Bouton câblé entre GND et A2

// Définition d'une nouvelle classe qui surcharge onSelect et onUnselect
class MonBouton: public MTradioButton
{
 public:
  MonBouton (uint8_t pin, String p_nom, byte valeur) // Nouveau constructeur
    :MTradioButton(pin, NO_ACTION, NO_ACTION, HIGH if_not_pressed, valeur), nom(p_nom)
    {};
 private:
  String nom; // Nom qui sera affiché sur la voie série
  virtual void onSelect(void) // Fonction à surcharger qui informe la sélection
  {
    Serial.print("On vient de choisir ");
    Serial.println(nom);
  }
  virtual void onUnselect(void) // Fonction à surcharger qui informe la désélection
  {
    Serial.print("On vient d'annuler ");
    Serial.println(nom);
  }
};



//Définition des boutons
MonBouton BoutonMW(PIN_BUTTON_MW, "MW", RADIO_BUTTON_0);
MonBouton BoutonLW(PIN_BUTTON_LW, "LW", RADIO_BUTTON_1);
MonBouton BoutonFM(PIN_BUTTON_FM, "FM", RADIO_BUTTON_2);



void setup()
{
  Serial.begin(115200);
  BoutonMW.select(); // Pour qu'il y ait au moins une gamme sélectionnée
  delay(16 milli_seconds); // Ainsi on est sûr que le bouton est sélectionné (retard possible de la prise en compte 16ms)
}


String noms[3] = {"MW", "LW", "FM"};

void loop()
{
  Serial.print("La gamme actuelle est ");
  Serial.println(noms[getMTradioButtonValeur()]);
  delay(2000 milli_seconds); // Pour avoir un affichage qui ne défile pas trop vite
}
