const int irSensorPin = 2;  // Chân kết nối cảm biến IR

void setup() {
  pinMode(irSensorPin, INPUT);
  Serial.begin(9600);
}

void loop() {
  int sensorValue = digitalRead(irSensorPin);
  
  if (sensorValue == LOW) {  // Tùy loại cảm biến, có thể đổi thành HIGH
    Serial.println("Có vật");
  } else {
    Serial.println("Không có vật");
  }
  
  delay(500);  // Chờ 500ms trước khi đọc lại cảm biến
}
