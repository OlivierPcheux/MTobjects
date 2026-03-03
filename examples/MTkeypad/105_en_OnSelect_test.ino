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

// MTkeypad onSelect and onUnselect tests

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

const char touches[] = { // Correspondence for display
    '1','2','3','A',
    '4','5','6','B',
    '7','8','9','C',
    '*','0','#','D'};


// Definition of a new class that overloads onSelect and onUnselect
class Keyboard: public MTkeypad
{
 public:
  Keyboard(byte *pinLines, byte *pinColumns) // New constructor
    :MTkeypad(pinLines, pinColumns)
    {};
 private:
  virtual void onSelect(int8_t touche) // Overload function which informs one key press
  {
    Serial.print(touches[touche]); // Character pressed
  }
  virtual void onUnselect(void) // Overload function which informs the release
  {
    Serial.println("⤵"); // Key released
  }
};


// Implementation of a personalized keyboard
Keyboard MyKeyboard(pinLines, pinColumns);

void setup()
{
  Serial.begin(115200); // Also put the console on 115200 Bauds
}
  
void loop(){}