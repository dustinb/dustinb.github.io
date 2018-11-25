/**
 * BasicHTTPClient.ino
 *
 *  Created on: 24.05.2015
 *
 */

#include <Arduino.h>
#include <WiFi.h>
#include <WiFiMulti.h>
#include <HTTPClient.h>
#define USE_SERIAL Serial

WiFiMulti wifiMulti;
HTTPClient http;

const int BUTTON1 = 4; 
const int BUTTON2 = 12;
const int BUTTON3 = 14;
const int BUTTON4 = 27;
const int GND1 = 15;
const int STATELED = 2;

int pressedButton = 0;

void setup() {
  
  USE_SERIAL.begin(115200);

  // Buttons
  pinMode(BUTTON1, INPUT_PULLUP);
  pinMode(BUTTON2, INPUT_PULLUP);
  pinMode(BUTTON3, INPUT_PULLUP);
  pinMode(BUTTON4, INPUT_PULLUP);
  
  // Built In LED
  pinMode(STATELED, OUTPUT);
  digitalWrite(STATELED, HIGH);

  // Ground pin for LED 1
  pinMode(GND1, OUTPUT);
  digitalWrite(GND1, HIGH);

  wifiMulti.addAP("bute-guest", "password1234");
 
  int t = 0;
  while(wifiMulti.run() != WL_CONNECTED) {
    USE_SERIAL.printf("[SETUP] WAIT %d...\n", t++);
    digitalWrite(STATELED, HIGH);
    delay(100);
    digitalWrite(STATELED, LOW);
    delay(100);
  }

  USE_SERIAL.printf("Setup completed.");
}

void loop() {

  if (digitalRead(BUTTON1) == LOW) {
    pressedButton = 1;
  } else if(digitalRead(BUTTON2) == LOW) {
    pressedButton = 2;
  } else if(digitalRead(BUTTON3) == LOW) {
    pressedButton = 3;
  } else if(digitalRead(BUTTON4) == LOW) {
    pressedButton = 4;
  } 
  
  if (pressedButton) {

    USE_SERIAL.printf("Button Pressed %d\n", pressedButton);
    
    // Since the button maybe lighted, blink a state button to show we received the button press
    for (int t = 3; t > 0; t--) {
      digitalWrite(STATELED, HIGH);
      delay(100);
      digitalWrite(STATELED, LOW);
      delay(100);
    }

    // Keep the state button on until the HTTP request is completed
    digitalWrite(STATELED, HIGH);

    // Prepare our URL
    USE_SERIAL.print("[HTTP] begin...\n");
    char url[80];  //buffer used to format a line (+1 is for trailing 0)
    sprintf(url,"https://dustin.theboss.solutions/res/staff_planner/BossButtons.php?button=%d", pressedButton);
    http.begin(url);

    USE_SERIAL.print("[HTTP] GET...\n");
    // start connection and send HTTP header
    int httpCode = http.GET();

    // httpCode will be negative on error
    if (httpCode > 0) {
        // HTTP header has been send and Server response header has been handled
        USE_SERIAL.printf("[HTTP] GET... code: %d\n", httpCode);

        // file found at server
        if (httpCode == HTTP_CODE_OK) {
           String payload = http.getString();
           // payload determines if LED stays on or OFF
           if (payload == "1") {
            digitalWrite(GND1, LOW);
           } else {
            digitalWrite(GND1, HIGH);
           }
           USE_SERIAL.println(payload);
        }
    } else {
      USE_SERIAL.printf("[HTTP] GET... failed, error: %s\n", http.errorToString(httpCode).c_str());
    }

    pressedButton = 0;
    http.end();
    digitalWrite(STATELED, LOW);
  }
}
