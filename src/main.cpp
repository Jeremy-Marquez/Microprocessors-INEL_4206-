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

      // String to concat data from temp sensor
      String httpRequestData = "value=";

    //==>Calculations done to calibrate the sensor (LTM84)<==
    /*
    y-y1 = m(x-x1) + b
    v=mT + b
    T=(v-b)/m

    m=-5.58 mV
    b= 1.038
    v = analog(read)

    T = (analogRead(sensor) - 1.038)/-0.00558

    887mV = -5.58(27) + b ==> b = 887mV + 5.58m(27) ==> 1.03766 ==> 1.038
    760mV = -5.58(50) + b ==> b = 760mV + 5.58m(50) ==> 1.039 ==> 1.038
    */

      httpRequestData.concat(((analogReadMilliVolts(sensor)* 0.001)- 1.038)/-0.00558);         
    

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