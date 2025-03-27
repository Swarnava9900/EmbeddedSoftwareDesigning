int led = 9;
int led1 = 8;
int led2 = LED_BUILTIN;
int data;

void setup() {
  Serial.begin(9600);
  pinMode(led, OUTPUT);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(10, OUTPUT);
}

void loop() {
  digitalWrite(10, HIGH);
  while(Serial.available() > 0){
    data = Serial.read();
    Serial.print(data);
    Serial.println();
    if(data == 70 || data == 102)
    {
      digitalWrite(led, HIGH);
    }

    else if(data == 82)
    {
      digitalWrite(led1, HIGH);
    }

    else if(data == 76)
    {
      digitalWrite(led2, HIGH);
    }

    else if(data == 48)
    {
      digitalWrite(led, LOW);
      digitalWrite(led1, LOW);
      digitalWrite(led2, LOW);
    }
  }
}
