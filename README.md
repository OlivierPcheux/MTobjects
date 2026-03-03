Version française plus bas.


Library MTobjects
=================


## Limitations
Only works on the AVRs (Nano, Uno, Mega) because of interruption management.
Use only timer 0 but completely.


## Objects addressed
- buttons plugged directly on an input, preferably between the pin and GND.
    Bell type, Two-Way Switch, radio button, double or triple clicks
    recognized.
- keypads
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


## Example
// This program makes the LED_BUILTIN blink on a Mega
#include <MTobjects.h> // V1.0.6 See http://arduino.dansetrad.fr/en/MTobjects
MThardPWM Blink(LED_BUILTIN, inpulses_width 500000 micro_seconds, periods_width 1000000 micro_seconds);
void setup(){}
void loop(){}


## Need help?
In addition to the examples of the library, documentation is at:
http://arduino.dansetrad.fr/en/MTobjects/accueil.php (in English)
http://arduino.dansetrad.fr/MTobjects/accueil.php (en français)
I am regularly on the Arduino French forum under the name of @vileroi.
I am also notified of a post which contains "@Vileroy"
Otherwise a personal email (Olivier@Dansetrad.fr) allows me to join.

Olivier

&nbsp;

&nbsp;

<hr>

Bibliothèque MTobjects
======================


## Limites
Fonctionne uniquement sur les AVR (Nano, Uno, Mega) à cause de la gestion par interruptions.
Utilise uniquement le timer 0 mais complètement.


## Objets utiles
- des boutons branchés directement sur une entrée, de préférence entre une pin et GND. 
Emule poussoir, va et vient, bouton radio, double ou triple clics reconnus.
- keypads
- des objets gérant le temps, pour avoir des appels réguliers ou non, uniques ou répétitifs
- PWM hard sur des broches spécifiques, avec possibilité de choisir facilement la période 
et les durées des impulsions
- PWM soft sur toutes les broches, avec possibilité de choisir facilement les périodes et 
périodes d'impulsion
- des servomoteurs ordinaires avec gestion automatique de la vitesse de déplacement. En ajoutant un 
quatrième fil, possibilité de mise sous tension sans mouvement
- moteurs pas à pas avec une gestion de 2 ou 4 bobines ou avec Step/Dir permettant 
vous d'exécuter plus de 10 000 pas ou micro-pas par seconde. Les moteurs peuvent 
avoir des accélérations


## Intérêt
Les boutons, horloges, PWM, servomoteurs, moteurs pas à pas utilisent entièrement et uniquement le
timer 0 pour avoir une programmation apparemment indépendante. Permet par exemple de
exécuter un stepper pendant un "delay()" d'une autre tâche. Vous pouvez utiliser la gestion
sans utiliser "loop()", ce qui facilite l'ajout de fonctions non fournis initialement. "loop()"
peut être bloquant.


## Par rapport à d'autres bibliothèques
La gestion se fait par interruption et ne nécessite pas de fonction MTobjects.run()
pour exécuter le code. loop() peut bloquer. C'est un peu comme si chaque objet était
géré en multitâche.
Les objets s'inclinent d'eux-mêmes avec leur déclaration. Il n'y a donc pas
fonction comme Button.begin().
L'utilisation d'objets ne nécessite souvent pas de code dans setup() et dans loop() et le
l'union de plusieurs codes fonctionnant séparément est aisée car elle suffit souvent
pour les mettre bout à bout.


## Exemple
// Ce programme fait clignoter le LED_BUILTIN sur un Mega
#include <MTobjects.h> // V1.0.6 Voir http://arduino.dansetrad.fr/en/MTobjects
#include <MTobjects.h> // V1.0.6 See http://arduino.dansetrad.fr/en/MTobjects
MThardPWM Blink(LED_BUILTIN, inpulses_width 500000 micro_seconds, periods_width 1000000 micro_seconds);
void setup(){}
void loop(){}


## Besoin d'aide ?
En plus des exemples de la bibliothèque, la documentation se trouve à l'adresse suivante :
http://arduino.dansetrad.fr/MTobjects/accueil.php (en français)
http://arduino.dansetrad.fr/en/MTobjects/accueil.php (en anglais)
Je suis régulièrement sur le forum Arduino français sous le nom de @vileroi.
Sinon un email personnel (Olivier@Dansetrad.fr) me permet d'être joint

Olivier
