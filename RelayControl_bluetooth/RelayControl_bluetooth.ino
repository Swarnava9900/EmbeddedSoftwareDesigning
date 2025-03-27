const int RELAY1_PIN = 2;  // Pin number for RELAY 1
const int RELAY2_PIN = 4;  // Pin number for RELAY 3

void setup() {
  Serial.begin(9600);  

  pinMode(RELAY1_PIN, OUTPUT);
  pinMode(RELAY2_PIN, OUTPUT);

  digitalWrite(RELAY1_PIN, HIGH);  // Ensure relay is OFF initially
  digitalWrite(RELAY2_PIN, HIGH);
}

void loop() {
  if (Serial.available()) {
    String command = Serial.readString();  
    command.trim();  // Remove newline characters

    if (command == "ON1") {
      digitalWrite(RELAY1_PIN, LOW);  // Turn on relay (if Active LOW)
      Serial.println("Relay 1 ON");
    } else if (command == "OFF1") {
      digitalWrite(RELAY1_PIN, HIGH); // Turn off relay
      Serial.println("Relay 1 OFF");
    } else if (command == "ON2") {
      digitalWrite(RELAY2_PIN, LOW);
      Serial.println("Relay 2 ON");
    } else if (command == "OFF2") {
      digitalWrite(RELAY2_PIN, HIGH);
      Serial.println("Relay 2 OFF");
    } else {
      Serial.println("Invalid Command!");
    }
  }
}
