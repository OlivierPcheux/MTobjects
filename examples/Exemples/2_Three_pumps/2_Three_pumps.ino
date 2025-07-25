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


// We have:
// - 3 pumps
// - 1 push button called "start"
// - 1 on/off button
// When you press the button called "start" the pumps activate one after the
// other for a while but when you press more 5 seconds on "start", the 3
// pumps run together for a while.


//  start─┬─┤ Pump1 ├──┤ Pump2 ├──┤ Pump3 │
//         │
//         └─┤ FiveSeconds ├──┤ 3Pumps │


/////////////////////////// Library used /////////////////////////
#include <MTobjects.h> // V1.0.6 See http://arduino.dansetrad.fr/MTobjects


/////////////////////////// Program constants /////////////////////////
const unsigned long TIME_PUMP_1 = 5ul*60*1000 milli_seconds; // The pump 1 will run for 5 minutes alone
const unsigned long TIME_PUMP_2 = 5ul*60*1000 milli_seconds; // The pump 2 will run for 5 minutes alone
const unsigned long TIME_PUMP_3 = 5ul*60*1000 milli_seconds; // The pump 3 will run for 5 minutes alone
const unsigned long TIME_3_PUMPS = 10ul*60*1000 milli_seconds; // The three pumps will run for 10 minutes alone
const unsigned long TIME_FOR_3_PUMPS = 5000 milli_seconds; // You have to press 5s to operate the three pumps


/////////////////////////// Pin used ///////////////////////////////
const uint8_t PIN_START_BUTTON = A0; // Button wired between A0 and GND
const uint8_t PIN_ON_OFF_BUTTON = A1; // Button wired between A1 and GND
const uint8_t PIN_PUMP_1 = 2; // A HIGH on pin 2 sets out pump N°1
const uint8_t PIN_PUMP_2 = 3; // A HIGH on pin 3 sets out pump N°2
const uint8_t PIN_PUMP_3 = 4; // A HIGH on pin 4 sets out pump N°3
const uint8_t PIN_ON = 5; // Informed if we are "under tension"


/////////////////////////// Allow the pump 3 to turn some time
void stopPump3(void)
{
   digitalWrite(PIN_PUMP_3, LOW); // Stop the pump 3
}
MTclock TimerPump3(TIME_PUMP_3, stopPump3, 1 action_and_stop, MT_OFF);


/////////////////////////// Allow the pump 2 to turn some time
void stopPump2(void)
{
  digitalWrite(PIN_PUMP_3, HIGH); // Start the pump 3
  digitalWrite(PIN_PUMP_2, LOW); // Stop the pump 2
  TimerPump3.start(); // Start the next timer
}
MTclock TimerPump2(TIME_PUMP_2, stopPump2, 1 action_and_stop, MT_OFF);


/////////////////////////// Allow the pump 1 to turn some time
void stopPump1(void)
{
  digitalWrite(PIN_PUMP_2, HIGH); // Start the pump  2
  digitalWrite(PIN_PUMP_1, LOW); // Stop the pump 1
  TimerPump2.start(); // Start the next timer
}
MTclock TimerPump1(TIME_PUMP_1, stopPump1, 1 action_and_stop, MT_OFF);


/////////////////////////// Allow the three pumps to turn some time
void stop3Pumps(void)
{
  digitalWrite(PIN_PUMP_1, LOW); // Stop the pumps
  digitalWrite(PIN_PUMP_2, LOW);
  digitalWrite(PIN_PUMP_3, LOW);
}
MTclock Timer3Pumps(TIME_3_PUMPS, stop3Pumps, 1 action_and_stop, MT_OFF);


/////////////////////////// Long press
void threePumps(void)
{
  digitalWrite(PIN_PUMP_1, HIGH); // Start the 3 pumps
  digitalWrite(PIN_PUMP_2, HIGH);
  digitalWrite(PIN_PUMP_3, HIGH);
  TimerPump1.stop(); // Stop the cycle timers "a pump at a time"
  TimerPump2.stop();
  TimerPump3.stop();
  Timer3Pumps.start(); // Start the next timer
}
MTclock TimerFiveSeconds(TIME_FOR_3_PUMPS, threePumps, 1 action_and_stop, MT_OFF);


/////////////////////////// On/Off button /////////////////////////////
void start(void)
{
  digitalWrite(PIN_ON, HIGH); // Light the on/off light
}
void completStop(void)
{
  TimerPump1.stop(); // Stop all timers
  TimerPump2.stop();
  TimerPump3.stop();
  Timer3Pumps.stop();
  digitalWrite(PIN_PUMP_1, LOW); // Stop the pumps
  digitalWrite(PIN_PUMP_2, LOW);
  digitalWrite(PIN_PUMP_3, LOW);
  digitalWrite(PIN_ON, LOW); // Switch off the on/off light
}
MTcheckButton OnOffButton(PIN_ON_OFF_BUTTON, start, completStop);


/////////////////////////// Start button ///////////////////////////////////
void shortStart(void)
{
  if (OnOffButton.getSelect()) // If we are running
  {
    TimerPump1.start(); // Start the cycle
    TimerPump2.stop(); // Stop the other timers
    TimerPump3.stop();
    Timer3Pumps.stop();
    TimerFiveSeconds.start(); // to see a long press
    digitalWrite(PIN_PUMP_2, LOW); // Stop the pumps 2 and 3
    digitalWrite(PIN_PUMP_3, LOW);
    digitalWrite(PIN_PUMP_1, HIGH); // Start the first pump...
   }
}
void relaxing(void)
{
  TimerFiveSeconds.stop(); // Not a long press
}
MTbutton StartButton(PIN_START_BUTTON, shortStart, relaxing);


/////////////////////////// Setup and loop ///////////////////////////////////
void setup()
{
  pinMode(PIN_PUMP_1, OUTPUT); // pumps in OUTPUT mode
  pinMode(PIN_PUMP_2, OUTPUT);
  pinMode(PIN_PUMP_3, OUTPUT);
  pinMode(PIN_ON, OUTPUT); // Control led
}

void loop(){} // To put another independent program there
