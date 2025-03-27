#include <WiFi.h>
#include <WebServer.h>

// 📶 WiFi Credentials
const char* ssid = "Drone_Controller";
const char* password = "12345678";

// 🎮 Web Server on Port 80
WebServer server(80);

// Function to Control Drone Motors
void controlDrone(String command) {
    if (command == "UP") {
        Serial.println("Take Off! 🛫");
        // Add motor control code here
    } else if (command == "DOWN") {
        Serial.println("Landing! 🛬");
        // Add landing motor control code
    } else if (command == "LEFT") {
        Serial.println("Turning Left! ↩️");
        // Add code to tilt left
    } else if (command == "RIGHT") {
        Serial.println("Turning Right! ↪️");
        // Add code to tilt right
    } else if (command == "STOP") {
        Serial.println("Stopping Drone! ✋");
        // Stop all motors
    }
}

// 🌐 HTML Webpage for Control UI
String webpage = "<!DOCTYPE html>"
                 "<html>"
                 "<head>"
                 "<title>Drone Controller 🚀</title>"
                 "<style>"
                 "body { font-family: Arial, sans-serif; text-align: center; margin: 20px; }"
                 "button { padding: 15px 30px; font-size: 20px; margin: 10px; }"
                 "</style>"
                 "</head>"
                 "<body>"
                 "<h1>🚀 Drone Controller 🌐</h1>"
                 "<button onclick=\"sendCommand('UP')\">🛫 Take Off</button>"
                 "<button onclick=\"sendCommand('DOWN')\">🛬 Land</button><br>"
                 "<button onclick=\"sendCommand('LEFT')\">⬅️ Left</button>"
                 "<button onclick=\"sendCommand('RIGHT')\">➡️ Right</button><br>"
                 "<button onclick=\"sendCommand('STOP')\">✋ STOP</button>"
                 "<script>"
                 "function sendCommand(cmd) {"
                 "fetch('/control?cmd=' + cmd);"
                 "}"
                 "</script>"
                 "</body>"
                 "</html>";

// 📡 Handle Web Requests
void handleRoot() {
    server.send(200, "text/html", webpage);
}

void handleControl() {
    String command = server.arg("cmd");
    controlDrone(command);
    server.send(200, "text/plain", "OK");
}

void setup() {
    Serial.begin(115200);

    // 🌐 Start WiFi as Access Point
    WiFi.softAP(ssid, password);
    Serial.println("WiFi Started! Connect to: " + String(ssid));

    // 🌍 Setup Web Server Routes
    server.on("/", handleRoot);
    server.on("/control", handleControl);
    
    server.begin();
    Serial.println("Web Server Started! 🌐");
}

void loop() {
    server.handleClient();
}
