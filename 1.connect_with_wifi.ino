#include <WiFi.h>  // 🌐 We invite the WiFi library to help us connect to the internet.

void setup() {
  Serial.begin(115200);  // 🚀 We start talking to the computer at a certain speed (baud rate).
  WiFi.begin("Name", "Password");  // 📡 We try to make friends with a Wi-Fi network using a special name (SSID) and secret code (password).

  // 🔁 We keep trying to connect until we succeed.
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print("Trying to Connect!");  // 🗣 We say, "Hey, I'm trying to make a new friend!" to the computer.
    delay(2000);  // ⏳ We wait patiently for 2 seconds before trying again.
  }
  Serial.println();  // 📋 We say, "Let's start a new line."
  Serial.println("Connected! Good to Go!");  // 🎉 We shout, "Yay, we're connected to the internet!" to celebrate.
  Serial.println(WiFi.localIP());  // 🏡 We proudly announce our unique address on the internet.
}

void loop() {
  // This is where we can do our special tasks over and over again.
  // But right now, it's empty, like a blank page in a magical book.
}
