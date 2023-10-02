// SerialPassthrogh for Stack-chan SCServo Model
#include <Arduino.h>
#include <M5Stack.h>

#define SerialSCS Serial1 // for Basic's PortA / RX/TX/V/G

void setup() {
  // Initialize M5Stack
  M5.begin(true,true,true,false); // disable I2C for Basic
  M5.Power.begin();
  // Initialize SerialPort
  Serial.begin(115200); // for PC (USB-Serial  already opened in M5.beguin)
//  SerialSCS.begin(1000000); // for SCServo (Stack-chan bord include SignalConverter)
  SerialSCS.begin(1000000, SERIAL_8N1, 22, 21); // for SCServo (Stack-chan bord include SignalConverter) // RX, TX
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