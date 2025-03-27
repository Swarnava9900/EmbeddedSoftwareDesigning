#include "BluetoothSerial.h"

BluetoothSerial SerialBT;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200); //starting serail monitor
  SerialBT.begin("ESP32_BT"); //set bt device name
  Serial.println("Bluetooth Started! Pair and send messages.");
}

void loop() {
  // put your main code here, to run repeatedly:
  if(SerialBT.available()) {
    String recievedData = SerialBT.readString(); //reading data
    Serial.print("Recieved: ");
    Serial.println(recievedData);

    // send a back response 
    SerialBT.print("ESP32 Recieved: ");
    SerialBT.println(recievedData);
  }
}
