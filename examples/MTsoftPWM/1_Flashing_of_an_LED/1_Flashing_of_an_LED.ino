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


// This program will flash LED_BUILTIN

#include <MTobjects.h> // V1.0.6 See http://arduino.dansetrad.fr/MTobjects


// 5 quick flashs
MTsoftPWM FiveFlash(LED_BUILTIN, inpulses_width 50000 micro_seconds, periods_width 100000 micro_seconds, start_with HIGH, 10 levels_and_stop);


// Launch of flashes every 2 seconds
void flash(void)
{
  FiveFlash.start(); // Relaunch PWM
}

MTclock Metronome(2000 milli_seconds, flash);


void setup(){}

void loop(){}