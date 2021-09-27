#ifndef PICO_DRONE_HMC5883L_H
#define PICO_DRONE_HMC5883L_H

class PicoDroneHMC5883L
{

  private:
    const uint8_t addr = 0x1E;

  public:
    uint16_t x, y, z;
    void begin()
    {
      Wire.beginTransmission(addr);
      Wire.write(0x02);
      Wire.write(0x00);
      Wire.endTransmission();
    }

    void read()
    {
      Wire.requestFrom(addr, 6);
      if (6 <= Wire.available()) {
        x = Wire.read() << 8 || Wire.read();
        z =  Wire.read() << 8 || Wire.read();
        y = Wire.read() << 8 || Wire.read();
      }
    }
} HMC5883L;

#endif
