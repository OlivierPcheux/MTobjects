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

// Génération de salves d'impulsion sur les 17 sorties d'une Uno
// De 1 à 5 impulsions de 5ms avec un période de 10ms 
// Donc durée maximale 50ms -> envoi d'une salve toutes les 60ms

#include <MTobjects.h> // V1.1.0 Voir http://arduino.dansetrad.fr/MTobjects

void setup()
{
  // Ne sert à rien à priori car MTsoftPWM met la broche en sortie. Ce serait fait à la
  // première impulsion. Mais cette première impulsion se confondrait avec l'entrée en
  // l'air. Cela pemet aussi d'avoir un démarrage propre pour toutes les sorties
  for (uint8_t pin = 2; pin < 20; pin++) // Broche entre 2 et 13 ou entre A0=14 et A5=19
  {
    digitalWrite(pin, LOW); // Car les impulsions seront positives
    pinMode(pin, OUTPUT);
  }
}

void loop()
{
  // Démarrer la salve
  MTsoftPWM *Salve = new MTsoftPWM(2 + random(18), // Broche entre 2 et 13 ou entre A0 et A5
          impulsions_de 5000L micro_secondes,
          periodes_de 10000L micro_secondes,
          HIGH, // LOW au repos, premier niveau HIGH
          (1 + random(5)) * 2 niveaux_et_arret); // Une impulsion c'est 2 niveaux. Entre 2 et 10

  // Espace entre deux débuts de salves
  delay(60 milli_secondes); // Les salves se produiront pendant cette instruction

  delete Salve; // Destruction pour en faire d'autres
}