int trigPin=2;
int echoPin=4;

int relay1=7;

bool relayState = false;  // Stores the relay's ON/OFF state
bool objectDetected = false;  // Tracks if an object is already detected

void setup() {
  Serial.begin(9600);
  Serial.println("Starting...");

  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  pinMode(relay1, OUTPUT);
  digitalWrite(relay1, HIGH);
}

void loop() {
  long duration, distance;

  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseInLong(echoPin, HIGH);
  distance = duration * 0.034 / 2;

  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  if (distance <= 0 || distance > 850) {
    Serial.println("⚠ ERROR: Invalid distance reading!");
    return;
  }

  if (distance <= 70 && !objectDetected) {
    objectDetected = true;
    relayState = !relayState;
    digitalWrite(relay1, relayState ? LOW : HIGH);
    Serial.println(relayState ? "✅ Relay ON" : "❌ Relay OFF");
  }


  if (distance > 70 && objectDetected) {
    objectDetected = false;
  }

  delay(250);
}
