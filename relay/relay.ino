const int relayPin = 7;  // Chân điều khiển relay

void setup() {
  pinMode(relayPin, OUTPUT);
  Serial.begin(9600);
  Serial.println("Bắt đầu test relay và motor...");
}

void loop() {
  Serial.println("Bật motor");
  digitalWrite(relayPin, LOW);  // LOW để bật relay (tùy module)
  delay(8000);  // Motor chạy 3 giây

  Serial.println("Tắt motor");
  digitalWrite(relayPin, HIGH); // Tắt relay+
  delay(3000);  // Dừng 3 giây
}
