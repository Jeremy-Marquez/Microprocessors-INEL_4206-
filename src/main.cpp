#include <WiFi.h>
#include <HTTPClient.h>
#include <string.h>

#define LED 2

const char* ssid = "Jeremy's Galaxy S22 Ultra";
const char* password = "mqwa9478";
const char* serverName = "http://34.198.194.143:1880/UpdateGauge";
const int sensor = 35;

//instantiate time to manage counter
unsigned long timeManager = 0;

//clock count in miliseconds (will use millis method)
unsigned long delayT = 5000;

void setup() {
  Serial.begin(115200);

  pinMode(LED,OUTPUT);
  pinMode(sensor, INPUT);

  WiFi.begin(ssid, password);
  while(WiFi.status() != WL_CONNECTED) {
    digitalWrite(LED,HIGH);
    delay(500);
  }
}

void loop() {

  if ((millis() - timeManager) > delayT) {
    //Check connection
    if(WiFi.status()== WL_CONNECTED){
      digitalWrite(LED,LOW);
      WiFiClient client;
      HTTPClient http;
    
      http.begin(client, serverName);
      
      http.addHeader("Content-Type", "application/x-www-form-urlencoded");

      // Data from temp sensor TO DO
      String httpRequestData = "value=";
      httpRequestData.concat(85.6/*analogRead(sensor)*/);         
    

      http.POST(httpRequestData);
      
      http.end();
    }
    else{
      WiFi.begin(ssid, password);
      while(WiFi.status() != WL_CONNECTED) {
      digitalWrite(LED,HIGH);
      delay(500);
      }
    }
    timeManager = millis();
  }
}