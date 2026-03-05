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

// Simulation d'une serrure codée.
// J'utilise un keypad 20 touches. Pour que ce programme fonctionne, il faut
// tout adapter PIN, REFERENCE, BAUDS, TABLE_DES_SEUILS, code[4]

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

// Code:1789# soit touches N°12, 6, 5, 4
byte code[4] = {12, 6, 5, 4}; // N° des touches pour 1789
//
//   1  2  3
//   4  5  6
//   7  8  9
//   *  0  #



byte caracteresOK = 0; // Nombre de caractères justes déjà appuyés

const char touches[] = { // Correspondance pour l'affichage
    'X', // Correspond à pas d'appui
    '#','0','*', // La touche # renvoie 1...
    '9','8','7',
    '6','5','4',
    '3','2','1',
    };


void raz(void) // Appelé si il n'y a pas d'activité
{
  caracteresOK = 0; // On recommencera depuis le début
  Serial.println("/"); // "Effacement" de l'affichage
}
MTclock RemiseAZero(5000 milli_secondes, raz, 1 action_et_arret, MT_OFF); // Compte le temps d'inactivité



void nouvelleTouche(byte touche) // Appelé quand on appuie sur une touche
{
  switch (touche) // Gestion des touches appuyées
  {
    case 3: break; // Touche * ignorée
    case 1: // Touche #
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
    default: // Une touche numérique est appuyée
      RemiseAZero.start(); // Repart pour 5s avant la RAZ
      Serial.print(touches[touche]); // Affichage du caractère correspondant
      if (touche == code[caracteresOK]) // La touche est correcte
        caracteresOK++; // Prêt pour la touche suivante
      else caracteresOK = 0; // On recommence depuis le début
  }    
}

MTanalogButtons Keypad(PIN, TABLE_DES_SEUILS, nouvelleTouche); // Mise en place du keypad

void setup()
{
  Serial.begin(BAUDS);
  analogReference(REFERENCE); // Permet de choisir la référence de tension
}
  
void loop(){}
