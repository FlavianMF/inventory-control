#ifndef __SETUPKEYPAD_H__
#define __SETUPKEYPAD_H__
#include <Arduino.h>
#include <Keypad.h>

const byte ROWS = 4;  // four rows
const byte COLS = 4;  // three columns
char keys[ROWS][COLS] = {{'1', '2', '3', 'A'},
                         {'4', '5', '6', 'B'},
                         {'7', '8', '9', 'C'},
                         {'*', '0', '#', 'D'}};

// connect to the row pinouts of the keypad
byte rowPins[ROWS] = {5, 4, 3, 2};
// connect to the column pinouts of the keypad
byte colPins[COLS] = {8, 7, 6, 9};

Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);

void keypadEvent(KeypadEvent key) {
  switch (keypad.getState()) {
    case PRESSED:
      break;
    case RELEASED:
      break;
    case HOLD:
      break;
  }
}

#endif  // __SETUPKEYPAD_H__