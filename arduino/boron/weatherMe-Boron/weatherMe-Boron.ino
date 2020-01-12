#include "Particle.h"
const unsigned long SEND_INTERVAL_MS = 2000;
const size_t READ_BUF_SIZE = 64;

String barometer;
String thermometer;
String hydrometer;
String accelerometer;
String vibration;
String light;
int counter = 0;
unsigned long lastSend = 0;
char readBuf[READ_BUF_SIZE];
size_t readBufOffset = 0;

void processBuffer();

void setup() {
    Particle.variable("pressure",barometer);
    Particle.variable("temperature",thermometer);
    Particle.variable("humidity",hydrometer);
    Particle.variable("movement",accelerometer);
    Particle.variable("vibration",vibration);
    Particle.variable("light",light);
    Particle.function("Fetch",getData);
    Serial.begin(9600);
    Serial1.begin(9600);
}

void loop() {

//     if (millis() - lastSend >= SEND_INTERVAL_MS) {
//     lastSend = millis();

//    Serial1.printlnf("%d", ++counter);
//    Serial.printlnf("Sent to Arduiuno: %d", counter);
//  }

//  // Read data from serial
//  while(Serial1.available()) {
//    if (readBufOffset < READ_BUF_SIZE) {
//      char c = Serial1.read();
//      if (c != '\n') {
//        // Add character to buffer
//        readBuf[readBufOffset++] = c;
//      }
//      else {
//        // End of line character found, process line
//        readBuf[readBufOffset] = 0;
//        processBuffer();
//        readBufOffset = 0;
//      }
//    }
//    else {
//      Serial.println("readBuf overflow, emptying buffer");
//      readBufOffset = 0;
//    }
//  }
}

float getData(String param){
    if(param == "pressure"){
        Serial1.println(0);
        Serial.printlnf("Sent to Arduino: pressure (0)");
        while(Serial1.available()){
            if (readBufOffset < READ_BUF_SIZE) {
          char c = Serial1.read();
          if (c != '\n') {
            // Add character to buffer
            readBuf[readBufOffset++] = c;
      }
          else {
        // End of line character found, process line
            readBuf[readBufOffset] = 0;
            processBuffer(param);
            readBufOffset = 0;
      }
    }
        else {
          Serial.println("readBuf overflow, emptying buffer");
          readBufOffset = 0;
    }
         }
        
    }
    else if(param == "temperature"){
        Serial1.println(1);
        Serial.printlnf("Sent to Arduino: temperature(1)");
        while(Serial1.available()){
            if (readBufOffset < READ_BUF_SIZE) {
          char c = Serial1.read();
          if (c != '\n') {
            // Add character to buffer
            readBuf[readBufOffset++] = c;
      }
          else {
        // End of line character found, process line
            readBuf[readBufOffset] = 0;
            processBuffer(param);
            readBufOffset = 0;
      }
    }
        else {
          Serial.println("readBuf overflow, emptying buffer");
          readBufOffset = 0;
    }
         }
        
    }
    else if(param == "humidity"){
        Serial1.println(2);
        Serial.printlnf("Sent to Arduino: humidity (2)");
        while(Serial1.available()){
            if (readBufOffset < READ_BUF_SIZE) {
          char c = Serial1.read();
          if (c != '\n') {
            // Add character to buffer
            readBuf[readBufOffset++] = c;
      }
          else {
        // End of line character found, process line
            readBuf[readBufOffset] = 0;
            processBuffer(param);
            readBufOffset = 0;
      }
    }
        else {
          Serial.println("readBuf overflow, emptying buffer");
          readBufOffset = 0;
    }
         }
        
    }
    else if(param == "movement"){
        Serial1.println(3);
        Serial.printlnf("Sent to Arduino: movement (3)");
        while(Serial1.available()){
            if (readBufOffset < READ_BUF_SIZE) {
          char c = Serial1.read();
          if (c != '\n') {
            // Add character to buffer
            readBuf[readBufOffset++] = c;
      }
          else {
        // End of line character found, process line
            readBuf[readBufOffset] = 0;
            processBuffer(param);
            readBufOffset = 0;
      }
    }
        else {
          Serial.println("readBuf overflow, emptying buffer");
          readBufOffset = 0;
    }
         }
        
    }
        else if(param == "vibration"){
        Serial1.println(4);
        Serial.printlnf("Sent to Arduino: vibration (4)");
        while(Serial1.available()){
            if (readBufOffset < READ_BUF_SIZE) {
          char c = Serial1.read();
          if (c != '\n') {
            // Add character to buffer
            readBuf[readBufOffset++] = c;
      }
          else {
        // End of line character found, process line
            readBuf[readBufOffset] = 0;
            processBuffer(param);
            readBufOffset = 0;
      }
    }
        else {
          Serial.println("readBuf overflow, emptying buffer");
          readBufOffset = 0;
    }
         }
        
    }
    else if(param == "light"){
        Serial1.println(5);
        Serial.printlnf("Sent to Arduino: light (5)");
        while(Serial1.available()){
            if (readBufOffset < READ_BUF_SIZE) {
          char c = Serial1.read();
          if (c != '\n') {
            // Add character to buffer
            readBuf[readBufOffset++] = c;
      }
          else {
        // End of line character found, process line
            readBuf[readBufOffset] = 0;
            processBuffer(param);
            readBufOffset = 0;
      }
    }
        else {
          Serial.println("readBuf overflow, emptying buffer");
          readBufOffset = 0;
    }
         }
        
    }
    Serial.flush();
    return (float)atof(readBuf);
}

void processBuffer(String param) {

  if(param == "pressure"){
      barometer = readBuf;
  }
  else if(param == "temperature"){
      thermometer = readBuf;
  }
  else if(param == "humidity"){
      hydrometer = readBuf;
  }
  else if(param == "movement"){
      accelerometer = readBuf;
  }
  else if(param == "vibration"){
      vibration = readBuf;
  }
  else if(param == "light"){
      light = readBuf;
  }
}
