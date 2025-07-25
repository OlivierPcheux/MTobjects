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


// This program redefines buttons to send characters. Here we derive a
// new class to avoid redefining lots of functions

#include <MTobjects.h> // V1.0.6 See http://arduino.dansetrad.fr/MTobjects

const uint8_t PIN_BUTTON_A = A0; // Button wired between A0 and GND
const uint8_t PIN_BUTTON_B = A1;
const uint8_t PIN_BUTTON_C = A2;
const uint8_t PIN_BUTTON_D = A3;
const uint8_t PIN_BUTTON_E = A4;
const uint8_t PIN_BUTTON_F = A5;


// Definition of a new class that overloads onselect
class MyBouton: public MTbutton
{
 public:
  MyBouton (uint8_t pin, char p_letter) // New constructor
    :MTbutton(pin), letter(p_letter) 
    {};
 private:
  char letter; // Letter that will be sent to the console
  virtual void onSelect(void) // Overload function which sends a letter
  {
    Serial.print(letter);
  }
};


// Definition of buttons
MyBouton BoutonA(PIN_BUTTON_A, 'A'); // This button will therefore send the letter 'A'
MyBouton BoutonB(PIN_BUTTON_B, 'B');
MyBouton BoutonC(PIN_BUTTON_C, 'C');
MyBouton BoutonD(PIN_BUTTON_D, 'D');
MyBouton BoutonE(PIN_BUTTON_E, 'E');
MyBouton BoutonF(PIN_BUTTON_F, 'F');


void setup()
{
  Serial.begin(115200); // Console initialization
}

void loop(){}