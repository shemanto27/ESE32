#include <WiFi.h>
#include "ThingSpeak.h"

const char* ssid = "ERROR0404";   // your network SSID (name) 
const char* password = "Password";   // your network password

WiFiClient  client;

unsigned long myChannelNumber = 1;
const char * myWriteAPIKey = "R2OR9ZM182I80DI9"; 

// Timer variables
unsigned long lastTime = 0;
unsigned long timerDelay = 30000;

void setup() {
 pinMode(25,INPUT);
 Serial.begin(115200);
 WiFi.mode(WIFI_STA);   
  
  ThingSpeak.begin(client);  // Initialize ThingSpeak

}

void loop() {
  // Connect or reconnect to WiFi
    if(WiFi.status() != WL_CONNECTED){
      Serial.print("Attempting to connect");
      while(WiFi.status() != WL_CONNECTED){
        WiFi.begin(ssid, password); 
        delay(5000);     
      } 
      Serial.println("\nConnected.");
    }

 int IR = digitalRead(25);
 Serial.print(IR);
 delay(2000);
  // Write to ThingSpeak. There are up to 8 fields in a channel, allowing you to store up to 8 different
    // pieces of information in a channel.  Here, we write to field 1.
    int x = ThingSpeak.writeField(myChannelNumber, 1, IR, myWriteAPIKey);
    //uncomment if you want to get temperature in Fahrenheit
    //int x = ThingSpeak.writeField(myChannelNumber, 1, temperatureF, myWriteAPIKey);

    if(x == 200){
      Serial.println("Channel update successful.");
    }
    else{
      Serial.println("Problem updating channel. HTTP error code " + String(x));
    }

}
