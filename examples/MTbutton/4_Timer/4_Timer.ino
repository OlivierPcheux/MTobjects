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


// This program lights an LED if you press a button and turns off it if you
// press a second time or if 5 seconds have passed

#include <MTobjects.h> // V1.0.6 See http://arduino.dansetrad.fr/MTobjects

const uint8_t PIN_BUTTON = A0; // Button wired between A0 and GND


void turnOff(void) // Called 5s after a turn on
{
  digitalWrite(LED_BUILTIN, LOW); // Turn off
}

// Delay of 5s which will extinguish
MTclock Temporisateur(5000 milli_seconds, turnOff, 1 action_and_stop, MT_OFF);

void change(void)
{
  if (digitalRead(LED_BUILTIN)) // If it's lit 
    digitalWrite(LED_BUILTIN, LOW); // We turn off
  else 
  {
    digitalWrite(LED_BUILTIN, HIGH); // Otherwise we light
    Temporisateur.start();
  }
}

MTbutton Bouton(PIN_BUTTON, change); // One click we light, one click we turn off



void setup()
{
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {}