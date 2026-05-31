/************************************************************
 * Project: Smart Socket using ESP8266 + Blynk IoT + Apple's Siri
 * Full Tutorial Video: https://your-youtube-link-here
 * Made by: iOT India
 * Description: This project allows you to control a relay (smart socket)

 * Siri Start Smart Socket Link : https://sgp1.blynk.cloud/external/api/update?token=YOUR-BLYNK-AUTH-TOKEN&v0=1  // Your Blynk Auth Token
 * Siri Stop Smart Socket Link : https://sgp1.blynk.cloud/external/api/update?token=YOUR-BLYNK-AUTH-TOKEN&v0=0   // Your Blynk Auth Token
 ************************************************************/

// ====== Blynk Credentials ======
#define BLYNK_TEMPLATE_ID "TMPL3UKfw5VI-"                     // Your Blynk Template ID
#define BLYNK_TEMPLATE_NAME "Smart Socket"                    // Your Blynk Template Name
#define BLYNK_AUTH_TOKEN "J0RdVyvIFW1jliuoZXHpgw1fPbf6V33098" // Your Blynk Auth Token

// Enable Serial Monitor (for debugging)
#define BLYNK_PRINT Serial

// ====== Required Libraries ======
#include <ESP8266WiFi.h>          // Handles WiFi connection
#include <BlynkSimpleEsp8266.h>   // Blynk IoT library

// ====== WiFi Credentials ======
char ssid[] = "********";        // Your WiFi name
char pass[] = "********";        // Your WiFi password

// ====== Pin Definitions ======
#define RELAY_PIN   5   // D1 → Relay (Active LOW)
#define RELAY_LED   2   // D4 → Indicator LED (Active LOW)
#define CONFIG_BTN  0   // D3 → Push Button (Active HIGH)

// ====== Variables ======
bool relayState = false;        // Stores relay ON/OFF state
bool lastButtonState = LOW;     // Stores previous button state

// ====== Blynk App Control ======
// Triggered when button widget (V0) is pressed in app
BLYNK_WRITE(V0) {
  relayState = param.asInt();   // Get value from app

  // Apply state to hardware (Active LOW logic)
  digitalWrite(RELAY_PIN, relayState ? LOW : HIGH);
  digitalWrite(RELAY_LED, relayState ? LOW : HIGH);
}

// ====== Sync State on Reconnect ======
BLYNK_CONNECTED() {
  Blynk.syncVirtual(V0);   // Sync last state from server
}

void setup() {
  Serial.begin(9600);   // Start serial communication

  // Set pin modes
  pinMode(RELAY_PIN, OUTPUT);
  pinMode(RELAY_LED, OUTPUT);
  pinMode(CONFIG_BTN, INPUT);

  // Default state: OFF
  digitalWrite(RELAY_PIN, HIGH);
  digitalWrite(RELAY_LED, HIGH);

  // Connect to WiFi + Blynk cloud
  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);
}

void loop() {
  Blynk.run();   // Maintain Blynk connection

  // ====== Button Handling ======
  bool buttonState = digitalRead(CONFIG_BTN);

  // Detect button press (LOW → HIGH transition)
  if (buttonState == HIGH && lastButtonState == LOW) {

    relayState = !relayState;  // Toggle state

    // Apply new state
    digitalWrite(RELAY_PIN, relayState ? LOW : HIGH);
    digitalWrite(RELAY_LED, relayState ? LOW : HIGH);

    // Update Blynk app
    Blynk.virtualWrite(V0, relayState);

    delay(200); // Debounce delay
  }

  lastButtonState = buttonState; // Save state
}
