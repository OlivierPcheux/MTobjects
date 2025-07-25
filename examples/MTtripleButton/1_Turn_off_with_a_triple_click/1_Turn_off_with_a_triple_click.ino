// Version 1.0.6

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


// Ce programme allume une led si on fait un triple clic sur le bouton et
// éteint la led sur un simple clic. 

#include <MTobjects.h> // V1.0.6 See http://arduino.dansetrad.fr/MTobjects

const uint8_t PIN_BUTTON = A0; // Bouton câblé entre GND et A0


void allume(void) // Appelée sur triple clic
{
  digitalWrite(LED_BUILTIN, HIGH);
}

void eteint(void) // Appelée sur simple clic
{
  digitalWrite(LED_BUILTIN, LOW);
}

MTtripleButton Bouton(PIN_BUTTON, allume, NO_ACTION, eteint);



void setup()
{
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop(){}  
