const int buzzerPin = 2;  // Chân kết nối còi chip 5V

void setup() {
  pinMode(buzzerPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  Serial.println("Bật còi trong 1 giây");
  digitalWrite(buzzerPin, HIGH);  // Bật còi
  delay(1000);  // Kêu trong 1 giây
  
  Serial.println("Tắt còi trong 1 giây");
  digitalWrite(buzzerPin, LOW);   // Tắt còi
  delay(1000);  // Nghỉ 1 giây trước khi lặp lại
}
