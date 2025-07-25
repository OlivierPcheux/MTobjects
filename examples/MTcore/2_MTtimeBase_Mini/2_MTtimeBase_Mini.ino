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

// This program allows you to add objects in order to find the minimum
// time base ensuring function for a given configuration

#include "MTobjects.h" // V1.0.6 See http://arduino.dansetrad.fr/MTobjects

// Creation of an object to do the measurement. This object changes the level
// of A5 each period of mttimebase. With a signal analyzer we must ensure
// that the signal does not have holes for correct function. We can thus have
// the smallest period for a given configuration.


// Creation of a square signal from the MTquickTime clock, with implementation
// of scans for the various objects (the most unfavorable cases)
class Measurement: public MTquickObject, public MTmediumObject, public MTslowObject
{
  public:
    Measurement(void);
  protected:
    virtual void quickAction(void); // Visualization of the functioning of the MTimeBase clock
};
Measurement::Measurement(void)
{
  pinMode(A5,OUTPUT); // Pin for the signal analyzer
}
void Measurement::quickAction(void)
{
  PINC = 0b00100000; // PC5 (= A5) level change
}
Measurement MyMeasurement;



word timeBase = 8 micro_seconds;
word mtSoftPWM; // MTsoftPWM number added
word mtServo; // MTservo number added
word mtUlnStepper; // MTulnStepper number added
word mtStepStepper; // MTstepStepper number added
boolean delaymillis = false; // If the system clock is disabled


void setup()
{
  MTstopDelayMillis(); // Disable system clock
  Serial.begin(115200);
}



void loop()
{
  // Configuration
  Serial.print("MTtimeBase: ");
  Serial.print(timeBase);
  Serial.println("µs");
  if (mtSoftPWM>0)
  {
    Serial.print(mtSoftPWM);
    Serial.println(" MTsoftPWM");
  }
  if (mtServo>0)
  {
    Serial.print(mtServo);
    Serial.println(" MTServo");
  }
  if (mtUlnStepper>0)
  {
    Serial.print(mtUlnStepper);
    Serial.println(" MTulnStepper");
  }
  if (mtStepStepper>0)
  {
    Serial.print(mtStepStepper);
    Serial.println(" MTstepStepper");
  }
  if (delaymillis>0) Serial.println("Arduino clock running");
  Serial.println();

  // Menu
  Serial.println("MTtimeBase: '*' => +20µs,  '+' => +4µs,  '-' => -4µs,  '/' => -20µs");
  Serial.println("A => Addition of an MTsoftPWM");
  Serial.println("B => Addition of an MTservo");
  Serial.println("C => Addition of an MTulnStepper");
  Serial.println("D => Addition of an MTstepStepper");
  Serial.println("E => Addition of Arduino clock");
  Serial.println("Reset button => programm resetting");
  Serial.println();

  // Commands
  while (!Serial.available()); // Wait a command
  switch(char(Serial.read()))
  {
    case '*':
      timeBase += 20; 
      break;
    case '+':
      timeBase += 4; 
      break;
    case '-':
      timeBase -= 4;
      break;
    case '/':
      timeBase -= 20;
      break;
    case 'a':
    case 'A':
      new MTsoftPWM(2, inpulses_width 1 micro_second, periods_width 2 micro_seconds);
      mtSoftPWM++;
      break;
    case 'b':
    case 'B':
      new MTservo(2);
      mtServo++;
      break;
    case 'c':
    case 'C':
      {
        MTulnStepper *Stepper = new MTulnStepper(pin_A1 2, pin_B1 2, pin_A2 2, pin_B2 2, WHOLE_STEP, accelerations_of 0 step_or_micro_step, 1 micro_second_per_step);
        Stepper->move(CONTINUE);
        mtUlnStepper++;
        break;
      }
    case 'd':
    case 'D':
      {
        MTstepStepper *Stepper = new MTstepStepper(pin_Step 2, pin_Dir UNCONNECTED, pin_EN UNCONNECTED, accelerations_of 0 step_or_micro_step, 16 micro_pas, 1 micro_second_per_step);
        Stepper->move(CONTINUE);
        mtStepStepper++;
	      break;
      }
    case 'e':
    case 'E':
      if (delaymillis) MTstopDelayMillis(); // Disable system clock
      else MTstartDelayMillis(); // Active the Arduino clock
      delaymillis = !delaymillis;
  }
  MTtimeBase(timeBase); // Minimum pour un seul pas à pas
}