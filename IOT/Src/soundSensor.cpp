#include "config.h"
#include "soundSensor.h"

float readSoundSensor()
{
    unsigned long startMillis = millis();
    float peakToPeak = 0;
    unsigned int signalMax = 0;
    unsigned int signalMin = 1024;

    while (millis() - startMillis < sampleWindow)
    {
        sample = analogRead(soundPin);
        if (sample < 1024)
        {
            if (sample > signalMax)
            {
                signalMax = sample;
            }
            else if (sample < signalMin)
            {
                signalMin = sample; // ✅ fixad
            }
        }
    }

    peakToPeak = signalMax - signalMin;

    float db = map(peakToPeak, 5, 500, 10.0, 100.0); // eller använd float-varianten om du vill ha decimaler

    Serial.print("Loudness: ");
    Serial.print(db);
    Serial.println(" dB");
    return db;
    // there exists a delay
    delay(200); // why is there a delay here???
}