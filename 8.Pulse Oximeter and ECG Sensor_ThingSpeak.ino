#include <WiFi.h>
#include <HTTPClient.h>
#include <Wire.h>
#include "MAX30100_PulseOximeter.h"

// Set your WiFi credentials
const char* ssid = "YourSSID";
const char* password = "YourPassword";
String serverName = "https://api.thingspeak.com/update?api_key=YourAPIKey";

#define REPORTING_PERIOD_MS 500

PulseOximeter pox;
uint32_t tsLastReport = 0;

void onBeatDetected() {
  Serial.println("Beat Detected!");
}

void setup() {
  Serial.begin(115200);
  Serial.print("Initializing pulse oximeter..");

  if (!pox.begin()) {
    Serial.println("FAILED");
    for (;;);
  } else {
    Serial.println("SUCCESS");
  }

  pox.setIRLedCurrent(MAX30100_LED_CURR_14_2MA);
  pox.setOnBeatDetectedCallback(onBeatDetected);

  WiFi.begin(ssid, password);
  Serial.println("Connecting");

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("");
  Serial.print("Connected to WiFi network with IP Address: ");
  Serial.println(WiFi.localIP());
}

void loop() {
  int spo2 = pox.getSpO2();
  int bpm = pox.getHeartRate();
  int ecgValue = analogRead(A0);

  pox.update();

  if (millis() - tsLastReport > REPORTING_PERIOD_MS) {
    Serial.print("Heart rate:");
    Serial.print(pox.getHeartRate());
    Serial.print("bpm / SpO2:");
    Serial.print(pox.getSpO2());
    Serial.print("% / ECG:");
    Serial.println(ecgValue);

    sendData(spo2, bpm, ecgValue);
    tsLastReport = millis();
  }
}

void sendData(int spo2, int bpm, int ecgValue) {
  HTTPClient http;

  String url = serverName + "&field1=" + spo2 + "&field2=" + bpm + "&field3=" + ecgValue;
  
  http.begin(url.c_str());

  int httpResponseCode = http.GET();

  if (httpResponseCode > 0) {
    Serial.print("HTTP Response code: ");
    Serial.println(httpResponseCode);
  } else {
    Serial.print("Error code: ");
    Serial.println(httpResponseCode);
  }

  http.end();
}
