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

// Un axe doit tourner en permanence. Si il s'arrête, la Nano doit envoyer un
// signal indiquant l'arrêt.


#include <MTobjects.h> // V1.1.0 Voir http://arduino.dansetrad.fr/MTobjects

const byte CAPTEUR = 2;


void allume(void) // Appelée en cas d'arrêt de plus de 3s
{
  digitalWrite(LED_BUILTIN, HIGH);
}
MTclock Temporisateur(3000 milli_secondes, allume);


void eteint(void) // Appelée pour chaque front du capteur
{
  pinMode(LED_BUILTIN, OUTPUT); // Peut être mis dans le setup
  Temporisateur.start(); // Réinitialise le temporisateur
  digitalWrite(LED_BUILTIN, LOW);
}
MTbutton Capteur(CAPTEUR, eteint, eteint);


void setup(){}
void loop(){}