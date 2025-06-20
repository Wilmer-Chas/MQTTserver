#include <Arduino.h>
#include "gasSensor.h"
#include "wifiHandler.h"
#include "config.h"
#include "router.h"
#include "soundSensor.h"
#include "pulseSensor.h"
#include "temperatureSensor.h"
#include <OffOnSwitch.h>
#include <microControllerID.h>
#include "MQTT.h"
#include <PubSubClient.h>
#include "mockData.h"

unsigned long lastSendTime = 0;
const unsigned long sendInterval = 5000; // 5 seconds

void setup() {
  Serial.begin(9600);
  Serial.println("Start up reached");
  pinMode(LED_BUILTIN, OUTPUT);
  connectToWiFi(10000); // connect once at boot

  setupMQTT();          // Initialize MQTT client config
  tryReconnectMQTT();      // Connect to broker initially
}

void loop() {

  mqttClient.loop();
  tryReconnectMQTT();

  unsigned long currentTime = millis();
  if (currentTime - lastSendTime >= sendInterval) {
    lastSendTime = currentTime;
    
    String jsonMockData = getMockSensorData();
    Serial.println("Publishing: " + jsonMockData);
    publishToMQTT("myname/project1/sensor1", jsonMockData);

  }
}