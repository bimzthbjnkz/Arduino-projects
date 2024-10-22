#define BLYNK_PRINT Serial
#include<WiFi.h>
#include<WiFiClient.h>
#include<BlynkSimpleEsp32.h>

char auth[]= "gQeWx10E6L8fzMmlP40hwHezmWHozQ1w";
char pass[]= "87654321";
char ssid[]= "Test";

void setup(){
  Serial.begin(9600);
  Blynk.begin(auth,ssid,pass,"blynk.cloud",80);
  
}

void loop(){
  Blynk.run();
}
