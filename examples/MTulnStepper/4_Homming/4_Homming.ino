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

// Ce programme initialise la position d'un moteur pas à pas, puis fait faire
// un tour dans un sens un tour dans l'autre à un pas à pas

#include <MTobjects.h> // V1.1.0 Voir http://arduino.dansetrad.fr/MTobjects

const float vitesse = 0.5 RPS;
const uint8_t fdc = A0; // Fin de course; fermé au repos 
boolean initialise = false; // Avant homming, true après


// Partie faisant faire un tout dans un sens, un tour dans l'autre
void inversion(void); // Pré-définition

MTulnStepper Stepper(pin_A1 2, pin_B1 3, pin_A2 4, pin_B2 5, UNE_PHASE, accelerations_sur 2048 pas_ou_micro_pas, vitesse, SENS_PAR_DEFAUT, inversion);

void inversion(void) // Inversion du sens
{
  if (initialise)
  {
    delay(1000); // Attendre un peu avant de repartir dans l'autre sens
    if (Stepper.getPosition() == 0) // Si il est en position de référence
      Stepper.move(Stepper.getStepsPerTurn()); // On fait un tour
    else Stepper.moveTo(); // Sinon on revient en position de référence
  }
}

// Initialisation
void setup()
{
  // Initialisation du fin de course
  pinMode(fdc, INPUT_PULLUP); // Interrupteur entre fdc et Gnd

  // Mise à l'origine
  Stepper.setSpeed(vitesse / 10); // Doucement pendant la mise en référence
  Stepper.move(-CONTINUE); // Retour vers l'origine
  while (!digitalRead(fdc)); // Attente de la position d'origine
  Stepper.stop(); // On est à l'origine; on s'arrête
  Stepper.setOrigin(); // Repérer la position
  initialise = true; // Permettre le fonctionnement normal

  // Cycle normal
  Stepper.setSpeed(vitesse); // Reprise de la vitesse normale pour travailler
  inversion();
}

void loop(){}
