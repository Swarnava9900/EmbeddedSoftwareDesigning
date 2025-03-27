#include <WiFi.h>
#include <WebServer.h>

const char* ssid = "SurakshaPin";
const char* password = "12345678";  // Change this if needed

WebServer server(80);

String latitude = "22.5726";  // Default (Kolkata)
String longitude = "88.3639";

void handleRoot() {
    String page = "<!DOCTYPE html>"
    "<html lang='en'><head><meta charset='UTF-8'><meta name='viewport' content='width=device-width, initial-scale=1.0'>"
    "<title>Suraksha Pin - SOS Location</title>"
    "<style>body {font-family: Arial, sans-serif; text-align: center; background: #f4f4f9; margin: 0; padding: 0;}"
    "h1 {color: #ff3b30;} #map {width: 90%; height: 500px; margin: 20px auto; border-radius: 10px;}"
    "button {padding: 10px 20px; font-size: 16px; background: #ff3b30; color: white; border: none; cursor: pointer; border-radius: 5px; margin: 10px;}"
    "button:hover {background: #d32f2f;}</style>"
    "<script src='https://maps.googleapis.com/maps/api/js?key=YOUR_GOOGLE_MAPS_API_KEY'></script>"
    "</head><body>"
    "<h1>🚨 SOS Alert - Suraksha Pin 🚨</h1>"
    "<button onclick='updateLocation()'>Update Location</button>"
    "<div id='map'></div>"
    "<script>"
    "let map, marker;"
    "function initMap() {"
    "const location = { lat: " + latitude + ", lng: " + longitude + "};"
    "map = new google.maps.Map(document.getElementById('map'), {center: location, zoom: 15});"
    "marker = new google.maps.Marker({position: location, map: map, title: 'SOS Location'});"
    "}"
    "function updateLocation() { fetch('/getLocation').then(response => response.json()).then(data => {"
    "const newLoc = { lat: parseFloat(data.lat), lng: parseFloat(data.lng) };"
    "marker.setPosition(newLoc); map.setCenter(newLoc);"
    "alert('Location updated! 📍 ' + data.lat + ', ' + data.lng);"
    "});}"
    "window.onload = initMap;"
    "</script></body></html>";

    server.send(200, "text/html", page);
}

void handleLocation() {
    String json = "{\"lat\": \"" + latitude + "\", \"lng\": \"" + longitude + "\"}";
    server.send(200, "application/json", json);
}

void setup() {
    Serial.begin(115200);
    WiFi.softAP(ssid, password);
    Serial.println("Access Point Started!");

    server.on("/", handleRoot);
    server.on("/getLocation", handleLocation);
    server.begin();
    Serial.println("Server running!");
}

void loop() {
    server.handleClient();
}
