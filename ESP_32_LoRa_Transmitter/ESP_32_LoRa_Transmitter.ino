#include <SPI.h>
#include <LoRa.h>

#define SS 5      // LoRa module NSS (CS)
#define RST 14    // LoRa module RESET
#define DIO0 2    // LoRa module DIO0

void setup() {
    Serial.begin(115200);
    while (!Serial);

    Serial.println("Starting LoRa Transmitter...");

    LoRa.setPins(SS, RST, DIO0);

    if (!LoRa.begin(433E6)) {  // Set frequency (433E6 for 433MHz, 868E6 for 868MHz, 915E6 for 915MHz)
        Serial.println("LoRa initialization failed!");
        while (1);
    }

    Serial.println("LoRa Initialized Successfully!");
}

void loop() {
    if(Serial.available()){
      String input = Serial.readString();
      Serial.println("Sending packet...");

      LoRa.beginPacket();
      LoRa.print(input);
      LoRa.endPacket();
      
      Serial.println("Packet Sent!");
    }
}
