void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(2, HIGH);
  Serial.println("Light ON !!");
  delay(2000);
  digitalWrite(3, HIGH);
  Serial.println("Power ON !!");
  delay(2000);
  digitalWrite(2, LOW);
  Serial.println("Light OFF !!");
  delay(2000);
  digitalWrite(3, LOW);
  Serial.println("Power OFF !!");
  delay(2000);
  
}
