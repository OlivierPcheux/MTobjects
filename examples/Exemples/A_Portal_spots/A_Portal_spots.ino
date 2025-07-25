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


// 3s after activating the portal, the first lighting lights up,
// 1s after the 2nd, 1s after the 3rd, 1s after the 4th and 1s after all the
// spots that light up the facade light up. After 30s everything goes out


// See https://forum.arduino.cc/t/piloter-luminaires-electrique-exterieur-avec-portail-electrique/1384084

/////////////////////////// Library used ///////////////////////////
#include "MTobjects.h" // V1.0.6 See http://arduino.dansetrad.fr/MTobjects


/////////////////////////// Pins used ///////////////////////////////
const uint8_t PORTAL_PIN = 2; // Information from the portal, LOW when the portal opens
const uint8_t SPOT_1 = A1; // A HIGH on the A1 pin lights the spot N°1
const uint8_t SPOT_2 = A2; // A HIGH on the A2 pin lights the spot N°2
const uint8_t SPOT_3 = A3; // A HIGH on the A3 pin lights the spot N°3
const uint8_t SPOT_4 = A4; // A HIGH on the A4 pin lights the spot N°4
const uint8_t FACADE_SPOTS = A5; // A HIGH on the A0 pin lights the facade spots


/////////////////////////// After 30s everything goes out
void extinction(void)
{
  digitalWrite(FACADE_SPOTS, LOW); // Extinction
  digitalWrite(SPOT_4, LOW);
  digitalWrite(SPOT_3, LOW);
  digitalWrite(SPOT_2, LOW);
  digitalWrite(SPOT_1, LOW);
}
MTclock ExtinctionTimer(30000 milli_seconds, extinction, 1 action_and_stop, MT_OFF);


/////////////////////////// 1s after all the spots that light the facade light up
void facadeSpotOn(void)
{
  digitalWrite(FACADE_SPOTS, HIGH); // Light up of facade spots
  ExtinctionTimer.start(); // Waiting for 1s before lighting the next spot
}
MTclock TimerFacade(1000 milli_seconds, facadeSpotOn, 1 action_and_stop, MT_OFF);


/////////////////////////// 1s after all the spots 4
void lightOnSpot4(void)
{
  digitalWrite(SPOT_4, HIGH); // Light up of 4th spots
  TimerFacade.start(); // Waiting for 1s before lighting the next spot
}
MTclock Timer4(1000 milli_seconds, lightOnSpot4, 1 action_and_stop, MT_OFF);


/////////////////////////// 1s after all the spots 3
void lightOnSpot3(void)
{
  digitalWrite(SPOT_3, HIGH); // Light up of 3rd spots
  Timer4.start(); // Waiting for 1s before lighting the next spot
}
MTclock Timer3(1000 milli_seconds, lightOnSpot3, 1 action_and_stop, MT_OFF);


/////////////////////////// 1s after all the spots 2
void lightOnSpot2(void)
{
  digitalWrite(SPOT_2, HIGH); // Light up of 2nd spots
  Timer3.start(); // Waiting for 1s before lighting the next spot
}
MTclock Timer2(1000 milli_seconds, lightOnSpot2, 1 action_and_stop, MT_OFF);


/////////////////////////// 3s after all the spots 1
void lightOnSpot1(void)
{
  digitalWrite(SPOT_1, HIGH); // Light up of 1st spots
  Timer2.start(); // Waiting for 1s before lighting the 2nd spot
}
MTclock Timer1(3000 milli_seconds, lightOnSpot1, 1 action_and_stop, MT_OFF);


/////////////////////////// Info du portail
void depart(void)
{
  Timer1.start(); // Waiting for 3s before lighting the next spot
}
MTbutton Portail(PORTAL_PIN, depart);



/////////////////////////// Setup and loop ///////////////////////////////////
void setup()
{
  pinMode(SPOT_1, OUTPUT);
  pinMode(SPOT_2, OUTPUT);
  pinMode(SPOT_3, OUTPUT);
  pinMode(SPOT_4, OUTPUT);
  pinMode(FACADE_SPOTS, OUTPUT);
}

void loop(){}// To put another independent program