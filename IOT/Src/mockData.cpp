#include <Arduino.h>
#include "mockData.h"

String getMockSensorData() {
  float temp = random(200, 350) / 10.0;   // 20.0 to 35.0 °C
  float hum = random(300, 700) / 10.0;    // 30.0% to 70.0%
  
  String json = "{";
  json += "\"temperature\": " + String(temp, 1) + ",";
  json += "\"humidity\": " + String(hum, 1);
  json += "}";
  
  return json;
}