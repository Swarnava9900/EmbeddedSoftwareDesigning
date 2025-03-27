int trigPin = 7;
int echoPin = 8;

void setup() {
  Serial.begin(9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}

void loop() {
  long duration, distance;

  digitalWrite(trigPin, LOW);
  delay(2);

  digitalWrite(trigPin, HIGH);
  delay(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);
  distance = duration * 0.034 / 2;

  Serial.print("\r Object Distance is : ");
  Serial.print(distance);
  Serial.println(" cm    ");

  delay(100);
}
