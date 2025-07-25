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


// See https://forum.arduino.cc/t/generer-des-salves-dimpulsions/1379201

// Generation of inpulse bursts on an output pin
// from 1 to 5 inpulses to 2/3Hz
// So maximum duration 2.5s -> repetition between 3 and 6s


#include <MTobjects.h> // V1.0.6 See http://arduino.dansetrad.fr/MTobjects

MTsoftPWM Bursts(LED_BUILTIN); // Set up

void setup()
{
  Bursts.stop(); // Stop because run in initialization. Could be done during its creation!
}

void loop()
{
  // Prepare from 1 to 5 inpulses to 2 to 3 Hz
  long period = (300 + random(200))*1000 micro_seconds; // Between 0.3s and 0.5s
  Bursts.setPeriod(period);
  Bursts.setInpulse(period/2);
  long number_of_levels = (1 + random(5)) * 2; // A inpulse is 2 levels. Between 2 and 10
  Bursts.setNumberOfLevels(number_of_levels levels_and_stop);
  
  // Start the burst
  Bursts.start();

  // Space between two beginnings of bursts
  long wait = 3000 + random(3000) milli_seconds; // Between 3s and 6s
  delay(wait); // Bursts will occur during this instruction
}