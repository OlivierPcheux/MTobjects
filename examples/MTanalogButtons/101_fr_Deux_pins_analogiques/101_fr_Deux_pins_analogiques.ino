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

// Ce programme vérifie qu'une lecture analogique sur une autre broche
// analogique ne perturbe pas la mesure
// Comme on utilise un seul CAN avec un multplexeur, il faut vérifier qu'en
// passant d'une broche à l'autre, on arrive bien à lire
//
// Ici, on va lire un keypad avec la broche A5 et metre la broche A0 à 5V.
// Comme on a deux MTanalogButtons, on va lire alternativement A5 et A0
// Avant la lecture des boutons, on lira donc un 5V.

#include <MTobjects.h> // V1.1.1 Voir http://arduino.dansetrad.fr/MTobjects


const byte PIN_1 = A5;
const byte PIN_2 = A0; // La broche A0 est à 5V
const word TABLE_DES_SEUILS[] = {982, 920, 880, 840, 797, 754, 710, 665, 619, 571, 523, 471, 421, 369, 316, 260, 204, 145, 87, 28, 0}; // Valeurs des seuils de comparaisons

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

MTanalogButtons Keypad1(PIN_1, TABLE_DES_SEUILS, appuis, relachement); // Celui que l'on observe
MTanalogButtons Keypad2(PIN_2, TABLE_DES_SEUILS); // Imposera des lectures à 1024


void setup()
{
  Serial.begin(115200); // Régler aussi la console à 115200 bauds!
  analogReference(INTERNAL); // On a ainsi allers retour sur le CAN entre le 5V et une tension faible si on appui sur un bouton
  Serial.println("Appuyez sur des touches");
}

void loop()
{
}