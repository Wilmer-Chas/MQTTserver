#include "config.h"
#include "router.h"
#include <WiFiS3.h>
#include <microControllerID.h>
#include "MQTT.h"





String sensorValueToString(void* sensorValue, SensorType type) {
  switch (type) {
    case SENSOR_INT:
      return String(*((int*)sensorValue));
    case SENSOR_FLOAT:
      return String(*((float*)sensorValue), 2);
    case SENSOR_STRING:
      return String((char*)sensorValue);
    default:
      Serial.println("Unsupported sensor type.");
      return "";
  }
}

// builds the json package to be sent to backend
String buildJsonPayload(const String& deviceId,
                        const char* key1, const String& value1,
                        const char* key2 = nullptr, const String& value2 = "",
                        const char* key3 = nullptr, const String& value3 = "") {
  String json = "{";

  // Always include device_id
  json += "\"device_id\": \"" + deviceId + "\",";

  // Always include first key-value pair
  json += "\"" + String(key1) + "\": " + value1;

  // Optionally include second key-value pair
  if (key2 != nullptr && value2.length() > 0) {
    json += ", \"" + String(key2) + "\": " + value2;
  }
  // Optionally include third key-value pair
  if (key3 != nullptr && value3.length() > 0) {
    json += ", \"" + String(key3) + "\": " + value3;
  }

  json += "}";

  return json;
}

void publishToMQTT(const String& topic, const String& json) {
  const char* finalTopic = topic.length() > 0 ? topic.c_str() : mqtt_topic;

  if (!mqttClient.connected()) {
    tryReconnectMQTT();
  }

  mqttClient.loop(); // keep connection alive

  bool success = mqttClient.publish(finalTopic, json.c_str());
  if (success) {
    Serial.print("Published to MQTT topic '");
    Serial.print(finalTopic);
    Serial.print("': ");
    Serial.println(json);
  } else {
    Serial.println("Failed to publish MQTT message");
  }
}



void sendSensorDataToMQTT(const char* topic,
                          const char* key1, void* sensorValue1, SensorType type1,
                          const char* key2 = nullptr, const String& value2 = "",
                          const char* key3 = nullptr, const String& value3 = "")
{                 
  String value1 = sensorValueToString(sensorValue1, type1);

  if (value1.length() == 0) return;

  String deviceId = readDeviceID();
  String json = buildJsonPayload(deviceId, key1, value1, key2, value2, key3, value3);

  publishToMQTT(topic, json);
}