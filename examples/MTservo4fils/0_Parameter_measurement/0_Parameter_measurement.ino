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

// This program makes it possible to measure the two values to go into parameters
// for a 4-wires servo

#include <MTobjects.h> // V1.0.6 See http://arduino.dansetrad.fr/MTobjects

const uint8_t PIN_SERVO = 9; // On Uno the usable commands pins are: 9, 10
                             // On Mega: 2, 3, 5, 6, 7, 8, 11, 12, 13, 44, 45, 46
const uint8_t POTENTIOMETER = A0; // Info on the position of the servo


MTservo4wires Servo(PIN_SERVO, POTENTIOMETER, cad_for_0_degree 0, cad_for_180_degree 1023); // These two values are to be measured for each servo

void setup()
{
  Serial.begin(115200); // Console preparation
}

void loop()
{
  Serial.print(F("cad_for_0_degree : "));
  Servo.writeDegree(0);
  delay(2000 milli_seconds); // We must wait until the servo is well in place
  Serial.print(analogRead(POTENTIOMETER));

  Serial.print(F(",  cad_for_180_degree : "));
  Servo.writeDegree(180);
  delay(2000 milli_seconds); // We must wait until the servo is well in place
  Serial.println(analogRead(POTENTIOMETER));
}