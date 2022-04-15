#define sensorPin 2 
#include <Servo.h>
 
int ledPin = 13; 
Servo myservo; 
int pos = 0;  
 
void setup() {
  myservo.attach(9);
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);  
  pinMode(sensorPin, INPUT);
}
 
void loop() {
  int senseValue = digitalRead(sensorPin);
  pos=0;
  if (senseValue == HIGH){
    
    digitalWrite(ledPin, HIGH);
    Serial.println("TOUCHED");
     for (pos = 0; pos <= 140; pos += 5) { 
    myservo.write(pos);              
    }
    delay(1000);
  }
    
  else {
    digitalWrite(ledPin,LOW);
    Serial.println("not touched");
    if(senseValue == LOW){
      for (pos = 140; pos >= 70; pos -= 5) { 
    myservo.write(pos);              
                          
  }      
    }
  } 
  delay(1000);
  
}
