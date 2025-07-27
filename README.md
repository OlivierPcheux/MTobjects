Library MTobjects


## Limitations
Only works on the AVRs (Nano, Uno, Mega) because of interruption management.
Use only timer 0 but completely.


## Objects addressed
- buttons plugged directly on an input, preferably between the pin and GND.
    Bell type, Two-Way Switch, radio button, double or triple clicks
    recognized.
- objects managing time, to have regular calls or not, unique or repetitive
- hard PWM on specific pins, with the possibility of easily choosing the period
    and the durations of impulses
- soft PWM on all pins, with the possibility of easily choosing the periods and
    impulse periods
- ordinary servomotors with automatic management of travel speed. By adding a
    fourth wire, possibility of a a switch on tension without movement
- steppers motors with a management of 2 or 4 coils or with Step/Dir allowing
    you to run more than 10,000 steps or micro-steps per second. Motors can
    have accelerations


## Utility
Buttons, clocks, PWM, servomotors, stepper motors use completely and only the
timer 0 to have an apparently independent programming. Allows for example to
run a stepper during a "delay()" of another task. You can use management
without using "loop()", which facilitates the addition of functions not
provided initially. "loop()" can be blocking.


## Compared to other libraries
Management is done by interruption and does not need a MTobjects.run() function
to execute the code. loop() can be blocking. It is a bit as if each object was
managed by multitasking.
Objects are tilt on their own with their declaration. There is therefore no
function like Button.begin().
The use of objects often does not require code in setup() and in loop() and the
union of several codes operating separated is easy because it is often enough
to put them to end to end.

## Need help?
In addition to the examples of the library, documentation is at:
http://arduino.dansetrad.fr/en/MTobjects/accueil.php (in English)
http://arduino.dansetrad.fr/MTobjects/accueil.php (en français)
I am regularly on the Arduino French forum under the name of @vileroi.
Otherwise a personal email (Olivier@Dansetrad.fr) allows me to join.

Olivier
