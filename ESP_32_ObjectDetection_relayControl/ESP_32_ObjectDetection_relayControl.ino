#define trigPin 13
#define echoPin 12

#define relay1 14
#define relay2 27

bool relayState = false;  // Stores the relay's ON/OFF state
bool objectDetected = false;  // Tracks if an object is already detected

void setup() {
  Serial.begin(115200);
  Serial.println("Starting...");

  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  pinMode(relay1, OUTPUT);
  digitalWrite(relay1, HIGH);  // Assuming relay is ACTIVE LOW
}

void loop() {
  long duration, distance;

  // Send trigger pulse
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Read echo pulse
  duration = pulseInLong(echoPin, HIGH);
  distance = duration * 0.034 / 2;

  // Print debug data
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  // Ignore invalid sensor readings
  if (distance <= 0 || distance > 400) {
    Serial.println("⚠ ERROR: Invalid distance reading!");
    return;
  }

  // Toggle relay only when a new person enters the detection zone
  if (distance <= 80 && !objectDetected) {
    relayState = !relayState;  // Toggle relay state
    digitalWrite(relay1, relayState ? LOW : HIGH);  // Update relay output
    Serial.println(relayState ? "✅ Relay ON" : "❌ Relay OFF");

    objectDetected = true;  // Mark object as detected to prevent rapid toggling
  }

  // Reset detection flag when object leaves detection zone
  if (distance > 80 && objectDetected) {
    objectDetected = false;  // Ready to detect next person
  }

  delay(250);  // Small delay for stability
}
