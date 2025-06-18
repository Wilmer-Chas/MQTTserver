#include "gasSensor.h"  
#include "config.h"


// Function to read the gas sensor
int readGasSensor()
{
  int gasLevel = analogRead(mq2Pin);  
  Serial.println("Reading gas concentration...");
  

  if (gasLevel > 100) {  // 100 is just an example threshold
    Serial.print("Gas concentration detected: ");
    Serial.println(gasLevel);
  } else {
    Serial.println("No significant gas detected.");
  }
  
  return gasLevel;
}


