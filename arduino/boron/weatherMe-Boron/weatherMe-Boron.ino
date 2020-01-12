#include "Particle.h"
const unsigned long SEND_INTERVAL_MS = 2000;
const size_t READ_BUF_SIZE = 64;

String barometer;
String thermometer;
String hydrometer;
String feelslike;
String altitude;
int counter = 0;
unsigned long lastSend = 0;
char readBuf[READ_BUF_SIZE];
size_t readBufOffset = 0;

void processBuffer();

void setup() {
    Particle.variable("pressure",barometer);
    Particle.variable("temperature",thermometer);
    Particle.variable("humidity",hydrometer);
    Particle.variable("feelslike",feelslike);
    Particle.variable("altitude",altitude);
    Particle.function("Fetch",getData);
    Serial.begin(9600);
    Serial1.begin(9600);
}

void loop() {
}

void getAll(){
    getData("pressure");
}

void serialFlush(){
  while(Serial.available() > 0) {
    char t = Serial.read();
  }
}

float getData(String param){
    if(param == "pressure"){
        Serial1.println(0);
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
        Serial1.println(3);
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
    else if(param == "feelslike"){
        Serial1.println(2);
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
        else if(param == "altitude"){
        Serial1.println(4);
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

    serialFlush();
    return (float)atof(readBuf);
}
   

void processBuffer(String param) {
	Serial.printlnf("Received from Arduino: %s", readBuf);
	if(param == "pressure"){
	    barometer = readBuf;
	}
	else if(param == "temperature"){
	    thermometer = readBuf;
	}
	else if(param == "humidity"){
	    hydrometer = readBuf;
	}
	else if(param == "altitude"){
	    altitude = readBuf;
	}
	else if(param == "feelslike"){
	    feelslike = readBuf;
	}
}
