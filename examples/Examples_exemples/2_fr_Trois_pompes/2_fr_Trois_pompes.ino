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


// Nous avons:
// - 3 pompes
// - 1 bouton poussoir nommé "depart"
// - 1 bouton marche/arrêt
// Quand on appuie le bouton nommé depart les pompes s'activent l'une après
// l’autre pendant un certain temps mais quand on appuie plus de 5 secondes
// sur depart les 3 pompes s’activent ensembles pendant un certain temps.


//  depart─┬─┤ Pompe1 ├──┤ Pompe2 ├──┤ Pompe3 │
//         │
//         └─┤ CinqSecondes ├──┤ 3Pompes │


/////////////////////////// Bibliothèque utilisée ///////////////////////////
#include "MTobjects.h" // V1.1.0 Voir http://arduino.dansetrad.fr/MTobjects


/////////////////////////// Constantes du programme /////////////////////////
const unsigned long TEMPS_POMPE_1 = 5ul*60*1000 milli_secondes; // La pompe 1 fonctionnera seule pendant 5 minutes
const unsigned long TEMPS_POMPE_2 = 5ul*60*1000 milli_secondes; // La pompe 2 fonctionnera seule pendant 5 minutes
const unsigned long TEMPS_POMPE_3 = 5ul*60*1000 milli_secondes; // La pompe 3 fonctionnera seule pendant 5 minutes
const unsigned long TEMPS_3_POMPES = 10ul*60*1000 milli_secondes; // Les 3 pompes fonctionneront ensembles pendant 10 minutes
const unsigned long TEMPS_ATTENTE_POUR_3_POMPES = 5000 milli_secondes; // Il faut appuyer 5s pour faire fonctionner les trois pompes


/////////////////////////// Broches utilisées ///////////////////////////////
const uint8_t PIN_BOUTON_DEPART = A0; // Bouton câblé entre GND et A0
const uint8_t PIN_BOUTON_MARCHE_ARRET = A1; // Bouton câblé entre GND et A1
const uint8_t PIN_POMPE_1 = 2; // Un HIGH sur la broche 2 met en marche la pompe N°1
const uint8_t PIN_POMPE_2 = 3; // Un HIGH sur la broche 3 met en marche la pompe N°2
const uint8_t PIN_POMPE_3 = 4; // Un HIGH sur la broche 4 met en marche la pompe N°3
const uint8_t PIN_MARCHE = 5; // Informe si on est "sous tension"


/////////////////////////// Permettre à la pompe 3 de tourner un certain temps
void arretPompe3(void)
{
   digitalWrite(PIN_POMPE_3, LOW); // Arrêt de la pompe 3
}
MTclock TemporisateurPompe3(TEMPS_POMPE_3, arretPompe3, 1 action_et_arret, MT_OFF);


/////////////////////////// Permettre à la pompe 2 de tourner un certain temps
void arretPompe2(void)
{
  digitalWrite(PIN_POMPE_3, HIGH); // Mise en marche de la pompe 3
  digitalWrite(PIN_POMPE_2, LOW); // Arrêt de la pompe 2
  TemporisateurPompe3.start(); // Déclenche le temporisateur suivant
}
MTclock TemporisateurPompe2(TEMPS_POMPE_2, arretPompe2, 1 action_et_arret, MT_OFF);


/////////////////////////// Permettre à la pompe 1 de tourner un certain temps
void arretPompe1(void)
{
  digitalWrite(PIN_POMPE_2, HIGH); // Mise en marche de la pompe 2
  digitalWrite(PIN_POMPE_1, LOW); // Arrêt de la pompe 1
  TemporisateurPompe2.start(); // Déclenche le temporisateur suivant
}
MTclock TemporisateurPompe1(TEMPS_POMPE_1, arretPompe1, 1 action_et_arret, MT_OFF);


/////////////////////////// Permettre aux 3 pompes de tourner un certain temps
void arret3Pompes(void)
{
  digitalWrite(PIN_POMPE_1, LOW); // Arrêt des pompes
  digitalWrite(PIN_POMPE_2, LOW);
  digitalWrite(PIN_POMPE_3, LOW);
}
MTclock Temporisateur3Pompes(TEMPS_3_POMPES, arret3Pompes, 1 action_et_arret, MT_OFF);


/////////////////////////// C'est un appui long
void troisPompes(void)
{
  digitalWrite(PIN_POMPE_1, HIGH); // Mise en marche des pompes
  digitalWrite(PIN_POMPE_2, HIGH);
  digitalWrite(PIN_POMPE_3, HIGH);
  TemporisateurPompe1.stop(); // Arrêter les temporisateurs du cycle une pompe à la fois
  TemporisateurPompe2.stop();
  TemporisateurPompe3.stop();
  Temporisateur3Pompes.start(); // Déclenche le temporisateur suivant
}
MTclock TemporisateurCinqSecondes(TEMPS_ATTENTE_POUR_3_POMPES, troisPompes, 1 action_et_arret, MT_OFF);


/////////////////////////// Bouton marche/arrêt /////////////////////////////
void marche(void)
{
  digitalWrite(PIN_MARCHE, HIGH); // Allumer le voyant Marche/arrêt
}
void arretComplet(void)
{
  TemporisateurPompe1.stop(); // Arrêter les temporisateurs
  TemporisateurPompe2.stop();
  TemporisateurPompe3.stop();
  Temporisateur3Pompes.stop();
  digitalWrite(PIN_POMPE_1, LOW); // Arrêt des pompes
  digitalWrite(PIN_POMPE_2, LOW);
  digitalWrite(PIN_POMPE_3, LOW);
  digitalWrite(PIN_MARCHE, LOW); // Eteindre le voyant Marche/arrêt
}
MTcheckButton BoutonMarcheArret(PIN_BOUTON_MARCHE_ARRET, marche, arretComplet);


/////////////////////////// Bouton départ ///////////////////////////////////
void departCourt(void)
{
  if (BoutonMarcheArret.getSelect()) // Si on est en mode marche
  {
    TemporisateurPompe1.start(); // Démarrer le cycle
    TemporisateurPompe2.stop(); // Arrêter les autres temporisateurs des pompes
    TemporisateurPompe3.stop();
    Temporisateur3Pompes.stop();
    TemporisateurCinqSecondes.start(); // Pour voir un appui long
    digitalWrite(PIN_POMPE_2, LOW); // Arrêt des pompes 2 et 3
    digitalWrite(PIN_POMPE_3, LOW);
    digitalWrite(PIN_POMPE_1, HIGH); // Marche de la première pompe...
   }
}
void relachement(void)
{
  TemporisateurCinqSecondes.stop(); // Pas d'appui long
}
MTbutton BoutonDepart(PIN_BOUTON_DEPART, departCourt, relachement);


/////////////////////////// Setup et loop ///////////////////////////////////
void setup()
{
  pinMode(PIN_POMPE_1, OUTPUT); // Sorties pour les pompes
  pinMode(PIN_POMPE_2, OUTPUT);
  pinMode(PIN_POMPE_3, OUTPUT);
  pinMode(PIN_MARCHE, OUTPUT); // Led de contrôle
}

void loop(){} // Pour y mettre un autre programme indépendant