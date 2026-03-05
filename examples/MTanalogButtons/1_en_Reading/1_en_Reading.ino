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

// This program tests the reading of the set of buttons with MTanalogButtons

#include <MTobjects.h> // V1.1.1 See http://arduino.dansetrad.fr/en/MTobjects

const word THRESHOLDS_TABLE[] = {982, 922, 880, 840, 797, 754, 710, 665, 619, 572, 522, 471, 421, 369, 316, 260, 203, 145, 87, 28, 0}; // Comparison threshold values

void press(byte key)
{
  Serial.print("Key number ");
  Serial.print(key);
  Serial.print(" just pressed ");
}
void release(void)
{
  Serial.println("and released");
}
MTanalogButtons Keypad(PIN, THRESHOLDS_TABLE, press, release);

void setup()
{
  Serial.begin(115200); // Also set the console to 115200 baud!
  analogReference(INTERNAL);
  Serial.println("Press keys");
}

void loop(){}