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


// Voir https://forum.arduino.cc/t/generer-des-salves-dimpulsions/1379201

// Génération de salves d'impulsion sur une sortie
// De 1 à 5 impulsions à 2/3Hz 
// Donc durée maximale 2,5s -> répétition entre 3 et 6s


#include <MTobjects.h> // V1.1.0 Voir http://arduino.dansetrad.fr/MTobjects

MTsoftPWM Salves(LED_BUILTIN); // Mise en place

void setup()
{
  Salves.stop(); // Arrêt car fonctionne à l'initialisation. Pourrait être fait lors de sa création!
}

void loop()
{
  // Préparer de 1 à 5 impulsions à 2 à 3 Hz
  long periode = (300 + random(200))*1000 micro_secondes; // Entre 0,3s et 0,5s
  Salves.setPeriod(periode);
  Salves.setPulse(periode/2);
  long nombre_de_niveaux = (1 + random(5)) * 2; // Une impulsion c'est 2 niveaux. Entre 2 et 10
  Salves.setNumberOfLevels(nombre_de_niveaux niveaux_et_arret);
  
  // Démarrer la salve
  Salves.start();

  // Espace entre deux débuts de salves
  long attente = 3000 + random(3000) milli_secondes; // Entre 3s et 6s
  delay(attente); // Les salves se produiront pendant cette instruction
}