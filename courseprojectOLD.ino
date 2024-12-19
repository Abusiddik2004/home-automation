#include <Servo.h>
#include <LiquidCrystal.h>

const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

#define light1 2
#define light2 3
#define fan1 4
#define water 5
Servo s1;
Servo s2;
int pos;

void setup() {
  Serial.begin(9600);
  pinMode(light1,OUTPUT);
  pinMode(light2,OUTPUT);
  pinMode(fan1,OUTPUT);
  pinMode(water,OUTPUT);
  s1.attach(9);
  int pos;

  lcd.begin(16, 2);
 
  lcd.print("hello, world!");
  
}

void loop() 
{
  if(Serial.available()>0)
  {
    char command=Serial.read();
    switch(command)
    {
      case 'a' :digitalWrite(light1,HIGH);
      break;
      case 'b' :digitalWrite(light1,LOW);
      break;
      case 'c' :digitalWrite(light2,HIGH);
      break;
      case 'd' :digitalWrite(light2,LOW);
      break;
      case 'e' :digitalWrite(fan1,HIGH);
      break;
      case 'f' :digitalWrite(fan1,LOW);
      break;
      case 'g' :for (pos=0;pos<=360;pos+=1){
                s1.write(pos);
                delay(10);
      }
      break;
      case 'h' :for (pos=360;pos>=0;pos-=1){
                s1.write(pos);
                delay(10);
      }
      break;
      case 'i' :for (pos=0;pos<=90;pos+=1){
                s1.write(pos);
                delay(10);
      }
      break;
      case 'j' :for (pos=90;pos>=0;pos-=1){
                s1.write(pos);
                delay(10);
      }
      case 'k' :digitalWrite(water,HIGH);
      break;
      case 'l' :digitalWrite(water,LOW);
      break;
      
      }
      Serial.println(command);
    }

if light1==HIGH:
lcd.noBlink();
  delay(3000);

lcd.blink();
  delay(3000);

}