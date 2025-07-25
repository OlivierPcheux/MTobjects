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


// I want to pilot N LEDs with N push buttons via a UNO, Nano or Mega
// card. When I press on a button and release it, the LED corresponding
// to the button lights up. When I press the same button, the corresponding
// LED goes out. A seventh push button is used to turn off all the LEDs that
// have been on.

#include <MTobjects.h> // V1.0.6 See http://arduino.dansetrad.fr/MTobjects

const uint8_t N = 6; // Number of buttons
const uint8_t PIN_BUTTON_ALL_OFF = 2; // Button wired between GND and 2
const uint8_t FIRST_BUTTON = 3;
const uint8_t FIRST_LED = N+3; // With N=6, the last LED is 14 (we can also say A0)
// For N=6 couples (button, LED) are:
// (3,9) (4,10) (5,11) (6,12) (7,13) (8,A0)




// The different zones (a button and an LED)
// Creation of a specific object
class Zone: public MTcheckButton
{
  public:
    Zone(uint8_t pinButton, uint8_t pinLed) // New constructor
      :MTcheckButton(pinButton), led(pinLed)
      {
        pinMode(pinLed, OUTPUT);
      };
    virtual void onSelect(void); // Overload function which informs the selection
    virtual void onUnselect(void); // Function to be overloaded which informs deselection
 private:
    uint8_t led; // LED pin corresponding to the button
};

void Zone::onSelect(void) // Light on the led
{
  digitalWrite(led, HIGH);
}
	
void Zone::onUnselect(void) // Light off the led
{
  digitalWrite(led, LOW);
}



// Use of the pointers to be able to make an initialization loop
Zone *Zones[N]; // Zone is therefore a table on Zone pointers



// The button that turns off everything
void lightOffAll(void)
{
  for (byte i = 0; i < N; i++) Zones[i]->unselect();
}
MTbutton ButtonlightOffAll(PIN_BUTTON_ALL_OFF, lightOffAll);


void setup()
{
  // Initialization of different zones:
  for (byte i = 0; i < N; i++) Zones[i] = new Zone(FIRST_BUTTON + i, FIRST_LED + i);
}

void loop(){}