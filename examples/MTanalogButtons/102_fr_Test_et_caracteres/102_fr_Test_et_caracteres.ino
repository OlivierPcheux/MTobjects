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

// Test de base de MTanalogButtons et ses attributs avec affichage des caractères

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

void affiche(byte touche) // Appelé quand on appuie sur une touche
{
  Serial.print(touches[touche]); // Affichage du caractère associé
}

void relache(void) // Appelé quand on relâche toutes les touches
{
  Serial.println();
}

MTanalogButtons Keypad(PIN, TABLE_DES_SEUILS, affiche, relache); // Mise en place du keypad

void setup()
{
  Serial.begin(BAUDS);
  analogReference(REFERENCE); // Permet de choisir la référence de tension
}
  
void loop(){}
