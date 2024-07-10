#include "src/console.h"
#include "src/emerald.h"
#include "src/frlg.h"

#define MAX_STEPS 7
#define MAX_STEP_LENGTH 8
#define BAUD_RATE 9600

void clearLongArray(unsigned long *pArr, int len);
void clearCharArray(char *pArr, int len);

void setup() {
  Serial.begin(BAUD_RATE);
  for (int i = 2; i <= 14; i++) {
    pinMode(i, OUTPUT);
  }
}

void loop() {
  static unsigned long instructions[MAX_STEPS];
  static unsigned int stepCount = 0;

  static char stepBlock[MAX_STEP_LENGTH];
  static unsigned int position = 0;

  char inByte = Serial.read();

  if (inByte != '?') {
    if (isDigit(inByte))
    {
      stepBlock[position] = inByte;
      position ++;
    }
    if (inByte == '+') {
      instructions[stepCount] = atol(stepBlock);

      Serial.print(stepCount + 1);
      Serial.print(F(": "));
      Serial.print(F("Step value: "));
      Serial.println(atol(stepBlock));
      
      clearCharArray(stepBlock, MAX_STEP_LENGTH);
      position = 0;
      stepCount++;
    }
  }
  else 
  {
    Serial.print(F("Mode: "));
    switch (instructions[0]) {
      case 0:
        Serial.println(F("FRLG RNG"));
        frlgLoop(instructions);
        break;
      case 1:
        Serial.println(F("RSE RNG"));
        emeraldLoop(instructions);
        break;
      case 2:
        Serial.println(F("FRLG ACE Seed Checker"));
        seedCheckerWithGrabACE(instructions);
        break;
      case 3:
      /*
        1 = Select Held
        2 = Intro Timer,
        3 = Audio Setting
        4 = Shoulder button setting
        5 = Button
        6 = Unused
      */
        Serial.println(F("FRLG Custom Seed Checker"));
        seedCheckerWithCustomSave(instructions);
        break;
      default:
        Serial.println(F("Unknown"));
        break;
    }
    clearLongArray(instructions, MAX_STEPS);
    stepCount = 0;
    Serial.println(F("Done."));
  }
}

void clearLongArray(unsigned long *pArr, int len) {
  while(len-- > 0)
        *pArr++ = 0;
}

void clearCharArray(char *pArr, int len) {
  while(len-- > 0)
        *pArr++ = '\0';
}