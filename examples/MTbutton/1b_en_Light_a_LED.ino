// Version 1.1.0

//###########################################################################
//###########################################################################
//####                                                                   ####
//####                          Olivier Pécheux                          ####
//####                        Olivier@Dansetrad.fr                       ####
//####                        (33) +6 69 77 82 58                        ####
//####              http://arduino.dansetrad.fr/en/MTobjects             ####
//####                                                                   ####
//###########################################################################
//###########################################################################


// The program will turn on the LED_BUILTIN led when pressing a button. 

#include <MTobjects.h> // V1.1.0 See http://arduino.dansetrad.fr/en/MTobjects 

const uint8_t PIN_BUTTON = A0; // Button wired between A0 and GND 

MTbutton Bouton(PIN_BUTTON); // Implementation of the button 



void setup()
{
  pinMode(LED_BUILTIN, OUTPUT); // LED initialization 
}

void loop()
{
  digitalWrite(LED_BUILTIN, Bouton.getSelect()); // Copies the state of the button to the LED 
  // digitalWrite(LED_BUILTIN, Bouton.getSelect()? HIGH : LOW) ; // More correct! 
}