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

// This program checks that an analog reading on another analog pin does not
// disturb the measurement
// As we use a single ADC with a multiplexer, it is necessary to check that
// in moving from one pin to another, we can read well
//
// Here, we will read a keypad with pin A5 and set pin A0 to 5V.
// As we have two MTanalogButtons, we will alternately read A5 and A0
// Before reading the buttons, we will therefore read a 5V.

#include <MTobjects.h> // V1.1.1 See http://arduino.dansetrad.fr/en/MTobjects


const byte PIN_1 = A5;
const byte PIN_2 = A0; // Pin A0 is at 5V
const word THRESHOLDS_TABLE[] = {982, 920, 880, 840, 797, 754, 710, 665, 619, 571, 523, 471, 421, 369, 316, 260, 204, 145, 87, 28, 0}; // Values of comparison thresholds

void press(byte key)
{ 
  Serial.print("Key #"); 
  Serial.print(key); 
  Serial.print(" just pressed ");
}

void release(void)
{ 
  Serial.println("and released"); 
}

MTanalogButtons Keypad1(PIN_1, THRESHOLDS_TABLE, press, release); // The one we observe
MTanalogButtons Keypad2(PIN_2, THRESHOLDS_TABLE); // Will force readings to 1024


void setup()
{ 
  Serial.begin(115200); // Also set the console to 115200 baud!
  analogReference(INTERNAL); // We thus go back and forth on the ADC between 5V and a low voltage if we press a button
  Serial.println("Press keys");
}

void loop(){}