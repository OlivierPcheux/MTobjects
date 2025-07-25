// Version V1.0.6

#ifndef _MTobjects_
#define _MTobjects_

#include <Arduino.h>

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



//###########################################################################
//###########################################################################
//####                                                                   ####
//####                    REGLAGES DE LA BIBLIOTHEQUE                    ####
//####                PEUT ETRE MODIFIE PAR L'UTILISATEUR                ####
//####                       SETTING OF THE LIBRARY                      ####
//####                    CAN BE CHANGED BY THE USER                     ####
//####                                                                   ####
//###########################################################################
//###########################################################################
#define RADIO_NB_BITS_GROUPE 3 // Nombre de bits pour la définition du groupe radio 0..6
                               // Number of bits for the definition of the radio group 0..6
                               // 0: 1 seul groupe de 128 boutons maxi
                               //    1 group of 128 buttons maximum
                               // 1: 2 groupes maxi de 64 boutons maxi chacun
                               //    2 groups maximum of 64 buttons max each
                               // 2: 4 groupes maxi de 32 boutons maxi
                               //    4 groups maximum of 32 buttons max each
                               // 3: 8 groupes maxi de 16 boutons maxi par défaut
                               //    8 groups maximum of 16 buttons max each
                               // 4: 16 groupes maxi de 8 boutons maxi
                               //    16 groups maximum of8 buttons max each
                               // 5: 32 groupes maxi de 4 boutons maxi
                               //    32 groups maximum of 4 buttons max each
                               // 6: 64 paires de boutons maxi
                               //    64 pairs of buttons maximum


// Par défaut les déplacements des moteurs pas à pas sont
// sur 32 bits, mais on peut remplacer par long par int si on veut
// utilise les nombres en 16 bits (traitement plus rapide)
// By default the movements of the steps motors are on 32 bits,
// but we can replace with "long" by "int" if we want to use
// 16 bit numbers (faster treatment)
#define int_t long
// #define int_t int



//###########################################################################
//###########################################################################
//####                                                                   ####
//####                      Définitions commentaires                     ####
//####                                                                   ####
//###########################################################################
//###########################################################################
// Ces mots peuvent être rajoutés sans effet. Cela permet d'avoir un code
// plus clair. Pour MT, un commentaire a un nom écrit en minuscules contenant
// le caractère _ sans en avoir aux extrémités

// Général
#define micro_seconde
#define micro_second
#define micro_secondes
#define micro_seconds
#define milli_secondes
#define milli_seconds
#define milli_seconde
#define milli_second
// Boutons
#define si_non_appuye
#define if_not_pressed
// Horloges
#define action_et_arret
#define action_and_stop
#define actions_et_arret
#define actions_and_stop
// PWM
#define niveau_et_arret
#define level_and_stop
#define niveaux_et_arret
#define levels_and_stop
#define on_commence_par
#define start_with
#define impulsion_de
#define inpulse_width
#define impulsions_de
#define inpulses_width
#define periode_de
#define period_width
#define periodes_de
#define periods_width
#define pour_cent
#define per_cent
// Servos
#define milli_secondes_pour_aller_de_0_a_180
#define milli_seconds_for_go_from_0_to_180
#define micro_secondes_initialement
#define micro_seconds_initially
#define degres_initialement
#define degree_initially
#define micro_secondes_minimum
#define micro_seconds_minimum
#define micro_secondes_maximum
#define micro_seconds_maximum
#define can_pour_0_degree
#define cad_for_0_degree
#define can_pour_180_degree
#define cad_for_180_degree
// Pas à pas
#define pin_A1
#define pin_B1
#define pin_A2
#define pin_B2
#define pin_Step
#define pin_Dir
#define pin_EN
#define micro_pas
#define micro_pas
#define pas_ou_micro_pas
#define step_or_micro_step
#define micro_secondes_par_pas
#define micro_second_per_step
#define position_absolue
#define absolute_position
#define accelerations_sur
#define accelerations_of



//###########################################################################
//###########################################################################
//####                                                                   ####
//####                             Constantes                            ####
//####                                                                   ####
//###########################################################################
//###########################################################################

// Pour les actions
#define PAS_D_ACTION NULL
#define NO_ACTION NULL
#define MT_ON 1
#define MT_OFF 0
#define MT_INFINI 0 // Merci aux profs de maths de ne pas s'étouffer
// Boutons
#define RADIO_BUTTON_0   0
#define RADIO_BUTTON_1   1
#define RADIO_BUTTON_2   2
#define RADIO_BUTTON_3   3
#define RADIO_BUTTON_4   4
#define RADIO_BUTTON_5   5
#define RADIO_BUTTON_6   6
#define RADIO_BUTTON_7   7
#define RADIO_BUTTON_8   8
#define RADIO_BUTTON_9   9
#define RADIO_GROUPE_0   0
#define RADIO_GROUPE_1   1
#define RADIO_GROUPE_2   2
#define RADIO_GROUPE_3   3
#define RADIO_GROUP_0   0
#define RADIO_GROUP_1   1
#define RADIO_GROUP_2   2
#define RADIO_GROUP_3   3
// Pas à pas
#define RPM * -1.0 // Rotations par minute
#define RPS * -60.0 // Rotations par seconde
#define CONTINUE ((unsigned int_t)(~0) >>1) // Rotation continue pour move, moveTo
#define NON_CONNECTEE -1 // Pour une broche EN ou DIR non connectée
#define UNCONNECTED -1 // Pour une broche EN ou DIR non connectée
#define DEMI_PAS 0
#define HALF_STEP 0
#define PAS_ENTIERS 1
#define WHOLE_STEP 1
#define UNE_PHASE -1
#define ONE_PHASE -1
#define SENS_PAR_DEFAUT false
#define DEFAULT_SENSE false
#define SENS_INVERSE true
#define REVERSE true
#define PAS_D_ACCELERATION 0
#define NO_ACCELERATION 0



//###########################################################################
//###########################################################################
//####                                                                   ####
//####                         Variables globales                        ####
//####                                                                   ####
//###########################################################################
//###########################################################################

// Debug
extern long debug;
// Boutons
extern word bounce; // Temps minimum en ms pour le traitement des rebonds
extern word doubleBounce; // Temps minimum en ms pour le traitement des rebonds
extern word tripleBounce; // Temps minimum en ms pour le traitement des rebonds

//###########################################################################
//###########################################################################
//####                                                                   ####
//####                          Divers fonctions                         ####
//####                                                                   ####
//###########################################################################
//###########################################################################


//###########################################################################
//##                               MTtimeBase                              ##
//###########################################################################
extern byte _ticksForMTquickObject_; // Ne pas utiliser
extern float _ratio_; // Ne pas utiliser

void MTtimeBase(word timeBaseForMTquickObject micro_secondes);
// par défaut:
// MTtimeBase(100 micro_secondes);


//###########################################################################
//##                                MTmillis                               ##
//###########################################################################
unsigned long MTmillis(void);
// Équivalent de millis(); mais avec une incrémentation de 1 toutes les ms.
// millis() s'incrémente de 1 ou de 2 toutes les 1,024ms
// Ceci bien entendu si le quartz a une fréquence de 16,000MHz


//###########################################################################
//##                                MTsecure                               ##
//###########################################################################
long MTsecure(volatile long &valeur);
word MTsecure(volatile word &valeur); // Template prends plus d'octets
unsigned long MTsecure(volatile unsigned long &valeur);
void MTsecure(volatile long &resultat, long &valeur);
void MTsecure(volatile word &resultat, word &valeur);
void MTsecure(volatile unsigned long &resultat, unsigned long &valeur);
// Permet de lire/écrire des multi-octets qui peuvent changer sous interruption


//###########################################################################
//##                             MTdigitalRead                             ##
//###########################################################################
bool MTdigitalRead(byte pin);
// Équivalent de digitalRead, mais sans supprimer le PWM éventuel


//###########################################################################
//##                        MTstart/stopDelayMillis                        ##
//###########################################################################
inline void MTstopDelayMillis(void) { TIMSK0 &= 0xFE; }
// Suspend l'horloge système, ce qui permet des interruptions plus régulières
// et du gain de temps. Par contre les fonctions delay(), millis() ainsi que
// delayMicroseconds() ne sont plus utilisables. millis() peur être remplacée
// par MTmillis()

inline void MTstartDelayMillis(void) { TIMSK0 |= 0x01; }
// Réactive l'horloge système



//###########################################################################
//###########################################################################
//####                                                                   ####
//####                          Classes de base                          ####
//####                                                                   ####
//###########################################################################
//###########################################################################


//###########################################################################
//##                             MTquickObject                             ##
//###########################################################################
class MTquickObject
{
  public:
    // -------- Attributs publiques -------
    MTquickObject *MTnextQuickObject; // Suite de la liste des MTquickObject
    // -------- Méthodes publiques --------
    MTquickObject(void); // Constructeur
    virtual ~MTquickObject(void); // Destructeur
    virtual void quickAction(void){}  // Appel du gestionnaire exactement toutes 
         //  les baseDeTempsDesMTquickObject
    virtual void baseDeTemps(void){} // Demande de mise à jour des temps
};



//###########################################################################
//##                             MTmediumObject                            ##
//###########################################################################
class MTmediumObject
{
  public:
    // -------- Attributs publiques -------
    MTmediumObject *MTnextMediumObject; // Suite de la liste des MTmediumObject
    // -------- Méthodes publiques --------
    MTmediumObject(void); // Constructeur
    virtual ~MTmediumObject(void); // Destructeur
    virtual void mediumAction(void){}  // Appel du gestionnaire exactement toutes 
         //  les 1ms
};


//###########################################################################
//##                              MTslowObject                             ##
//###########################################################################
class MTslowObject
{
  public:
    // -------- Attributs publiques -------
    MTslowObject *MTnextSlowObject; // Suite de la liste des MTslowObject
    // -------- Méthodes publiques --------
    MTslowObject(void); // Constructeur
    virtual ~MTslowObject(void); // Destructeur
    virtual void slowAction(void){}  // Appel du gestionnaire toutes les
        // MTtimeBaseSlowObject si le traitement précédent est fini
};



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
class MTclock: public MTslowObject
{
  public:
    // -------- Méthodes publiques --------
    MTclock(unsigned long interval_ms milli_secondes, // Temps entre les actions
      void (*onTimeFunction)(void) = PAS_D_ACTION, // Pas d'action par défaut
      unsigned long numberOfActions = MT_INFINI, // Nombre d'actions, infini par défaut
      boolean active = MT_ON); // Actif par défaut
    inline void setInterval_ms(unsigned long interval_ms = 1000 milli_secondes) { unsigned long temp = millis(); MTsecure(MTtimeStart, temp); MTsecure(MTinterval_ms, interval_ms); }
    inline unsigned long getInterval_ms(void) { return MTinterval_ms; }
    inline void setOnTimeFunction(void (*onTimeFunction)(void) = PAS_D_ACTION) { MTonTimeFunction = onTimeFunction; }
    inline void setNumberOfActions(unsigned long numberOfActions = MT_INFINI) { MTsecure(MTnumberOfActions, numberOfActions); start(); }
    inline unsigned long getNumberOfActions(void) { return MTsecure(MTnumberOfActions); }
    inline unsigned long getNumberOfActionsRemains(void) { return MTsecure(MTremains); } 
    void start(void);
    inline void stop(void) { MTactive = MT_OFF; }
    inline boolean getActive(void) { return MTactive; }
  protected:
    // -------- Attributs protégés --------
    unsigned long MTinterval_ms; // Temps caractéristique en millisecondes
    void (*MTonTimeFunction)(void); // Fonction extérieure gérant l'événement temporel
    unsigned long MTnumberOfActions; // Nombre d'appels à faire
    volatile boolean MTactive; // true si actif
    unsigned long MTtimeStart; // Heure de départ du comptage en millisecondes
    volatile unsigned long MTremains; // Nombre d'appels qui reste à faire, 0 pour infini
    // -------- Méthodes protégées -------
    virtual void onTime(void) {} // Pour le gestionnaire utilisateur
    virtual void slowAction(void);  // Pour onTime
};


//###########################################################################
//##                             MTdoubleClock                             ##
//###########################################################################
// MTdoubleClock fournit deux événements réguliers alternés
#define MTonTimeFunction1 MTonTimeFunction // Pour réutiliser MTclock
#define MTonTime1 MTonTime
#define onTime1 onTime
#define setOnTimeFunction1 setOnTimeFunction
class MTdoubleClock: public MTclock
{
  public:
    // -------- Méthodes publiques --------
    MTdoubleClock(unsigned long interval1_ms, // Attente avant la première action
      unsigned long interval_ms2, // Attente avant la deuxième action
      void (*onTimeFunction1)(void) = PAS_D_ACTION, // Pas de première action par défaut
      void (*onTimeFunction2)(void) = PAS_D_ACTION, // Pas de deuxième action par défaut
      unsigned long numberOfActions = MT_INFINI, // Nombre d'actions en tout, infini par défaut
      boolean active = MT_ON); // Actif par défaut
    // inline void setInterval1_ms(unsigned long interval1_ms = 1000 milli_secondes) { MTinterval_ms = interval1_ms; }
    inline void setInterval1_ms(unsigned long interval1_ms = 1000 milli_secondes) { MTsecure(MTinterval_ms, interval1_ms); }
    inline void setInterval2_ms(unsigned long interval2_ms = 1000 milli_secondes) { MTsecure(MTinterval2_ms, interval2_ms); }
    inline unsigned long getInterval1_ms(void) { return MTinterval_ms; }
    inline unsigned long getInterval2_ms(void) { return MTinterval2_ms; }
    // inline void setOnTimeFunction1(void (*onTimeFunction1)(void) = PAS_D_ACTION) { MTonTimeFunction = onTimeFunction1; }
    inline void setOnTimeFunction2(void (*onTimeFunction2)(void) = PAS_D_ACTION) { MTonTimeFunction2 = onTimeFunction2; }
    // inline void setNumberOfActions(unsigned long numberOfActions = MT_INFINI) { MTsecure(MTnumberOfActions, numberOfActions); }
    // inline unsigned long getNumberOfActions(void) { return MTsecure(MTnumberOfActions); }
    // inline unsigned long getNumberOfActionsRemains(void) { return MTsecure(MTremains); } 
    virtual void start(void);
    // void stop(void) { MTactive = MT_OFF; }
    // inline boolean getActive(void) { return MTactive; }
  protected:  
    // -------- Attributs protégés --------
    // void (*MTonTimeFunction1)(void); // Fonction extérieure gérant le premier événement temporel
    unsigned long MTinterval2_ms; // Temps caractéristique en millisecondes
    void (*MTonTimeFunction2)(void); // Fonction extérieure gérant le deuxième événement temporel
    boolean MTwhatAction; // true: on fera l'action 1, false: ce sera l'action 2
    // -------- Méthodes protégées -------
    // virtual void onTime1(void){} // Pour le gestionnaire utilisateur
    virtual void onTime2(void){}
    virtual void slowAction(void);  // Pour onTime1 et onTime2
};



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
// MTbutton fournit la gestion pour un bouton poussoir

class MTbutton: public MTslowObject, public MTmediumObject
{
  public:
    // -------- Méthodes publiques --------
    MTbutton(uint8_t pin, // Broche sur lequel est branché le bouton
      void (onSelectFunction)(void) = PAS_D_ACTION, // Pas d'action par défaut
      void (onUnselectFunction)(void) = PAS_D_ACTION, // Pas d'action par défaut
      boolean repos = HIGH si_non_appuye); // État de la broche, bouton au repos. INPUT_PULLUP si HIGH
    inline void setOnSelectFunction(void (*onSelectFunction)(void) = PAS_D_ACTION)
      { MTonSelectFunction = onSelectFunction; }
    inline void setOnUnselectFunction(void (*onUnselectFunction)(void) = PAS_D_ACTION)
      { MTonUnselectFunction = onUnselectFunction; }
    inline boolean getSelect(void) { return (MTetat & 1) ^ MTrepos; } // true si appuyé
  protected:
    // -------- Attributs protégés --------
    uint8_t MTpin; // Broche sur lequel est branché le bouton
    void (*MTonSelectFunction)(void); // Fonction extérieure gérant l'appui
    void (*MTonUnselectFunction)(void); // Fonction extérieure gérant le relâchement
    uint8_t MTrepos; // État du bouton au repos (HIGH ou LOW)
    volatile byte MTetat; // État actuel 0 pour LOW, 1 pour HIGH, +0x80/0x40 si on n'a pas encore tenu compte du changement 
    word MTtimeStartBounce; // Comptage en millisecondes
    // -------- Méthodes protégées ---------
    virtual void onSelect(void) {} // Pour le gestionnaire utilisateur
    virtual void onUnselect(void) {} // Pour le gestionnaire utilisateur
    virtual void slowAction(void);  // Pour onSelect, onUnselect
    virtual void mediumAction(void);  // Pour onSelect, onUnselect
};

//###########################################################################
//##                             MTdoubleButton                            ##
//###########################################################################
// MTdoubleButton fournit la gestion pour un bouton poussoir gérant le clic
// et le double-clic



#define onDoubleSelect onUnselect
#define onDoubleSelectFunction onUnselectFunction // Unselect n'est pas employé
#define MTonDoubleSelectFunction MTonUnselectFunction
#define setOnDoubleSelectFunction setOnUnselectFunction
class MTdoubleButton: public MTbutton
{
  public:
    // -------- Méthodes publiques --------
    MTdoubleButton(uint8_t pin, // Broche sur lequel est branché le bouton
      void (onDoubleSelectFunction)(void) = PAS_D_ACTION, // Pas d'action par défaut
      void (onSelectFunction)(void) = PAS_D_ACTION, // Pas d'action par défaut
      boolean repos = HIGH si_non_appuye); // État de la broche, bouton au repos. INPUT_PULLUP si HIGH
    // inline void setOnSelectFunction(void (*onSelectFunction)(void) = PAS_D_ACTION) { MTonSelectFunction = onSelectFunction; }
    // inline void setOnDoubleSelectFunction(void (*onDoubleSelectFunction)(void) = PAS_D_ACTION) { MTonDoubleSelectFunction = MTonDoubleSelectFunction; }
    // inline boolean getSelect(void) { return MTetat ^ MTrepos; } // true si appuyé
  protected:
    // -------- Attributs protégés --------
    // uint8_t MTpin; // Broche sur lequel est branché le bouton
    // void (*MTonSelectFunction)(void); // Fonction extérieure gérant l'appui
    // void (*MTonDoubleSelectFunction)(void); // Fonction extérieure gérant le double appui
    // word MTtimeStartBounce; // Comptage en millisecondes
    word MTtimeStartDoubleBounce; // Comptage en millisecondes
    // uint8_t MTrepos; // État du bouton au repos (HIGH ou LOW)
    // volatile byte MTetat; // État actuel 0 pour LOW, 1 pour HIGH, +0x80/0x40 si on n'a pas encore tenu compte du changement 
    byte MTarmed; // Nombre de clics déjà vus 0 ou 1
    // -------- Méthode protégée ---------
    // virtual void onSelect(void) {} // Pour le gestionnaire utilisateur
    // virtual void onDoubleSelect(void) {} // Pour le gestionnaire utilisateur
    virtual void slowAction(void);  // Appel du gestionnaire toutes les BASE_DE_TEMPS
    virtual void mediumAction(void);  // Pour onSelect, onUnselect
};


//###########################################################################
//##                             MTtripleButton                            ##
//###########################################################################
// MTtripleButton fournit la gestion pour un bouton poussoir gérant le clic,
// le double-clic et le triple-clic

#define MTtimeStartTripleBounce MTtimeStartDoubleBounce
class MTtripleButton: public MTdoubleButton
{
  public:
    // -------- Méthodes publiques --------
    MTtripleButton(uint8_t pin, // Broche sur lequel est branché le bouton
      void (onTipleSelectFunction)(void) = PAS_D_ACTION, // Pas d'action par défaut
      void (onDoubleSelectFunction)(void) = PAS_D_ACTION, // Pas d'action par défaut
      void (onSelectFunction)(void) = PAS_D_ACTION, // Pas d'action par défaut
      boolean repos = HIGH si_non_appuye); // État de la broche, bouton au repos. INPUT_PULLUP si HIGH
    // inline void setOnSelectFunction(void (*onSelectFunction)(void) = PAS_D_ACTION) { MTonSelectFunction = onSelectFunction; }
    // inline void setOnDoubleSelectFunction(void (*onSelectFunction)(void) = PAS_D_ACTION)
    //    { MTonDoubleSelectFunction = MTonDoubleSelectFunction; }
    inline void setOnTripleSelectFunction(void (*onSelectFunction)(void) = PAS_D_ACTION)
          { MTonTripleSelectFunction = MTonTripleSelectFunction; }
    //inline boolean getSelect(void) { return MTetat ^ MTrepos; } // true si appuyé
  protected:
    // -------- Attributs protégés --------
    //uint8_t MTpin; // Broche sur lequel est branché le bouton
    // void (*MTonSelectFunction)(void); // Fonction extérieure gérant l'appui
    // void (*MTonDoubleSelectFunction)(void); // Fonction extérieure gérant le double appui
    void (*MTonTripleSelectFunction)(void); // Fonction extérieure gérant le triple appui
    //word MTtimeStartBounce; // Comptage en millisecondes
    //word MTtimeStartTripleBounce; // Comptage en millisecondes entre deux appuis
    //uint8_t MTrepos; // État du bouton au repos (HIGH ou LOW)
    // byte MTetat; // État actuel 0 pour LOW, 1 pour HIGH, +0x80/0x40/0x20 si on n'a pas encore tenu compte du changement 
    //byte MTarmed; // Nombre de clics déjà vus
    // -------- Méthodes protégées --------
    // virtual void onSelect(void) {} // Pour le gestionnaire utilisateur
    // virtual void onDoubleSelect(void) {} // Pour le gestionnaire utilisateur
    virtual void onTripleSelect(void) {} // Pour le gestionnaire utilisateur
    virtual void slowAction(void);  // Gestion des événements
    virtual void mediumAction(void);  // Pour onSelect, onDoubleSelect, onTripleSelect
};


//###########################################################################
//##                             MTcheckButton                             ##
//###########################################################################
// MTcheckButton fournit la gestion pour un interrupteur type va et vient, ou
// case à cocher.

class MTcheckButton: public MTbutton
{
  public:
    // -------- Méthodes publiques --------
    MTcheckButton(uint8_t pin, // Broche sur lequel est branché le bouton
      void (onSelectFunction)(void) = PAS_D_ACTION, // Pas d'action par défaut
      void (onUnselectFunction)(void) = PAS_D_ACTION, // Pas d'action par défaut
      boolean repos = HIGH si_non_appuye); // État de la broche, bouton au repos. INPUT_PULLUP si HIGH
    // inline void setOnSelectFunction(void (*onSelectFunction)(void) = PAS_D_ACTION) { MTonSelectFunction = onSelectFunction; }
    // inline void setOnUnselectFunction(void (*onUnselectFunction)(void) = PAS_D_ACTION) { MTonUnselectFunction = onUnselectFunction; }
    inline boolean getSelect(void) { return (MTstatus < 0); } // true si mémoire actve
    inline void select(void) { MTetat |= 0x80; } // Active ce bouton
    inline void unselect(void) { MTetat |= 0x40; } // Désactive ce bouton
  protected:
    // -------- Attributs protégés --------
    // uint8_t MTpin; // Broche sur lequel est branché le bouton
    // void (*MTonSelectFunction)(void); // Fonction extérieure gérant l'appui
    // void (*MTonUnselectFunction)(void); // Fonction extérieure gérant le relâchement
    // word MTtimeStartBounce; // Comptage en millisecondes
    // uint8_t MTrepos; // État du bouton au repos (HIGH ou LOW)
    // boolean MTetat; // État actuel 0 pour LOW, 1 pour HIGH, +0x80/0x40 si on n'a pas encore tenu compte du changement 
    volatile char MTstatus; // Mémoire 0x80 allumé / 0x00 éteint
    // -------- Méthodes protégées --------
    // virtual void onSelect(void) {} // Pour le gestionnaire utilisateur
    // virtual void onUnselect(void) {} // Pour le gestionnaire utilisateur
    virtual void slowAction(void);  // Pour la gestion des appuis
    virtual void mediumAction(void);  // Pour onSelect, onUnselect
};


//###########################################################################
//##                             MTradioButton                             ##
//###########################################################################
// MTradioButton fournit la gestion pour un interrupteur type choix unique:
// la sélection d'un bouton désélectionne les autres boutons du même groupe

class MTradioButton: public MTcheckButton
{
  public:
    // -------- Méthodes publiques --------
    MTradioButton(uint8_t pin, // Broche sur lequel est branché le bouton
      void (onSelectFunction)(void) = PAS_D_ACTION, // Pas d'action par défaut
      void (onUnselectFunction)(void) = PAS_D_ACTION, // Pas d'action par défaut
      boolean repos = HIGH si_non_appuye, // État de la broche, bouton au repos. INPUT_PULLUP si HIGH
      byte valeur = 0, // Laissé libre pour l'utilisateur
      byte groupe = 0); // Numéro du groupe
    // inline void setOnSelectFunction(void (*onSelectFunction)(void) = PAS_D_ACTION) { MTonSelectFunction = onSelectFunction; }
    // inline void setOnUnselectFunction(void (*onUnselectFunction)(void) = PAS_D_ACTION) { MTonUnselectFunction = onUnselectFunction; }
    // inline boolean getSelect(void) { return (MTstatus < 0); } // true si mémoire actve
    // inline void select(void) { MTetat |= 0x80; } // Active ce bouton
    // inline void unselect(void) { MTetat |= 0x40; } // Désactive ce bouton
    inline byte getValeur(void) { return (MTstatus & 0x7F) >> RADIO_NB_BITS_GROUPE; } // Retourne la valeur du bouton
    inline byte getGroupe(void) { return MTstatus & ((1 << RADIO_NB_BITS_GROUPE) - 1); } // Retourne le groupe du bouton
    friend byte getMTradioButtonValeur(byte groupe); // Retourne la valeur du contrôle actif du groupe
    friend MTradioButton *getMTradioButtonPointeur(byte groupe); // Retourne l'adresse du contrôle actif
    friend void unselectMTradioButton(byte groupe); // Désélectionne tous les boutons radios d'un groupe
  protected:
    // -------- Attributs protégés --------
    static MTradioButton *_radioActif_[1 << RADIO_NB_BITS_GROUPE]; // Pointeurs sur l'élément actif
    // uint8_t MTpin; // Broche sur lequel est branché le bouton
    // void (*MTonSelectFunction)(void); // Fonction extérieure gérant l'appui
    // void (*MTonUnselectFunction)(void); // Fonction extérieure gérant le relâchement
    // word MTtimeStartBounce; // Comptage en millisecondes
    // uint8_t MTrepos; // État du bouton au repos (HIGH ou LOW)
    // boolean MTetat; // État actuel 0 pour LOW, 1 pour HIGH, +0x80/0x40 si on n'a pas encore tenu compte du changement 
    // char MTstatus; // Sélectionné ou pas, valeur et groupe
    // -------- Méthodes protégées --------
    virtual void onSelect(void) {} // Pour le gestionnaire utilisateur
    virtual void onUnselect(void) {} // Pour le gestionnaire utilisateur
    virtual void slowAction(void);  // Pour la gestion des appuis
    virtual void mediumAction(void);  // Pour onSelect, onUnselect
};

byte getMTradioButtonValeur(byte groupe = 0); // Retourne la valeur du contrôle actif du groupe
MTradioButton *getMTradioButtonPointeur(byte groupe = 0); // Retourne l'adresse du contrôle actif
void unselectMTradioButton(byte groupe = 0); // Désélectionne tous les boutons radios d'un groupe
#define getMTradioButtonValue getMTradioButtonValeur


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

// Sur Uno les broches utilisables sont: 9, 10
// Sur Mega: 2, 3, 5, 6, 7, 8, 11, 12, 13, 44, 45, 46


class MThardPWM: MTslowObject
{
  public:
    // -------- Méthodes publiques --------
    MThardPWM(uint8_t pin, // Broche de sortie
      float inpulseMicrosecond = 10000 micro_secondes, // Durée de l'impulsion en µs; signal carré par défaut
      float periodMicrosecond = 20000 micro_secondes); // Pléonasme: c'est la période du signal en µs; 50Hz par défaut
    void setInpulse(float inpulseMicrosecond = 10000 micro_secondes);
    inline float getInpulse(void) { return MTinpulse; }
    void setDutyCycle(float dutyCycle = 50.0) { setInpulse(dutyCycle * getPeriod() / 100.0); }
    float getDutyCycle(void) { return getInpulse() * 100.0 / getPeriod(); }
    void setPeriod(float periodMicrosecond = 20000 micro_secondes);
    inline float getPeriod(void) { return MTperiod; }
    float getResolution(void); //Retourne la résolution en µs (entre 62,5ns à 64µs) 
    void detach(void); // Déconnecte la broche, elle redevient "normale" en entrée (n'efface pas les temps programmés)
    void attach(void); // Reconnecte la broche, si elle a été "détached"
  protected:
    // -------- Attributs protégés --------
    uint8_t MTpin; // Numéro de la broche
    float MTinpulse; // Largeur d'impulsion en µs
    float MTperiod; // Période en µs
    word MTbase; // Registre de base du timer de cette broche
    byte MToutput; // N° de la sortie (A=0 B=2 C=4) à l'initialisation n° de la broche
    byte MTprediviseur; // Prédiviseur utilisé.
    // -------- Méthode protégée ----------
    virtual void slowAction(void); // Pour l'initialisation
    
};


//###########################################################################
//##                               MTsoftPWM                               ##
//###########################################################################
// MTsoftPWM permet de faire du PWM de façon logicielle sur une broche, de
// faire clignoter une led ou de faire varier son intensité, de donner une
// impulsion en sortie, même de faire tourner un pas à pas en commandant Step

class MTsoftPWM: public MTquickObject, public MTslowObject
{
  public:
    // -------- Méthodes publiques --------
    MTsoftPWM(uint8_t pin, // Broche de sortie
      unsigned long inpulseMicrosecond = 10000 micro_secondes, // Durée de l'impulsion en µs; signal carré par défaut
      unsigned long periodMicrosecond = 20000 micro_secondes, // Période du signal en µs; 50Hz par défaut
      uint8_t depart = HIGH, // Niveau de l'impulsion (au départ)
      unsigned long numberOfLevels = MT_INFINI, // Nombre de niveaux en tout, infini par défaut
      void (*onStopFunction)(void) = PAS_D_ACTION, // Pas d'action par défaut
      boolean active = MT_ON); // Actif par défaut
    void setInpulse(unsigned long inpulseMicrosecond = 10000 micro_secondes);
    inline unsigned long getInpulse(void) { return MTinpulse * (_ticksForMTquickObject_ << 2); }
    void setDutyCycle(float dutyCycle = 50.0) { setInpulse(dutyCycle * getPeriod() / 100.0); }
    float getDutyCycle(void) { return getInpulse() * 100.0 / getPeriod(); }
    void setPeriod(unsigned long periodMicrosecond = 20000 micro_secondes);
    inline unsigned long getPeriod(void) { return MTperiod * (_ticksForMTquickObject_ << 2); }
    inline word getResolution(void) {return _ticksForMTquickObject_ << 2; } // C'est la base de temps!
    inline void setNumberOfLevels(unsigned long numberOfLevels = MT_INFINI) { MTsecure(MTnumberOfLevels, numberOfLevels); } // Impose un nombre de niveaux avant de s'arrêter
    inline unsigned long getNumberOfLevels(void) { return MTnumberOfLevels; } // Retourne le nombre de niveaux demandés
    inline unsigned long getNumberOfLevelsRemains(void) { return MTsecure(MTremains)-1; } // Retourne le nombre de niveaux qu'il reste encore à faire
    inline void stop(void) { MTactive = MT_OFF;   if (MTdepart) *MTport |= MTmask; else *MTport &= ~MTmask; } // Suspend l'activité
    void start(void); // Redémarre l'activité
    inline boolean getActive(void) { return MTactive > 0; } // Actif si true
  protected:
    // -------- Attributs protégés --------
    uint8_t *MTport;
    uint8_t MTmask ; // broche de sortie
    unsigned long MTinpulse; // Temps caractéristique en ticks
    unsigned long MTperiod; // Temps caractéristique en ticks
    volatile uint8_t MTdepart; // Niveau de départ
    volatile unsigned long MTnumberOfLevels; // Nombre d'appels à faire
    void (*MTonStopFunction)(void); // Fonction extérieure appelée lors de l'arrêt
    volatile byte MTactive; // 0: arrêt, 1: marche, 2: on vient de s'arrêter
    unsigned long MTticksStart; // S'incrémente à chaque appel d'action
    volatile unsigned long MTremains; // Nombre d'appels qui reste à faire, 0 pour infini
    boolean MTwhatAction; // true: on fera l'action 1, false: ce sera l'action 2
    // -------- Méthodes protégées -------
    virtual void onStop(void) {} // Pour le gestionnaire utilisateur
    virtual void slowAction(void); // Pour onStop
    virtual void quickAction(void);  // Pour gérer le signal
    virtual void baseDeTemps(void); // Demande de mise à jour des temps
};


//###########################################################################
//###########################################################################
//####                                                                   ####
//####                               Servos                              ####
//####                                                                   ####
//###########################################################################
//###########################################################################

//###########################################################################
//##                                MTservo                                ##
//###########################################################################
// MTservo permet de gérer un servomoteur avec un PWM hard. La résolution
// pourait être de 0,5µs, mais cela n'a pas de sens pratique. C'est plus aisé
// de garder une résolution de 1µs (environ 0,1)

// Sur Uno les broches utilisables sont: 9, 10
// Sur Mega: 2, 3, 5, 6, 7, 8, 11, 12, 13, 44, 45, 46

#define writeMicrosecond write // write = writeMicrosecond = writeDegree
#define writeDegree write
#define MTservo4wires MTservo4fils
class MTservo: public MTmediumObject, public MTslowObject
{
  public:
    // -------- Méthodes publiques --------
    MTservo(uint8_t pin, // Broche de sortie
      word timeFrom0To180Millisecond = 1000 milli_secondes_pour_aller_de_0_a_180, // 1s pour les 180°
      void (*onStopFunction)(void) = PAS_D_ACTION, // Pas d'action par défaut
      word initialInpulse = 1500 micro_secondes_initialement, // En microseconde ou en degré
      word minInpulseMicroseconds = 500 micro_secondes_minimum, // Durée de l'impulsion minimum
      word maxInpulseMicroseconds = 2500 micro_secondes_maximum, // Durée de l'impulsion maximale
      word periodMicroseconds = periode_de 20000 micro_secondes); // Période , maximum 32ms
    void setTimeFrom0To180(word timeFrom0To180Millisecond = 1000 milli_secondes_pour_aller_de_0_a_180); // Vitesse de déplacement
    inline word getTimeFrom0To180(void) { return MTtimeFrom0To180; }/* Récupère le vitesse de déplacement
    void writeDegree(word angleDegree);  Fixe la position. Précision de la commande environ 0,1 degré 
    void writeMicrosecond(word inpulseMillisecond); // Fixe la position. Précision de la commande 1µs */
    void write(word valeur); // Identique à writeMicrosecond ou à writeDegree
    inline word readMicrosecond(void) { return MTinpulse >> 4; } // Retourne le temps de l'impulsion
    inline byte readDegree(void) { return round(180.0 * (MTinpulse - MTminInpulse) / (MTmaxInpulse - MTminInpulse)); } // Retourne l'angle
    inline void setMinInpulseMicroseconds(word minInpulseMicroseconds = 500 micro_secondes_minimum) { minInpulseMicroseconds <<= 4; MTsecure(MTminInpulse, minInpulseMicroseconds); } // Fixe la durée minimale de l'impulsion
    inline word getMinInpulseMicroseconds(void) { return MTminInpulse >> 4; } // Retourne la durée minimale de l'impulsion
    inline void setMaxInpulseMicroseconds(word maxInpulseMicroseconds = 2500 micro_secondes_maximum) { maxInpulseMicroseconds <<= 4; MTsecure(MTmaxInpulse, maxInpulseMicroseconds); } // Fixe la durée maximale de l'impulsion
    inline word getMaxInpulseMicroseconds(void) { return MTmaxInpulse >> 4; } // Retourne la durée maximale de l'impulsion
    void setPeriod(word periodMicroseconds = periode_de 20000 micro_secondes); // Fixe la période des impulsions
    inline word getPeriod(void) { return MTperiod; } // Lit la période des implusions
    inline boolean getRun(void) {return MTsens != 0; } // true si il se déplace, false si il est arrêté
    void detach(void); // Déconnecte la broche, elle redevient "normale" (n'efface pas les temps programmés)
    void attach(void); // Reconnecte la broche, si elle a été "détached"
  protected:
    // -------- Attributs protégés --------
    uint8_t MTpin; // Numéro de la broche
    word MTtimeFrom0To180; // Temps demandé pour 180°
    void (*MTonStopFunction)(void); // Fonction extérieure appelée lors de l'arrêt
    word MTinpulse; // En µs*16, position finale demandée
      word MTminInpulse; // En µs*16, 500 micro_secondes par défaut
      word MTmaxInpulse; // En µs*16, 2500 micro_secondes par défaut
    word MTperiod; // En µs, période
    volatile word MTbase; // Registre de base du timer de cette broche
    volatile byte MToutput; // N° de la sortie (A=0 B=2 C=4) à l'initialisation n° de la broche
    volatile int8_t MTsens; // Sens de variation +/-1(à cause du ralentissement), 0 pour arrêt, 2 pour "on vient de s'arrêter"
    long MTactualInpulse; // En µs*16, position intermédiaire demandée (à cause du ralentissement)
    word MTincrement; // En µs*16, incrément à chaque inpulse d’horloge (à cause du ralentissement)
    // -------- Méthodes protégées --------
    virtual void onStop(void) {} // Pour le gestionnaire utilisateur
    virtual void slowAction(void); // Pour l'initialisation et pour onStop
    virtual void mediumAction(void);  // Pour gérer l'avance
};


//###########################################################################
//##                              MTservo4fils                             ##
//###########################################################################
// MTservo4fils permet de gérer un servomoteur avec un PWM hard ayant un fil
// supplémentaire soudé sur le point milieu su potentiomètre interne.

// Sur Uno les broches utilisables sont: 9, 10
// Sur Mega: 2, 3, 5, 6, 7, 8, 11, 12, 13, 44, 45, 46

class MTservo4fils: public MTservo
{
  public:
    // -------- Méthodes publiques --------
    MTservo4fils(uint8_t pin, // Broche de sortie
      uint8_t pinPot, // Broche du point milieu du potentiomètre
      word canFor0degree, // Valeur d'analogRead(pinPot) pour 0°
      word canFor180degree, // Valeur d'analogRead(pinPot) pour 180°
      word timeFrom0To180Millisecond = 1000 milli_secondes_pour_aller_de_0_a_180, // 1s pour les 180°
      void (*onStopFunction)(void) = NULL, // Pas d'action par défaut
      word minInpulseMicroseconds = 500 micro_secondes_minimum,
      word maxInpulseMicroseconds = 2500 micro_secondes_maximum,
      word periodMicroseconds = periode_de 20000 micro_secondes);
    //void setTimeFrom0To180(word timeFrom0To180Millisecond = 1000 milli_secondes_pour_aller_de_0_a_180);
    //inline word getTimeFrom0To180(void) { return MTtimeFrom0To180; }/* 
    //void writeDegree(word angleDegree);  Fixe la position. Précision de la commande environ 0,1 degré 
    //void writeMicrosecond(word inpulseMillisecond); // Fixe la position. Précision de la commande 1µs */
    //inline word readMicrosecond(void) { return MTinpulse >> 4; }
    //inline word readDegree(void) { return 180.0 * (MTinpulse - MTminInpulse) / (MTmaxInpulse - MTminInpulse); }
    //inline word getMinInpulseMicroseconds(void) { return MTminInpulse >> 4; }
    //inline word getMaxInpulseMicroseconds(void) { return MTmaxInpulse >> 4; }
    //inline boolean getRun(void) {return MTsens != 0; } // true si il se déplace, false si il est arrêté
    //void detach(void); // Déconnecte la broche, elle redevient "normale" (n'efface pas les temps programmés)
    //void attach(void); // Reconnecte la broche, si elle a été "détached"
  protected:    
    // -------- Attribut protégé ----------
    //void (*MTonStopFunction)(void); // Fonction extérieure appelée lors de l'arrêt
    // -------- Méthodes protégées --------
    //virtual void slowAction(void); // Pour l’initialisation et pour onStop
    //virtual void mediumAction(void);  // Pour gérer l'avance
    //virtual void onStop(void) {} // Pour le gestionnaire utilisateur
};



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

class MTulnStepper: public MTquickObject, public MTmediumObject, public MTslowObject
{
  public:
    // -------- Méthodes publiques --------
    MTulnStepper(int8_t pinA1, int8_t pinB1, int8_t pinA2 = NON_CONNECTEE, int8_t pinB2 = NON_CONNECTEE, // Broches arduino
      char mode = PAS_ENTIERS, // Choix PAS_ENTIERS, DEMI_PAS ou UNE_PHASE
      int_t acceleration = 2048 pas_ou_micro_pas, // Taille de l'accélération
      float speed = 0.2 RPS, // Choix de la vitesse en µs ou en tr/s ou tr/mn
      boolean reverse = SENS_PAR_DEFAUT, // Fait tourner dans l'autre sens si true
      void (*onStopFunction)(void) = PAS_D_ACTION, // Pas d'action par défaut
      word stepsPerTurn = 2048);  // Nombre de pas par tour
    inline void setReverse(boolean normalOrReverse = SENS_PAR_DEFAUT) { MTreverse = normalOrReverse; } // Permet d'inverser le sens de rotation
    inline void setOnStopFunction(void (*onStopFunction)(void) = PAS_D_ACTION) { MTonStopFunction = onStopFunction; } // Fonction à appeler lors de l'arrêt
    inline void setStepsPerTurn(word stepsPerTurn = 2048) { MTunTour = stepsPerTurn; } // Nombre de pas par tour, par défaut 2048 
    inline word getStepsPerTurn(void) { return MTunTour; } // Retourne le nombre de pas par tour
    inline void setOrigin(void) { setPosition(0); } // Fixe ici la position d'origine (p.ex après une mise en origine machine)
    inline void setPosition(int_t position) { MTsecure(MTposition, position); } // Fixe arbitrairement une position 
    inline int_t getPosition(void) { return MTsecure(MTposition); } // Retourne la position du moteur
    inline int_t getRest(void) { int_t temp = MTsecure(MTrest); return temp > 0 ? temp : 0; } // Retourne le nombre de pas restant à faire
 	inline void setAcceleration(int_t acceleration) { MTacceleration = (acceleration <= 0 ? 1 : acceleration); } // Nombres de pas d'accélération
    void setSpeed(float speed = 0.1 RPS); // Choix de la vitesse en µs ou en tr/s ou tr/mn
    inline float getSpeedMicrosecond(void) { return (MTtickTime / 256.0) * (_ticksForMTquickObject_ << 2); } // Temps entre 2 pas en µs
    inline float getSpeedRPS(void) { return 1000000.0 / getSpeedMicrosecond() / MTunTour; } // Vitesse en tr/s
    inline float getSpeedRPM(void) { return 60000000.0 / getSpeedMicrosecond() / MTunTour; } // Vitesse en tr/mn
    void move(int_t nbSteps); // Avancer ou reculer de nbSteps (déplacement relatif)
    void moveAndWait(int_t nbSteps); // Avancer ou reculer de nbSteps et attendre la fin du mouvement
    void moveTo(int_t position = 0); // Aller en position demandée (déplacement absolu)
    void moveToAndWait(int_t position); // Aller en position demandée et attendre la fin du mouvement
    inline void wait(void) { while (MTrest > 0); } // Attend que le moteur soit arrêté
    inline void stop(void) { int_t temp = 0; MTsecure(MTrest, temp); } // Arrête le moteur
    inline bool stopped(void) { return MTrest <= 0; } // Retourne true si le moteur est arrêté
    void setMode(char mode = PAS_ENTIERS); // Choix PAS_ENTIERS, DEMI_PAS ou UNE_PHASE
  protected:
    // -------- Attributs protégés --------
    volatile uint8_t *MTportA1; // Première bobine
    uint8_t MTbitA1;
    volatile uint8_t *MTportB1; // Deuxième bobine
    uint8_t MTbitB1;
    volatile uint8_t *MTportA2; // Première bobine,
    uint8_t MTbitA2;
    volatile uint8_t *MTportB2; // Deuxième bobine
    uint8_t MTbitB2;
    char MTmode; // PAS_ENTIERS: pas entiers deux phases, DEMI_PAS: demi-pas UNE_PHASE: pas entiers une seule phase
    int_t MTacceleration; // Taille de l'accélération
    boolean MTreverse; // Inversion des sens de rotation
    void (*MTonStopFunction)(void); // Fonction extérieure appelée lors de l'arrêt
    word MTunTour; // Nombre de pas ou de micro-pas par tour
    volatile int_t MTposition; // Position absolue
    volatile int_t MTfaits; // Nombre de pas faits dans le mouvement en cours
    uint8_t MTpas; // Pas que l'on vient de faire
    volatile int_t MTrest; //Nombre de pas restant à faire 0: vient de s'arrêter, -1 arrêt enregistré
    volatile uint32_t MTtickTime; // Temps entre de pas en 256ème de ticks
    volatile uint32_t MTtickTimeMax; // Temps entre de pas en 256ème de ticks à la vitesse maxi
    float MTcoef; // Coefficient pour calculer les vitesses
    uint32_t MTrestTicks; // Nombre de ticks restants avant de faire un pas
    uint32_t MTerror; // Erreur à tenir compte la prochaine fois
    volatile boolean MTsens; // Sens de rotation à faire
    // -------- Méthodes protégées -------
    virtual void onStop(void) {} // Pour le gestionnaire utilisateur
    virtual void slowAction(void); // Pour onStop
    virtual void mediumAction(void); // Pour les accélérations
    virtual void quickAction(void);  // Pour avancer
    virtual void baseDeTemps(void); // Demande de mise à jour des temps
};


//###########################################################################
//##                             MTstepStepper                             ##
//###########################################################################
// MTaccelStepStepper permet de gérer un moteur pas à pas piloté par un
// driver genre A4988, TB6600... avec des accélérations et des déccélérations

class MTstepStepper: public MTquickObject, public MTmediumObject, public MTslowObject
{
  public:
    // -------- Méthodes publiques --------
    MTstepStepper(int8_t pinStep, int8_t pinDir = NON_CONNECTEE, int8_t pinEn = NON_CONNECTEE, // Broches arduino
      int_t acceleration = 16*200 pas_ou_micro_pas, // Taille de l'accélération
      word microsteps = 16, // Nombre de micro-pas. Valeur conseillée 8 ou 16
      float speed = 1.0 RPS, // Choix de la vitesse en µs ou en tr/s ou tr/mn
      boolean reverse = SENS_PAR_DEFAUT, // Fait tourner dans l'autre sens si true
      void (*onStopFunction)(void) = PAS_D_ACTION, // Pas d'action par défaut
      word stepsPerTurn = 200);  // Nombre de pas par tour
    inline void disable(void) { digitalWrite(MTpinEn, HIGH); } // Mise hors tension du moteur  
    inline void enable(void) { digitalWrite(MTpinEn, LOW); } // Mise sous tension du moteur  
    inline void setReverse(boolean normalOrReverse = SENS_PAR_DEFAUT) { MTreverse = normalOrReverse; } // Permet d'inverser le sens de rotation
    inline void setOnStopFunction(void (*onStopFunction)(void) = PAS_D_ACTION) { MTonStopFunction = onStopFunction; } // Fonction à appeler lors de l'arrêt
    inline void setMicroStepsPerTurn(word stepsPerTurn = 200*16) { MTunTour = stepsPerTurn; } // Nombre de pas par tour, par défaut 200*16 
    inline word getMicroStepsPerTurn(void) { return MTunTour; } // Retourne le nombre de pas par tour
    inline void setOrigin(void) { setPosition(0); } // Fixe ici la position d'origine (p.ex après une mise en origine machine)
    inline void setPosition(int_t position) { MTsecure(MTposition, position); } // Fixe arbitrairement une position 
    inline int_t getPosition(void) { return MTsecure(MTposition); } // Retourne la position du moteur
    inline int_t getRest(void) { int_t temp = MTsecure(MTrest); return temp > 0 ? temp : 0; } // Retourne le nombre de pas restant à faire
 	inline void setAcceleration(int_t acceleration) { MTacceleration = (acceleration <= 0 ? 1 : acceleration); } // Nombres de pas d'accélération
    void setSpeed(float speed = 1.0 RPS); // Choix de la vitesse en µs ou en tr/s ou tr/mn
    inline float getSpeedMicrosecond(void) { return (MTtickTime / 256.0) * (_ticksForMTquickObject_ << 2); } // Temps entre 2 pas en µs
    inline float getSpeedRPS(void) { return 1000000.0 / getSpeedMicrosecond() / MTunTour; } // Vitesse en tr/s
    inline float getSpeedRPM(void) { return 60000000.0 / getSpeedMicrosecond() / MTunTour; } // Vitesse en tr/mn
    void move(int_t nbSteps); // Avancer ou reculer de nbSteps (déplacement relatif)
    void moveAndWait(int_t nbSteps); // Avancer ou reculer de nbSteps et attendre la fin du mouvement
    void moveTo(int_t position = 0); // Aller en position demandée (déplacement absolu)
    void moveToAndWait(int_t position); // Aller en position demandée et attendre la fin du mouvement
    inline void wait(void) { while (MTrest > 0); } // Attend que le moteur soit arrêté
    inline void stop(void) { int_t temp = 0; MTsecure(MTrest, temp); } // Arrête le moteur
    inline bool stopped(void) { return MTrest <= 0; } // Retourne true si le moteur est arrété
  protected:
    // -------- Attributs protégés --------
    volatile uint8_t *MTportStep; // Step
    uint8_t MTbitStep;
    int8_t MTpinDir; // Dir, int à cause du NON_CONNECTE qui vaut -1
    int8_t MTpinEn; // EN, active 
    int_t MTacceleration; // Taille de l'accélération
    boolean MTreverse; // Inversion des sens de rotation
    void (*MTonStopFunction)(void); // Fonction extérieure appelée lors de l'arrêt
    word MTunTour; // Nombre de pas ou de micro-pas par tour
    volatile int_t MTposition; // Position absolue
    volatile int_t MTfaits; // Nombre de pas faits dans le mouvement en cours
    volatile int_t MTrest; //Nombre de pas restant à faire 0: vient de s'arrêter, -1 arrêt enregistré
    volatile uint32_t MTtickTime; // Temps entre de pas en 256ème de ticks
    volatile uint32_t MTtickTimeMax; // Temps entre de pas en 256ème de ticks à la vitesse maxi
    float MTcoef; // Coefficient pour calculer les vitesses
    uint32_t MTrestTicks; // Nombre de ticks restants avant de faire un pas
    uint32_t MTerror; // Erreur à tenir compte la prochaine fois
    volatile boolean MTsens; // Sens de rotation à faire
    // -------- Méthodes protégées -------
    virtual void onStop(void) {} // Pour le gestionnaire utilisateur
    virtual void slowAction(void); // Pour onStop
    virtual void mediumAction(void); // Pour les accélérations
    virtual void quickAction(void);  // Pour l'avance
    virtual void baseDeTemps(void); // Demande de mise à jour des temps
};


#endif
