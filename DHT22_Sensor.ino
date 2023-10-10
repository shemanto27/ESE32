#include <DHT.h>

// Define the pin where the DHT sensor is connected
#define DHTPIN 2
// Define the type of DHT sensor (DHT22)
#define DHTTYPE DHT22

// Create a DHT object named 'dht' using the defined pin and sensor type
DHT dht(DHTPIN, DHTTYPE);

void setup() {
  // Start communication with the computer via the Serial monitor
  Serial.begin(115200);

  // Initialize the DHT sensor
  dht.begin();
}

void loop() {
  // Wait for a few seconds before taking another measurement
  delay(2000);

  // Read humidity and temperature from the DHT sensor
  float h = dht.readHumidity();
  float t = dht.readTemperature();

  // Check if the sensor readings are valid (not "nan" - Not a Number)
  if (isnan(h) || isnan(t)) {
    // If the readings are not valid, print an error message
    Serial.println("Failed to read from DHT sensor!");
  } else {
    // If the readings are valid, print the humidity and temperature values
    Serial.print("Humidity (%): ");
    Serial.println(h);
    Serial.print("Temperature (C): ");
    Serial.println(t);
  }
}
