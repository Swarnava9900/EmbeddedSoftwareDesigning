#include <WiFi.h>
#include <WebServer.h>
// #include <TinyGPS++.h>
#include <HardwareSerial.h>

const char* ssid = "Soumya_speed_net";
const char* password = "#0x15AE#";

WebServer server(80);

void handleData() {
  String jsonResponse = "{";
  jsonResponse += "\"latitude\":\"42.3567° N\",";
  jsonResponse += "\"longitude\":\"-71.0892° W\"";
  jsonResponse += "}";

  server.send(200, "application/json", jsonResponse);
}

void setup() {
  Serial.begin(115200);

  WiFi.begin(ssid, password);
  Serial.print("Connecting to WiFi");
  while(WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("\nConnected to WiFi successfully !!");
  Serial.print("ESP_32 IP Address: ");
  Serial.println(WiFi.localIP());

  server.on("/gps", handleData);
  server.begin();
}

void loop() {
  server.handleClient();
}
