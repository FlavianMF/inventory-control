#ifndef __SETUPLCD_H__
#define __SETUPLCD_H__
#include <Arduino.h>
#include <LiquidCrystal_I2C.h>
#include <Wire.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

#endif  // __SETUPLCD_H__