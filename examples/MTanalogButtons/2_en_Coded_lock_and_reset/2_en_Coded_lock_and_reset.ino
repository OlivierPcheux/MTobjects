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

// Simulation of a coded lock.
// I use a 20-key keypad. For this program to work, you must
// adapt everything PIN, REFERENCE, BAUDS, THRESHOLDS_TABLE, code[4]

#include <MTobjects.h> // V1.1.0 See http://arduino.dansetrad.fr/en/MTobjects

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

// Code:1789# i.e. keys N°12, 6, 5, 4
byte code[4] = {12, 6, 5, 4}; // Key number for 1789
//
//   1  2  3
//   4  5  6
//   7  8  9
//   *  0  #


byte charactersOK = 0; // Number of fair characters already pressed

const char keys[] = { // Match for display 
    'X', // Corresponds to no support 
    '#','0','*', // Key # returns 1... 
    '9','8','7',
    '6','5','4',
    '3','2','1',
    };


void reset(void) // Called if there is no activity
{
  charactersOK = 0; // We start again from the begining
  Serial.println("/"); // "Erasure" from the display
}
MTclock Reset(5000 milli_seconds, reset, 1 action_and_stop, MT_OFF); // Count inactivity time


void newKey(byte key) // Called when you press a key
{
  switch (key) // Management of keys pressed
  {
    case 3: break; // Key * ignored
    case 1: // Key #
      Reset.stop(); // No need to test inactivity
      if (charactersOK == 4) // The code is good
      {
        Serial.print("\nCode good, switching on the spoon");
        delay(1000);
        Serial.println(" ... end of power");
      }
      else Serial.println("\nIncorrect code");
      charactersOK = 0; // We start again from the begining
      break;
    default: // A numeric key is supported
      Reset.start(); // Leave for 5s before the reset
      Serial.print(keys[key]); // Display of the corresponding character
      if (key == code[charactersOK]) // The key is correct
        charactersOK++; // Ready for the next key
      else charactersOK = 0; // We start again from the begining
  }    
}

MTanalogButtons Keypad(PIN, THRESHOLDS_TABLE, newKey); // Implementation of keypad

void setup()
{
  Serial.begin(BAUDS);
  analogReference(REFERENCE); // Allows you to choose the voltage reference
}
  
void loop(){}