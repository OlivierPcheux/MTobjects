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

// MTkeypad setOnSelectFunction and setOnUnselectFunction tests

//   4    5    6    7
//   │    │    │    │
//   ├─1  ├─2  ├─3  ├─A
//   │ └──│─┴──│─┴──│─┴───A0
//   ├─4  ├─5  ├─6  ├─B
//   │ └──│─┴──│─┴──│─┴───A1
//   ├─7  ├─8  ├─9  ├─C
//   │ └──│─┴──│─┴──│─┴───A2
//   └─*  └─0  └─#  └─D
//     └────┴────┴────┴───A3


#include <MTobjects.h> // V1.1.0 See http://arduino.dansetrad.fr/en/MTobjects

const uint8_t PIN_LINES[] = {4 lines_on, A0, A1, A2, A3}; // Keypad lines pins
const uint8_t PIN_COLUMNS[] = {4 columns_on, 4, 5, 6, 7}; // Keypad columns pins

const char keys[] = { // Correspondence for display
    '1','2','3','A',
    '4','5','6','B',
    '7','8','9','C',
    '*','0','#','D'};



// Keypad
MTkeypad Keypad(PIN_LINES, PIN_COLUMNS); // Implementation of keypad



// Callback functions
void display1(int8_t key) // Called when you press a key
{
  Serial.print("  display1 :");
  Serial.println(keys[key]); // Associated character display
}

void display2(int8_t key) // Called when you press a key
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
  Serial.begin(115200); // Also put the console on 115200 Bauds
}
  
void loop(){}