// Version 1.1.0

//###########################################################################
//###########################################################################
//####                                                                   ####
//####                          Olivier Pécheux                          ####
//####                        Olivier@Dansetrad.fr                       ####
//####                        (33) +6 69 77 82 58                        ####
//####               http://arduino.dansetrad.fr/en/MTobjects            ####
//####                                                                   ####
//###########################################################################
//###########################################################################


// I want a traffic light, and when a pedestrian presses the button, the
// light immediately changes to orange. Of course when the light turns green,
// a time delay prevents the light from turning orange immediately. The
// timings will be done with delay().

// The delays are smaller than in real life to see the operation


// See https://forum.arduino.cc/t/piloter-luminaires-electrique-exterieur-avec-portail-electrique/1384084

//////////////////////////// Library used ///////////////////////////////////
#include <MTobjects.h> // V1.1.0 See http://arduino.dansetrad.fr/MTobjects


//////////////////////////// Pins used //////////////////////////////////////
const uint8_t PIN_BUTTON = 2; // For the pedestrian, a press blocks the cars
const uint8_t GREEN = 5; // A HIGH on pin A1 turns on the green light
const uint8_t ORANGE = 4; // A HIGH on pin A2 turns on the orange light
const uint8_t RED = 3; // A HIGH on pin A3 turns on the red light


///////////////////////////// Global variable ///////////////////////////////
volatile boolean buttonRemember; // Change to true on a call
// You must declare the button volatile so that the while in loop rereads
// the state of the button at each iteration. "buttonRemember" is modified by
// interrupt, and if we don't put "volatile", the compiler optimizes and
// and don't read again


//////////////////////////// Installation of the button /////////////////////
void memorization(void)
{ 
  buttonRemember = true; // If we are here, it means that the button was pressed
}
MTbutton Button(PIN_BUTTON, memorization); // Call the function if pressed
// Note: An MTbutton also works during delay



//////////////////////////// Setup and loop /////////////////////////////////
void setup()
{ 
  pinMode(GREEN, OUTPUT); 
  pinMode(ORANGE, OUTPUT); 
  pinMode(RED, OUTPUT);
}

void loop()
{ 
  // Green light 
  digitalWrite(GREEN, HIGH); // Turning on the green light 
  digitalWrite(RED, LOW); 
  delay(3000); // The green light lasts at least 3s, it cannot be interrupted before 

  // Waiting for the button to be pressed 
  while (buttonRemember == false); // We stay green if there are no pedestrians 

  // Orange light 
  digitalWrite(ORANGE, HIGH); // Switching on the orange light 
  digitalWrite(GREEN, LOW); 
  delay(1000); // The orange light lasts 1s 

  // Red light 
  digitalWrite(RED, HIGH); // Switching on the red light 
  digitalWrite(ORANGE, LOW); 
  buttonRemember = false; // Clearing the memory, the button has been taken into account 
  // By clearing the memory now the press can be recorded even during the red light 
  delay(5000); // The red light lasts 5s
}