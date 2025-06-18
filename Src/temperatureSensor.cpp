#include "temperatureSensor.h"
#include "DHT.h"
#include "config.h"

DHT dht(temperaturePin, DHTTYPE);

float temperatureCelsius = 0.0;

int readTemperatureSensor()
{
  temperatureCelsius = dht.readTemperature();

  if (isnan(temperatureCelsius)) {
    Serial.println("Failed to read temperature from DHT11 sensor!");
  } else {
    Serial.print("Temperature in Celsius: ");
    Serial.println(temperatureCelsius);
    return temperatureCelsius;
  }
}