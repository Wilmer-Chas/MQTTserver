#include "config.h"
#include "pulseSensor.h"

int readPulseSensor()
{
    delay(20);
    pulseSensor.outputSample(); // Output current sample

    // If a beat was detected, output beat info
    if (pulseSensor.sawStartOfBeat())
    {
        return pulseSensor.getBeatsPerMinute();
    }
    return 0;
} 

int randomPulseValue()
{
    int randomValue = random(0, 100); // Generates a random number between 0 and 99
    return randomValue;
}