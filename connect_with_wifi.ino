#include <WiFi.h>  // Include the WiFi library, which allows us to connect to a Wi-Fi network.

void setup() {
  Serial.begin(115200);  // Initialize the serial communication at a baud rate of 115200.
  WiFi.begin("Your WiFi Name", "WiFi Password");  // Attempt to connect to a Wi-Fi network with the specified SSID and password.

  while (WiFi.status() != WL_CONNECTED)  // Enter a loop that continues until the device is connected to the Wi-Fi network.
  {
    Serial.print("Trying to Connect!");  // Print "Trying to Connect!" to the serial monitor.
    delay(2000);  // Pause for 2 seconds before the next iteration of the loop.
  }
  Serial.println();  // Print a new line to the serial monitor.
  Serial.println(" WiFi Connected! Good to Go!");  // Print "WiFi Connected! Good to Go!" to indicate a successful Wi-Fi connection.
}

void loop() {
  // put your main code here, to run repeatedly:
}
