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

// MTkeypad basic test with characters display

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

uint8_t pinLines[] = {4 lines_on, A0, A1, A2, A3}; // Keypad lines pins
uint8_t pinColumns[] = {4 columns_on, 4, 5, 6, 7}; // Keypad columns pins

const char keys[] = { // Correspondence for display
    '1','2','3','A',
    '4','5','6','B',
    '7','8','9','C',
    '*','0','#','D'};

void display(int8_t key) // Called when you press a key
{
  Serial.print(keys[key]); // Associated character display
}

void release(void) // Called when you drop all the keys
{
  Serial.println();
}

MTkeypad Keypad(pinLines, pinColumns, display, release); // Implementation of keypad

void setup()
{
  Serial.begin(115200); // Also put the console on 115200 Bauds
}
  
void loop(){}