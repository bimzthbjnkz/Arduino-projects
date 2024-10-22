#include <WiFi.h>  // Include the WiFi library

const char* targetSSID = "aku malu kalian minta data";  // Replace with your target WiFi network SSID
int previousRSSI = 0;   // Variable to store the previous RSSI value
int rssiThreshold = 2; // Threshold for detecting motion (change in RSSI)
unsigned long lastScanTime = 0;
const unsigned long scanInterval = 200; // Time between scans (2 seconds)

void setup() {
  Serial.begin(9600);
  WiFi.mode(WIFI_STA);  // Set ESP32 to station mode
  WiFi.disconnect();    // Ensure WiFi starts disconnected
  delay(100);
  Serial.println("Starting WiFi sensing for motion detection...");
}

void loop() {
  unsigned long currentTime = millis();
  
  // Perform WiFi scan every 2 seconds
  if (currentTime - lastScanTime >= scanInterval) {
    lastScanTime = currentTime;

    // Scan for WiFi networks
    int numNetworks = WiFi.scanNetworks();
    bool targetFound = false;

    // Loop through available networks and find target network
    for (int i = 0; i < numNetworks; ++i) {
      if (WiFi.SSID(i) == targetSSID) {
        targetFound = true;
        int currentRSSI = WiFi.RSSI(i);

        // Print the current RSSI value
        Serial.print("Current RSSI for ");
        Serial.print(targetSSID);
        Serial.print(": ");
        Serial.println(currentRSSI);

        // Check for significant change in RSSI (motion detection)
        if (abs(currentRSSI - previousRSSI) > rssiThreshold) {
          Serial.println("Motion detected!");
        } else {
          Serial.println("No motion detected.");
        }

        // Update previous RSSI
        previousRSSI = currentRSSI;
        break;
      }
    }

    // If target network is not found, print a message
    if (!targetFound) {
      Serial.println("Target network not found.");
    }
  }
}
