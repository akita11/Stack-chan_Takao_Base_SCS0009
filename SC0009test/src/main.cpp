// SerialPassthrogh for Stack-chan SCServo Model
#include <Arduino.h>
#include <M5Unified.h>

#define SerialSCS Serial1 // for Basic's PortA / RX/TX/V/G


void setup() {
  // Initialize M5Stack
  M5.begin(); 
  M5.In_I2C.release();  // Release internal I2C when using Port.A with UART.

  // Initialize SerialPort
#if defined( ARDUINO_M5Stack_Core_ESP32 )
  SerialSCS.begin(1000000, SERIAL_8N1, 22, 21); // for SCServo (Stack-chan bord include SignalConverter) // RX, TX
#elif defined(ARDUINO_M5STACK_Core2)
  SerialSCS.begin(1000000, SERIAL_8N1, 33, 32); // for SCServo (Stack-chan bord include SignalConverter) // RX, TX
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
