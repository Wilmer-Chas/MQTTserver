#ifndef CONFIG_H
#define CONFIG_H

#include <PulseSensorPlayground.h> // library that probably needs to be added
#include "DHT.h" // this might be bad, refactor it later?
// #include <TinyGPS++.h> // this is likely a terrible idea 

class TinyGPSPlus; // forward declare TinyGPS++.

// MQTT Broker details
#include <WiFiS3.h>
#include <PubSubClient.h>

extern const char* mqtt_server;
extern const int mqtt_port;
extern const char* mqtt_topic;
extern const char* mqtt_user;
extern const char* mqtt_pass;

extern WiFiClient wifiClient;
extern PubSubClient mqttClient;

// temperature STUFF
extern int temperaturePin; // Analog pin A0
#define DHTTYPE DHT11

// Gas stuff
extern const int mq2Pin;   // Pin where the analog output of the MQ-2 is connected

// Wifi part
extern const char* ssid;
extern const char* password;
extern const char* server; // IP or domain
extern const int port;
extern const bool useSSL; 


// sound sensor stuff
extern int soundPin;
extern const int sampleWindow;
extern unsigned int sample;

// GPS Sensor
extern const int RXPin; // Serial RX pin
extern const int TXPin; // Serial TX pin
extern const uint32_t GPSBaud; // Baud rate for GPS module
extern TinyGPSPlus gps; // TinyGPSPlus object

// pulse Sensor
extern const int OUTPUT_TYPE; // or PROCESSING_VISUALIZER
extern const int PULSE_INPUT;
extern const int PULSE_BLINK;
extern const int PULSE_FADE;
extern const int THRESHOLD;
extern PulseSensorPlayground pulseSensor;

// Power pins
extern const int soundSensorPowerPin;
extern const int temperatureSensorPowerPin;
extern const int airSensorPowerPin;
extern const int gpsSensorPowerPin;

#endif