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


// Je veux un feu tricolore, et quand un piéton appuie sur le bouton, le feu
// passe immédiatement à l'orange. Bien entendu quand le feu passe au vert,
// une temporisation empêche le feu de passer à l'orange immédiatement. Les
// temporisations se feront avec delay().

// Les temporisations sont plus petites que dans la vraie vie pour voir le
// fonctionnement


// Voir https://forum.arduino.cc/t/piloter-luminaires-electrique-exterieur-avec-portail-electrique/1384084

/////////////////////////// Bibliothèque utilisée ///////////////////////////
#include <MTobjects.h> // V1.1.0 Voir http://arduino.dansetrad.fr/MTobjects


/////////////////////////// Broches utilisées ///////////////////////////////
const uint8_t BROCHE_BOUTON = 2; // Pour le piéton, un appui bloque les voitures
const uint8_t VERT = 5; // Un HIGH sur la broche A1 allume le feu vert
const uint8_t ORANGE = 4; // Un HIGH sur la broche A2 allume le feu orange
const uint8_t ROUGE = 3; // Un HIGH sur la broche A3 allume le feu rouge


/////////////////////////// Variable globale ///////////////////////////////
volatile boolean boutonMemorise; // Passe à true lors d'un appel
// Il faut déclarer le bouton volatile pour que le while dans loop relise
// l'état du bouton à chaque itération. "boutonMemorise" est modifié par
// interruption, et si on ne met pas "volatile", le compilateur optimise et
// et ne refait pas la lecture


/////////////////////////// Mise en place du bouton ////////////////////////
void memorisation(void)
{
  boutonMemorise = true; // Si on est ici, c'est que le bouton à été appuyé
}
MTbutton Bouton(BROCHE_BOUTON, memorisation); // Appel de la fonction si appui
// Note: Un MTbutton fonctionne aussi pendant le delay



/////////////////////////// Setup et loop ///////////////////////////////////
void setup()
{
  pinMode(VERT, OUTPUT);
  pinMode(ORANGE, OUTPUT);
  pinMode(ROUGE, OUTPUT);
}

void loop()
{
  // Feu vert
  digitalWrite(VERT, HIGH); // Allumage du feu vert
  digitalWrite(ROUGE, LOW);
  delay(3000); // Le feu vert dure au minimum 3s, il ne peut pas être interrompu avant

  // Attente de l'appui sur le bouton
  while (boutonMemorise == false); // On reste au vert si il n'y a pas de piétons

  // Feu orange
  digitalWrite(ORANGE, HIGH); // Allumage du feu orange
  digitalWrite(VERT, LOW);
  delay(1000); // Le feu orange dure 1s

  // Feu rouge
  digitalWrite(ROUGE, HIGH); // Allumage du feu rouge
  digitalWrite(ORANGE, LOW);
  boutonMemorise = false; // Effacement de la mémoire, on a pris en compte le bouton
  // En effaçant la mémoire maintenant l'appui peut être enregistré même pendant le feu rouge
  delay(5000); // Le feu rouge dure 5s
}