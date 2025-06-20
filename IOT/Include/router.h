#ifndef ROUTER_H
#define ROUTER_H


enum SensorType {
    SENSOR_INT,
    SENSOR_FLOAT,
    SENSOR_STRING
};

void publishToMQTT(const String& topic, const String& json);

/**
 * @brief Sends sensor data as a JSON payload to an MQTT topic.
 *
 * This function formats one or more sensor key-value pairs (with types) into a JSON object,
 * attaches the device ID, and publishes the result to a given MQTT topic. If the topic is null
 * or empty, it defaults to a predefined global `mqtt_topic`.
 *
 * @param topic        The MQTT topic to publish to. If null or empty, a default topic is used.
 * @param key1         The key name for the primary sensor value.
 * @param sensorValue1 A pointer to the primary sensor value (int, float, or string).
 * @param type1        The type of the primary sensor value (e.g., SENSOR_INT, SENSOR_FLOAT, SENSOR_STRING).
 * @param key2         (Optional) The key name for a secondary sensor value.
 * @param value2       (Optional) The stringified value for the secondary key.
 * @param key3         (Optional) The key name for a third sensor value.
 * @param value3       (Optional) The stringified value for the third key.
 *
 * @note The device ID is automatically retrieved and included in the payload as "device_id".
 *
 * @see sensorValueToString()
 * @see buildJsonPayload()
 * @see publishToMQTT()
 */
void sendSensorDataToMQTT(const char* topic,
                          const char* key1, void* sensorValue1, SensorType type1,
                          const char* key2 = nullptr, const String& value2 = "",
                          const char* key3 = nullptr, const String& value3 = "");

#endif
