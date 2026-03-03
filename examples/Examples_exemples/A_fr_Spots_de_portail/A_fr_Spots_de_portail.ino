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


// 3s après l'activation du portail le premier luminaire s'allume, 1s après
// le 2ème, 1s après le 3ème, 1s après le 4ème et 1s après tout les spots qui
// éclairent la façade s'allument. Au bout de 30s tout s'éteint.


// Voir https://forum.arduino.cc/t/piloter-luminaires-electrique-exterieur-avec-portail-electrique/1384084

/////////////////////////// Bibliothèque utilisée ///////////////////////////
#include <MTobjects.h> // V1.1.0 Voir http://arduino.dansetrad.fr/MTobjects


/////////////////////////// Broches utilisées ///////////////////////////////
const uint8_t PIN_PORTAIL = 2; // Information venant du portail, LOW quand le portail s'ouvre
const uint8_t SPOT_1 = A1; // Un HIGH sur la broche A1 allume le spot N°1
const uint8_t SPOT_2 = A2; // Un HIGH sur la broche A2 allume le spot N°2
const uint8_t SPOT_3 = A3; // Un HIGH sur la broche A3 allume le spot N°3
const uint8_t SPOT_4 = A4; // Un HIGH sur la broche A4 allume le spot N°4
const uint8_t SPOT_FACADE = A5; // Un HIGH sur la broche A0 allume les spots de la facade


/////////////////////////// Au bout de 30s tout s'éteint
void extinction(void)
{
  digitalWrite(SPOT_FACADE, LOW); // Extinction
  digitalWrite(SPOT_4, LOW);
  digitalWrite(SPOT_3, LOW);
  digitalWrite(SPOT_2, LOW);
  digitalWrite(SPOT_1, LOW);
}
MTclock TemporisateurExtinction(30000 milli_secondes, extinction, 1 action_et_arret, MT_OFF);


/////////////////////////// 1s après tout les spots qui éclairent la façade s'allument
void allumageSpotsFacade(void)
{
  digitalWrite(SPOT_FACADE, HIGH); // Allumage des spots qui éclairent la façade
  TemporisateurExtinction.start(); // Attente de 1s avant d'allumer le spot suivant
}
MTclock TemporisateurFacade(1000 milli_secondes, allumageSpotsFacade, 1 action_et_arret, MT_OFF);


/////////////////////////// 1s après le 4ème luminaire s'allume
void allumageSpot4(void)
{
  digitalWrite(SPOT_4, HIGH); // Allumage du 4ème spot
  TemporisateurFacade.start(); // Attente de 1s avant d'allumer le spot suivant
}
MTclock Temporisateur4(1000 milli_secondes, allumageSpot4, 1 action_et_arret, MT_OFF);


/////////////////////////// 1s après le 3ème luminaire s'allume
void allumageSpot3(void)
{
  digitalWrite(SPOT_3, HIGH); // Allumage du 3ème spot
  Temporisateur4.start(); // Attente de 1s avant d'allumer le spot suivant
}
MTclock Temporisateur3(1000 milli_secondes, allumageSpot3, 1 action_et_arret, MT_OFF);


/////////////////////////// 1s après le 2ème luminaire s'allume
void allumageSpot2(void)
{
  digitalWrite(SPOT_2, HIGH); // Allumage du 2ème spot
  Temporisateur3.start(); // Attente de 1s avant d'allumer le spot suivant
}
MTclock Temporisateur2(1000 milli_secondes, allumageSpot2, 1 action_et_arret, MT_OFF);


/////////////////////////// 3s après le 1er luminaire s'allume
void allumageSpot1(void)
{
  digitalWrite(SPOT_1, HIGH); // Allumage du 1er spot
  Temporisateur2.start(); // Attente de 1s avant d'allumer le 2ème spot
}
MTclock Temporisateur1(3000 milli_secondes, allumageSpot1, 1 action_et_arret, MT_OFF);


/////////////////////////// Info du portail
void depart(void)
{
  Temporisateur1.start(); // Attente de 3s avant d'allumer le spot suivant
}
MTbutton Portail(PIN_PORTAIL, depart);



/////////////////////////// Setup et loop ///////////////////////////////////
void setup()
{
  pinMode(SPOT_1, OUTPUT);
  pinMode(SPOT_2, OUTPUT);
  pinMode(SPOT_3, OUTPUT);
  pinMode(SPOT_4, OUTPUT);
  pinMode(SPOT_FACADE, OUTPUT);
}

void loop(){} // Pour y mettre un autre programme indépendant