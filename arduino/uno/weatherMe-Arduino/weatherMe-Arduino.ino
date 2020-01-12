/* How to use the DHT-22 sensor with Arduino uno
   Temperature and humidity sensor
   More info: http://www.ardumotive.com/how-to-use-dht-22-sensor-en.html
   Dev: Michalis Vasilakis // Date: 1/7/2015 // www.ardumotive.com */
#include "DHT.h"
#define DHTPIN 2     // Digital pin connected to the DHT sensor
#define DHTTYPE DHT22   // DHT 22  (AM2302), AM2321
//Libraries
#include <Wire.h>
#include <SPI.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BMP280.h>
//Constants
const size_t READ_BUF_SIZE = 64;
#define BMP_SCK 13
#define BMP_MISO 12
#define BMP_MOSI 11
#define BMP_CS 10
#define forcase 1013.25
//Variables
char readBuf[READ_BUF_SIZE];
size_t readBufOffset = 0;
//Objects
void processBuffer();
DHT dht(DHTPIN, DHTTYPE);
Adafruit_BMP280 bme; // I2C
void setup()
{
  Serial.begin(9600);
  dht.begin();
  if (!bme.begin()) {
    Serial.println("Could not find a valid BMP280 sensor, check wiring!");
    while (1);
  }
}
void loop()
{
  float h = dht.readHumidity();
  // Read temperature as Celsius (the default)
  float t = dht.readTemperature();
  // Check if any reads failed and exit early (to try again).
  if (isnan(h) || isnan(t)) {
    Serial.println(F("Failed to read from DHT sensor!"));
    return;
  }
  // Compute heat index in Celsius (isFahreheit = false)
  float hic = dht.computeHeatIndex(t, h, false);
//  if(Serial.available()){
//      input = Serial.read();
//      Serial.println(input);
//      if(input == 'h') Serial.println(h);
//      else if(input == 't') Serial.println(t);
//      else if(input == 'i') Serial.println(hic);
//      else if(input == 'b') Serial.println(bme.readPressure());
//      else if(input == 'a') Serial.println(bme.readAltitude(forcase));
//      delay(100);
//    }  
//      Serial.println(h);
//      Serial.println(t);
//      Serial.println(hic);
//      Serial.println(bme.readPressure());
//      Serial.println(bme.readAltitude(forcase));
//      delay(3000);
while(Serial.available()){
  if(readBufOffset < READ_BUF_SIZE){
    char c = Serial.read();
    if(c != '\n'){
      readBuf[readBufOffset++] = c;
    }
    else{
      readBuf[readBufOffset] = 0;
      processBuffer(h, t, hic, &bme);
      readBufOffset = 0;
    }
  }
  else{
    readBufOffset = 0;
  }
}
}

void processBuffer(float h, float t, float hic, Adafruit_BMP280* bme){
  int input = atoi(readBuf);
  if(input == 0) Serial.println(bme->readPressure());
  else if(input == 1) Serial.println(t);
  else if(input == 2) Serial.println(hic);
  else if(input == 3)Serial.println(h);
  else if(input == 4) Serial.println(bme->readAltitude(forcase));
}
