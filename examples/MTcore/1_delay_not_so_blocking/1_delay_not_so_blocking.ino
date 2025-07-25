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

// This program shows that we can put delays(), and even suspend
// a delay() by another

// This program has a "blink with delay" in the background.
// When you press a button, 10 characters are sent to the console using a
// delay. As we have free time while the delay work, we show that we can take
// advantage of it to manage the rotation of a stepper.
// The two simultaneous delay() will not interfere with the memorization of
// the support of the button or the rotation of the stepper. The duration of
// the blink can be extended at most 100ms if the change of state must be
// done during the 100ms delay.

#include <MTobjects.h> // V1.0.6 See http://arduino.dansetrad.fr/MTobjects

const uint8_t PIN_BOUTON = A0;

void buttonPressed(void)
{
  for (char letter = 'A'; letter <= 'Z'; letter++)
  {
    Serial.print(letter); // Therefore writes the alphabet in 2.6s
    delay(100 milli_seconds); // Who will therefore suspend the blink delay
  }
  Serial.println(); // To be ready for a new alphabet
}

MTbutton Bouton(PIN_BOUTON, buttonPressed);

MTulnStepper Stepper(pin_A1 2, pin_B1 3, pin_A2 4, pin_B2 5);

void setup()
{
  digitalWrite(LED_BUILTIN, LOW); // Led in OUTPUT, light off 
  pinMode(LED_BUILTIN, OUTPUT);

  Serial.begin(115200); // To send messages
  
  Stepper.move(CONTINUE); // Infinite rotation
}

void loop()
{
  // Classic program of "blink with delay"
  Serial.println(F("I light on"));
  digitalWrite(LED_BUILTIN, HIGH);
  delay(5000 milli_seconds);
  Serial.println(F("I light off"));
  digitalWrite(LED_BUILTIN, LOW);
  delay(5000 milli_seconds);
}