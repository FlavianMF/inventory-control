#include <Arduino.h>
#include <HTTPClient.h>
#include <Keypad.h>
#include <WiFi.h>

#include "api-credentiasl.h"
#include "network-credentials.h"
#include "setupKeypad.h"

void setup() {
  Serial.begin(115200);

  WiFi.mode(WIFI_STA);
  WiFi.begin(SSID, PASS);

  Serial.println("Started");
  Serial.print("Connecting");
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  keypad.addEventListener(
      keypadEvent);  // Add an event listener for this keypad

  Serial.println("Ready to go");
}

void loop() {}