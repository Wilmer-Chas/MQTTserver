#include <config.h>
#include "MQTT.h"
#include <Arduino.h>
#include <PubSubClient.h>

void setupMQTT() {
  mqttClient.setServer(mqtt_server, mqtt_port);
}

unsigned long lastReconnectAttempt = 0;
const unsigned long reconnectInterval = 5000; // try every 5 seconds

void tryReconnectMQTT() {
  if (mqttClient.connected()) return; // already connected

  unsigned long now = millis();
  if (now - lastReconnectAttempt > reconnectInterval) {
    lastReconnectAttempt = now;
    Serial.print("Attempting MQTT connection...");
    if (mqttClient.connect("ArduinoClient", mqtt_user, mqtt_pass)) {
      Serial.println("connected to MQTT");
      // Subscribe if needed here
    } else {
      Serial.print("failed, rc=");
      Serial.println(mqttClient.state());
      Serial.println(" will retry...");
    }
  }
}

