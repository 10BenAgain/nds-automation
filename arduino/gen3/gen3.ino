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
  for (int i = 2; i < 14; i++) {
    pinMode(i, OUTPUT);
  }
}

void loop() {
  static unsigned long instructions[MAX_STEPS];
  static unsigned int stepCount = 0;

  static unsigned char stepBlock[MAX_STEP_LENGTH];
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
      clearCharArray(stepBlock, MAX_STEP_LENGTH);
      position = 0;
      stepCount++;
    }
  }
  else 
  {
    switch (instructions[0]) {
      case 0:
        frlgLoop(instructions);
        break;
      case 1:
        emeraldLoop(instructions);
        break;
      default:
        break;
    }
    clearLongArray(instructions, MAX_STEPS);
    stepCount = 0;
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