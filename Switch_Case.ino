#define led01  13
#define led02 12
#define button1 8
#define button2 9

void setup() {
pinMode(led01, OUTPUT);
pinMode(led02, OUTPUT);
pinMode(button1, INPUT_PULLUP);
pinMode(button2, INPUT_PULLUP);
}
void loop() {

int x = 0;
int hasilValue1 = digitalRead(button1);
int hasilValue2 = digitalRead(button2);
if(hasilValue1 == 1){
  x++;
}
if(hasilValue2 == 1){
  x--;
}
switch(x){
  case 1:
  digitalWrite(led01, HIGH);
  digitalWrite(led02, LOW);
  break;
  case 2:
  digitalWrite(led01, LOW);
  digitalWrite(led02, HIGH);
  break;
}
}