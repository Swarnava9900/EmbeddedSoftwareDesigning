int led = LED_BUILTIN;
int data;


void setup() {
  Serial.begin(9600);
  pinMode(led, OUTPUT);
}

void loop() {
  while(Serial.available() > 0)
  {
    data = Serial.read();
    Serial.print(data);
    if(data == 48)
      digitalWrite(led, HIGH);
    else if(data == 49)
      digitalWrite(led, LOW); 
  }
}
