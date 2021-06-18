#include <HCPCA9685.h>
#include <math.h>
#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

/* I2C slave address for the device/module. Default I2C address is 0x40 */
#define  I2CAdd 0x40


HCPCA9685 HCPCA9685(I2CAdd); //Create an instance of the PCA9685 library
RF24 radio(7,8); //Create an instance of nRF24L01 library using pins 7(CE) and 8(CSN)

void setup() {
  HCPCA9685.Init(SERVO_MODE); //Initialize library
  HCPCA9685.Sleep(false); //Wake device up
}

void loop() {
  HCPCA9685.Servo(0, 0); //Servo 0, Position 0
  delay(10);
}

double calculateHeightL1(double phi, double theta, double H, double R){
  const double phi1 = 0 * PI / 180;
  double L1;
  
  double x1 = R * cos(phi1);
  double y1 = R * sin(phi1);

  double nx = cos(theta) * sin(phi);
  double ny = sin(theta) * sin(phi);
  double nz = cos(phi);

  double D = nz * H;

  L1 = (D - nx * x1 - ny * y1) / nz;

  return L1;
}
