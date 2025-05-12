//Xanh dương (Blue) → IN1 (chân 8 Arduino)

//Hồng (Pink) → IN2 (chân 9 Arduino)

//Vàng (Yellow) → IN3 (chân 10 Arduino)

//Cam (Orange) → IN4 (chân 11 Arduino)

//Đỏ (Red - VCC) → 5V Arduino
#include <Stepper.h>

const int stepsPerRevolution = 2048;  // Số bước mỗi vòng
const int motorSpeed = 10;            // Tốc độ quay (RPM)

// Chân kết nối động cơ bước 28BYJ-48 với Arduino
const int in1 = 8;
const int in2 = 9;
const int in3 = 10;
const int in4 = 11;

Stepper myStepper(stepsPerRevolution, in1, in3, in2, in4);

void setup() {
  Serial.begin(9600);
  myStepper.setSpeed(motorSpeed);
  Serial.println("Động cơ bắt đầu quay...");
}

void loop() {
  Serial.println("Quay theo chiều kim đồng hồ");
  myStepper.step(stepsPerRevolution);  // Quay 1 vòng theo chiều kim đồng hồ
  delay(1000);

  Serial.println("Quay ngược chiều kim đồng hồ");
  myStepper.step(-stepsPerRevolution); // Quay 1 vòng ngược chiều kim đồng hồ
  delay(1000);
}
