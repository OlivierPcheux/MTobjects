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

// MTanalogButtons getKey test

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
    '.', // Corresponds to no support
    '#','0','*', // Key # returns 1...
    '9','8','7',
    '6','5','4',
    '3','2','1',
    };

MTanalogButtons Keypad(PIN, THRESHOLDS_TABLE); // Implementation of keypad

void setup()
{
  Serial.begin(BAUDS);
  analogReference(REFERENCE); // Allows you to choose the voltage reference
}
  
void loop()
{
  Serial.println(Keypad.getKey()); // Displays the press number or -1 otherwise
  delay(200); // To slow down the display
}