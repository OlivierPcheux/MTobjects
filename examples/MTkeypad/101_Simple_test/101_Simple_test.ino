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

// Test de base de MTkeypad et ses attributs 

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

void affiche(int8_t touche) // Appelé quand on appuie sur une touche
{
  Serial.print("Touche N°");
  Serial.print(touche);
  Serial.println(" appuyée");
}

void relache(void) // Appelé quand on relâche toutes les touches
{
  Serial.println("Aucune touche appuyée");
}

MTkeypad Keypad(pinLignes, pinColonnes, affiche, relache); // Mise en place du keypad

void setup()
{
  Serial.begin(115200); // Mettre aussi la console sur 115200 bauds
}
  
void loop(){}
