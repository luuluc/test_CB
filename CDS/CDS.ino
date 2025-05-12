const int lightSensorPin = A0;  // Chân kết nối cảm biến quang trở (CDS)

void setup() {
  Serial.begin(9600);
}

void loop() {
  int sensorValue = analogRead(lightSensorPin);
  
  if (sensorValue > 500) {  // Ngưỡng ánh sáng, có thể điều chỉnh
    Serial.println("Tối");
  } else {
    Serial.println("Sáng");
  }
  
  delay(500);  // Chờ 500ms trước khi đọc lại cảm biến
}
