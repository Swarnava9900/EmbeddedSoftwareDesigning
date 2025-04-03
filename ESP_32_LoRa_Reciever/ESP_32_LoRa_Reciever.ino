#include <SPI.h>
#include <LoRa.h>

#define SS 5      // LoRa module NSS (CS)
#define RST 14    // LoRa module RESET
#define DIO0 2    // LoRa module DIO0

void setup() {
    Serial.begin(115200);
    while (!Serial);

    Serial.println("Starting LoRa Receiver...");

    LoRa.setPins(SS, RST, DIO0);

    //433mhz radio freq start

    if (!LoRa.begin(433E6)) {
        Serial.println("LoRa initialization failed!");
        while (1);
    }

    Serial.println("LoRa Receiver Initialized!");
}

void loop() {
    int packetSize = LoRa.parsePacket();
    // Serial.println(packetSize);
    if (packetSize) {
        Serial.print("Received packet: ");

        while (LoRa.available()) {
            Serial.print((char)LoRa.read());
        }

        Serial.println();
    }
}
