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


// Ce programme allume une led si on appuie sur un bouton et l'éteint si on
// appuie une deuxième fois ou si 5 secondes se sont écoulées

#include <MTobjects.h> // V1.1.0 Voir http://arduino.dansetrad.fr/MTobjects

const uint8_t PIN_BUTTON = A0; // Bouton câblé entre GND et A0


void eteint(void) // Appelée 5s après un allumage
{
  digitalWrite(LED_BUILTIN, LOW); // On éteint
}

// Temporisation de 5s qui va éteindre
MTclock Temporisateur(5000 milli_secondes, eteint, 1 action_et_arret, MT_OFF);

void change(void)
{
  if (digitalRead(LED_BUILTIN)) // Si c'est allumé
    digitalWrite(LED_BUILTIN, LOW); // On éteint
  else 
  {
    digitalWrite(LED_BUILTIN, HIGH); // Sinon on allume
    Temporisateur.start();
  }
}

MTbutton Bouton(PIN_BUTTON, change); // Un clic on allume, un clic on éteint



void setup()
{
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {}