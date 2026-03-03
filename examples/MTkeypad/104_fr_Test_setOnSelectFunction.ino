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

// Test de setOnSelectFunction et setOnUnselectFunction de MTkeypad

//   4    5    6    7
//   │    │    │    │
//   ├─1  ├─2  ├─3  ├─A
//   │ └──│─┴──│─┴──│─┴───A0
//   ├─4  ├─5  ├─6  ├─B
//   │ └──│─┴──│─┴──│─┴───A1
//   ├─7  ├─8  ├─9  ├─C
//   │ └──│─┴──│─┴──│─┴───A2
//   └─*  └─0  └─#  └─D
//     └────┴────┴────┴───A3


#include <MTobjects.h> // V1.1.0 Voir http://arduino.dansetrad.fr/MTobjects

uint8_t pinLignes[] = {4 lignes_sur, A0, A1, A2, A3}; // Broches des lignes du keypad
uint8_t pinColonnes[] = {4 colonnes_sur, 4, 5, 6, 7}; // Broches des colonnes du keypad

const char touches[] = { // Correspondance entre les n° de touches et les symboles
    '1','2','3','A',
    '4','5','6','B',
    '7','8','9','C',
    '*','0','#','D'};



// Keypad
MTkeypad Keypad(pinLignes, pinColonnes); // Mise en place du keypad



// Fonctions callback
void affiche1(int8_t touche) // Appelé quand on appuie sur une touche
{
  Serial.print("  affiche1 :");
  Serial.println(touches[touche]); // Affichage du caractère associé
}

void affiche2(int8_t touche) // Appelé quand on appuie sur une touche
{
  Serial.print("  affiche2 :");
  Serial.println(touches[touche]); // Affichage du caractère associé
}

void relache1(void) // Appelé quand on relâche toutes les touches
{
  Serial.println("  relache1");
}

void relache2(void) // Appelé quand on relache toutes les touches
{
  Serial.println("  relache2");
}



// Changement des fonctions callback
byte laquelle = 0; // Choix du couple de fonctions callback
void change(void) // Change les fonctions callback toutes les 5 secondes
{
  switch (laquelle++)
  {
    case 0: Serial.println("Série 1");
      Keypad.setOnSelectFunction(affiche1);
      Keypad.setOnUnselectFunction(relache1);
      break;
    case 1: Serial.println("Série 2");
      Keypad.setOnSelectFunction(affiche2);
      Keypad.setOnUnselectFunction(relache2);
      break;
    case 2: Serial.println("Pas de fonctions callback");
      Keypad.setOnSelectFunction();
      Keypad.setOnUnselectFunction();
      laquelle = 0;
  }
}

MTclock Horloge(5000 milli_secondes, change); // Changement des fonctions callback



// Initialisation
void setup()
{
  Serial.begin(115200); // Mettre aussi la console sur 115200 bauds
}
  
void loop(){}
