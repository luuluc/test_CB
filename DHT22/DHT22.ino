#include <DHT.h>

#define DHTPIN 2      // Chân kết nối cảm biến DHT22
#define DHTTYPE DHT22 // Loại cảm biến

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(9600);
  dht.begin();
}

void loop() {
  float humidity = dht.readHumidity();
  float temperature = dht.readTemperature();
  
  if (isnan(humidity) || isnan(temperature)) {
    Serial.println("Lỗi đọc cảm biến DHT22");
  } else {
    Serial.print("Nhiệt độ: ");
    Serial.print(temperature);
    Serial.print("°C, Độ ẩm: ");
    Serial.print(humidity);
    Serial.println("%");
  }
  
  delay(2000);  // Đọc dữ liệu mỗi 2 giây
}
