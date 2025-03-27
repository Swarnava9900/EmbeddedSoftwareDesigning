const int analogPin = A0;  // Analog pin to read voltage
const float referenceVoltage = 5.0;  // Reference voltage (for 5V Arduino)
const int resolution = 1023;  // 10-bit ADC (0-1023)

void setup() {
    Serial.begin(9600);
}

void loop() {
    int analogValue = analogRead(analogPin);  // Read ADC value
    float voltage = (analogValue / float(resolution)) * referenceVoltage;  // Convert to voltage

    Serial.print("Voltage: ");
    Serial.print(voltage);
    Serial.println(" V");

    delay(1000);  // Delay for readability
}
