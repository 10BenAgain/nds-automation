#include "src/console.h"
#include "src/emerald.h"
#include "src/frlg.h"

#define INSTRUCTION_LIMIT 7

const unsigned long BAUD_RATE = 9600;
const unsigned int INCREMENT = 8;
const unsigned int TIMER_MAX = 75000;
const unsigned int BUTTON = 13; 


void setup() {
  Serial.begin(BAUD_RATE);
  for (int i = 2; i <= 14; i++) {
    pinMode(i, OUTPUT);
  }
}

void loop() {
    static unsigned int startingTimer = 35000;
    static unsigned int storage = 2000;

    unsigned long instructions[INSTRUCTION_LIMIT];
    instructions[0] = 0;
    instructions[1] = 0;
    instructions[2] = startingTimer;
    instructions[3] = 0;
    instructions[4] = 0;
    instructions[5] = BUTTON;
    instructions[6] = 0;

    static int count = 1;
    while (storage-- > 0) {
        Serial.print(F("Starting loop..\n"));
        Serial.print(F("Current timer: "));
        Serial.print(startingTimer);
        Serial.println(F(" "));
        Serial.print(F("Iteration: "));
        Serial.print(count);
        Serial.println(F(" "));

        seedCheckerWithCustomSave(instructions);
        if (startingTimer >= TIMER_MAX)
            break;
            
        startingTimer += INCREMENT;
        count++;
        waitMilliseconds(2000);
    }
}

