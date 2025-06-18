#ifndef OFFONSWITCH_H
#define OFFONSWITCH_H

enum Sensor {
    TEMPERATURESENSOR,
    AIRSENSOR,
    GPSSENSOR,
    SOUNDSENSOR
};

void switchSensor(Sensor sensorType);
void turnOffSensors();
void switchSensorState();
int getTotalSensors();

#endif