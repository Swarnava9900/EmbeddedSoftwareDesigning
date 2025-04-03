#include <TinyGPS++.h>  // GPS Data parser
#include <HardwareSerial.h>  // UART Communication

#define RX 16
#define TX 17
#define GPSBaud 9600

TinyGPSPlus gps; // TinyGPS++ object creation
HardwareSerial GPS_Serial(1); // 2nd UART communication 

void setup() {
  Serial.begin(115200);
  GPS_Serial.begin(GPSBaud, SERIAL_8N1, RX, TX);
  Serial.println("Waiting for GPS signal...");
}

void loop() {
  // Process all available GPS data
  while(GPS_Serial.available() > 0) {
    char c = GPS_Serial.read();
    // Uncomment below if you want to see raw GPS data
    // Serial.write(c); 
    
    if(gps.encode(c)) {  // encode() returns true if new sentence was properly parsed
      if(gps.location.isUpdated()) {
        Serial.print("Latitude: ");
        Serial.println(gps.location.lat(), 6);
        Serial.print("Longitude: ");
        Serial.println(gps.location.lng(), 6);
        Serial.print("Altitude: ");
        Serial.print(gps.altitude.meters());
        Serial.println("m");
        Serial.print("Speed: ");
        Serial.print(gps.speed.kmph());
        Serial.println("km/h");
        Serial.print("Satellites: ");
        Serial.println(gps.satellites.value());
        Serial.println();  // Add empty line for readability
      }
    }
  }
  
  // Optional: Small delay to prevent overwhelming the serial monitor
  delay(10);
}