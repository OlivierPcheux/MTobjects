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


// Ce programme va simuler un choix MW-LW-FM. On choisit la gamme par des
// boutons câblés sur A0, A1, et A2. La console nous indique les changements 

#include <MTobjects.h> // V1.1.0 Voir http://arduino.dansetrad.fr/MTobjects

const uint8_t PIN_BUTTON_MW = A0; // Bouton câblé entre GND et A0
const uint8_t PIN_BUTTON_LW = A1; // Bouton câblé entre GND et A1
const uint8_t PIN_BUTTON_FM = A2; // Bouton câblé entre GND et A2


//Définition du bouton MW
void choixMW(void)
{
  Serial.println("On vient de choisir MW"); // Appelée si on appuie sur MW
}

void choixMWfini(void)
{
  Serial.println("On vient d'annuler MW"); // Appelée si on appuie sur LW ou FM
}

MTradioButton BoutonMW(PIN_BUTTON_MW, choixMW, choixMWfini, HIGH si_non_appuye, RADIO_BUTTON_0);



//Définition du bouton LW
void choixLW(void)
{
  Serial.println("On vient de choisir LW");
}

void choixLWfini(void)
{
  Serial.println("On vient d'annuler LW");
}

MTradioButton BoutonLW(PIN_BUTTON_LW, choixLW, choixLWfini, HIGH si_non_appuye, RADIO_BUTTON_1);



//Définition du bouton FM
void choixFM(void)
{
  Serial.println("On vient de choisir FM");
}

void choixFMfini(void)
{
  Serial.println("On vient d'annuler FM");
}

MTradioButton BoutonFM(PIN_BUTTON_FM, choixFM, choixFMfini, HIGH si_non_appuye, RADIO_BUTTON_2);



void setup()
{
  Serial.begin(115200);
  BoutonMW.select(); // Pour qu'il y ait au moins une gamme sélectionnée
  delay(16 milli_secondes); // Ainsi on est sûr que le bouton est sélectionné (retard possible de la prise en compte 16ms)
}


String noms[3] = {"MW", "LW", "FM"};

void loop()
{
  Serial.print("La gamme actuelle est ");
  Serial.println(noms[getMTradioButtonValeur()]);
  delay(2000 milli_secondes); // Pour avoir un affichage qui ne défile pas trop vite
}
