// Version V1.1.1

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

// MTanalogButtons onSelect and onUnselect tests

#include <MTobjects.h> // V1.1.1 See http://arduino.dansetrad.fr/en/MTobjects

// You must give the pin for analog reading
const uint8_t PIN = A5; // Change A5 to A0..A7 depending on the case
//
// You must choose the voltage reference to use for the conversion
// DEFAULT: for Vcc
// INTERNAL: 1.1V for Nano/Uno
// INTERNAL1V1: 1.1V for Mega
// INTERNAL2V56: 2.56V for Mega
// EXTERNAL: to use AREF
#define REFERENCE INTERNAL
//
// You must give the console transfer rate
#define BAUDS 115200 // 115200 recommended, but you can put 9600
// Don't forget to set the console to 115200 bauds

const word THRESHOLDS_TABLE[] = {942, 838, 797, 709, 618, 571, 471, 369, 316, 203, 87, 28, 0}; // Comparison threshold values


//   1  2  3
//   4  5  6
//   7  8  9
//   *  0  #

const char keys[] = { // Match for display 
    'X', // Corresponds to no support 
    '#','0','*', // Key # returns 1... 
    '9','8','7',
    '6','5','4',
    '3','2','1',
    };


// Definition of a new class that overloads onSelect and onUnselect
class Keyboard: public MTanalogButtons
{
 public:
  Keyboard(uint8_t pin, const word *THRESHOLDS) // New constructor
    :MTanalogButtons(pin, THRESHOLDS)
    {};
 private:
  virtual void onSelect(byte touche) // Overload function which informs one key press
  {
    Serial.print(keys[touche]); // Character pressed
  }
  virtual void onUnselect(void) // Overload function which informs the release
  {
    Serial.println("⤵"); // Key released
  }
};


// Implementation of a personalized keyboard
Keyboard MyKeyboard(PIN, THRESHOLDS_TABLE);

void setup()
{
  Serial.begin(BAUDS);
  analogReference(REFERENCE); // Allows you to choose the voltage reference
}
  
void loop(){}