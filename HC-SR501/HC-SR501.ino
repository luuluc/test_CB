const int pirSensorPin = 2;  // Chân kết nối cảm biến chuyển động HC-SR501

void setup() {
  pinMode(pirSensorPin, INPUT);
  Serial.begin(9600);
}

void loop() {
  int sensorValue = digitalRead(pirSensorPin);
  
  if (sensorValue == HIGH) {  // Khi phát hiện chuyển động
    Serial.println("Phát hiện chuyển động");
  } else {
    Serial.println("Không có chuyển động");
  }
  
  delay(500);  // Chờ 500ms trước khi đọc lại cảm biến
}
