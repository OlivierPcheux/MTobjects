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

// This program uses MTanalogButtons in the traditional way (apparently
// without interruptions)

#include <MTobjects.h> // V1.1.1 See http://arduino.dansetrad.fr/MTobjects


// Of course, you must adapt PIN, REFERENCE, BAUDS, THRESHOLDS_TABLE and keys

const uint8_t PIN = A5; // Change A5 to A0..A7 depending on your case
#define REFERENCE INTERNAL
#define BAUDS 115200 // 115200 recommended, but you can use 9600

const word THRESHOLDS_TABLE[] = {982, 922, 880, 840, 797, 754, 710, 665, 619, 572, 522, 471, 421, 369, 316, 260, 203, 145, 87, 28, 0}; // Values of comparison thresholds

//   Y X W V U
//   T S R Q P
//   O N M L K
//   J I H G F
//   E D C B A

const char keys[] = { // Match for display
    '-', // 0 corresponds to no press
    'T','S','R','Q','P', // The T key returns 1... 
    'O','N','M','L','K',
    'J','I','H','G','F',
    'E','D','C','B','A'
    };

MTanalogButtons Keypad(PIN, THRESHOLDS_TABLE);

void setup()
{
  Serial.begin(BAUDS);
  analogReference(REFERENCE); // Allows you to choose the voltage reference 
  Serial.println("Press keys");
}

byte key, oldKey;
void loop()
{
  key = Keypad.getKey();
  if (key != oldKey)
  {
    if (key)
    {
      Serial.print(keys[key]);
      Serial.print(" pressed ");
    }
    else Serial.println("and released");
    oldKey = key;
  }
}