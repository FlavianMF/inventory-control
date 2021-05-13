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

// connect to the row pinouts of the keypad-black pins
// byte rowPins[ROWS] = {32, 33, 25, 26};
byte rowPins[ROWS] = {13, 12, 14, 27};
// connect to the column pinouts of the keypad-white pins
// byte colPins[COLS] = {27, 14, 12, 13};
byte colPins[COLS] = {26, 25, 33, 32};

Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);

#endif  // __SETUPKEYPAD_H__