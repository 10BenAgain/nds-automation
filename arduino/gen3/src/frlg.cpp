#include "console.h"

#define LOAD_INTO_GAME_MS 2680
#define WAIT_FOR_SAV_MENU 3950
#define ARRAY_SIZE(arr) (sizeof(arr) / sizeof(arr[0]))

static Settings CurrentSettings = { 0, 0 };

void
saveTheGame() {
  ButtonDelay Save[] = {
    {0, START_PRESS},
    {200, DOWN_PRESS},
    {200, DOWN_PRESS},
    {200, DOWN_PRESS},
    {200, DOWN_PRESS},
    {200, DOWN_PRESS},
    {1000, A_PRESS},
    {800, A_PRESS},
    {1000, A_PRESS},
    {4200, B_PRESS}
  };
  int length = ARRAY_SIZE(Save);
  processButtonDelay(Save, length);
}

void
openSettings() {
  ButtonDelay Settings[] = {
    {0, START_PRESS},
    {200, DOWN_PRESS},
    {200, DOWN_PRESS},
    {200, DOWN_PRESS},
    {200, DOWN_PRESS},
    {200, DOWN_PRESS},
    {1500, A_PRESS}
  };
  int length = ARRAY_SIZE(Settings);
  processButtonDelay(Settings, length);
}

void
switchAudioMode() {
  ButtonDelay Audio[] = {
    {0, START_PRESS},
    {200, DOWN_PRESS},
    {200, DOWN_PRESS},
    {200, DOWN_PRESS},
    {200, LEFT_PRESS},
    {1200, B_PRESS},
    {200, B_PRESS}
  };
  int length = ARRAY_SIZE(Audio);
  processButtonDelay(Audio, length);
  
  if (CurrentSettings.audio == 0) 
    CurrentSettings.audio++;
  else 
    CurrentSettings.audio = 0;
  saveTheGame();
}

void 
switchButtonMode(unsigned int mode) {
  ButtonDelay Audio[] = {
    {0, START_PRESS},
    {200, DOWN_PRESS},
    {200, DOWN_PRESS},
    {200, DOWN_PRESS},
    {200, DOWN_PRESS}
  };
  int length = ARRAY_SIZE(Audio);
  processButtonDelay(Audio, length);

  switch (mode)
  {
  case 0: // L=A
    if (CurrentSettings.shoulder == 1) 
      openPin(LEFT_PRESS);
    else if (CurrentSettings.shoulder == 2) 
      openPin(RIGHT_PRESS);
    break;
  case 1: // HELP
    if (CurrentSettings.shoulder == 0)
      openPin(LEFT_PRESS);
    else if (CurrentSettings.shoulder == 2)
      openPin(RIGHT_PRESS);
    break;
  case 2: // LR
    if (CurrentSettings.shoulder == 0)
      openPin(LEFT_PRESS);
    else if (CurrentSettings.shoulder == 1)
      openPin(RIGHT_PRESS);
    break;
  default:
    break;
  }
  CurrentSettings.shoulder = mode;
  openPin(B_PRESS);
  waitMicroseconds(1500);
  openPin(B_PRESS);
  waitMicroseconds(800);
  saveTheGame();
}


void 
fossilSeqFrlg() {
  ButtonDelay FOSSIL_SEQ[] = {
    {0, A_PRESS},
    {1509, A_PRESS}
  };
  int length = ARRAY_SIZE(FOSSIL_SEQ);
  processButtonDelay(FOSSIL_SEQ, length);
}

void 
starterSeq() {
  ButtonDelay STARTER_SEQ[] = {
    {0, A_PRESS},
    {2095, A_PRESS},
    {1173, A_PRESS}
  };
  int length = ARRAY_SIZE(STARTER_SEQ);
  processButtonDelay(STARTER_SEQ, length);
}

void 
snorlaxSeq() {
  ButtonDelay SNORLAX_SEQ[] = {
    {0, A_PRESS},
    {1006, A_PRESS},
    {8581, A_PRESS}
  };
  int length = ARRAY_SIZE(SNORLAX_SEQ);
  processButtonDelay(SNORLAX_SEQ, length);
}

void 
hypnoSeq() {
  ButtonDelay HYPNO_SEQ[] = {
    {0, A_PRESS},
    {1341, A_PRESS},
    {1090, A_PRESS},
    {1006, A_PRESS},
    {2180, A_PRESS},
    {2012, A_PRESS}
  };
  int length = ARRAY_SIZE(HYPNO_SEQ);
  processButtonDelay(HYPNO_SEQ, length);
}

void 
laprasSeq() {
  ButtonDelay LAPRAS_SEQ[] = {
    {0, A_PRESS},
    {1274, A_PRESS},
    {503, A_PRESS}
  };
  int length = ARRAY_SIZE(LAPRAS_SEQ);
  processButtonDelay(LAPRAS_SEQ, length);
}

void 
magikarpSeq() {
  ButtonDelay MAGIKARP_SEQ[] = {
    {0, A_PRESS},
    {1005, A_PRESS},
    {1676, A_PRESS}
  };
  int length = ARRAY_SIZE(MAGIKARP_SEQ);
  processButtonDelay(MAGIKARP_SEQ, length);
}

void 
togepiSeq() {
  ButtonDelay TOGEPI_SEQ[] = {
    {0, A_PRESS},
    {1173, A_PRESS},
    {1006, A_PRESS},
    {1173, A_PRESS},
    {922, A_PRESS},
    {922, A_PRESS}
  };
  int length = ARRAY_SIZE(TOGEPI_SEQ);
  processButtonDelay(TOGEPI_SEQ, length);
}

void 
sweetScentFRLG() {
  ButtonDelay SWEET_SCENT_FRLG[] = {
    {0, START_PRESS},
    {200, DOWN_PRESS},
    {200, A_PRESS},
    {2000, DOWN_PRESS},
    {200, A_PRESS},
    {200, DOWN_PRESS}
  };
  int length = ARRAY_SIZE(SWEET_SCENT_FRLG);
  processButtonDelay(SWEET_SCENT_FRLG, length);
}

void 
abraSeq() {
  ButtonDelay ABRA_GC_SEQ[] = {
    {0, A_PRESS},
    {2012, A_PRESS},
    {2012, A_PRESS}
  };
  int length = ARRAY_SIZE(ABRA_GC_SEQ);
  processButtonDelay(ABRA_GC_SEQ, length);
};

void 
clefairySeq() {
  ButtonDelay CLEFAIRY_GC_SEQ[] = {
    {0, A_PRESS},
    {2012, A_PRESS},
    {2012, DOWN_PRESS},
    {60, A_PRESS}
  };
  int length = ARRAY_SIZE(CLEFAIRY_GC_SEQ);
  processButtonDelay(CLEFAIRY_GC_SEQ, length);
}

void 
dratiniSeq() {
  ButtonDelay DRATINI_GC_SEQ[] = {
    {0, A_PRESS},
    {2012, A_PRESS},
    {2012, DOWN_PRESS},
    {60, DOWN_PRESS},
    {60, A_PRESS}
  };
  int length = ARRAY_SIZE(DRATINI_GC_SEQ);
  processButtonDelay(DRATINI_GC_SEQ, length);
}

void 
scypinSeq() {
  ButtonDelay SCYPIN_GC_SEQ[] = {
    {0, A_PRESS},
    {2012, A_PRESS},
    {2012, DOWN_PRESS},
    {60, DOWN_PRESS},
    {60, DOWN_PRESS},
    {60, A_PRESS}
  };
  int length = ARRAY_SIZE(SCYPIN_GC_SEQ);
  processButtonDelay(SCYPIN_GC_SEQ, length);
}

void 
porygonSeq() {
  ButtonDelay PORYGON_GC_SEQ[] = {
    {0, A_PRESS},
    {2012, A_PRESS},
    {2012, DOWN_PRESS},
    {60, DOWN_PRESS},
    {60, DOWN_PRESS},
    {60, DOWN_PRESS},
    {60, A_PRESS}
  };
  int length = ARRAY_SIZE(PORYGON_GC_SEQ);
  processButtonDelay(PORYGON_GC_SEQ, length);
}

void catchWildPokemonMasterBall() {
  ButtonDelay THROW_BALL[] = {
    {3000, A_PRESS},
    {800, RIGHT_PRESS},
    {800, A_PRESS},
    {1200, RIGHT_PRESS},
    {800, RIGHT_PRESS},
    {800, A_PRESS},
    {800, A_PRESS},
    {5000, A_PRESS},
    {800, B_PRESS}
  };
  int length = ARRAY_SIZE(ButtonDelay);
  processButtonDelay(THROW_BALL, length);
}

/*
  * This assumes that you are standing in front of a PC
  * And that when you open Bill's PC to *move* Pokemon
  * The corrupted Pokemon is already hovered over in the box
*/
void 
performGrabACE() {
  ButtonDelay GRAB_ACE[] = {
    {0, A_PRESS},
    {1592, A_PRESS},
    {1592, A_PRESS},
    {1173, A_PRESS},
    {1000, A_PRESS},
    {1844, DOWN_PRESS},
    {200, DOWN_PRESS},
    {200, A_PRESS},
    {2850, A_PRESS},
    {200, A_PRESS},
    {800, RIGHT_PRESS},
    {800, A_PRESS},
    {800, A_PRESS},
    {800, LEFT_PRESS},
    {800, A_PRESS},
    {800, A_PRESS},
    {800, A_PRESS},
    {800, A_PRESS},
    {800, RIGHT_PRESS},
    {800, A_PRESS},
    {800, A_PRESS},
    {800, LEFT_PRESS},
    {800, A_PRESS},
    {800, A_PRESS},
    {800, B_PRESS},
    {800, B_PRESS},
    {4526, B_PRESS},
    {600, B_PRESS},
    {600, B_PRESS}
  };
  int length = ARRAY_SIZE(GRAB_ACE);
  processButtonDelay(GRAB_ACE, length);
}

/*
  * Simple function that just opens up the trainer card
  * Assumes player is standing in the overworld and is able
  * to open the main start menu
*/
void
checkTrainerCard() {
  ButtonDelay CHECK_TID[] = {
    {0, START_PRESS},
    {200, DOWN_PRESS},
    {200, DOWN_PRESS},
    {200, DOWN_PRESS},
    {200, A_PRESS}
  };
  int length = ARRAY_SIZE(CHECK_TID);
  processButtonDelay(CHECK_TID, length);
}

/*
  * Function performs opening the Teachy TV
  * and then waiting inside the TV screen for a specified amount of time
  * Assumes that the TV is registered key item
*/
void 
teachyTV(unsigned long timer) {
  unsigned long startTimer = millis();
  openPin(SELECT_PRESS);
  waitMicroseconds(MS_UL(1200));
  unsigned long endTimer = millis();
  unsigned long waitTime = timer - (endTimer - startTimer);

  if (waitTime < 0) 
    return;
    
  Serial.println(waitTime);
  delay(waitTime);
  openPin(B_PRESS);
  waitMicroseconds(MS_UL(1000));
}

typedef void (*SeqPtr)();

SeqPtr selectSeqFrlg(int mode) {
  switch (mode) {
    case 1: 
      return fossilSeqFrlg;
    case 2:
      return starterSeq;
    case 4:
      return magikarpSeq;
    case 5:
      return laprasSeq;
    case 6:
      return togepiSeq;
    case 7:
      return sweetScentFRLG;
    case 8:
      return abraSeq;
    case 9:
      return clefairySeq;
    case 10:
      return dratiniSeq;
    case 11:
      return scypinSeq;
    case 12:
      return porygonSeq;
    case 13:
      return snorlaxSeq;
    default:
      return NULL;
  }
  return NULL;
}

static unsigned long loopTimer = 0;

/*
  * Reboots the console then waits 10 seconds
  * Presses A to get to main menu, waits 3 seconds
*/
void 
getToDSMenuFromReboot() {
  rebootConsole();
  waitMilliseconds(10000);
  openPin(A_PRESS);
  waitMilliseconds(3000);
}

/*
  * Simple sequence of button presses and delays
  * Meant to just get us from the save selection menu into the game
  * Selects save, skips recap, that's it
*/
void 
menuToGame() {
  Serial.println(F("Selecting save file..."));
  waitMicroseconds(MS_UL(60));
  openPin(A_PRESS);
  Serial.println(F("Skipping recap..."));
  waitMicroseconds(MS_UL(LOAD_INTO_GAME_MS));
  openPin(B_PRESS);
  waitMicroseconds(MS_UL(LOAD_INTO_GAME_MS));
  Serial.println(F("Loaded into game..."));
}

/*
  * Holds select if needed before the game is selected in the DS menu
  * Sets an initial start time stored in a global variable
  * Loads the game by pressing on on the DS menu 
  * Waits for an amount of time speficied by the user minimum of 35,000 MS
  * Holds down save selection button, then waits until save menu is ready
  * Executes sequence for skipping recap and loading into the game
*/
void 
introLoop(int button, int select, unsigned long timer) {
  if (select) {
    digitalWrite(SELECT_PRESS, HIGH);
    Serial.println(F("Holding select..."));
  }
  loopTimer = micros();

  Serial.println(F("Waiting thru intro timer..."));
  openPin(A_PRESS);
  waitMicroseconds(MS_UL(timer));

  Serial.println(F("Intro complete..."));
  digitalWrite(button, HIGH);
  waitMicroseconds(MS_UL(WAIT_FOR_SAV_MENU));
  digitalWrite(button, LOW);

  menuToGame();
}

/*
  * Function for preforming RNG sequence
  * Based on user input, a sequence for getting into an encounter is seleceted
  * Checks if the total time is shorter than possible and continues to wait if not
  * Starts the encounter by pressing A 
*/
void 
frlgLoop(unsigned long *seq) {
  introLoop(seq[5], seq[1], seq[2]);
 
  if (seq[6] > 0)
    teachyTV(seq[6]);
  
  if (seq[4] != 0){
    Serial.print(F("Mode is not NULL: 0x"));
    Serial.print((uintptr_t)seq[4], HEX);
    Serial.println(F(" "));
    selectSeqFrlg(seq[4])();
  }
  else {
    Serial.println(F("Mode is NULL"));
    openPin(A_PRESS);
  }

  if (micros() - loopTimer > MS_UL(seq[3])) {
    loopTimer = 0;
    return;
  }

  Serial.println(F("Waiting for encounter"));
  while(micros() - loopTimer < MS_UL(seq[3])) {
  }

  loopTimer = 0;
  openPin(A_PRESS);
}

/*
  * Performs and intro loop sequence with user input
  * Once loaded into the game, performs a grab ACE code
  * for changing the TID to the intro seed
  * Opens up the trainer card then waits for 10 seconds 
  * for camera to capture the value
  * Reboots the console to reset the seed and start again
*/
void
seedCheckerWithGrabACE(unsigned long *seq) {
  Serial.println(F("Rebooting console.."));
  getToDSMenuFromReboot();
  Serial.println(F("Console rebooted..."));
  loopTimer = loopTimer ? 0 : loopTimer;

  introLoop(seq[5], seq[1], seq[2]);
  performGrabACE();

  waitMilliseconds(500);

  checkTrainerCard();
}

/*
  * This assumes we are using the special save file that
  * Prints out the initial seed when player speaks with
  * Rival's sister. This simply reboots, performs the timer sequence,
  * Then starts the conversation by pressing A
*/
void
seedCheckerWithCustomSave(unsigned long *seq) {
  Serial.println(F("Rebooting console.."));
  getToDSMenuFromReboot();
  Serial.println(F("Console rebooted..."));
  loopTimer = loopTimer ? 0 : loopTimer;

  // Button, Select, Intro Timer
  introLoop(seq[5], seq[1], seq[2]);
  waitMilliseconds(500);
  
  // Audio Settings
  if (seq[3] != CurrentSettings.audio) {
    openSettings();
    switchAudioMode();
    waitMicroseconds(1000);
  }
  // Shoulder button settings
  if (seq[4] != CurrentSettings.shoulder) {
    openSettings();
    switchButtonMode(seq[4]);
    waitMicroseconds(1000);
  }
  
  openPin(A_PRESS);
}
