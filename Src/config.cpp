#include <Arduino.h> // this might be a bad idea
#include <config.h>
#include <WiFiS3.h>
#include <TinyGPS++.h>


// MQTT Broker details
const char* mqtt_server = "broker.hivemq.com"; // Not using local broker
const int mqtt_port = 1883;
const char* mqtt_topic = "myname/project1/sensor1";     // Change as needed
// Optional: MQTT credentials
const char* mqtt_user = "";
const char* mqtt_pass = "";

WiFiClient wifiClient;
PubSubClient mqttClient(wifiClient);



// gas stuff
const int mq2Pin = A1;   // Pin where the analog output of the MQ-2 is connected

// Wifi part
const char* ssid = "Tele2_e3476a"; // "Chas Academy"
const char* password = "kzn4i2n3"; // "EverythingLouderThanEverythingElse"
const char* server = "chas-challenge.vercel.app"; // IP or domain : use the command (ipconfig) in command terminal to find out what it is // "chas-challenge.vercel.app"
const int port = 443; // 443
extern const bool useSSL = true; // specifies if it uses HTTP (local host) or HTTPS, use true for HTTPS and false for HTTP 

// sound sensor stuff
int soundPin = A3;
const int sampleWindow = 100;
unsigned int sample;


// pulse Sensor
const int OUTPUT_TYPE = SERIAL_PLOTTER; // or PROCESSING_VISUALIZER
const int PULSE_INPUT = A4;
const int PULSE_BLINK = LED_BUILTIN;
const int PULSE_FADE = 5;
const int THRESHOLD = 650;
PulseSensorPlayground pulseSensor;


// temperature sensor
int temperaturePin = A0; // Analog pin A0

//GPS Sensor
const int RXPin = 3;
const int TXPin = 4;
const uint32_t GPSBaud = 9600;

TinyGPSPlus gps;

// power pins
const int soundSensorPowerPin = 6;
const int temperatureSensorPowerPin = 7;
const int airSensorPowerPin = 8;
const int gpsSensorPowerPin = 9;