#include "console.h"

#define POWER_PIN 14

void openPin(unsigned int pin) {
    switch (pin) {
        case 2:
            PORTD |= (1 << PORTD2);
            break;
        case 3:
            PORTD |= (1 << PORTD3);
            break;
        case 4:
            PORTD |= (1 << PORTD4);
            break;
        case 5:
            PORTD |= (1 << PORTD5);
            break;
        case 6:
            PORTD |= (1 << PORTD6);
            break;
        case 7:
            PORTD |= (1 << PORTD7);
            break;
        case 8:
            PORTB |= (1 << PORTB0);
            break;
        case 9:
            PORTB |= (1 << PORTB1);
            break;
        case 10:
            PORTB |= (1 << PORTB2);
            break;
        case 11:
            PORTB |= (1 << PORTB3);
            break;
        case 12:
            PORTB |= (1 << PORTB4);
            break;
        case 13:
            PORTB |= (1 << PORTB5);
            break;
        case 14:
            PORTC |= (1 << PORTC0);
        default:
            break;
    }

    _delay_ms(59);
    PORTD &= ~(B11111100);
    PORTB = 0;
    PORTC &= ~(1 << PORTC0);
}

void softResetGameNDS() {
  PORTD |= B00001100;
  PORTB |= B00110000;

  _delay_ms(250);

  PORTD &= ~B00001100;
  PORTB &= ~B00110000;
}

void processButtonDelay(ButtonDelay * bd, unsigned int steps) {
  for (int i = 0; i < steps; i++) {
    if (bd[i].delay) {
      Serial.print(F("Delaying for: "));
      Serial.print(bd[i].delay);
      Serial.println(F(" "));
      delay(bd[i].delay);
    }
    Serial.print(F("Pressing: "));
    Serial.print(bd[i].button);
    Serial.println(F(" "));
    openPin(bd[i].button);
  }
}


