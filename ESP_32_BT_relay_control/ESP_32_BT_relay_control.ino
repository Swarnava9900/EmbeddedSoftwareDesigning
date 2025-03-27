#include "BluetoothSerial.h"

#define RELAY1 2
#define RELAY2 4

BluetoothSerial SerialBT; // Creating Bluetooth object

void setup() {
    Serial.begin(115200);
    SerialBT.begin("ESP_32_SmartHome");
    Serial.println("Bluetooth is connected !!");

    pinMode(RELAY1, OUTPUT);
    pinMode(RELAY2, OUTPUT);

    digitalWrite(RELAY1, HIGH);  // Adjust if relay is active LOW
    digitalWrite(RELAY2, HIGH);
}

void loop() {
    if (SerialBT.available()) {
        String receivedData = SerialBT.readString();
        receivedData.trim();  // Remove unwanted characters (\n, \r)

        Serial.print("Received: ");
        Serial.println(receivedData);

        if (receivedData.equalsIgnoreCase("on1")) {
            Serial.println("Turning Relay 1 ON");
            digitalWrite(RELAY1, LOW); // Change to HIGH if relay logic is reversed
        } 
        else if (receivedData.equalsIgnoreCase("off1")) {
            Serial.println("Turning Relay 1 OFF");
            digitalWrite(RELAY1, HIGH);
        } 
        else if (receivedData.equalsIgnoreCase("on2")) {
            Serial.println("Turning Relay 2 ON");
            digitalWrite(RELAY2, LOW);
        } 
        else if (receivedData.equalsIgnoreCase("off2")) {
            Serial.println("Turning Relay 2 OFF");
            digitalWrite(RELAY2, HIGH);
        } 
        else {
            Serial.println("Invalid Command");
        }
    }
}
