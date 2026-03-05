// Version V1.1.0

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

// Simulation d'une serrure codée avec effacement de la mémoire en cas
// d'inactivité
//
// Code:1789# soit touches N°0, 6, 7, 8, 11

//   4    5    6
//   │    │    │
//   ├─1  ├─2  ├─3
//   │ └──│─┴──│─┴───A0
//   ├─4  ├─5  ├─6
//   │ └──│─┴──│─┴───A1
//   ├─7  ├─8  ├─9
//   │ └──│─┴──│─┴───A2
//   └─*  └─0  └─#
//     └────┴────┴───A3


#include <MTobjects.h> // V1.1.0 Voir http://arduino.dansetrad.fr/MTobjects

// Broches du keypad
const uint8_t PIN_LIGNES[] = {4 lignes_sur, A0, A1, A2, A3}; // Broches des lignes du keypad
const uint8_t PIN_COLONNES[] = {3 colonnes_sur, 4, 5, 6}; // Broches des colonnes du keypad

byte caracteresOK = 0; // Nombre de caractères justes déjà appuyés
byte code[4] = {0, 6, 7, 8}; // N° des touches pour 1789

const char touches[] = { // Correspondance pour l'affichage
    '1','2','3',
    '4','5','6',
    '7','8','9',
    '*','0','#'};


void raz(void); // Appelé si il n'y a pas d'activité
MTclock RemiseAZero(5000 milli_secondes, raz, 1 action_et_arret, MT_OFF); // Compte le temps d'inactivité


void nouvelleTouche(int8_t touche) // Appelé quand on appuie sur une touche
{
  switch (touche) // Gestion des touches appuyées
  {
    case 9: break; // Touche * ignorée
    case 11: // Touche #
      RemiseAZero.stop(); // Plus besoin de tester l'inactivité
      if (caracteresOK == 4) // Le code est bon
      {
        Serial.print("\nCode bon, mise sous tension de la gâche");
        delay(1000);
        Serial.println(" ... fin d'alimentation");
      }
      else Serial.println("\nCode incorrect");
      caracteresOK = 0; // On recommence depuis le début
      break;
    default: // Une autre touche est appuyée
      Serial.print(touches[touche]); // Affichage du caractère correspondant
      if (touche == code[caracteresOK]) // La touche est correcte
        caracteresOK++; // Prêt pour la touche suivante
      else caracteresOK = 0; // On recommence depuis le début
      RemiseAZero.start(); // Repart pour 5s avant la RAZ
  }    
}

MTkeypad Keypad(PIN_LIGNES, PIN_COLONNES, nouvelleTouche); // Mise en place du keypad


void raz(void) // Appelé si il n'y a pas d'activité
{
  caracteresOK = 0; // On recommencera depuis le début
  Serial.println("/"); // "Effacement" de l'affichage
}

void setup()
{
  Serial.begin(115200); // Mettre aussi la console sur 115200 bauds
}
  
void loop(){}
