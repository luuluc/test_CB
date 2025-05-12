const int mq2SensorPin = 2;  // Chân kết nối cảm biến MQ-2

void setup() {
  pinMode(mq2SensorPin, INPUT);
  Serial.begin(9600);
}

void loop() {
  int sensorValue = analogRead(mq2SensorPin);
  
  if (sensorValue > 300) {  // Ngưỡng phát hiện khí, có thể điều chỉnh
    Serial.println("Phát hiện khí gas/smoke");
  } else {
    Serial.println("Không phát hiện khí");
  }
  
  delay(500);  // Chờ 500ms trước khi đọc lại cảm biến
}
