#include <WiFi.h>
#include <WiFiServer.h>

#define LED 2

// 🏰 We create a magical server that listens on port 80
WiFiServer server(80);

// 🧙‍♂️ We have a special friend (client) to help us with incoming messages
WiFiClient client;

void setup() {
  pinMode(LED, OUTPUT);
  // 🚀 We prepare to talk and understand our friend's messages
  Serial.begin(115200);

  // 🌐 We try to connect to the Wi-Fi network with a secret name and password
  WiFi.begin("Name", "Password");

  // 🔄 While we're not connected, we keep trying every 2 seconds
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print("Trying to Connect!");
    delay(2000);
  }
  Serial.println();
  Serial.println("Connected! Good to Go!"); // 🎉 Hooray, we're connected!
  Serial.println(WiFi.localIP()); // 🏡 We proudly tell everyone our address

  // ✨ We start our magical server
  server.begin();
}

void loop() {
  // 🚪 We check if there's a new friend knocking at our door (client connected)
  client = server.available();

  if (client) {
    // 💌 We create a special box for our friend's message
    String request = "";

    // 🎵 We listen to our friend as long as they're connected
    while (client.connected()) {
      if (client.available()) {
        char c = client.read(); // 📜 We read one character from our friend

        // 🌟 We check if the character is a special "newline"
        if (c == '\n') {
          // 📣 When we see the "newline," we share our friend's message with the world
          Serial.println(request);
          
          // 🪄 You can do some special magic here to do things with the message
          
          // Now, let's explain these lines using our story:

          // 🌐 If our friend's message contains "ledON"
          // it means they want to turn a light ON, just like a magic spell!
          if (request.indexOf("ledON") != -1) {              
            // request.indexOf: This part is like searching for a specific word or phrase in a sentence.
            // != -1: This part is like getting a yes or no answer. When you use != -1, it means "not equal to -1." In computer language, -1 means "no" or "not found." So, != -1 checks if something is found.
            
            digitalWrite(LED, HIGH); // ✨ We use our magic wand (digitalWrite) to make the light shine brightly.
          }

          // 🌐 If our friend's message contains "ledOFF"
          // it means they want to turn the light OFF, like another magic spell!
          if (request.indexOf("ledOFF") != -1) {
            // ✨ We use our magic wand (digitalWrite) to make the light go dark.
            digitalWrite(LED, LOW);
          }
          request = ""; // 🧹 We clear our special box for the next message
        } else {
          request += c; // 🧩 If it's not a "newline," we add the character to our message box
        }
      }
    }

    // 🚪 After we've shared the message, we say goodbye to our friend and close the door
    client.stop();
  }
}
