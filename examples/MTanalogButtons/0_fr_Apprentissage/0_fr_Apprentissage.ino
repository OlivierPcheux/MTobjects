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

// Ce programme utilise l'apprentissage pour générer un programme dedémonstration
// de MTanalogButtons
//
// Il faut changer quelques constantes pour le configurer.
//
// Il faut donner la broche pour la lecture analogique
#define PIN A5 // Changer A5 en A0..A7 suivant le cas
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



// *************************** Mémorisation des valeurs du CAN pour tous les boutons
byte lecture[128]; // Contiendra les valeurs possibles du CAN pour tous les boutons   

inline void ecrire(word valeur) // Enregistre que l'on a vu la valeur passée en argument (0 à 1023)
{
  lecture[valeur/8] = bitSet(lecture[valeur/8], valeur%8);
}

byte lire(word valeur) // true si le CAN a eu cette valeur
{
  return bitRead(lecture[valeur/8], valeur%8); 
}


// *************************** Variables globales
boolean repos; // true pour 1023, false pour 0 quand aucun bouton n'est appuyé
word valeurLue, // Résultat de la conversion puis n° de la touche
     oldValeurLue, oldOldValeurLue, // Mémorisation pour permettre trois lectures consécutives identiques
     tempsDepart; // Pour patienter tant qu'on appuie sur une touche; word suffit car on ne dépassera jamais 3000
int indexDebut = 0, indexFin = 0; // Pour explorer la table et lire les valeurs limites
byte nbBoutons = 0;
boolean pasPremiereVirgule = false;



void setup()
{
	
  // *************************** Initialisations
  Serial.begin(BAUDS); // Régler aussi la console à BAUDS bauds!
  analogReference(REFERENCE); // Permet de choisir la référence de tension
  Serial.println(F("/*\nAppuyez sur toutes les touches, une par une\n"));
  repos = (analogRead(PIN) > 512); // Au repos on a 0 ou 1023

  // *************************** On attend qu'une touche soit appuyée
  do
  {
    oldValeurLue = valeurLue; // Sauvegarde de la mesure précédente du CAN
    valeurLue = analogRead(PIN); // Nouvelle lecture
  } while ((valeurLue!=oldValeurLue) || // Il faut lire deux valeurs identiques (double lecture par sécurité)
     (repos && (valeurLue > 1020)) || (!repos && (valeurLue < 3))); // Et on s'écarte du repos

  // *************************** Recherche des valeurs possibles du CAN
  do // Tant qu'on appui sur des touches
  {
    do // Tant que l'on ne lit pas une bonne valeur du CAN
    {
      oldOldValeurLue = oldValeurLue; // Sauvegarde des mesures précédentes du CAN
      oldValeurLue = valeurLue;
      valeurLue = analogRead(PIN); // Nouvelle lecture
    } while ((valeurLue!=oldValeurLue) || (valeurLue!=oldOldValeurLue)); // On recommence jusqu'à avoir trois lectures identiques
    ecrire(valeurLue); // On trouve une valeur, on l'enregistre

    // Gestion du timer, on sortir de la boucle si on n'appuie plus sur une touche pendant 3s
    if (repos) // Suivant qu'on ait 0 ou 1023 sans appuis
    {
      if (analogRead(PIN) < 1020) tempsDepart = millis(); // RAZ du timer tant qu'on appuie
    }
    else if (analogRead(PIN) > 5) tempsDepart = millis();
  } while ((word)millis() - tempsDepart < 3000);


  // ***************************  Affichage des valeurs lues pour contrôle
  // 1 indique une valeur vue, 0 une valeur que ne donne pas le CAN
  for (word ligne=0; ligne<16; ligne++) // 1023 valeurs possibles affichées avec 16 lignes de 64 valeurs 
  {
    if (ligne == 0) Serial.print("  0"); // N° de la ligne affichée à gauche
    else if (ligne == 1) Serial.print(" 64");
    else Serial.print(ligne*64);
    Serial.print(" "); // Pour aligner la table
    for (word colonne=0; colonne<64; colonne++) Serial.print(lire(ligne*64+colonne)); // Les valeurs
    Serial.println(); // Fin de ligne
  }
  Serial.println();


  // *************************** On compte le nombre de boutons. 
  // C'est le nombre d'intervalle de la table qui contiennent que des 0. Les 1 indiquent un bouton
  while (indexDebut < 1024)
  {
    while (!lire(indexDebut)) indexDebut++; // On se place sur la première valeur 1
    while (lire(indexDebut) && (indexDebut < 1024)) indexDebut++; // On se place sur le premier 0 qui suit
    nbBoutons++;
  }


  // *************************** Affichage un nombre de boutons sur la console
  Serial.print(F("\nJ'ai vu "));
  Serial.print(--nbBoutons);
  Serial.print(F(" boutons\n*/\n\n"));


  // *************************** On fait maintenant l'affichage du programme de test
  // Commentaires du départ, début commun
  Serial.print(F("// Ce programme teste la lecture de l'ensemble de boutons avec MTanalogButtons\n\n"
    "#include <MTobjects.h> // V1.1.1 Voir http://arduino.dansetrad.fr/MTobjects\n\n"
    "const byte PIN = "));
  Serial.print(PIN);  
  Serial.print(F(";\nconst word TABLE_DES_SEUILS[] = {"));

  // Il faut donner la table des valeurs
  // Les valeurs sont par ordre décroissantes si au repos on a CAN=1023
  if (repos)
  {
    indexDebut = 1023;
    while (!lire(indexDebut)) indexDebut--; // On se place sur la dernière valeur
    while (lire(indexDebut) && (indexDebut >= 0)) indexDebut--; // On se place avant la dernière valeur
    while ((indexDebut >= 0) && (indexFin >= 0))
    {
      indexFin = indexDebut; // On cherche un intervalle sans bouton. Cela finit à indexDebut
      while (!lire(indexFin) && (indexFin >= 0)) indexFin--;  // La zone commence à indexFin + 1
      if (indexFin >= 0) // C'est un intervalle sans boutons
      {
        if (pasPremiereVirgule) Serial.print(F(", ")); // La première fois on ne met pas de virgules
        pasPremiereVirgule = true; // Les autres fois on la mettra
        Serial.print((indexDebut + indexFin + 1)/2); // Et on met le milieu de l'intervalle
      }
      indexDebut = indexFin;
      while (lire(indexDebut) && (indexDebut >= 0)) indexDebut--; // On se replace avant le bouton
    }
    Serial.print(F(", 0"));
  }
  // Les valeurs sont par ordre croissant si au repos on a CAN=0
  else
  {
    indexDebut = 0;
    while (!lire(indexDebut)) indexDebut++; // On se place sur la première valeur
    while (lire(indexDebut) && (indexDebut < 1024)) indexDebut++; // On se place après la première valeur
    while ((indexDebut < 1024) && (indexFin < 1024))
    {
      indexFin = indexDebut; // On cherche un intervalle sans bouton. Cela commence à indexDebut
      while (!lire(indexFin) && (indexFin < 1024)) indexFin++;  // La zone finit à indexFin - 1
      if (indexFin < 1024) // C'est un intervalle sans boutons
      {
        if (pasPremiereVirgule) Serial.print(F(", ")); // La première fois on ne met pas de virgules
        pasPremiereVirgule = true; // Les autres fois on la mettra
        Serial.print((indexDebut + indexFin - 1)/2); // Et on met le milieu de l'intervalle
      }
      indexDebut = indexFin;
      while (lire(indexDebut) && (indexDebut < 1024)) indexDebut++; // On se replace après le bouton
    }
    Serial.print(F(", 1024"));
  }

  // Suite du programme
  Serial.print(F("}; // Valeurs des seuils de comparaisons\n\n"

    "void appuis(byte touche)\n"
    "{\n"
    "  Serial.print(\"La touche n°\");\n"
    "  Serial.print(touche);\n"
    "  Serial.print(\" vient d'être appuyée \");\n"
    "}\n"

    "void relachement(void)\n"
    "{\n"
    "  Serial.println(\"et relâchée\");\n"
    "}\n"

    "MTanalogButtons Keypad(PIN, TABLE_DES_SEUILS, appuis, relachement);\n\n"


    "void setup()\n"
    "{\n"
    "  Serial.begin("));
  Serial.print(BAUDS);
  Serial.print(F("); // Régler aussi la console à "));
  Serial.print(BAUDS);
  Serial.print(F(" bauds!\n"));
  if (REFERENCE != DEFAULT)
  {
    Serial.print(F("  analogReference("));
    Serial.print(REFERENCE);
    Serial.print(F(");\n"));
  }
  Serial.print(F("  Serial.println(\"Appuyez sur des touches\");\n"
    "}\n\n"

    "void loop(){}"));
}


void loop()
{
}