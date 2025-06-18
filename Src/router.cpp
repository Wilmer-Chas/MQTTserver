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

void publishToMQTT(const String& json) {
  if (!mqttClient.connected()) {
    tryReconnectMQTT();
  }
  mqttClient.loop(); // keep connection alive

  bool success = mqttClient.publish(mqtt_topic, json.c_str());
  if (success) {
    Serial.println("Published to MQTT: " + json);
  } else {
    Serial.println("Failed to publish MQTT message");
  }
}


/**
 * @brief Sends sensor data to a backend server over Wi-Fi.
 *
 * Constructs a JSON payload that includes a required sensor key-value pair,
 * the device ID, and optionally a second key-value pair.
 *
 * @param sensorValue Pointer to the sensor value (int, float, or string).
 * @param type Type of the sensor value (SENSOR_INT, SENSOR_FLOAT, SENSOR_STRING).
 * @param key1 The key name for the primary sensor value.
 * @param path The API endpoint path to send the data to.
 * @param customHost Optional. Custom hostname or IP for the backend server (defaults to `server`).
 * @param key2 Optional. The key name for a secondary sensor value (e.g., longitude).
 * @param sensorValue2 Optional. The stringified value for the secondary key.
 */
void sendSensorData(void* sensorValue,
                    SensorType type,
                    const char* key1,
                    const char* path,
                    const char* customHost,
                    const char* key2,
                    const String& sensorValue2,
                    const char* key3,
                    const String& sensorValue3)
{
  const char* hostToUse = (customHost != nullptr) ? customHost : server;
  String value1 = sensorValueToString(sensorValue, type);

  if (value1.length() == 0) return;

  String deviceId = readDeviceID();
  String json = buildJsonPayload(deviceId, key1, value1, key2, sensorValue2, key3, sensorValue3);

  publishToMQTT(json);
}