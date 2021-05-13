#include <Arduino.h>
#include <HTTPClient.h>
#include <Keypad.h>
// #include <LiquidCrystal_I2C.h>
#include <WiFi.h>
#include <Wire.h>

#include "api-credentiasl.h"
#include "network-credentials.h"
#include "setupKeypad.h"
#include "setupLCD.h"

enum INFORMATIONS { COMPONENT_ID, PROJECT, QUANTITY };
int information = COMPONENT_ID;

void getValueFromKeypad(int* informations) {
  bool confirm = false;
  char key = 0;
  information = 0;

  while (!confirm) {
    lcd.clear();
    switch (information) {
      case COMPONENT_ID:
        lcd.setCursor(0, 0);
        Serial.print("Id: ");
        lcd.print("ID do Componente");
        lcd.setCursor(0, 1);
        break;
      case PROJECT:
        lcd.setCursor(0, 0);
        lcd.print("ID do Projeto");
        lcd.setCursor(0, 1);
        Serial.print("Project: ");
        break;
      case QUANTITY:
        lcd.setCursor(0, 0);
        Serial.print("Qtd: : ");
        lcd.print("Quantidade");
        lcd.setCursor(0, 1);
        break;
      default:
        break;
    }
    lcd.print(informations[information]);
    Serial.println(informations[information]);
    while (!key) {
      key = keypad.getKey();
    }
    switch (key) {
      case '*':
        informations[information] /= 10;
        break;
      case 'D':
        if (information == QUANTITY) confirm = true;
        information++;
        break;
      default:
        key -= '0';
        if (key < 0 || key > 9) break;
        informations[information] *= 10;
        informations[information] += key;
        break;
    }
    key = 0;
  }
  Serial.println("return getvalues");
  // return informations;
}

void sendInformations(int* informations) {
  Serial.println("init send");
  String queryParams = "ID=";
  queryParams += (String)informations[0];
  queryParams += "&PROJECT=";
  queryParams += (String)informations[1];
  queryParams += "&QTD=";
  queryParams += (String)informations[2];
  Serial.println(queryParams);
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Sending Data ...");
  sendData(queryParams);
  lcd.print("Finished Sending");
  delay(1000);
}

void setup() {
  Serial.begin(115200);

  WiFi.mode(WIFI_STA);
  WiFi.begin(SSID, PASS);

  // lcd.begin(16, 2);
  lcd.init();
  lcd.backlight();

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print(" Connecting ... ");
  Serial.println("Started");
  Serial.print("Connecting");
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  lcd.setCursor(0, 1);
  lcd.print("Connected!");
  Serial.println("Ready to go");
  sendData("");
}

void loop() {
  int informations[3] = {0, 0, 0};
  getValueFromKeypad(informations);
  sendInformations(informations);
}