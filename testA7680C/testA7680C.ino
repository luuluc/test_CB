#include <SoftwareSerial.h>
SoftwareSerial simSerial(32, 33); // TX 7 ; RX 8

#define PHONE_NUMBER      "0888124475"              // thay đổi số điện thoại
#define SET_BAUDRATE      "AT+IPREX=115200"         // thay đổi baudrate (VD: "AT+IPREX=115200")
#define MCU_SIM_BAUDRATE  115200

void sim_at_wait() {
    delay(100);
    while (simSerial.available()) {
        Serial.write(simSerial.read());
    }
}

bool sim_at_cmd(String cmd) {
    simSerial.println(cmd);
    sim_at_wait();
    return true;
}

bool sim_at_send(char c) {
    simSerial.write(c);
    return true;
}

void call() {                  // Hàm thực hiện cuộc gọi
    String temp = "ATD";
    temp += PHONE_NUMBER;
    temp += ";";
    sim_at_cmd(temp); 

    delay(20000);               // gọi 20 giây
    sim_at_cmd("ATH");           // ngắt cuộc gọi
}

void setup() {
    Serial.begin(MCU_SIM_BAUDRATE);
    delay(200);
    simSerial.begin(MCU_SIM_BAUDRATE);
    delay(200);
    
    Serial.println("\n\n\n\n-----------------------\nSystem started!!!!");
    
    sim_at_cmd("AT");           // Kiểm tra AT Command
    delay(200);
    sim_at_cmd("AT+IPREX?");    // Kiểm tra tốc độ baud rate
    delay(200);
    sim_at_cmd(SET_BAUDRATE);   // Cài tốc độ baudrate
    delay(200);
    sim_at_cmd("ATI");          // Thông tin module SIM
    delay(200);
    sim_at_cmd("AT+CPIN?");     // Kiểm tra trạng thái của thẻ SIM
    delay(200);
    sim_at_cmd("AT+CSQ");       // Kiểm tra tín hiệu mạng
    delay(200);
    sim_at_cmd("AT+CIMI");      // Kiểm tra IMSI
    delay(200);

    pinMode(13, OUTPUT); 
    digitalWrite(13, HIGH);

    call();                     // chỉ thực hiện cuộc gọi
}

void loop() {     
    if (Serial.available()) {
        char c = Serial.read();
        simSerial.write(c);
    }
    sim_at_wait();
}
