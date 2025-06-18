#include <Arduino.h>
#include "gasSensor.h"
#include "wifiHandler.h"
#include "config.h"
#include "router.h"
#include "soundSensor.h"
#include "pulseSensor.h"
#include "temperatureSensor.h"
#include <OffOnSwitch.h>
#include <gps.h>

#define gpsSerial Serial1  // or Serial2, etc.

void switchSensor(Sensor sensorType)
{
    switch (sensorType) 
    {
    case TEMPERATURESENSOR: 
    {
        digitalWrite(temperatureSensorPowerPin, HIGH);
        int temperatureLevel = readTemperatureSensor();
        Serial.println("Temperature Sensor State Reached");
        Serial.println(temperatureLevel);
        sendSensorData(&temperatureLevel, SENSOR_INT, "temperatureValue", "/api/temp");
        break;
    }
    case AIRSENSOR: 
    {
        digitalWrite(airSensorPowerPin, HIGH);
        int gasLevel = readGasSensor();           // Read the gas sensor value
        Serial.println("gas Sensor State Reached");
        Serial.println(gasLevel);
        sendSensorData(&gasLevel, SENSOR_INT, "smoke","/api/airQuality", nullptr, "propane", String(0), "c02", String(0));                 // Send gas data over Wi-Fi
        break;
    }
    case SOUNDSENSOR: 
    {
        digitalWrite(soundSensorPowerPin, HIGH);
        float soundLevel = readSoundSensor();
        Serial.println("sound Sensor State Reached");
        Serial.println(soundLevel);
        sendSensorData(&soundLevel, SENSOR_FLOAT, "soundValue", "/api/sound"); 
        break;
    }
    case GPSSENSOR: 
    {
        // GPSCoordinates coords = getGPSCoordinates(gpsSerial);
        // float longitudeLevel = readLongitudeGpsValue(coords);
        // float latitudeLevel = readLatitudeGpsValue(coords);
        digitalWrite(gpsSensorPowerPin, HIGH);
        float longitudeLevel = randomGPSValue();
        float latitudeLevel = randomGPSValue();
        Serial.println("Gps Sensor State Reached");
        Serial.println(longitudeLevel);
        Serial.println(latitudeLevel);
        sendSensorData(&longitudeLevel, SENSOR_FLOAT, "longitudeValue", "/api/gps", 
               nullptr, "latitudeValue", String(latitudeLevel, 6)); 
        break;
    }
    default:
        Serial.println("Unsupported sensor");
        break;
    }
}


void turnOffSensors()
{
    digitalWrite(temperatureSensorPowerPin, LOW);
    digitalWrite(airSensorPowerPin, LOW);
    digitalWrite(soundSensorPowerPin, LOW);
    digitalWrite(gpsSensorPowerPin, LOW);
}

int stateSensorCounter = 0; // global variable
Sensor sensorList[] = {TEMPERATURESENSOR, AIRSENSOR, SOUNDSENSOR, GPSSENSOR};

// gets amount of sensors
int getTotalSensors() {
    return sizeof(sensorList) / sizeof(sensorList[0]);
}

// cycles through the sensors
void switchSensorState() {
    turnOffSensors();
    switchSensor(sensorList[stateSensorCounter]);
    stateSensorCounter = (stateSensorCounter + 1) % getTotalSensors(); // Loop back to 0 through modolus
}