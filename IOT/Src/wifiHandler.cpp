#include <Arduino.h>
#include <WiFiS3.h>
#include "config.h"
#include "wifiHandler.h"

void connectToWiFi(int timeout) {
    Serial.print("Connecting to WiFi");
    Serial.flush();

    int status = WL_IDLE_STATUS;
    int startAttemptTime = millis();

    // ✅ Start connection only once
    WiFi.begin(ssid, password);
    Serial.println("WiFi.begin() called");

    // Keep looping until connected or timeout reached
    while (status != WL_CONNECTED && millis() - startAttemptTime < timeout) {
        status = WiFi.status();  // ✅ Only check status after begin()
        delay(1000);
        Serial.print(".");
    }

    if (status == WL_CONNECTED) {
        Serial.println("\nConnected to WiFi!");
        Serial.print("IP Address: ");
        Serial.println(WiFi.localIP());
    } else {
        Serial.println("\nWiFi not connected — continuing without connection.");
    }
}
