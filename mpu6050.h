#ifndef PICO_DRONE_MPU6050_H
#define PICO_DRONE_MPU6050_H

class PicoDroneMPU6050
{
  public:
  void begin()
  {
    // Register 107 - Power Management 1
    Wire.beginTransmission(0x68);
    Wire.write(107);
    Wire.write(0);
    Wire.endTransmission();
    // Register 26 - Configuration
    for(uint8_t i = 2; i <= 7; i++)
    {
      Wire.beginTransmission(0x68);
      Wire.write(26);
      Wire.write((i << 3) | 0x04);
      Wire.endTransmission();
    }
    // Register 27 – Gyroscope Configuration
    Wire.beginTransmission(0x68);
    Wire.write(27);
    Wire.write(0b11111000);
    Wire.endTransmission();
    // Register 28 – Accelerometer Configuration
    Wire.beginTransmission(0x68);
    Wire.write(28);
    Wire.write(0b11100000);
    Wire.endTransmission();
  }
} MPU6050;

#endif
