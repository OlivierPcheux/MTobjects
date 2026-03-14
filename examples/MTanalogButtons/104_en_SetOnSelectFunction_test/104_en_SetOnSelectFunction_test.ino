// Version V1.1.0

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

// MTanalogButtons setOnSelectFunction and setOnUnselectFunction tests

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

// Keypad
MTanalogButtons Keypad(PIN, THRESHOLDS_TABLE); // Implementation of keypad



// Callback functions
void display1(byte key) // Called when you press a key
{
  Serial.print("  display1 :");
  Serial.println(keys[key]); // Associated character display
}

void display2(byte key) // Called when you press a key
{
  Serial.print("  display2 :");
  Serial.println(keys[key]); // Associated character display
}

void release1(void) // Called when you drop all the keys
{
  Serial.println("  release1");
}

void release2(void) // Called when you drop all the keys
{
  Serial.println("  release2");
}



// Change of callback functions
byte which = 0; // Choice of callback functions torque
void change(void) // Change the callback functions every 5 seconds
{
  switch (which++)
  {
    case 0: Serial.println("Serie 1");
      Keypad.setOnSelectFunction(display1);
      Keypad.setOnUnselectFunction(release1);
      break;
    case 1: Serial.println("Serie 2");
      Keypad.setOnSelectFunction(display2);
      Keypad.setOnUnselectFunction(release2);
      break;
    case 2: Serial.println("No callback functions");
      Keypad.setOnSelectFunction();
      Keypad.setOnUnselectFunction();
      which = 0;
  }
}

MTclock Horloge(5000 milli_seconds, change); // Change the callback functions



// Initialization
void setup()
{
  Serial.begin(BAUDS);
  analogReference(REFERENCE); // Allows you to choose the voltage reference
  change(); // To implement the first series of functions
}
  
void loop(){}