# Overview

*Disclaimer* _The project in its current stage is a prototype, meant to be further developed. That means that some features, like the portability of the product, is not present as of yet._

This project encompasses a sensor embedded in a belt or wristband designed to measure various values such as temperature, movement, gas, pulse, and sound levels. The sensor readings can be used for health tracking, environmental monitoring, and general wellness.


# Features
Temperature Measurement: Measures the environment's temperature.

GPS Detection: Detects and records Location using a GPS Sensor.

Gas Monitoring: Measures gas levels, such as CO2 or particulate matter.

Pulse Monitoring: Tracks heart rate or pulse to detect dangerous values.

Noise Level Detection: Measures ambient noise levels for noise pollution assessment.

# Getting Started

To build the project from the source code:

Clone this repository:
```
  git clone https://github.com/7-eleven-development/7-11-IOT.git
```
Install required dependencies (example for Arduino or similar):

Install Platform IO on Visual Studio Code and have a C++ Compiler

Open the project in VSCode.

Upload the code to your hardware specificaly targetting mk1010 wifi.

Configure tasks.json to your compilers settings

Example tasks.json


![Screenshot 2025-05-19 160940](https://github.com/user-attachments/assets/8f9e3b15-9e8c-424f-87b2-079376b12876)


# Latest Release

The latest release can be found on the Release Page. Install by zip or fork the repostiory

# Documentation

This section provides details on the sensor functions, methods, and expected inputs/outputs.
Available Sensors:

    Temperature Sensor

        Function: Measures temperature in °C.

        API: readTemperatureSensor()

        Returns: A float value representing the temperature.

    GPS Sensor

        Function: Tracks current location by longitude and latitude.

        API: readLatitudeGpsValue(), readLongitudeGpsValue()

        Returns: Float values representing latitude and Longitude

    Gas Sensor

        Function: Measures particulate matter or gases.

        API: readGasSensor()

        Returns: A float representing the gas value.

    Pulse Sensor

        Function: Measures pulse rate (heartbeats per minute).

        API: readPulseSensor()

        Returns: An integer representing the pulse rate.

    Sound Sensor

        Function: Measures ambient noise levels in decibels (dB).

        API: readSoundSensor()

        Returns: A float representing the sound level.

# Architecture Description

    Sensor Integration: The code integrates with sensors (e.g., temperature, motion, gas, etc.) through libraries.

    Data Collection and Transmission: The sensor data is collected and sent either to a local display or to a cloud server for further analysis.

    WiFi: Data can be transmitted to a cloud server or connected devices using WiFi.

Main Files

    gps.cpp: Handles GPS sensor readings and integrates with other sensors.

    "sensor".cpp: Reads data from individual sensors and processes them.

    router.cpp: Manages communication between the IoT device and the server.

    OffOnSwitch.cpp: Manages power, reading, and Wi-Fi transmission for multiple sensors by cycling through them one at a time in a looped sequence.

    microControllerID.cpp: Reads and returns a unique device identifier by accessing the microcontroller's hardware ID registers.

    wifiHandler.cpp: Handles connecting the device to a Wi-Fi network using provided credentials, with a timeout to prevent indefinite blocking.


# Future Enhancements
Software:

  Improve on how pulse values are read to make the most critical part of this system be more reliable
  
  Fault detection, identify errors during execution that can lead to silent failures

  Improve concurrency flow within the program, enableing non blocking behaviour.

  Watchdog, simulate Watchdog behaviour upon sensor reading to ensure that the program does not get blocked upon sensor reading.

  Secure data transmission between backend and IOT (read up on it)
  
Hardware:

  _In general: More reliable and smaller sanesors for portability_
  
  An air quality sensor that read actual air quality levels, not just gas.

  A pulse sensor that measures puls via the wrist, for portability and ease of use.

  