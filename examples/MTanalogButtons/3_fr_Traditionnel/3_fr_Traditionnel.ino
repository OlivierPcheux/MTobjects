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

// Ce programme utilise MTanalogButtons de façon traditionnelle (apparemment
// sans interruptions)

#include <MTobjects.h> // V1.1.1 Voir http://arduino.dansetrad.fr/MTobjects


// Bien entendu, il faut adapter PIN, REFERENCE, BAUDS, TABLE_DES_SEUILS et touches

const uint8_t PIN = A5; // Changer A5 en A0..A7 suivant le cas
#define REFERENCE INTERNAL
#define BAUDS 115200 // 115200 conseillée, mais on peut utiliser 9600

const word TABLE_DES_SEUILS[] = {982, 922, 880, 840, 797, 754, 710, 665, 619, 572, 522, 471, 421, 369, 316, 260, 203, 145, 87, 28, 0}; // Valeurs des seuils de comparaisons

//   Y X W V U
//   T S R Q P
//   O N M L K
//   J I H G F
//   E D C B A

const char touches[] = { // Correspondance pour l'affichage
    '-', // 0 correspont à pas d'appuis
    'T','S','R','Q','P', // La touche T renvoie 1...
    'O','N','M','L','K',
    'J','I','H','G','F',
    'E','D','C','B','A'
    };

MTanalogButtons Keypad(PIN, TABLE_DES_SEUILS);

void setup()
{
  Serial.begin(BAUDS);
  analogReference(REFERENCE); // Permet de choisir la référence de tension
  Serial.println("Appuyez sur des touches");
}

byte key, oldKey;
void loop()
{
  key = Keypad.getKey();
  if (key != oldKey)
  {
    if (key)
    {
      Serial.print(touches[key]);
      Serial.print(" appuyé ");
    }
    else Serial.println("et relâché");
    oldKey = key;
  }
}