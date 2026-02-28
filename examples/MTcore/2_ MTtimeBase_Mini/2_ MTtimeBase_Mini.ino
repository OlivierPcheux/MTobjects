// Version 1.1.0

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

// Ce programme permet de rajouter des objets dans le but de trouver la base
// de temps minimum assurant le fonctionnement pour une configuration donnée

#include <MTobjects.h> // V1.1.0 Voir http://arduino.dansetrad.fr/MTobjects

// Création d'un objet pour faire la mesure. Cet objet fait changer le niveau
// de A5 chaque période de MTtimeBase. Avec un analyseur de signaux on doit
// s'assurer que le signal ne présente pas de trous pour un fonctionnement
// correct. On peut ainsi avoir la période la plus petite pour une
// configuration donnée.


// Création d'un signal carré issu de l'horloge MTquickTime, avec mise en place 
// des scans pour les différents objets (cas le plus défavorable)
class Mesure: public MTquickObject, public MTmediumObject, public MTslowObject
{
  public:
    Mesure(void);
  protected:
    virtual void quickAction(void); // Visualisation du fonctionnement de l'horloge MTtimeBase
};
Mesure::Mesure(void)
{
  pinMode(A5,OUTPUT); // Broche pour l'analyseur de signaux
}
void Mesure::quickAction(void)
{
  PINC = 0b00100000; // Changement de niveau de PC5 = A5
}
Mesure NotreMesure;



word BaseDeTemps = 8 micro_secondes;
word mtSoftPWM; // Nombre de MTsoftPWM rajoutés
word mtServo; // Nombre de MTservo rajoutés
word mtUlnStepper; // Nombre de MTulnStepper rajoutés
word mtStepStepper; // Nombre de MTstepStepper rajoutés
boolean delaymillis = false; // Si l'horloge système est désactivée


void setup()
{
  MTstopDelayMillis(); // Désactive l'horloge système
  Serial.begin(115200);
}



void loop()
{
  // Configuration
  Serial.print("MTtimeBase: ");
  Serial.print(BaseDeTemps);
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
  if (delaymillis>0) Serial.println("Horloge Arduino en route");
  Serial.println();

  // Menu
  Serial.println("MTtimeBase: '*' => +20µs,  '+' => +4µs,  '-' => -4µs,  '/' => -20µs");
  Serial.println("A => ajout d'un MTsoftPWM");
  Serial.println("B => ajout d'un MTservo");
  Serial.println("C => ajout d'un MTulnStepper");
  Serial.println("D => ajout d'un MTstepStepper");
  Serial.println("E => ajout de l'horloge Arduino");
  Serial.println("bouton Reset => réinitialisation du programme");
  Serial.println();

  // Commandes
  while (!Serial.available()); // Attente d'une commande
  switch(char(Serial.read()))
  {
    case '*':
      BaseDeTemps += 20; 
      break;
    case '+':
      BaseDeTemps += 4; 
      break;
    case '-':
      BaseDeTemps -= 4;
      break;
    case '/':
      BaseDeTemps -= 20;
      break;
    case 'a':
    case 'A':
      new MTsoftPWM(2, impulsions_de 1 micro_seconde, periodes_de 2 micro_secondes);
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
        MTulnStepper *Stepper = new MTulnStepper(pin_A1 2, pin_B1 2, pin_A2 2, pin_B2 2, PAS_ENTIERS, accelerations_sur 0 pas_ou_micro_pas, 1 micro_secondes_par_pas);
        Stepper->move(CONTINUE);
        mtUlnStepper++;
        break;
      }
    case 'd':
    case 'D':
      {
        MTstepStepper *Stepper = new MTstepStepper(pin_Step 2, pin_Dir NON_CONNECTEE, pin_EN NON_CONNECTEE, accelerations_sur 0 pas_ou_micro_pas, 16 micro_pas, 1 micro_secondes_par_pas);
        Stepper->move(CONTINUE);
        mtStepStepper++;
	      break;
      }
    case 'e':
    case 'E':
      if (delaymillis) MTstopDelayMillis(); // Désactive l'horloge système
      else MTstartDelayMillis(); // Active l'horloge Arduino
      delaymillis = !delaymillis;
  }
  MTtimeBase(BaseDeTemps); // Minimum pour un seul pas à pas
}