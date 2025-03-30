void setup() {
  Serial.begin(9600);
  pinMode(2, OUTPUT);
  digitalWrite(2, HIGH);
  delay(1000);
  Serial.println("IRRIGATION SYSTEM IS ON");
  delay(2000);
}

void loop() {
  int value = analogRead(A0);
  Serial.print("Soil Moisture Value: ");
  Serial.println(value);

  if (value > 950) {
    digitalWrite(2, LOW);
    Serial.println("Water Pump is ON");
  } else {
    digitalWrite(2, HIGH);
    Serial.println("Water Pump is OFF");
  }

  if (value < 300) {
    Serial.println("Moisture Level: HIGH (Soil is Wet)");
  } else if (value >= 300 && value <= 950) {
    Serial.println("Moisture Level: MID (Soil is Moist)");
  } else {
    Serial.println("Moisture Level: LOW (Soil is Dry)");
  }

  Serial.println("----------------------------");
  delay(2000);
}
