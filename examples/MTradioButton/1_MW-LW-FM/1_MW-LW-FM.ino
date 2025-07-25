// Version 1.0.6

//###########################################################################
//###########################################################################
//####                                                                   ####
//####                          Olivier Pécheux                          ####
//####                        Olivier@Dansetrad.fr                       ####
//####                        (33) +6 69 77 82 58                        ####
//####               http://arduino.dansetrad.fr/MTobjects               ####
//####                                                                   ####
//###########################################################################
//###########################################################################


// This program will simulate an MW-LW-FM choice. We choose the range
//by wired buttons on A0, A1, and A2. The console tells us about changes 

#include <MTobjects.h> // V1.0.6 See http://arduino.dansetrad.fr/MTobjects

const uint8_t PIN_BUTTON_MW = A0; // Button wired between A0 and GND
const uint8_t PIN_BUTTON_LW = A1; // Button wired between A1 and GND
const uint8_t PIN_BUTTON_FM = A2; // Button wired between A2 and GND


// Implementation of the button MW
void choiceMW(void)
{
  Serial.println("We just chosen MW"); // Called if MW is pressed
}

void choiceMWend(void)
{
  Serial.println("We have just canceled MW"); // Called if LW or FM is pressed
}

MTradioButton ButtonMW(PIN_BUTTON_MW, choiceMW, choiceMWend, HIGH if_not_pressed, RADIO_BUTTON_0);



// Implementation of the button LW
void choiceLW(void)
{
  Serial.println("We just chosen LW");
}

void choiceLWend(void)
{
  Serial.println("We have just canceled LW");
}

MTradioButton ButtonLW(PIN_BUTTON_LW, choiceLW, choiceLWend, HIGH if_not_pressed, RADIO_BUTTON_1);



// Implementation of the button FM
void choiceFM(void)
{
  Serial.println("We just chosen FM");
}

void choiceFMend(void)
{
  Serial.println("We have just canceled FM");
}

MTradioButton ButtonFM(PIN_BUTTON_FM, choiceFM, choiceFMend, HIGH if_not_pressed, RADIO_BUTTON_2);



void setup()
{
  Serial.begin(115200);
  ButtonMW.select(); // So that there is at least one selected range
  delay(16 milli_seconds); // So we are sure that the button is selected (possible delay in taking into account 16ms)
}


String names[3] = {"MW", "LW", "FM"};

void loop()
{
  Serial.print("The current range is ");
  Serial.println(names[getMTradioButtonValue()]); // Displays the selected button name
  delay(2000 milli_seconds); // To have a display that does not parade too quickly
}