#ifndef FRLG_h
#define FRLG_h

#include <Arduino.h>

void frlgLoop(unsigned long *seq);
void seedCheckerWithGrabACE(unsigned long *seq);
void seedCheckerWithCustomSave(unsigned long *seq);
void seedCheckerWithCustomSaveStartup_R(unsigned long *seq);
void seedCheckerWithCustomSaveStartup_L(unsigned long *seq);

#endif