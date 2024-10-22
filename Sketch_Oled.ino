#include<Adafruit_GFX.h>
#include<Adafruit_SSD1306.h>
#include<Wire.h>


Adafruit_SSD1306 display(128,64,&Wire,-1);

void setup() {
Serial.begin(9600);

display.begin(SSD1306_SWITCHCAPVCC,0X3C);
}

display.setTextSize(3,2);
display.setTextColor(WHITE);
display.setCursor(24,48);
display.print("Halo Saka");
display.display();
display.clearDisplay();
delay(10);
}

void loop() {
