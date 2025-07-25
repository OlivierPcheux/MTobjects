// Version V1.0.6

#include <Arduino.h>
#include <MTobjects.h> // V1.0.6 Voir http://arduino.dansetrad.fr/MTobjects

//###########################################################################
//###########################################################################
//####                                                                   ####
//####                          Olivier Pécheux                          ####
//####                       Olivier@Dansetrad.fr                        ####
//####                        (33) +6 69 77 82 58                        ####
//####               http://arduino.dansetrad.fr/MTobjects               ####
//####                                                                   ####
//###########################################################################
//###########################################################################

#if !defined(__AVR_ATmega328P__) && !defined(__AVR_ATmega328__) && !defined(__AVR_ATmega2561__) && !defined(__AVR_ATmega2560__)
  #error Cette bibliothèque ne fonctionne que sur Uno, Nano ou Mega
#endif


//###########################################################################
//###########################################################################
//####                                                                   ####
//####                         Variables globales                        ####
//####                                                                   ####
//###########################################################################
//###########################################################################

// Debug
long debug;
// Boutons
word bounce = 40 milli_secondes; // Temps minimum en ms pour le traitement des rebonds
word doubleBounce = 250 milli_secondes; // Temps minimum en ms pour le traitement des doubles clics
word tripleBounce = 300 milli_secondes; // Temps minimum en ms pour le traitement des triples clics
//PWM & Servos
#define Timer1 0x80
#define Timer3 0x90
#define Timer4 0xA0
#define Timer5 0xB0
#define OutputA 0
#define OutputB 2
#define OutputC 4

#if defined(__AVR_ATmega2561__) || defined(__AVR_ATmega2560__)
const PROGMEM byte MT_TIMER[] = {
  Timer1 + OutputC, // broche 0
  Timer1 + OutputC, // broche 1
  Timer3 + OutputB, // broche 2
  Timer3 + OutputC, // broche 3
  Timer1 + OutputC, // broche 4
  Timer3 + OutputA, // broche 5
  Timer4 + OutputA, // broche 6
  Timer4 + OutputB, // broche 7
  Timer4 + OutputC, // broche 8
  Timer1 + OutputC, // broche 9
  Timer1 + OutputC, // broche 10
  Timer1 + OutputA, // broche 11
  Timer1 + OutputB, // broche 12
  Timer1 + OutputC, // broche 13
  Timer5 + OutputC, // broche 44
  Timer5 + OutputB, // broche 45
  Timer5 + OutputA}; // broche 46
#endif

//###########################################################################
//###########################################################################
//####                                                                   ####
//####                      Coeur de la bibliothèque                     ####
//####                                                                   ####
//###########################################################################
//###########################################################################


//###########################################################################
//##                       Variables événementielles                       ##
//###########################################################################
MTquickObject  *firstMTquickObject = NULL;  // Pointeur sur le premier MTquickObject
MTmediumObject *firstMTmediumObject = NULL; // Pointeur sur le premier MTmediumObject
MTslowObject   *firstMTslowObject = NULL;   // Pointeur sur le premier MTslowObject


//###########################################################################
//##                               MTtimeBase                              ##
//###########################################################################
byte _ticksForMTquickObject_ = 25; // 100µs
word _timeCounterForMTslowObject_ = 0; // Par défaut compte de 0 à 19 pour 20ms
word _timeCounterForMTmediumObject_ = 0; // Compte de 0 à 255 pour 16ms
float _ratio_; // Rapport pour ajuster les QuickObjets après MTtimeBase

void MTtimeBase(word timeBaseForMTquickObject micro_secondes)
{
  // Mise à jour pour les MTquickObject
  if (timeBaseForMTquickObject >= 8)
  {
    timeBaseForMTquickObject = (timeBaseForMTquickObject & 0x03FC) >> 2; // Nouveau _ticksForMTquickObject_
      _ratio_ = float(_ticksForMTquickObject_) / float(timeBaseForMTquickObject);
    _ticksForMTquickObject_ = timeBaseForMTquickObject;
    // Mise à jour éventuelles des différents MTquickObject
    //    Les MTquickObject utilisent non pas les µs, mais les ticks (nombre
    //    d'appels de leur fonction action()). Si on divise leur base de
    //    temps par N, il faut qu'ils multiplient leur nombres de ticks par N
    MTquickObject *MTquickObjectPtr = firstMTquickObject; // On va pointer toutes les MTquickObject
    while (MTquickObjectPtr != NULL) // Tant qu'il reste des MTquickObject à visiter
    {
      MTquickObjectPtr->baseDeTemps(); // Donner la main pour qu'il s'autogère
      MTquickObjectPtr = MTquickObjectPtr->MTnextQuickObject; // On poursuit la liste
    }  
  }
}


//###########################################################################
//##                                MTsecure                               ##
//###########################################################################
long MTsecure(volatile long &valeur)
{
  uint8_t sreg = SREG; // Sauvegarde du bit I (Global Interrupt Enable)
  cli(); // A cause d'un long qu'on ne peut pas lire si il change
  long temp = valeur;
  SREG = sreg; // Remise dans l'état d'origine inters ou pas
  return temp;
}
word MTsecure(volatile word &valeur)
{
  uint8_t sreg = SREG; // Sauvegarde du bit I (Global Interrupt Enable)
  cli(); // A cause d'un word qu'on ne peut pas lire si il change
  word temp = valeur;
  SREG = sreg; // Remise dans l'état d'origine inters ou pas
  return temp;
}
unsigned long MTsecure(volatile unsigned long &valeur)
{
  uint8_t sreg = SREG; // Sauvegarde du bit I (Global Interrupt Enable)
  cli(); // A cause d'un unsigned long qu'on ne peut pas lire si il change
  unsigned long temp = valeur;
  SREG = sreg; // Remise dans l'état d'origine inters ou pas
  return temp;
}
void MTsecure(volatile long &resultat, long &valeur)
{
  uint8_t sreg = SREG; // Sauvegarde du bit I (Global Interrupt Enable)
  cli(); // A cause d'un long qu'on ne peut pas lire si il change
  resultat = valeur;
  SREG = sreg; // Remise dans l'état d'origine inters ou pas
}
void MTsecure(volatile word &resultat, word &valeur)
{
  uint8_t sreg = SREG; // Sauvegarde du bit I (Global Interrupt Enable)
  cli(); // A cause d'un word qu'on ne peut pas lire si il change
  resultat = valeur;
  SREG = sreg; // Remise dans l'état d'origine inters ou pas
}
void MTsecure(volatile unsigned long &resultat, unsigned long &valeur)
{
  uint8_t sreg = SREG; // Sauvegarde du bit I (Global Interrupt Enable)
  cli(); // A cause d'un unsigned long qu'on ne peut pas lire si il change
  resultat = valeur;
  SREG = sreg; // Remise dans l'état d'origine inters ou pas
}


//###########################################################################
//##                             MTdigitalRead                             ##
//###########################################################################
bool MTdigitalRead(byte pin)
{
  return (*portInputRegister(digitalPinToPort(pin)) & digitalPinToBitMask(pin)) > 0;
}


//###########################################################################
//##                                MTmillis                               ##
//###########################################################################
unsigned long _temps_ms_; // horloge interne MTcore
unsigned long MTmillis(void) // Équivalent à millis()
{
  TIMSK0 |= 0b00000100; // Interruptions pour l'horloge MTcore (et pour les MTquickObject)
  return MTsecure(_temps_ms_);
}



//###########################################################################
//##                 TIMER0_COMPA_vect -> Les MTquickObject                ##
//###########################################################################
ISR(TIMER0_COMPA_vect)
{
  // Gestion pour avoir une horloge à 100µs
  TCCR0A = 0; // Mode normal, on n'utilise pas le PWM du timer 0
  // Note: doit être fait après le setup, sinon l'initialisation remet 3
  OCR0A += _ticksForMTquickObject_; // Pour la prochaine fois
  
  // Traitement des MTquickObject rajoutées, entièrement fait à chaque fois
  MTquickObject *MTquickObjectPtr = firstMTquickObject; // On va pointer toutes les MTquickObject
  while (MTquickObjectPtr != NULL) // Tant qu'il reste des MTquickObject à visiter
  {
    MTquickObjectPtr->quickAction(); // Donner la main pour qu'il s'autogère
    MTquickObjectPtr = MTquickObjectPtr->MTnextQuickObject; // On poursuit la liste
  }
}


//###########################################################################
//##                 TIMER0_COMPB_vect -> Les MTslowObject                 ##
//##                                   -> Les MTmediumObject               ##
//###########################################################################
ISR(TIMER0_COMPB_vect)
{
  // Gestion pour avoir une horloge à 1ms
  TCCR0A = 0; // Mode normal, on n'utilise pas le PWM du timer 0
  // Note: doit être fait après le setup, sinon l'initialisation remet 3
  _temps_ms_++; // Horloge MTcore
  OCR0B +=250; // Pour dans 1ms


  if ((++_timeCounterForMTmediumObject_ & 0xF) != 0) return; // 15 fois sur 16, soit toutes les 16ms 

  // Gestionnaire des MTmediumObject
  static bool notBusyMedium=true; // Permet de ne pas rentrer dans la boucle des notBusyMedium si on n'en est pas sorti 
  if (notBusyMedium) // Si une autre instance n'est pas en route
  {
    notBusyMedium = false; // Pour que cette partie du code ne puisse être exécutée qu'une seule fois en même temps
    sei(); // Permet aux horloges de tourner (système, mais aussi traitement des MTquickObject)
    MTmediumObject *MTmediumObjectPtr = firstMTmediumObject; // On va pointer toutes les MTmediumObject
    while (MTmediumObjectPtr != NULL) // Tant qu'il reste des MTmediumObject à visiter
    {
      MTmediumObjectPtr->mediumAction(); // Donner la main pour qu'il s'autogère
      MTmediumObjectPtr = MTmediumObjectPtr->MTnextMediumObject; // On poursuit la liste
    }  
    cli(); // Pour pouvoir finir la sortie avant d'être interrompu
    notBusyMedium = true;
  }
  
  // Gestionnaire des MTslowObject
  static bool notBusySlow=true; // Permet de ne pas rentrer dans la boucle des MTslowObject si on n'en est pas sorti 
  // traitement des MTslowObject rajoutés, fait si on n'est pas en train d'en traiter une autre.
  if (notBusySlow) // Si une autre instance n'est pas en route
  {
    notBusySlow = false; // Pour que cette partie du code ne puisse être exécutée qu'une seule fois en même temps
    sei(); // Permet aux horloges de tourner (système, mais aussi traitement des MTquickObject et MTmeduimObject)
    // Gestion des MTslowObject rajoutés
    MTslowObject *MTslowObjectPtr = firstMTslowObject; // On va pointer tous les MTslowObject
    while (MTslowObjectPtr != NULL) // Tant qu'il reste des MTslowObject à visiter
    {
      MTslowObjectPtr->slowAction(); // Donner la main pour qu'il s'autogère
      MTslowObjectPtr = MTslowObjectPtr->MTnextSlowObject; // On poursuit la liste
    }
    cli(); // Pour pouvoir finir la sortie avant d'être interrompu
    notBusySlow = true;
  }
}


//###########################################################################
//##                            Classes de base                            ##
//###########################################################################
MTquickObject::MTquickObject()
{
  // Insertion de l'objet dans la chaîne
  MTnextQuickObject = firstMTquickObject;
  firstMTquickObject = this;
  TIMSK0 |= 0b00000010; // Interruptions pour les MTquickObject
}

MTquickObject::~MTquickObject()
{
  // Suppression de l'objet dans la chaïne
  if (firstMTquickObject == this) firstMTquickObject = firstMTquickObject->MTnextQuickObject; // C'était le premier de la liste
  else
  {
    MTquickObject *MTquickObjectPtr = firstMTquickObject; // Pointer sur le premier
    while (MTquickObjectPtr != this) MTquickObjectPtr = MTquickObjectPtr->MTnextQuickObject; // On poursuit la liste
    // Maintenant MTquickObjectPtr pointe sur l'objet précédent
    MTquickObjectPtr->MTnextQuickObject = MTnextQuickObject; // On saute notre objet
  }
}


MTmediumObject::MTmediumObject()
{
  // Insertion de l'objet dans la chaîne
  MTnextMediumObject = firstMTmediumObject;
  firstMTmediumObject = this;
  TIMSK0 |= 0b00000100; // Interruptions pour les MTmediumObject
}

MTmediumObject::~MTmediumObject()
{
  // Suppression de l'objet dans la chaïne
  if (firstMTmediumObject == this) firstMTmediumObject = firstMTmediumObject->MTnextMediumObject; // C'était le premier de la liste
  else
  {
    MTmediumObject *MTmediumObjectPtr = firstMTmediumObject; // Pointer sur le premier
    while (MTmediumObjectPtr != this) MTmediumObjectPtr = MTmediumObjectPtr->MTnextMediumObject; // On poursuit la liste
    // Maintenant MTmediumObjectPtr pointe sur l'objet précédent
    MTmediumObjectPtr->MTnextMediumObject = MTnextMediumObject; // On saute notre objet
  }
}


MTslowObject::MTslowObject()
{
  // Insertion de l'objet dans la chaîne
  MTnextSlowObject = firstMTslowObject;
  firstMTslowObject = this;
  TIMSK0 |= 0b00000100; // Interruptions pour les MTslowObject
}

MTslowObject::~MTslowObject()
{
  // Suppression de l'objet dans la chaïne
  if (firstMTslowObject == this) firstMTslowObject = firstMTslowObject->MTnextSlowObject; // C'était le premier de la liste
  else
  {
    MTslowObject *MTslowObjectPtr = firstMTslowObject; // Pointer sur le premier
    while (MTslowObjectPtr != this) MTslowObjectPtr = MTslowObjectPtr->MTnextSlowObject; // On poursuit la liste
    // Maintenant MTslowObjectPtr pointe sur l'objet précédent
    MTslowObjectPtr->MTnextSlowObject = MTnextSlowObject; // On saute notre objet
  }
}



//###########################################################################
//###########################################################################
//####                                                                   ####
//####                              Horloges                             ####
//####                                                                   ####
//###########################################################################
//###########################################################################


//###########################################################################
//##                                MTclock                                ##
//###########################################################################
// MTclock fournit un événement régulier


//############################### Constructeur ##############################
MTclock::MTclock(unsigned long interval_ms milli_secondes, // Temps entre les actions
    void (*onTimeFunction)(void), // Pas d'action par défaut
    unsigned long numberOfActions, // Nombre d'actions, infini par défaut
    boolean active) // Actif par défaut
  : MTinterval_ms(interval_ms),
    MTonTimeFunction(onTimeFunction),
      MTnumberOfActions(numberOfActions),
    MTactive(active),
    MTremains(numberOfActions)
{}

//################################## start ##################################
void MTclock::start(void)
{
  MTactive = MT_OFF;
  MTremains  = MTnumberOfActions; // Remise à zéro du comptage, permet de recommencer
  MTtimeStart = MTmillis();
  MTactive = MT_ON;
}

//################################ slowAction ###############################
// Appelée régulièrement par le gestionnaire
void MTclock::slowAction(void)
{
  if (MTactive && (MTmillis() - MTtimeStart > MTinterval_ms))  // C'est son espace-temps
  {
    MTtimeStart += MTinterval_ms; // Réarmement
    onTime(); // Pour l'utilisateur
    if (MTonTimeFunction != PAS_D_ACTION) (*MTonTimeFunction)(); // Action possible de l'utilisateur
    if (MTremains  > 0) if (--MTremains  == 0) MTactive = MT_OFF;
  }
}


//###########################################################################
//##                             MTdoubleClock                             ##
//###########################################################################
// MTdoubleClock fournit deux événements réguliers alternés

//############################### Constructeur ##############################
MTdoubleClock::MTdoubleClock(unsigned long interval1_ms, // Attente avant la première action
    unsigned long interval2_ms, // Attente avant la deuxième action
    void (*onTimeFunction1)(void), // = PAS_D_ACTION, Pas de première action par défaut
    void (*onTimeFunction2)(void), // = PAS_D_ACTION, Pas de deuxième action par défaut
    unsigned long numberOfActions, // = MT_INFINI, Nombre d'actions en tout,  infini par défaut
    boolean active) // = MT_ON, Actif par défaut
  : MTclock(interval1_ms, onTimeFunction1, numberOfActions, active),
    MTinterval2_ms(interval2_ms), MTonTimeFunction2(onTimeFunction2), MTwhatAction(true)
{}

//################################ slowAction ###############################
// Appelée régulièrement par le gestionnaire
void MTdoubleClock::slowAction(void)
{
  if (MTactive)  // Si on est actif
  {{
    if (MTwhatAction) // Et partant pour la première action
    {
      if (MTmillis() - MTtimeStart > MTinterval_ms)  // Et c'est l'heure
      {
        MTtimeStart += MTinterval_ms; // Réarmement pour la deuxième action
        onTime1(); // Pour l'utilisateur
        if (MTonTimeFunction != NULL) (*MTonTimeFunction)(); // Action possible de l'utilisateur
        if (MTremains  > 0) if (--MTremains  == 0) MTactive = MT_OFF;
        MTwhatAction = false;
      }
    }
    else
    {
      if (MTmillis() - MTtimeStart > MTinterval2_ms)  // Et c'est l'heure
      {
        MTtimeStart += MTinterval2_ms; // Réarmement pour la première action
        onTime2(); // Pour l'utilisateur
        if (MTonTimeFunction2 != NULL) (*MTonTimeFunction2)(); // Action possible de l'utilisateur
        if (MTremains  > 0) if (--MTremains  == 0) MTactive = MT_OFF;
        MTwhatAction = true;
      }
    }
  }}
}

//################################## start ##################################
void MTdoubleClock::start(void)
{
  MTactive = MT_OFF;
  MTremains  = MTnumberOfActions; // Remise à zéro du comptage, permet de recommencer
  MTwhatAction = true;
  MTtimeStart = MTmillis();
  MTactive = MT_ON;
}



//###########################################################################
//###########################################################################
//####                                                                   ####
//####                              Boutons                              ####
//####                                                                   ####
//###########################################################################
//###########################################################################


//###########################################################################
//##                                MTbutton                               ##
//###########################################################################

//############################### Constructeur ##############################
MTbutton::MTbutton(uint8_t pin, // Broche sur lequel est branché le bouton
    void (onSelectFunction)(void), // Pas d'action par défaut
    void (onUnselectFunction)(void), // Pas d'action par défaut
    boolean repos) // État de la broche, bouton au repos. INPUT_PULLUP si HIGH
  : MTpin(pin), MTonSelectFunction(onSelectFunction), MTonUnselectFunction(onUnselectFunction),
    MTrepos(repos), MTetat(repos)
{
  if (MTrepos) pinMode(MTpin, INPUT_PULLUP);
}

//############################### mediumAction ##############################
// Appelée régulièrement par le gestionnaire pour voir les changements
void MTbutton::mediumAction(void)
{
  if (((MTetat & 1) != MTdigitalRead(MTpin)) && // Il a changé d'état
//  if (((MTetat & 1) != digitalRead(MTpin)) && // Équivalent mais désactive le timer si il y en a un
      (word(MTmillis()) - MTtimeStartBounce > bounce)) // Et on a attendu la fin des rebonds
  {
    MTetat ^= 1; // On change son état
    MTtimeStartBounce = word(MTmillis());
    if ((MTetat & 1) ^ MTrepos) MTetat |= 0x80; // Bouton appuyé, on mémorise
    else MTetat |= 0x40; // Bouton relâché, on mémorise
  }
}

//################################ slowAction ###############################
// Appelée régulièrement par le gestionnaire pour gérer les événements
void MTbutton::slowAction(void)
{
  if ((MTetat & 0x80) > 0) // Le bouton a été appuyé
  {
    MTetat &= 0x7F;
    onSelect(); // Pour l'utilisateur
    if (MTonSelectFunction != PAS_D_ACTION) (*MTonSelectFunction)(); // Action possible de l'utilisateur
  }
  if ((MTetat & 0x40) > 0) // Le bouton a été relâché
  {
    MTetat &= 0xBF;
    onUnselect(); // Pour l'utilisateur
    if (MTonUnselectFunction != PAS_D_ACTION) (*MTonUnselectFunction)(); // Action possible de l'utilisateur
  }
}


//###########################################################################
//##                             MTdoubleButton                            ##
//###########################################################################
// MTdoubleButton fournit la gestion pour un bouton poussoir gérant le clic
// et le double-clic

//############################### Constructeur ##############################
MTdoubleButton::MTdoubleButton(uint8_t pin, // Broche sur lequel est branché le bouton
    void (onDoubleSelectFunction)(void), // Pas d'action par défaut
    void (onSelectFunction)(void), // Pas d'action par défaut
    boolean repos) // État de la broche, bouton au repos. INPUT_PULLUP si HIGH
  : MTbutton(pin, onSelectFunction, onDoubleSelectFunction, repos), MTarmed(0)
{}

//############################### mediumAction ##############################
// Appelée régulièrement par le gestionnaire pour voir les changements
void MTdoubleButton::mediumAction(void)
{
  // bouton:       _________--___--__________________--_________
  // doubleBounce:          <------->                <------->
  // MTarmed:      _________-----____________________---------__
  // select:       __________________________________________^__
  // doubleSelect: ______________^______________________________

  // Traitement d'un appui  
  if (((MTetat & 1) != MTdigitalRead(MTpin)) && // Il a changé d'état
//  if (((MTetat & 1) != digitalRead(MTpin)) && // Équivalent mais désactive le timer si il y en a un
      (word(MTmillis()) - MTtimeStartBounce > bounce)) // Et on a attendu la fin des rebonds
  {
    MTetat ^= 1; // On change son état
    MTtimeStartBounce = word(MTmillis());
    if ((MTetat & 1) ^ MTrepos) // On vient d'appuyer sur le bouton
    {{
      if (MTarmed) // c'est le deuxième appui
      {
        MTarmed = false;
        MTetat |= 0x80; // Double clic, on mémorise
      }
      else // On mémorise et on attend
      {
        MTarmed = true;
        MTtimeStartDoubleBounce = millis();
	  }
    }}
  }
  // Dépassement du temps pendant lequel on peut voir un double clic
  if (MTarmed && (word(MTmillis()) - MTtimeStartDoubleBounce > doubleBounce)) // On n'a pas vu le double clic
  {
    MTarmed = false;
    MTetat |= 0x40; // Simple clic, on mémorise    
  }
}

//################################ slowAction ###############################
// Appelée régulièrement par le gestionnaire pour gérer les événements
void MTdoubleButton::slowAction(void)
{
  if ((MTetat & 0x80) > 0) // Le bouton a été appuyé
  {
    MTetat &= 0x7F;
    onDoubleSelect(); // Pour l'utilisateur
    if (MTonDoubleSelectFunction != PAS_D_ACTION) (*MTonDoubleSelectFunction)(); // Action possible de l'utilisateur
  }
  if ((MTetat & 0x40) > 0) // Le bouton a été relâché
  {
    MTetat &= 0xBF;
    onSelect(); // Pour l'utilisateur
    if (MTonSelectFunction != PAS_D_ACTION) (*MTonSelectFunction)(); // Action possible de l'utilisateur
  }
}


//###########################################################################
//##                             MTtripleButton                            ##
//###########################################################################
// MTtripleButton fournit la gestion pour un bouton poussoir gérant le clic,
// le double-clic et le triple-clic

//############################### Constructeur ##############################
MTtripleButton::MTtripleButton(uint8_t pin, // Broche sur lequel est branché le bouton
    void (onTipleSelectFunction)(void), // = PAS_D_ACTION, Pas d'action par défaut
    void (onDoubleSelectFunction)(void), // = PAS_D_ACTION, Pas d'action par défaut
    void (onSelectFunction)(void), // = PAS_D_ACTION, Pas d'action par défaut
    boolean repos) // = HIGH si_non_appuye, État de la broche, bouton au repos. INPUT_PULLUP si HIGH
  : MTdoubleButton(pin, onDoubleSelectFunction, onSelectFunction, repos), MTonTripleSelectFunction(onTipleSelectFunction)
{}

//############################### mediumAction ##############################
// Appelée régulièrement par le gestionnaire
void MTtripleButton::mediumAction(void)
{
  // bouton:       _________--___--___--___________--__--_________________--_________
  // tripleBounce:          <----<------->         <---<------->          <------->
  // MTarmed:      _________1111122222_____________1111222222222__________111111111__
  // select:       _______________________________________________________________^__
  // doubleSelect: ____________________________________________^_____________________
  // tripleSelect: ___________________^______________________________________________

  // Traitement d'un appui  
  if (((MTetat & 1) != MTdigitalRead(MTpin)) && // Il a changé d'état
//  if (((MTetat & 1) != digitalRead(MTpin)) && // Équivalent mais désactive le timer si il y en a un
      (word(MTmillis()) - MTtimeStartBounce > bounce)) // Et on a attendu la fin des rebonds
  {
    MTetat ^= 1; // On change son état
    MTtimeStartBounce = word(MTmillis());
    if ((MTetat & 1) ^ MTrepos) // On vient d'appuyer sur le bouton
    {{
      if (MTarmed == 2) // c'est le troisième appui
      {
        MTarmed = 0;
        MTetat |= 0x80; // Triple clic, on mémorise
      }
      else // On mémorise et on attend
      {
        MTarmed++;
       MTtimeStartTripleBounce = millis();
      }
    }}
  }
  // Dépassement du temps pendant lequel on peut voir un double clic
  if (MTarmed && (word(MTmillis()) - MTtimeStartTripleBounce > tripleBounce)) // On n'a pas vu le double clic
  {{
    if (MTarmed == 2)
    {
      MTarmed = 0;
      MTetat |= 0x40; // Double clic, on mémorise    
    }
    else // MTarmed = 1
    {
      MTarmed = 0;
      MTetat |= 0x20; // Simple clic, on mémorise   
    }
  }}
}

//################################ slowAction ###############################
// Appelée régulièrement par le gestionnaire pour gérer les événements
void MTtripleButton::slowAction(void)
{
  if ((MTetat & 0x80) > 0) // Triple clic mémorisé
  {
    MTetat &= 0x7F;
    onTripleSelect(); // Pour l'utilisateur
    if (MTonTripleSelectFunction != PAS_D_ACTION) (*MTonTripleSelectFunction)(); // Action possible de l'utilisateur
  }
  if ((MTetat & 0x40) > 0) // Double clic mémorisé
  {
    MTetat &= 0xBF;
    onDoubleSelect(); // Pour l'utilisateur
    if (MTonDoubleSelectFunction != PAS_D_ACTION) (*MTonDoubleSelectFunction)(); // Action possible de l'utilisateur
  }
  if ((MTetat & 0x20) > 0) // Simple clic mémorisé
  {
    MTetat &= 0xDF;
    onSelect(); // Pour l'utilisateur
    if (MTonSelectFunction != PAS_D_ACTION) (*MTonSelectFunction)(); // Action possible de l'utilisateur
  }
}


//###########################################################################
//##                             MTcheckButton                             ##
//###########################################################################
// MTcheckButton fournit la gestion pour un interrupteur type va et vient, ou
// case à cocher.


//############################### Constructeur ##############################
MTcheckButton::MTcheckButton(uint8_t pin, // Broche sur lequel est branché le bouton
    void (onSelectFunction)(void), // Pas d'action par défaut
    void (onUnselectFunction)(void), // Pas d'action par défaut
    boolean repos) // État de la broche, bouton au repos. INPUT_PULLUP si HIGH
  : MTbutton(pin, onSelectFunction, onUnselectFunction, repos), MTstatus(0)
{
}

//############################### mediumAction ##############################
// Appelée régulièrement par le gestionnaire pour voir les changements
void MTcheckButton::mediumAction(void)
{
  if (((MTetat & 1) != MTdigitalRead(MTpin)) && // Il a changé d'état
//  if (((MTetat & 1) != digitalRead(MTpin)) && // Équivalent mais désactive le timer si il y en a un
      (word(MTmillis()) - MTtimeStartBounce > bounce)) // Et on a attendu la fin des rebonds
  {
    MTetat ^= 1; // On change son état
    MTtimeStartBounce = word(MTmillis());
    if (MTetat ^ MTrepos) // bouton appuyé
    {
      if (MTstatus >= 0) MTetat |= 0x80; // Bouton sélectionné, on mémorise
      else MTetat |= 0x40; // Bouton désélectionné, on mémorise
    }
  }
}

//################################ slowAction ###############################
// Appelée régulièrement par le gestionnaire pour gérer les événements
void MTcheckButton::slowAction(void)
{
  if ((MTetat & 0x80) > 0) // Le bouton a été sélectionné
  {
    MTetat &= 0x7F;
    MTstatus |= 0x80; // S'active
    onSelect(); // Pour l'utilisateur
    if (MTonSelectFunction != PAS_D_ACTION) (*MTonSelectFunction)(); // Action possible de l'utilisateur
  }
  if ((MTetat & 0x40) > 0) // Le bouton a été désélectionné
  {
    MTetat &= 0xBF;
    MTstatus &= 0x7F; // Se désactive
    onUnselect(); // Pour l'utilisateur
    if (MTonUnselectFunction != PAS_D_ACTION) (*MTonUnselectFunction)(); // Action possible de l'utilisateur
  }
}


//###########################################################################
//##                             MTradioButton                             ##
//###########################################################################
// MTradioButton fournit la gestion pour un interrupteur type choix unique:
// la sélection d'un bouton désélectionne les autres boutons du même groupe


//############################### _radioActif_ ##############################
// Le tableau _radioActif_[groupe] indique quel est le bouton actif de groupe.
// Il n'y a donc qu'un pointeur pour tous les instances d'un groupe
MTradioButton *MTradioButton::_radioActif_[1 << RADIO_NB_BITS_GROUPE] = {NULL}; // Un seul pointeur pour tous sur l'élément actif


//############################### Constructeur ##############################
MTradioButton::MTradioButton(uint8_t pin, // Broche sur lequel est branché le bouton
    void (onSelectFunction)(void), // = PAS_D_ACTION, Pas d'action par défaut
    void (onUnselectFunction)(void), // PAS_D_ACTION, Pas d'action par défaut
    boolean repos, // = HIGH si_non_appuye, État de la broche, bouton au repos. INPUT_PULLUP si HIGH
    byte valeur, // = 0, Laissé libre pour l'utilisateur
    byte groupe) // = 0, Numéro du groupe
  : MTcheckButton(pin, onSelectFunction, onUnselectFunction, repos)
{
    MTstatus = ((valeur << RADIO_NB_BITS_GROUPE) & 0x7F) // Chaque MTradioButton peut avoir une valeur
             + (groupe & ((1 << RADIO_NB_BITS_GROUPE) - 1))
             + 0; // bouton désactivé

  // Pour le statut qui comporte 3 champs
  // 1 si sélection           valeur                      groupe
  // └-------------┴---------------------------┴----------------------------┘
  //      1 bit     7-RADIO_NB_BITS_GROUPE bits   RADIO_NB_BITS_GROUPE bits
  //
}

//############################### mediumAction ##############################
// Appelée régulièrement par le gestionnaire pour voir les changements
void MTradioButton::mediumAction(void)
{
  if (((MTetat & 1) != MTdigitalRead(MTpin)) && // Il a changé d'état
//  if (((MTetat & 1) != digitalRead(MTpin)) && // Équivalent mais désactive le timer si il y en a un
      (word(MTmillis()) - MTtimeStartBounce > bounce)) // Et on a attendu la fin des rebonds
  {
    MTetat ^= 1; // On change son état
    if (((MTetat & 1) ^ MTrepos) // Bouton appuyé
        &&  (MTstatus >= 0)) // Et non sélectionné
      MTetat |= 0x80;
  }
}

//################################ slowAction ###############################
// Appelée régulièrement par le gestionnaire pour gérer les événements
void MTradioButton::slowAction(void)
{
  if ((MTetat & 0x80) > 0) // Le bouton a été sélectionné
  {
    if (_radioActif_[MTstatus & ((1 << RADIO_NB_BITS_GROUPE) - 1)] != NULL) _radioActif_[MTstatus & ((1 << RADIO_NB_BITS_GROUPE) - 1)]->MTetat |= 0x40; // Désactive le copain éventuel
    _radioActif_[MTstatus & ((1 << RADIO_NB_BITS_GROUPE) - 1)] = this; // Autorise les copains à le demander
  }
  if ((MTetat & 0xC0) > 0) MTcheckButton::slowAction(); // Appel des fonctions utilisateur et maj de MTstatus
}


//############################## unselectMTradioButton ##############################
// Désélectionne tous les boutons radios d'un groupe (en fait on n'est désélectionne qu'un seul!)
void unselectMTradioButton(byte groupe) // = 0
{
  groupe &= (1 << RADIO_NB_BITS_GROUPE) - 1; // Évite les débordements
  if (getMTradioButtonPointeur(groupe) != NULL)  MTradioButton::_radioActif_[groupe]->MTetat |= 0x40; // Désélection du bouton actif si il existe
  MTradioButton::_radioActif_[groupe] = NULL; // Plus personne n'est actif
}


//############################## getMTradioButtonValeur #############################
// Retourne la valeur du contrôle actif du groupe
byte getMTradioButtonValeur(byte groupe) // = 0
{
  groupe &= (1 << RADIO_NB_BITS_GROUPE) - 1; // Évite les débordements
  if (MTradioButton::_radioActif_[groupe] != NULL) return (MTradioButton::_radioActif_[groupe]->MTstatus & 0x7F) >> RADIO_NB_BITS_GROUPE;
  else return 0x80; // Pas de contrôle radio sélectionné
}

//############################# getRadioPointeur ############################
// Retourne l'adresse du contrôle actif
MTradioButton *getMTradioButtonPointeur(byte groupe) // = 0
{
  groupe &= (1 << RADIO_NB_BITS_GROUPE) - 1; // Évite les débordements
  return MTradioButton::_radioActif_[groupe];
}



//###########################################################################
//###########################################################################
//####                                                                   ####
//####                                PWM                                ####
//####                                                                   ####
//###########################################################################
//###########################################################################

//###########################################################################
//##                               MThardPWM                               ##
//###########################################################################
// MThardPWM permet de faire du PWM de façon matériel sur une broche, de
// faire clignoter une led ou de faire varier son intensité, de piloter un
// servo, un moteur CC, faire un son... On est limité par les possibilités de
// l'Arduino et les broches possibles sont imposées. Cela ressemble à
// analogWrite, mais sur les timers 16 bits seulement. On peut par contre
// choisir sa fréquence et il y a le maximum de précision sur le rapport
// cyclique


//############################### Constructeur ##############################
MThardPWM::MThardPWM(uint8_t pin, // Broche de sortie
    float inpulseMicrosecond, // = 10000 micro_secondes, Durée de l'impulsion en µs
    float periodMicrosecond) // = 20000 micro_secondes, Pléonasme: c'est la période du signal en µs
  : MTpin(pin),
    MTinpulse(inpulseMicrosecond),
    MTperiod(periodMicrosecond),
    MTbase(0xFFFF)
{
  // L'initialisation est impossible à faire à la création, il faut la faire après la mise en place du système
}


//################################ setPeriod ################################
void MThardPWM::setPeriod(float periodMicrosecond) // = 20000 micro_secondes
{ 
  // Attente d'initialisation
  while (MTbase == 0xFFFF);

  // Mémorisation du temps de l'impulsion
  float oldInpulse = getInpulse();
  
  // Calcul du prédiviseur
  if (periodMicrosecond <= 4095.0) MTprediviseur = 0;        //  /1  0,0625ns       0 .. 4095µs
  else if (periodMicrosecond <= 32767.0) MTprediviseur = 3;   //  /8   0.5µs  4096µs .. 32767µs
  else if (periodMicrosecond <= 262136.0) MTprediviseur = 6;  //  /64   4µs    32768µs .. 262136µs
  else if (periodMicrosecond <= 1048544.0) MTprediviseur = 8; //  /256  16µs  262137µs .. 1048544µs
  else MTprediviseur = 10;                        //  /1024 64µs 1048545µs .. 4s

  // Calcul du diviseur
  float temp = 16.0 * periodMicrosecond / (1 << MTprediviseur);
  if (temp < 1) temp = 1;
  word diviseur = (temp > 65534.99) ? 65534 : trunc(temp) - 1;

  // Affectation des registres
  _SFR_BYTE(_SFR_MEM8(MTbase)) &= 0xFC; // TCCR?A: WGM?1:0 = 10 (mode 14)
  _SFR_BYTE(_SFR_MEM8(MTbase)) |= 0x02; //

  const PROGMEM static byte PourTCCRB[] = {0b00011001, 0, 0, 0b00011010, 0, 0, 0b00011011, 0, 0b00011100, 0, 0b00011101}; // Prédiviseurs
  _SFR_BYTE(_SFR_MEM8(MTbase + 1)) = pgm_read_byte_near(PourTCCRB + MTprediviseur); //TCCR?B:  WGM?3:2 = 11 (mode 14)
  _SFR_WORD(_SFR_MEM8(MTbase + 6)) = diviseur; // ICR?A

  //Mise à jour des valeurs qui ont pu être corrigées
  MTperiod = (_SFR_WORD(_SFR_MEM8(MTbase + 6)) + 1.0) * (1 << MTprediviseur) / 16.0;

  // Remise de la même impulsion
  setInpulse(oldInpulse);

  // Reprend le comptage au début, non indispensable
   _SFR_WORD(_SFR_MEM8(MTbase + 4)) = _SFR_WORD(_SFR_MEM8(MTbase + 6))-1;
}


//################################# setInpulse ################################
void MThardPWM::setInpulse(float inpulseMicrosecond) // = 10000 micro_secondes
{ 
  // Attente d'initialisation
  while (MTbase == 0xFFFF);

  // Largeur d'impulsion
  if (inpulseMicrosecond < 0) inpulseMicrosecond = 0;
  if (inpulseMicrosecond > MTperiod) inpulseMicrosecond = MTperiod; // Maxi

  inpulseMicrosecond =  (inpulseMicrosecond * (_SFR_WORD(_SFR_MEM8(MTbase + 6)) + 1) / MTperiod); // OCR = .. * ICR / ..
  if (inpulseMicrosecond > 1)
  {
    attach();
    _SFR_WORD(_SFR_MEM8(MTbase + MToutput + 8)) = inpulseMicrosecond - 1;
    //Mise à jour des valeurs qui ont pu être corrigées
    MTinpulse = (_SFR_WORD(_SFR_MEM8(MTbase + MToutput+ 8)) + 1.0) * (1 << MTprediviseur) / 16.0;
  }
  else
  {
    detach();
    pinMode(MTpin, OUTPUT);
    digitalWrite(MTpin, LOW);
    MTinpulse = 0;
  }


  // Reprend le comptage au début, non indispensable
   _SFR_WORD(_SFR_MEM8(MTbase + 4)) = _SFR_WORD(_SFR_MEM8(MTbase + 6))-1;
}


//################################ slowAction ###############################
void MThardPWM::slowAction(void)
{
  if (MTbase == 0xFFFF) // Initialisation
  {
    // Transformation pin -> (MTbase, MToutput)
    #if defined(__AVR_ATmega328P__) || defined(__AVR_ATmega328__)
      if (MTpin == 9) MToutput = 0;
      else MToutput = 2;
      MTbase = 0x80;
    #elif defined(__AVR_ATmega2561__) || defined(__AVR_ATmega2560__)
      MToutput = pgm_read_byte_near(MT_TIMER + ((MTpin > 13 ? MTpin - 30 : MTpin) % 17));
      MTbase = MToutput & 0xF0; if (MTbase > 0x00A0) MTbase = 0x0120;
      MToutput &= 0x0F;
    #endif
  
    // Calcul des temps
    setPeriod(MTperiod);
    setInpulse(MTinpulse);
    
    // Mise en route de la sortie
    switch (MToutput) // TCCR?A <- 10
    {
      #if defined(__AVR_ATmega2561__) || defined(__AVR_ATmega2560__)
        case OutputC:
          _SFR_BYTE(_SFR_MEM8(MTbase)) &= 0xF3;
          _SFR_BYTE(_SFR_MEM8(MTbase)) |= 0x08;
          break;
      #endif
      case OutputA:
        _SFR_BYTE(_SFR_MEM8(MTbase)) &= 0x3F;
        _SFR_BYTE(_SFR_MEM8(MTbase)) |= 0x80;
        break;
      default: // OutputB
        _SFR_BYTE(_SFR_MEM8(MTbase)) &= 0xCF;
        _SFR_BYTE(_SFR_MEM8(MTbase)) |= 0x20;
    }
    pinMode(MTpin, OUTPUT);
  }
}


//############################## getResolution ##############################
float MThardPWM::getResolution(void)
{
  while (MTbase == 0xFFFF); // Attente d'initialisation
  switch (_SFR_BYTE(_SFR_MEM8(MTbase + 1)) & 7)
  {
    case 1: return 0.0625;
    case 2: return 0.5;
    case 3: return 4;
    case 4: return 16;
    case 5: return 64;
    default: return 0;
  }
}


//################################## detach #################################
// Déconnecte la broche provisoirement, elle redevient "normale" (n'efface
// pas les temps programmés). La broche est en entrée sans pullup. On peut
// alors utiliser pinMode(), digitalRead(), digitalWrite(), analogRead().
// Ne pas utiliser analogWrite
void MThardPWM::detach(void)
{
  // Broche en entrée
  pinMode(MTpin, INPUT);
  // Déconnexion du timer
  switch (MToutput) // TCCR?A <- 10
  {
    #if defined(__AVR_ATmega2561__) || defined(__AVR_ATmega2560__)
      case OutputC:
        _SFR_BYTE(_SFR_MEM8(MTbase)) &= 0xF3;
        break;
    #endif
    case OutputA:
      _SFR_BYTE(_SFR_MEM8(MTbase)) &= 0x3F;
      break;
    default: // OutputB
      _SFR_BYTE(_SFR_MEM8(MTbase)) &= 0xCF;
  }
}


//################################## attach #################################
// Reconnecte la broche, si elle a été "détached"
void MThardPWM::attach(void)
{
  // Connexion du timer
  switch (MToutput) // TCCR?A <- 10
  {
    #if defined(__AVR_ATmega2561__) || defined(__AVR_ATmega2560__)
      case OutputC:
        _SFR_BYTE(_SFR_MEM8(MTbase)) |= 0x08;
        break;
    #endif
    case OutputA:
      _SFR_BYTE(_SFR_MEM8(MTbase)) |= 0x80;
      break;
    default: // OutputB
      _SFR_BYTE(_SFR_MEM8(MTbase)) |= 0x20;
  }
  // Broche en sortie
  pinMode(MTpin, OUTPUT);
}


//###########################################################################
//##                               MTsoftPWM                               ##
//###########################################################################
// MTsoftPWM permet de faire du PWM de façon logicielle sur une broche, de
// faire clignoter une led ou de faire varier son intensité, de donner une
// impulsion en sortie, même de faire tourner un pas à pas en commandant Step

#define MT_ACTION_1 true
#define MT_ACTION_2 false

//############################### Constructeur ##############################
MTsoftPWM::MTsoftPWM(uint8_t pin, // Broche de sortie
    unsigned long inpulseMicrosecond, // = 10000 micro_secondes, Durée de l'impulsion en µs; signal carré par défaut
    unsigned long periodMicrosecond, // = 20000 micro_secondes, Période du signal en µs; 50Hz par défaut
    uint8_t depart, // = HIGH, Niveau au début
    unsigned long numberOfLevels, // = MT_INFINI, Nombre de niveaux en tout, infini par défaut
    void (*onStopFunction)(void), // = PAS_D_ACTION, Pas d'action par défaut
    boolean active) // = MT_ON, Actif par défaut
  : MTport((uint8_t*)portOutputRegister(digitalPinToPort(pin))),
    MTmask(digitalPinToBitMask(pin)),
    MTinpulse(inpulseMicrosecond / (_ticksForMTquickObject_ << 2)),
    MTperiod(periodMicrosecond / (_ticksForMTquickObject_ << 2)),
    MTdepart(depart),
    MTnumberOfLevels(numberOfLevels),
    MTonStopFunction(onStopFunction),
      MTactive(active),
    MTticksStart(0),
    MTremains(numberOfLevels),
    MTwhatAction(MT_ACTION_1)
{
  digitalWrite(pin, depart);
  pinMode(pin, OUTPUT);
}


//################################# setInpulse ################################
void MTsoftPWM::setInpulse(unsigned long inpulseMicrosecond) // = 10000 micro_secondes
{ 
  MTinpulse = inpulseMicrosecond / (_ticksForMTquickObject_ << 2);
  if (MTinpulse > MTperiod) MTinpulse = MTperiod;
}


//################################ setPeriod ################################
void MTsoftPWM::setPeriod(unsigned long periodMicrosecond) // = 20000 micro_secondes
{
  MTperiod = periodMicrosecond / (_ticksForMTquickObject_ << 2);
  if (MTinpulse > MTperiod) MTinpulse = MTperiod;
  
}


//################################## start ##################################
void MTsoftPWM::start(void)
{
  MTactive = MT_OFF;
  byte sreg = SREG; cli(); // Ne pas remettre des broches qui pourraient avoir changées
  if (MTdepart) *MTport |= MTmask; else *MTport &= ~MTmask;
  SREG = sreg;
  MTremains  = MTnumberOfLevels; // Remise à zéro du comptage, permet de recommencer
  MTwhatAction = MT_ACTION_1; // Prochaine action: fin de inpulse
  MTticksStart = 0;
  MTactive = MT_ON;
}


//################################ slowAction ###############################
// Pour faire l'initialisation et action lors de l'arrêt
void MTsoftPWM::slowAction(void)
{ 
  // Action si on vient de finir les niveaux
  if (MTactive == 2)  // On vient de s'arrêter
  {
    MTactive = 0; // Pour ne plus en tenir compte
    onStop(); // Pour l'utilisateur
    if (MTonStopFunction != NULL) (*MTonStopFunction)(); // Action possible de l'utilisateur
  }
}


//############################### quickAction ###############################
// Appelée régulièrement par le gestionnaire
void MTsoftPWM::quickAction(void)
{
  if (MTactive == 1)  // Si on est actif
  {
    if (MTwhatAction) // Si on fait l'impulsion
    {
      if (++MTticksStart >= MTinpulse)  // Et c'est l'heure de la fin du inpulse
      {
        *(MTport-2) = MTmask; // Ta gueule la bit (traduction de toggle the pine)
        if (MTremains  != MT_INFINI) if (--MTremains  == 1) MTactive = 2;
        MTwhatAction = MT_ACTION_2;
      }
    }
    else
    {
      if (++MTticksStart >= MTperiod)  // Et c'est l'heure de la fin de la période
      {
        *(MTport-2) = MTmask;
        MTticksStart = 0; // Réarmement
        if (MTremains  != MT_INFINI) if (--MTremains  == 1) MTactive = 2;
        MTwhatAction = MT_ACTION_1;
      }
    }
  }
}


//############################### baseDeTemps ###############################
void MTsoftPWM::baseDeTemps(void)
{
  byte sreg=SREG; cli(); // Peut être utilisé dans ou hors interruption
  MTinpulse *= _ratio_;
  MTperiod *= _ratio_;
  MTticksStart *= _ratio_;
  SREG = sreg;
}



//###########################################################################
//###########################################################################
//####                                                                   ####
//####                               Servos                              ####
//####                                                                   ####
//###########################################################################
//###########################################################################

//###########################################################################
//##                               MTservo                               ##
//###########################################################################
// MTservo permet de gérer un servomoteur avec un PWM hard. La résolution
// pourait être de 0,5µs, mais cela n'a pas de sens pratique. C'est plus aisé
// de garder une résolution de 1µs (environ 0,1)

//############################### Constructeur ##############################
MTservo::MTservo(uint8_t pin, // Broche de sortie
    word timeFrom0To180Millisecond, // = 1000 milli_secondes_pour_aller_de_0_a_180, 1s pour les 180°
    void (*onStopFunction)(void), // = PAS_D_ACTION, Pas d'action par défaut
    word initialInpulse, // = 1500 micro_secondes_initialement, En microseconde ou en degré
    word minInpulseMicroseconds, // = 500 micro_secondes_minimum
    word maxInpulseMicroseconds, // = 2500 micro_secondes_maximum
    word periodMicroseconds) // = 20000 micro_secondes_de_periode
  : MTpin(pin),
    MTtimeFrom0To180(timeFrom0To180Millisecond),
    MTonStopFunction(onStopFunction),
    MTinpulse(initialInpulse),
    MTminInpulse(minInpulseMicroseconds << 4),
    MTmaxInpulse(maxInpulseMicroseconds << 4), 
    MTperiod(periodMicroseconds),
    MTbase(0xFFFF),
    MTsens(0),
    MTactualInpulse((initialInpulse << 4)+1)
{
  // L'initialisation est impossible à faire à la création, il faut la faire après la mise en place du système
}


//############################ setTimeFrom0To180 ############################
void MTservo::setTimeFrom0To180(word timeFrom0To180Millisecond) // = 1000 milli_secondes_pour_aller_de_0_a_180
{ 
   if ((MTtimeFrom0To180 = timeFrom0To180Millisecond) < 17) MTincrement = -1;
  else MTincrement = (MTmaxInpulse - MTminInpulse) * 16.0 / MTtimeFrom0To180;
} 


//############################# writeMicrosecond ############################
//############################### writeDegree ###############################
//################################## write ##################################
void MTservo::write(word valeur)/*
void MTservo::writeDegree(word angleDegree)
void writeMicrosecond(word inpulseMillisecond); */
{
 // Attente des 20ms à l'initialisation
  while (MTbase == 0xFFFF);
  // Arrêt du servo
  MTsens = 0;

  // Calcul de la position
  if ((valeur <<= 4) > MTmaxInpulse) return;
  if (valeur <= 361*16) MTinpulse = float(valeur) * (MTmaxInpulse - MTminInpulse) / (180.0*16.0) + MTminInpulse;
  else MTinpulse = valeur;
  if (MTinpulse < MTminInpulse) return;

  // Mise en marche du servo
  if (MTactualInpulse != MTinpulse)
    MTsens = (MTactualInpulse < MTinpulse) * 2 - 1; // A faire quand tout est prêt
}


//################################ slowAction ###############################
// Pour faire l'initialisation et action lors de l'arrêt
void MTservo::slowAction(void)
{ 
  // Initialisation
  if (MTbase == 0xFFFF) // Initialisation
  {
    // Transformation pin -> (MTbase, MToutput)
    #if defined(__AVR_ATmega328P__) || defined(__AVR_ATmega328__)
      if (MTpin == 9) MToutput = 0;
      else MToutput = 2;
      MTbase = 0x80;
    #elif defined(__AVR_ATmega2561__) || defined(__AVR_ATmega2560__)
      MToutput = pgm_read_byte_near(MT_TIMER + ((MTpin > 13 ? MTpin - 30 : MTpin) % 17));
      MTbase = MToutput & 0xF0; if (MTbase > 0x00A0) MTbase = 0x0120;
      MToutput &= 0x0F;
    #endif

    // Calcul de l'incrément possible fait toutes les 16ms
    setTimeFrom0To180(MTtimeFrom0To180);
    
    // Programmation de la période et initialisation du timer
    _SFR_BYTE(_SFR_MEM8(MTbase)) &= 0xFC; // TCCR?A: WGM?1:0 = 10 (mode 14)
    _SFR_BYTE(_SFR_MEM8(MTbase)) |= 0x02; //
    _SFR_BYTE(_SFR_MEM8(MTbase + 1)) = 0b00011010; //TCCR?B:  WGM?3:2 = 11 (mode 14), /8
    _SFR_WORD(_SFR_MEM8(MTbase + 6)) = (MTperiod << 1) - 1; // ICR?A

    // Mise en route de la sortie
    switch (MToutput) // TCCR?A <- 10
    {
      #if defined(__AVR_ATmega2561__) || defined(__AVR_ATmega2560__)
        case OutputC:
          _SFR_BYTE(_SFR_MEM8(MTbase)) &= 0xF3;
          _SFR_BYTE(_SFR_MEM8(MTbase)) |= 0x08;
          break;
      #endif
      case OutputA:
        _SFR_BYTE(_SFR_MEM8(MTbase)) &= 0x3F;
        _SFR_BYTE(_SFR_MEM8(MTbase)) |= 0x80;
        break;
      default: // OutputB
        _SFR_BYTE(_SFR_MEM8(MTbase)) &= 0xCF;
        _SFR_BYTE(_SFR_MEM8(MTbase)) |= 0x20;
    }
    pinMode(MTpin, OUTPUT);

    // Durée de l'impulsion
    writeMicrosecond(MTinpulse);
  }

  // Action si on vient de finir de bouger
  if (MTsens == 2)  // On vient de s'arrêter
  {
    MTsens = 0; // Pour ne plus en tenir compte
    onStop(); // Pour l'utilisateur
    if (MTonStopFunction != NULL) (*MTonStopFunction)(); // Action possible de l'utilisateur
  }
}


//############################### mediumAction ##############################
// Pour gérer les avances ralenties
void MTservo::mediumAction(void)
{
  if (!(MTsens & 1)) return; // 0 ou 2
  // Si on est ici, c'est que l'on doit bouger
  if (MTsens >0) // on va dans le sens 500µs -> 2500µs
  {
    MTactualInpulse += MTincrement;
    if (MTactualInpulse >= long(MTinpulse)) // On est arrivé
    {
      MTsens = 2; // = "On vient d'arriver"
      MTactualInpulse = MTinpulse;
    }
  }
  else  // on va dans le sens 2500µs -> 500µs
  {
    MTactualInpulse -= MTincrement;
    if (MTactualInpulse <= long(MTinpulse)) // On est arrivé
    {
      MTsens = 2; // = "On vient d'arriver"
      MTactualInpulse = MTinpulse;
    }
  }
  _SFR_WORD(_SFR_MEM8(MTbase + MToutput + 8)) = (MTactualInpulse >> 3) -1; // MTactualInpulse >> 4 est en µs, il nous le faut en 0,5µs
}


//################################## detach #################################
// Déconnecte la broche provisoirement, elle redevient "normale" (n'efface
// pas les temps programmés). La broche est en entrée sans pullup. On peut
// alors utiliser pinMode(), digitalRead(), digitalWrite(), analogRead().
// Ne pas utiliser analogWrite
void MTservo::detach(void)
{
  // Broche en entrée
  pinMode(MTpin, INPUT);
  // Dconnexion du timer
  switch (MToutput) // TCCR?A <- 10
  {
    #if defined(__AVR_ATmega2561__) || defined(__AVR_ATmega2560__)
      case OutputC:
        _SFR_BYTE(_SFR_MEM8(MTbase)) &= 0xF3;
        break;
    #endif
    case OutputA:
      _SFR_BYTE(_SFR_MEM8(MTbase)) &= 0x3F;
      break;
    default: // OutputB
      _SFR_BYTE(_SFR_MEM8(MTbase)) &= 0xCF;
  }
}


//################################## attach #################################
// Reconnecte la broche, si elle a été "détached"
void MTservo::attach(void)
{
  // Connexion du timer
  switch (MToutput) // TCCR?A <- 10
  {
    #if defined(__AVR_ATmega2561__) || defined(__AVR_ATmega2560__)
      case OutputC:
        _SFR_BYTE(_SFR_MEM8(MTbase)) |= 0x08;
        break;
    #endif
    case OutputA:
      _SFR_BYTE(_SFR_MEM8(MTbase)) |= 0x80;
      break;
    default: // OutputB
      _SFR_BYTE(_SFR_MEM8(MTbase)) |= 0x20;
  }
  // Broche en sortie
  pinMode(MTpin, OUTPUT);
}


//################################ setPeriod ################################
void MTservo::setPeriod(word periodMicroseconds) // = 20000 micro_secondes_de_periode
{
  // Attente des 20ms à l'initialisation
  while (MTbase == 0xFFFF);

  // Changement de période
  MTperiod = periodMicroseconds; 
  byte sreg = SREG;
  cli();
  _SFR_WORD(_SFR_MEM8(MTbase + 6)) = (MTperiod << 1) - 1; // ICR?A
  SREG = sreg;
}


//###########################################################################
//##                              MTservo4fils                             ##
//###########################################################################
// MTservo4fils permet de gérer un servomoteur avec un PWM hard ayant un fil
// supplémentaire soudé sur le point milieu su potentiomètre interne.

//############################### Constructeur ##############################
MTservo4fils::MTservo4fils(uint8_t pin, // Broche de sortie
    uint8_t pinPot, // Broche du point milieu du potentiomètre
    word canFor0degree, // Valeur d'analogRead(pinPot) pour 0°
    word canFor180degree, // Valeur d'analogRead(pinPot) pour 180°
    word timeFrom0To180Millisecond, // = 1000 milli_secondes_pour_aller_de_0_a_180, 1s pour les 180°
    void (*onStopFunction)(void), // = NULL, Pas d'action par défaut
    word minInpulseMicroseconds, // = 500 micro_secondes_minimum
    word maxInpulseMicroseconds, // = 2500 micro_secondes_maximum
    word periodMicroseconds) // = 20000 micro_secondes_de_periode
  : MTservo(pin, timeFrom0To180Millisecond, onStopFunction, 0, minInpulseMicroseconds, maxInpulseMicroseconds, periodMicroseconds)
{
  ADMUX=64; // Fait avant l'initialisation de la carte, copie de ce qui sera mis
  ADCSRA=135;
  MTinpulse =  map(analogRead(pinPot), canFor0degree, canFor180degree, minInpulseMicroseconds, maxInpulseMicroseconds);
  MTactualInpulse = (MTinpulse << 4) - 1;
}



//###########################################################################
//###########################################################################
//####                                                                   ####
//####                             Pas à pas                             ####
//####                                                                   ####
//###########################################################################
//###########################################################################

//###########################################################################
//##                              MTulnStepper                             ##
//###########################################################################
// MTulnStepper permet de gérer un moteur pas à pas piloté par un driver
// genre ULN2003


//############################## Constructeur ###############################
MTulnStepper::MTulnStepper(int8_t pinA1, int8_t pinB1, int8_t pinA2, int8_t pinB2, // Broches arduino
    char mode, // Choix PAS_ENTIERS, DEMI_PAS ou UNE_PHASE
    int_t acceleration, // Taille de l'accélération
    float speed, // Choix de la vitesse en µs ou en tr/s ou tr/mn
    boolean reverse, // Fait tourner dans l'autre sens si true
    void (*onStopFunction)(void), // Pas d'action par défaut
    word stepsPerTurn)  // Nombre de pas par tour
  : MTmode(mode),
    MTacceleration(acceleration <= 0 ? 1 : acceleration),
    MTreverse(reverse),
    MTonStopFunction(onStopFunction), 
    MTrest(0)
{
  MTportA1 = portOutputRegister(digitalPinToPort(pinA1));
  MTbitA1 = digitalPinToBitMask(pinA1);
  MTportB1 = portOutputRegister(digitalPinToPort(pinB1));
  MTbitB1 = digitalPinToBitMask(pinB1);
  MTportA2 = portOutputRegister(digitalPinToPort(pinA2));
  MTbitA2 = digitalPinToBitMask(pinA2);
  MTportB2 = portOutputRegister(digitalPinToPort(pinB2));
  MTbitB2 = digitalPinToBitMask(pinB2);
  *MTportA1 &= ~MTbitA1; // digitalWrite(pinA1, LOW);
  *MTportB1 &= ~MTbitB1; // digitalWrite(pinB1, LOW);
  pinMode(pinA1, OUTPUT);
  pinMode(pinB1, OUTPUT);
  if (pinA2 >= 0)
  {
    *MTportA2 |= MTbitA2; // digitalWrite(pinA2, HIGH);
    *MTportB2 |= MTbitB2; // digitalWrite(pinB2, HIGH);
    pinMode(pinA2, OUTPUT);
    pinMode(pinB2, OUTPUT);
  }
  else 
  {
    MTportA2 = 0;
    MTmode = PAS_ENTIERS; // Demi-pas impossible avec deux commandes
  }
  MTunTour = stepsPerTurn * (1 + (MTmode == 0));
  setSpeed(speed);
  MTposition = MTpas = 0;
  if (MTmode == UNE_PHASE) MTpas--; // Lignes impaires dans la table
}


//################################# setSpeed ################################
void MTulnStepper::setSpeed(float speed)
{
  // Transformation RPM, RPS et µs en nb de baseDeTemps
  if (speed <= 0) speed = -60000000.0 / (speed * MTunTour); // RPM en µs
  speed /= (_ticksForMTquickObject_ << 2); // µs en ticks
  if (speed < 1.0) speed = 1.0; // Trop rapide, la vitesse est celle de la base de temps
  uint32_t temp = speed > 0xFFFFFF ? 0xFFFFFFFF : speed * 256.0;
  MTsecure(MTtickTimeMax, temp); 
}


//################################### move ##################################
void MTulnStepper::move(int_t nbSteps) // Avancer ou reculer de nbSteps (déplacement relatif)
{
  MTcoef = sqrt(MTacceleration);
  byte sreg = SREG; cli();
  MTtickTime = MTcoef = MTtickTimeMax * MTcoef;
  MTerror = MTtickTime + 128;
  MTrestTicks = MTerror >> 8;
  MTerror &= 255; 
  MTfaits = 1;

  if (nbSteps > 0)
  {
    MTsens = true;
    MTrest = nbSteps;
  }
  else
  {
    MTsens = false;
    MTrest = -nbSteps;
  }
  SREG = sreg;
}


//############################### moveAndWait ###############################
void MTulnStepper::moveAndWait(int_t nbSteps)
{
  move(nbSteps);
  wait();
}

//################################## moveTo #################################
void MTulnStepper::moveTo(int_t position) // Aller à la position absolue
{
  byte sreg = SREG; cli();
  position -= MTposition ;
  move(position);
  SREG = sreg;
}


//############################### moveToAndWait ###############################
void MTulnStepper::moveToAndWait(int_t position)
{
  moveTo(position);
  wait();
}


//################################## setMode #################################
// Choix PAS_ENTIERS, DEMI_PAS ou UNE_PHASE
// Apelée régulièrement par le gestionnaire
void MTulnStepper::setMode(char mode)
{ 
  if (MTportA2 == 0) return; // avec deux fils, on doit ête en PAS_ENTIERS seulement
  MTmode = mode;
  if (MTmode == PAS_ENTIERS) MTpas = MTpas & 0x06; // lignes paires du tbleau
  if (MTmode == UNE_PHASE) MTpas = ((MTpas - 1) & 0x06) + 1; // lignes impaires du tbleau
  MTunTour = 2048 * (1 + (mode == 0));
} 


//################################ slowAction ###############################
// Appelée régulièrement par le gestionnaire
void MTulnStepper::slowAction(void)
{
  if (MTrest == 0)  // On vient de s'arrêter
  {
    MTrest--; // Pour ne plus en tenir compte
    onStop(); // Pour l'utilisateur
    if (MTonStopFunction != NULL) (*MTonStopFunction)(); // Action possible de l'utilisateur
  }
}


//############################### mediumAction ##############################
// Appelée régulièrement par le gestionnaire
void MTulnStepper::mediumAction(void)
{
  if (MTrest > 0)
  {
    long temp = MTtickTimeMax; // Si on est en mode vitesse constante
    if (MTfaits < MTacceleration) temp = (MTcoef / sqrt(MTfaits)); // On est en phase d'accélération
    if (MTrest < MTacceleration) // On est en phase d'décélération
    {
      long temp2 = (MTcoef / sqrt(MTrest));
	  if (temp2 > temp) temp = temp2;
    }
    MTtickTime = temp;
  }
}


//################################ quickAction ###############################
// Table des pas:
// pas 0  0011
// pas 1  0010
// pas 2  0110
// pas 3  0100
// pas 4  1100
// pas 5  1000
// pas 6  1001
// pas 7  0001

void MTulnStepper::quickAction(void)
{
  if (MTrest <= 0) return; // Rien à faire si on est arrivé
  if (--MTrestTicks) return; // Rien à faire si ce n'est pas l'heure
  // Gestion des pas et des positions
  if (MTrest != CONTINUE) MTrest--; // Un pas en moins
  MTfaits++;
  if (MTsens ^ MTreverse) 
  {
    MTposition++;
    MTpas = (MTpas + (MTmode == DEMI_PAS ? 1 : 2)) & 0x07; // Progression dans la table
  }
  else
  {
    MTposition--;
    MTpas = (MTpas - (MTmode == DEMI_PAS ? 1 : 2)) & 0x07; // Progression dans la table
  }

  // Faire avancer le moteur
  // Solution 1 avec une table, économise 200 octets de code
  /*
  uint8_t table[8] ={0b0011, 0b0010, 0b0110, 0b0100, 0b1100, 0b1000, 0b1001, 0b0001};
  uint8_t pas;
  pas = table[MTpas];
  if (pas & 1) *MTportA1 |= MTbitA1; // digitalWrite(pinA1, HIGH);
  else *MTportA1 &= ~MTbitA1; // digitalWrite(pinA1, LOW);
  if (pas & 2) *MTportB1 |= MTbitB1; // digitalWrite(pinB1, HIGH);
  else *MTportB1 &= ~MTbitB1; // digitalWrite(pinB1, LOW);
  if (MTportA2 != 0)
  {
    if (pas & 4) *MTportA2 |= MTbitA2; // digitalWrite(pinA2, HIGH);
    else *MTportA2 &= ~MTbitA2; // digitalWrite(pinA2, LOW);
    if (pas & 8) *MTportB2 |= MTbitB2; // digitalWrite(pinB2, HIGH);
    else *MTportB2 &= ~MTbitB2; // digitalWrite(pinB2, LOW);
  }
  */

  // Solution 2 avec des if, économise 9 octets de donnée, va 10% plus vite
  if (MTpas < 4) if (MTpas < 2) if (MTpas == 0) // Pas 0 -> 0011
  {
    *MTportA1 &= ~MTbitA1; // digitalWrite(pinA1, LOW);
    *MTportB1 &= ~MTbitB1; // digitalWrite(pinB1, LOW);
    if (MTportA2 != 0)
    { 
      *MTportA2 |= MTbitA2; // digitalWrite(pinA2, HIGH);
      *MTportB2 |= MTbitB2; // digitalWrite(pinB2, HIGH);
    }
  }
  else // Pas 1 -> 0010
  {
    // *MTportA1 &= ~MTbitA1; // digitalWrite(pinA1, LOW);
    *MTportB1 &= ~MTbitB1; // digitalWrite(pinB1, LOW);
    if (MTportA2 != 0)
    {
      *MTportA2 |= MTbitA2; // digitalWrite(pinA2, HIGH);
      *MTportB2 &= ~MTbitB2; // digitalWrite(pinB2, LOW);
    }
  }
  else if (MTpas == 2) // Pas 2 -> 0110
  {
    *MTportA1 &= ~MTbitA1; // digitalWrite(pinA1, LOW);
    *MTportB1 |= MTbitB1; // digitalWrite(pinB1, HIGH);
    if (MTportA2 != 0)
    {
      *MTportA2 |= MTbitA2; // digitalWrite(pinA2, HIGH);
      *MTportB2 &= ~MTbitB2; // digitalWrite(pinB2, LOW); 
    }
  }
  else // Pas 3 -> 0100 
  {
    *MTportA1 &= ~MTbitA1; // digitalWrite(pinA1, LOW);
    *MTportB1 |= MTbitB1; // digitalWrite(pinB1, HIGH);
    if (MTportA2 != 0)
    {
      *MTportA2 &= ~MTbitA2; // digitalWrite(pinA2, LOW);
      // *MTportB2 &= ~MTbitB2; // digitalWrite(pinB2, LOW);
    }
  }
  else if (MTpas < 6) if (MTpas == 4) // Pas 4 -> 1100
  {
    *MTportA1 |= MTbitA1; // digitalWrite(pinA1, HIGH);
    *MTportB1 |= MTbitB1; // digitalWrite(pinB1, HIGH);
    if (MTportA2 != 0)
    {
      *MTportA2 &= ~MTbitA2; // digitalWrite(pinA2, LOW);
      *MTportB2 &= ~MTbitB2; // digitalWrite(pinB2, LOW);
    }
  }
  else // Pas 5 -> 1000
  {
    *MTportA1 |= MTbitA1; // digitalWrite(pinA1, HIGH);
    *MTportB1 &= ~MTbitB1; // digitalWrite(pinB1, LOW);
    if (MTportA2 != 0)
    {
      // *MTportA2 &= ~MTbitA2; // digitalWrite(pinA2, LOW);
      *MTportB2 &= ~MTbitB2; // digitalWrite(pinB2, LOW);
    }
  }
  else if (MTpas == 6) // Pas 6 -> 1001
  {
    *MTportA1 |= MTbitA1; // digitalWrite(pinA1, HIGH);
    *MTportB1 &= ~MTbitB1; // digitalWrite(pinB1, LOW);
    if (MTportA2 != 0)
    {
      *MTportA2 &= ~MTbitA2; // digitalWrite(pinA2, LOW);
      *MTportB2 |= MTbitB2; // digitalWrite(pinB2, HIGH);
    }
  }
  else // Pas 7 -> 0001
  {
    *MTportA1 &= ~MTbitA1; // digitalWrite(pinA1, LOW);
    // *MTportB1 &= ~MTbitB1; // digitalWrite(pinB1, LOW);
    if (MTportA2 != 0)
    {
      *MTportA2 &= ~MTbitA2; // digitalWrite(pinA2, LOW);
      *MTportB2 |= MTbitB2; // digitalWrite(pinB2, HIGH);
    }
  }
  
  // Gestion du prochain déclenchement
  MTerror += MTtickTime;
  MTrestTicks = MTerror>> 8;
  MTerror &= 255; 
}


//############################### baseDeTemps ###############################
void MTulnStepper::baseDeTemps(void) // Demande de mise à jour des temps
{
  byte sreg=SREG; cli(); // Peut être utilisé dans ou hors interruption
  MTtickTimeMax *= _ratio_;
  if (MTtickTimeMax < 256) MTtickTimeMax = 256; // Trop rapide, on prends la base de temps
  MTtickTime *= _ratio_;
  if (MTtickTime < 256) MTtickTime = 256; // Trop rapide, on prends la base de temps
  // MTrestTicks *= _ratio_; // Ne fonctionne pas
  SREG = sreg;
}


//###########################################################################
//##                             MTstepStepper                             ##
//###########################################################################
// MTstepStepper permet de gérer un moteur pas à pas piloté par un driver
// genre A4988, TB6600...


//############################## Constructeur ###############################
MTstepStepper::MTstepStepper(int8_t pinStep, int8_t pinDir, int8_t pinEn, // Broches arduino
    int_t acceleration, // Taille de l'accélération
    word microsteps, // = 16, Nombre de micro-pas. Valeur conseillée 8 ou 16
    float speed, // = 1.0 RPS, Choix de la vitesse en µs ou en tr/s ou tr/mn
    boolean reverse, // = SENS_PAR_DEFAUT, Fait tourner dans l'autre sens si true
    void (*onStopFunction)(void), // = PAS_D_ACTION, Pas d'action par défaut
    word stepsPerTurn) // = 200, Nombre de pas par tour
  : MTpinDir(pinDir),
    MTpinEn(pinEn),
    MTacceleration(acceleration <= 0 ? 1 : acceleration),
    MTreverse(reverse),
    MTonStopFunction(onStopFunction), 
    MTunTour(stepsPerTurn * microsteps),
    MTposition(0),
    MTrest(0)
{
  MTportStep = portOutputRegister(digitalPinToPort(pinStep));
  MTbitStep = digitalPinToBitMask(pinStep);
  *MTportStep &= ~MTbitStep; // digitalWrite(pinStep, LOW); // Inutile la mise sous tension, mais on peut instancier longtemps après
  pinMode(pinStep, OUTPUT);
  if (pinDir > 0) pinMode(pinDir, OUTPUT);
  if (pinEn > 0) 
  {
    digitalWrite(pinEn, LOW); // Fait à la mise sous tension
    pinMode(pinEn, OUTPUT);
  }
  setSpeed(speed);
}


//################################# setSpeed ################################
void MTstepStepper::setSpeed(float speed)
{
  // Transformation RPM, RPS et µs en nb de baseDeTemps
  if (speed <= 0) speed = -60000000.0 / (speed * MTunTour); // RPM en µs
  speed /= (_ticksForMTquickObject_ << 2); // µs en ticks
  if (speed < 1.0) speed = 1.0; // Trop rapide, la vitesse est celle de la base de temps
  uint32_t temp = speed > 0xFFFFFF ? 0xFFFFFFFF : speed * 256.0;
  MTsecure(MTtickTimeMax, temp);
}


//################################### move ##################################
void MTstepStepper::move(int_t nbSteps) // Avancer ou reculer de nbSteps (déplacement relatif)
{
  MTcoef = sqrt(MTacceleration);
  byte sreg = SREG; cli();
  MTtickTime = MTcoef = MTtickTimeMax * MTcoef;
  MTerror = MTtickTime + 128;
  MTrestTicks = MTerror >> 8;
  MTerror &= 255;
  MTfaits = 1;

  if (nbSteps > 0)
  {
    MTsens = true;
    MTrest = nbSteps;
    if (MTpinDir != 0) digitalWrite(MTpinDir, !MTreverse);
  }
  else
  {
    MTsens = false;
    MTrest = -nbSteps;
    if (MTpinDir != 0) digitalWrite(MTpinDir, MTreverse);
  }
  SREG = sreg;
}
    

//############################### moveAndWait ###############################
void MTstepStepper::moveAndWait(int_t nbSteps)
{
  move(nbSteps);
  wait();
}

//################################## moveTo #################################
void MTstepStepper::moveTo(int_t position) // Aller à la position absolue
{
  byte sreg = SREG; cli();
  position -=  MTposition ;
  move(position);
  SREG = sreg;
}
    

//############################### moveToAndWait ###############################
void MTstepStepper::moveToAndWait(int_t position)
{
  moveTo(position);
  wait();
}


//################################ slowAction ###############################
// Appelée régulièrement par le gestionnaire
void MTstepStepper::slowAction(void)
{
  if (MTrest == 0)  // On vient de s'arrêter
  {
    MTrest--; // Pour ne plus en tenir compte
    onStop(); // Pour l'utilisateur
    if (MTonStopFunction != NULL) (*MTonStopFunction)(); // Action possible de l'utilisateur
  }
}


//############################### mediumAction ##############################
// Appelée régulièrement par le gestionnaire
void MTstepStepper::mediumAction(void)
{
  if (MTrest > 0)
  {
    long temp = MTtickTimeMax; // Si on est en mode vitesse constante
    if (MTfaits < MTacceleration) temp = (MTcoef / sqrt(MTfaits)); // On est en phase d'accélération
    if (MTrest < MTacceleration)  // On est en phase d'décélération
    {
      long temp2 = (MTcoef / sqrt(MTrest));
	  if (temp2 > temp) temp = temp2;
    }
    MTtickTime = temp;
  }
}


//################################ quickAction ###############################
void MTstepStepper::quickAction(void)
{
  if (MTrest <= 0) return; // Rien à faire si on est arrivé
  if (--MTrestTicks) return; // Rien à faire si ce n'est pas l'heure

  // Faire avancer le moteur
  *MTportStep |= MTbitStep; // digitalWrite(MTpinStep, HIGH);
  
  // Gestion du prochain déclenchement
  MTerror += MTtickTime;
  MTrestTicks = MTerror>> 8;
  MTerror &= 255; 

  // Gestion des pas et des positions
  if (MTrest != CONTINUE) MTrest--; // Un pas en moins
  MTfaits++;
  if (MTsens) MTposition++; else MTposition--; // Nouvelle position absolue

  // Fin de l'impulsion sur Step
  *MTportStep &= ~MTbitStep; // digitalWrite(MTpinStep, LOW);
}

//############################### baseDeTemps ###############################
void MTstepStepper::baseDeTemps(void) // Demande de mise à jour des temps
{
  byte sreg=SREG; cli(); // Peut être utilisé dans ou hors interruption
  MTtickTimeMax *= _ratio_;
  if (MTtickTimeMax < 256) MTtickTimeMax = 256; // Trop rapide, on prends la base de temps
  MTtickTime *= _ratio_;
  if (MTtickTime < 256) MTtickTime = 256; // Trop rapide, on prends la base de temps
  // MTrestTicks *= _ratio_; // Ne fonctionne pas
  SREG = sreg;
}


