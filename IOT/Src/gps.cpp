
#include "config.h" // Include the config file for global variables
#include "gps.h"
#include <TinyGPS++.h>



GPSCoordinates getGPSCoordinates(Stream& gpsStream) {
    GPSCoordinates result = { false, 0.0f, 0.0f };

    unsigned long start = millis();
    while (millis() - start < 2000) {
        while (gpsStream.available() > 0) {
            gps.encode(gpsStream.read());
        }

        if (gps.location.isValid()) {
            result.valid = true;
            result.latitude = gps.location.lat();
            result.longitude = gps.location.lng();
            return result;
        }
    }

    return result;
}


float readLatitudeGpsValue(GPSCoordinates gpsCoordinates)
{
    float latitude = gpsCoordinates.latitude;
    return latitude;
}

float readLongitudeGpsValue(GPSCoordinates gpsCoordinates)
{
     float longitude = gpsCoordinates.longitude;
     return longitude;
}

float randomGPSValue()
{
    int randomValue = random(0, 100); // Generates a random number between 0 and 99
    return randomValue;
}