#include <WiFi.h>

const char* SSID = "Soumya_speed_net";     // Replace with your WiFi SSID
const char* PASSWORD = "#0x15AE#"; // Replace with your WiFi Password

void setup() {
    Serial.begin(115200);
    WiFi.begin(SSID, PASSWORD);
    Serial.print("Connecting to WiFi");

    int attempt = 0;
    while (WiFi.status() != WL_CONNECTED && attempt < 20) { // Try for 20 attempts
        delay(500);
        Serial.print(".");
        attempt++;
    }

    if (WiFi.status() == WL_CONNECTED) {
        Serial.println("\nWiFi Connected!");
        Serial.print("IP Address: ");
        Serial.println(WiFi.localIP()); // Prints local IP address
    } else {
        Serial.println("\nFailed to connect to WiFi.");
    }
}

void loop() {
    if (WiFi.status() != WL_CONNECTED) {
        Serial.println("WiFi Disconnected! Reconnecting...");
        WiFi.disconnect();
        WiFi.reconnect();
    } else {
        Serial.println("WiFi is Connected.");
    }
    delay(5000); // Check WiFi status every 5 seconds
}
