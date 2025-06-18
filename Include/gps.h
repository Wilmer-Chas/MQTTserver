#ifndef GPS_H
#define GPS_H

#include <Arduino.h> // Needed for Stream class

struct GPSCoordinates {
    bool valid;
    float latitude;
    float longitude;
};

// Accept a reference to any Stream (Serial, Serial1, SoftwareSerial, etc.)
GPSCoordinates getGPSCoordinates(Stream& gpsStream);
float readLatitudeGpsValue(GPSCoordinates gpsCoordinates);
float readLongitudeGpsValue(GPSCoordinates gpsCoordinates);
float randomGPSValue();

#endif