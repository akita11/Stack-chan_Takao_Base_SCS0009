// SerialPassthrogh for Stack-chan SCServo Model
#include <Arduino.h>
#include <M5Stack.h>

#if defined( ARDUINO_M5Stack_Core_ESP32 )
  #define SerialSCS Serial1 // for Basic's PortA / RX/TX/V/G
#elif defined(ARDUINO_M5STACK_Core2)
  #define SerialSCS Serial2 // for Core2's PortA / RX/TX/V/G
#endif


void setup() {
  // Initialize M5Stack
  M5.begin(true,true,true,false); // disable I2C for Basic
  M5.Power.begin();
  // Initialize SerialPort
  Serial.begin(115200); // for PC (USB-Serial  already opened in M5.beguin)

#if defined( ARDUINO_M5Stack_Core_ESP32 )
  SerialSCS.begin(1000000, SERIAL_8N1, 22, 21); // for SCServo (Stack-chan bord include SignalConverter) // RX, TX
#elif defined(ARDUINO_M5STACK_Core2)
  SerialSCS.begin(1000000); // for SCServo (Stack-chan bord include SignalConverter)
#endif
}
void loop() {
  // PC to SCServo
  if (Serial.available()) {
    int inByte = Serial.read();
    SerialSCS.write(inByte);
    SerialSCS.flush(); // wait send
    SerialSCS.read(); // flash call back
  }
  // SCServo to PC
  if (SerialSCS.available()) {
    int inByte = SerialSCS.read();
    Serial.write(inByte);
    Serial.flush(); // wait send
  }
  M5.update();
}
