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


// Voir https://forum.arduino.cc/t/generer-des-salves-dimpulsions/1379201

// Generation of bursts on the 17 pins of a Uno
// from 1 to 5 inpulse of 5ms with a period of 10ms
// So maximum duration 50ms -> Shipping of a burst every 60ms

#include <MTobjects.h> // V1.0.6 See http://arduino.dansetrad.fr/MTobjects

void setup()
{
  // Is not usefull because MTsoftPWM puts the pin in OUTPUT. It would be done at  
 // first inpulse. But this first inpulse_width would merge with the input in the begining 
 // It also can have a clean start for all output
  for (uint8_t pin = 2; pin < 20; pin++) // Pin between 2 and 13 or between A0=14 and A5=19
  {
    digitalWrite(pin, LOW); // Because the inpulses will be positive
    pinMode(pin, OUTPUT);
  }
}

void loop()
{
  // Start the burst
  MTsoftPWM *Burst = new MTsoftPWM(2 + random(18), // Pin between 2 and 13 or between A0 and A5
          inpulses_width 5000L micro_seconds,
          periods_width 10000L micro_seconds,
          HIGH, // LOW to rest, first level HIGH
          (1 + random(5)) * 2 levels_and_stop); // An inpulses is 2 levels. Between 2 and 10

  // Space between two beginnings of bursts
  delay(60 milli_seconds); // Bursts will occur during this instruction

  delete Burst; // Destruction to make others
}