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


// Je veux piloter N leds avec N boutons poussoirs via une carte Uno, Nano ou
// Mega. Lorsque j’appuie sur un bouton et que je le relâche, la LED
// correspondante au bouton s’allume. Lorsque je refait une pression sur le
// même bouton, la LED correspondante s’éteint. Un dernier bouton poussoir
// sert à éteindre d'une seule pression toutes les leds qui ont été allumées.


#include <MTobjects.h> // V1.1.0 Voir http://arduino.dansetrad.fr/MTobjects

const uint8_t N = 6; // Nombre de boutons
const uint8_t PIN_BUTTON_ETEINT = 2; // Bouton câblé entre GND et 2
const uint8_t PREMIER_BOUTON = 3;
const uint8_t PREMIERE_LED = N+3; // Avec N=6, la dernière led est la 14 (on peut aussi la nomer A0)
// Pour N=6 les couples (bouton, led) sont:
// (3,9) (4,10) (5,11) (6,12) (7,13) (8,A0)




// Les différentes zones (un bouton et une led)
// Création d'un objet spécifique
class Zone: public MTcheckButton
{
  public:
    Zone(uint8_t pinBouton, uint8_t pinLed) // Nouveau constructeur
      :MTcheckButton(pinBouton), led(pinLed)
      {
        pinMode(pinLed, OUTPUT);
        Serial.println(pinBouton*100+pinLed);
      };
    virtual void onSelect(void); // Fonction à surcharger qui informe la sélection
    virtual void onUnselect(void); // Fonction à surcharger qui informe la désélection
 private:
    uint8_t led; // Broche de la led correspondant au bouton
};

void Zone::onSelect(void) // Allume la led
{
  digitalWrite(led, HIGH);
}
	
void Zone::onUnselect(void) // Eteint la led
{
  digitalWrite(led, LOW);
}



// Les boutons qui allument, passage des pointeurs pour pouvoir faire de boucle d'initialisation 
Zone *Zones[N]; // Zone est donc un tableau sur des pointeurs de Zone



// Le bouton qui éteint tout
void eteintTout(void)
{
  for (byte i = 0; i < N; i++) Zones[i]->unselect();
}
MTbutton BoutonEteintTout(PIN_BUTTON_ETEINT, eteintTout);




void setup()
{
  // Initialisation des différentes zones:
  for (byte i = 0; i < N; i++) Zones[i] = new Zone(PREMIER_BOUTON + i, PREMIERE_LED + i); 
}

void loop(){}