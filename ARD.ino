#include <SoftwareSerial.h>
#define trigPin 6
#define echoPin 7
#define trigPin1 12
#define echoPin1 11
#define tonepin 10
SoftwareSerial esperial(2, 3); // RX | TX 

int shockPin = 4;
bool  shockVal=LOW ;

int duration, distance,duration1, distance1;
 
void setup() {
  esperial.begin(115200);
 Serial.begin(9600);

  pinMode (shockPin, INPUT) ;
 
  
 pinMode(trigPin, OUTPUT);  
 pinMode(echoPin, INPUT);
 
pinMode(trigPin1, OUTPUT);  
 pinMode(echoPin1, INPUT);
 

}
void loop() {
 
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
    
  digitalWrite(trigPin1, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin1, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin1, LOW);
  
  // Measure the response from the HC-SR04 Echo Pin
 
  duration = pulseIn(echoPin, HIGH);
    duration1 = pulseIn(echoPin1, HIGH);

  
  // Determine distance from duration
  // Use 343 metres per second as speed of sound
  
  distance = (duration / 2) * 0.0343;
    distance1 = (duration1 / 2) * 0.0343;

  
   
  
  shockVal = digitalRead(shockPin) ;
 
   if ((shockVal == HIGH)&&( (distance < 15) ||   (distance < 15)) ) 
   { 
 esperial.println(1);
   delay(500);
  } else {
 esperial.println(0);
       delay(500);
  } 

  Serial.println(distance);
if((distance <10 )&&(distance > 0) ||  ((distance1 < 10)&&(distance1 > 0)))
{
  tone(tonepin, 1500, 500);
     noTone(tonepin) ;
     
}
else if ((distance < 30)&&(distance > 10) /*||  ((distance1 < 30)&&(distance1 > 10))*/)
{
  tone(tonepin, 1000, 1000);
     delay(200);
     noTone(tonepin) ;
     }
else if((distance <70 )&&(distance > 30) ||  ((distance1 < 70)&&(distance1 > 30)))
{
  
  tone(tonepin,2000 , 500);
  
  noTone(tonepin) ;
     
}else
{ noTone(tonepin);

}}



