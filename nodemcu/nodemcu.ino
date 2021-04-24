#include <ESP8266WiFi.h>
#include <FirebaseArduino.h>
#define FIREBASE_HOST "indsafe-377e6-default-rtdb.firebaseio.com"
#define FIREBASE_AUTH "W9lg4smBsD1hsxU3N4INYxlmvt2sqPX50X9Q6phS"
#define WIFI_SSID "Redmi"
#define WIFI_PASSWORD "ashu9819"

int fd=0;
float td=0.0;
int gd = 0;
void setup() {
  Serial.begin(9600);
  pinMode(D5,INPUT);//light
  pinMode(D6,INPUT);//temp
  pinMode(D7,INPUT);//gas
  
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  Serial.print("connecting");
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(500);
  }
  Serial.println();
  Serial.print("connected: ");
  Serial.println(WiFi.localIP());
  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
  Serial.print("connected firebase");
}

void loop() {
  fd = digitalRead(D5);
  Firebase.setInt("Light_value",fd);

  td = analogRead(D6);
  Firebase.setFloat("Temp_value",td);

  gd = analogRead(D7);
  Firebase.setFloat("Gas_value",gd);
  
  Serial.println(fd);
  Serial.println(td);
  Serial.println(gd);
}
