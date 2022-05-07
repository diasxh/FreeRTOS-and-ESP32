int ledPin = 2;

void setup() {
    // Set LED as output
    pinMode(ledPin, OUTPUT);
    // Serial monitor setup
    Serial.begin(115200);
}

void loop() {
    digitalWrite(ledPin, HIGH);
    delay(500);
    digitalWrite(ledPin, LOW);
    delay(500);
}
