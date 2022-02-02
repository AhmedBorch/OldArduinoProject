#include <ESP8266WiFi.h>
#include <FirebaseArduino.h>
#define firebaseURl "mycar-38687.firebaseio.com"
#define authCode "xyFSJnTVnI39SRc8vmX7fXXI2PMlNfxzkrpqR0Fb"
#define wifiName "MENTORNATIONS1"
#define wifiPass "IOT4YOUTH"
#include <SoftwareSerial.h>


 int state ;
void setupFirebase() {

  Firebase.begin(firebaseURl, authCode);
 
 
}


void setupWifi() {

  WiFi.begin(wifiName, wifiPass);
  Serial.println("Hey i'm connecting...");
  while (WiFi.status() != WL_CONNECTED) {
    Serial.println(".");
    delay(500);
  }
  Serial.println();
  Serial.println("I'm connected and my IP address: ");
  Serial.println(WiFi.localIP());
}


 
 void setup() {
 
  Serial.begin(115200);

  setupWifi();
  setupFirebase();

}

void getData(){
String path ="Alarm";
if (Serial.available())
{
  int val = Serial.parseInt();
  if (val==1){
      Firebase.set("Alarm","Shock");
  }
  else{
    Firebase.set("Alarm","noShock");
  }

}
}


void loop() {
 
  getData();
}
 

