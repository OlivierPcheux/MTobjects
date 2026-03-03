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

// Ce programme montre que l'on peut mettre des delays(), et même suspendre
// un delay() par un autre

// Ce programme comporte un "blink with delay" en toile de fond.
// Quand on appuie sur un bouton, 10 caractères sont envoyés sur la console 
// en utilisant un delay. Comme on a du temps libre pendant que les delay
// travaillent, on montre que l'on peut en profiter pour gérer la rotation
// d'un pas à pas. 
// Les deux delay() simultanés ne vont pas gêner la mémorisation de l'appui
// du bouton ni la rotation du moteur. La durée du blink peut être rallongée
// au maximum de 100ms si le changement d'état doit se faire pendant le delay
// de 100ms.

#include <MTobjects.h> // V1.1.0 Voir http://arduino.dansetrad.fr/MTobjects

const uint8_t PIN_BOUTON = A0;

void boutonAppuye(void)
{
  for (char lettre = 'A'; lettre <= 'Z'; lettre++)
  {
    Serial.print(lettre); // Écrit donc l'alphabet en 2,6s
    delay(100 milli_secondes); // Qui va donc suspendre le delay du blink
  }
  Serial.println(); // Pour être prêt pour un nouvel alphabet
}

MTbutton Bouton(PIN_BOUTON, boutonAppuye);

MTulnStepper Stepper(pin_A1 2, pin_B1 3, pin_A2 4, pin_B2 5);

void setup()
{
  digitalWrite(LED_BUILTIN, LOW); // Led en sortie, éteinte 
  pinMode(LED_BUILTIN, OUTPUT);

  Serial.begin(115200); // Pour envoyer les messages
  
  Stepper.move(CONTINUE); // Rotation infinie
}

void loop()
{
  // Programme classique du "blink with delay"
  Serial.println(F("J'allume"));
  digitalWrite(LED_BUILTIN, HIGH);
  delay(5000 milli_secondes);
  Serial.println(F("J'éteins"));
  digitalWrite(LED_BUILTIN, LOW);
  delay(5000 milli_secondes);
}