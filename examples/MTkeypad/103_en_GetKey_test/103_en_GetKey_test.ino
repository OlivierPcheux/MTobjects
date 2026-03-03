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

// MTkeypad getKey test

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

MTkeypad Keypad(pinLines, pinColumns); // Implementation of keypad

void setup()
{
  Serial.begin(115200); // Also put the console on 115200 Bauds
}
  
void loop()
{
  Serial.println(Keypad.getKey()); // Displays the press number or -1 otherwise
  delay(1000); // To slow down the display
}