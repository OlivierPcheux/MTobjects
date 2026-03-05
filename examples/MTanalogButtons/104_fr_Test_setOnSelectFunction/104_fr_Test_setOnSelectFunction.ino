// Version V1.1.1

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

// Test de setOnSelectFunction et setOnUnselectFunction de MTanalogButtons

#include <MTobjects.h> // V1.1.1 Voir http://arduino.dansetrad.fr/MTobjects

// Il faut donner la broche pour la lecture analogique
const uint8_t PIN = A5; // Changer A5 en A0..A7 suivant le cas
//
// Il faut choisir la référence de tension à utiliser pour la conversion
// DEFAULT: pour Vcc
// INTERNAL: 1,1V pour Nano/Uno
// INTERNAL1V1: 1,1V pour Mega
// INTERNAL2V56: 2,56V pour Mega
// EXTERNAL: pour utiliser AREF
#define REFERENCE INTERNAL
//
// Il faut donner le taux de transfert de la console
#define BAUDS 115200 // 115200 conseillée, mais on peut mettre 9600
// Ne pas oublier de régler la console à 115200 bauds

const word TABLE_DES_SEUILS[] = {942, 838, 797, 709, 618, 571, 471, 369, 316, 203, 87, 28, 0}; // Valeurs des seuils de comparaisons

//
//   1  2  3
//   4  5  6
//   7  8  9
//   *  0  #


const char touches[] = { // Correspondance pour l'affichage
    'X', // correspond à pas d'appui
    '#','0','*', // la touche # renvoie 1...
    '9','8','7',
    '6','5','4',
    '3','2','1',
    };




// Keypad
MTanalogButtons Keypad(PIN, TABLE_DES_SEUILS); // Mise en place du keypad



// Fonctions callback
void affiche1(byte touche) // Appelé quand on appuie sur une touche
{
  Serial.print("  affiche1 :");
  Serial.println(touches[touche]); // Affichage du caractère associé
}

void affiche2(byte touche) // Appelé quand on appuie sur une touche
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
  change(); // Pour mettre en place la première série de fonctions
}
  
void loop(){}
