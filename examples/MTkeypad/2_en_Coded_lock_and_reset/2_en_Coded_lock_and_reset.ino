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

// 4 digit coded lock, with the management of inactivity
//
// Code:1789# or keys N°0, 6, 7, 8, 11

//   4    5    6
//   │    │    │
//   ├─1  ├─2  ├─3
//   │ └──│─┴──│─┴───A0
//   ├─4  ├─5  ├─6
//   │ └──│─┴──│─┴───A1
//   ├─7  ├─8  ├─9
//   │ └──│─┴──│─┴───A2
//   └─*  └─0  └─#
//     └────┴────┴───A3


#include <MTobjects.h> // V1.1.0 See http://arduino.dansetrad.fr/en/MTobjects

// Keypad pins
const uint8_t PIN_LINES[] = {4 lines_on, A0, A1, A2, A3}; // Keypad lines pins
const uint8_t PIN_COLUMNS[] = {3 columns_on, 4, 5, 6}; // Keypad columns pins

byte charactersOK = 0; // Number of fair characters already pressed
byte code[4] = {0, 6, 7, 8}; // Key number for 1789

const char keys[] = { // Correspondence for display
    '1','2','3',
    '4','5','6',
    '7','8','9',
    '*','0','#'};

void reset(void); // Call if no activity
MTclock Reset(5000 milli_seconds, reset, 1 action_and_stop, MT_OFF); // Count inactivity time


void newKey(int8_t key) // Called when you press a key
{
  switch (key) // Management of keys pressed
  {
    case 9: break; // Key * ignored
    case 11: // Key #
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
      Serial.print(keys[key]); // Display of the corresponding character
      if (key == code[charactersOK]) // The key is correct
        charactersOK++; // Ready for the next key
      else charactersOK = 0; // We start again from the begining
      Reset.start(); // Leave for 5s before the reset
  }    
}

MTkeypad Keypad(PIN_LINES, PIN_COLUMNS, newKey); // Implementation of keypad

void reset(void) // Called if there is no activity
{
  charactersOK = 0; // We start again from the begining
  Serial.println("/"); // "Erasure" from the display
}

void setup()
{
  Serial.begin(115200); // Also put the console on 115200 Bauds
}
  
void loop(){}