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

// Ce programme teste la lecture de l'ensemble de boutons avec MTanalogButtons

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

const word TABLE_DES_SEUILS[] = {982, 922, 880, 840, 797, 754, 710, 665, 619, 572, 522, 471, 421, 369, 316, 260, 203, 145, 87, 28, 0}; // Valeurs des seuils de comparaisons

void appuis(byte touche)
{
  Serial.print("La touche n°");
  Serial.print(touche);
  Serial.print(" vient d'être appuyée ");
}
void relachement(void)
{
  Serial.println("et relâchée");
}
MTanalogButtons Keypad(PIN, TABLE_DES_SEUILS, appuis, relachement);

void setup()
{
  Serial.begin(BAUDS);
  analogReference(REFERENCE); // Permet de choisir la référence de tension
  Serial.println("Appuyez sur des touches");
}

void loop(){}