#include "HCPCA9685.h"
#include "math.h"

/* I2C slave address for the device/module. Default I2C address is 0x40 */
#define  I2CAdd 0x40

/* Create an instance of the library */
HCPCA9685 HCPCA9685(I2CAdd);

void setup() {
  HCPCA9685.Init(SERVO_MODE); // Initialize library
  HCPCA9685.Sleep(false); // Wake device up
}

void loop() {
  HCPCA9685.Servo(0, 0); // Servo 0, Position 0
  delay(10);
}
