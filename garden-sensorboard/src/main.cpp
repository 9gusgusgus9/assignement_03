#include <Arduino.h>
#include <WiFi.h>
#include <HTTPClient.h>

#include "device/DeviceBuilder.h"
#include "components/actuator/led/Led.h"
#include "components/sensor/photoresistor/Photoresistor.h"
#include "components/sensor/thermometer/Thermometer.h"

#define LED_PIN 20
#define PHOTO_PIN 5
#define TMP_PIN 7

Led* led = new Led(LED_PIN);
Photoresistor* photoresistor = new Photoresistor(PHOTO_PIN);
Thermometer* tmp = new Thermometer(TMP_PIN);
DeviceBuilder* dev = new DeviceBuilder();
const char* ssid = "iPhone di Gustavo";
const char* password = "qwertyui";
String serverPath = "http://172.20.10.4:5000";
String getLight = "/lightstatus";
String getTemperature = "/temperaturestatus";
unsigned long timeOfLastRequest = 0;

void connectToWifi(const char* ssid, const char* password){
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);
  Serial.println("Connecting to WiFi..");
  while(WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.print("WiFi connected at IP: ");
  Serial.println(WiFi.localIP());
}

void getStatus(String str){
	HTTPClient http;
	http.begin((serverPath + str).c_str());
	int httpCode = http.GET();
	if(httpCode > 0) {
		String payload = http.getString();
		Serial.println(payload);
	}else{
		Serial.println("Error on HTTP request");
	}
	http.end();
}

int sendData(String type, float value){  
   	HTTPClient http;
   	http.begin(serverPath + "/" + type);      
   	http.addHeader("Content-Type", "application/json");
   	int retCode = http.POST("{\"value\":\"" + String(value) + "\"}");
	if(retCode > 0) {
		String payload = http.getString();
		Serial.println(payload);
	}else{
		Serial.println("Error on HTTP request");
	}
   	http.end();
   	return retCode;
}

void setup() {
	Serial.begin(115200);
  	connectToWifi(ssid, password);
}

void loop() {
	if(millis() - timeOfLastRequest > 10000){
		tmp->compute();
		photoresistor->compute();
		if(WiFi.status() == WL_CONNECTED){
			sendData("light", photoresistor->getLight());
			sendData("temperature", tmp->getTemperature());
			timeOfLastRequest = millis();
		} else {
			Serial.println("WiFi Disconnected... Reconnecting");
			connectToWifi(ssid, password);
		}
	}

}
