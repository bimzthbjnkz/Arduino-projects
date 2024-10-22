#include<Servo.h>
Servo horizontal;
Servo vertical;
const int serH = 10;
const int serV = 11;

const int ldrLeftTop = 3; //ldr1
const int ldrRightTop = 4; //ldr2
const int ldrLeftBottom = 5; //ldr3
const int ldrRightBottom = 6; //ldr4

int ldr1; //Value
int ldr2;
int ldr3;
int ldr4;

void setup() {
Serial.begin(9600);
horizontal.attach(serH);
vertical.attach(serV);
pinMode(ldrLeftTop, INPUT );
pinMode(ldrLeftTop, INPUT );
pinMode(ldrLeftTop, INPUT );
pinMode(ldrLeftTop, INPUT );
delay(200);
}


void loop() {


int i=0;

ldr1 = analogRead(ldrLeftTop);
ldr2 = analogRead(ldrRightTop);
ldr3 = analogRead(ldrLeftBottom);
ldr4 = analogRead(ldrRightBottom);

if(ldr1 < ldr3 && ldr2 < ldr4){
  vertical.write(i++);
  if(i > 60){
    i--
  }
}
else if(ldr1 > ldr3 && ldr2 > ldr4){
  vertical.write(i--);
  if(i < 30){
    i++
  }
}
else if(ldr1 < ldr2 && ldr3 <ldr4){
  horizontal.write(i++);
  if(i > 170){
    i--
  }
}
else if(ldr2 < ldr1 && ldr3 < ldr4){
  horizontal.write(-60);
}
}
