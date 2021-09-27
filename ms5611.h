#ifndef PICO_DRONE_MS5611_H
#define PICO_DRONE_MS5611_H

class PicoDroneMS5611
{

  private:
    const uint8_t addr = 0x1E;
    const uint8_t CMD_ADC_READ = 0x00;
    const uint8_t CMD_RESET = 0x1E;
    const uint8_t CMD_CONV_D1 = 0x40;
    const uint8_t CMD_CONV_D2 = 0x50;
    const uint8_t CMD_READ_PROM = 0xA2;
    const uint8_t osr = 0x06;

    uint32_t rawPressure = 0;



    const uint32_t seaLevel = 101325;

    uint32_t readRegister24(uint8_t reg)
    {
      uint32_t value;
      Wire.beginTransmission(addr);
      Wire.write(reg);
      Wire.endTransmission();

      Wire.beginTransmission(addr);
      Wire.requestFrom(addr, 3);
      while (!Wire.available()) {};
      uint8_t vxa = Wire.read();
      uint8_t vha = Wire.read();
      uint8_t vla = Wire.read();
      Wire.endTransmission();
      value = ((int32_t)vxa << 16) | ((int32_t)vha << 8) | vla;
      return value;
    }


  public:
    void begin()
    {

    }


    double getAltitude()
    {
      Wire.beginTransmission(addr);
      Wire.write(CMD_CONV_D1 + osr);
      Wire.endTransmission();
      delay(1);
      rawPressure = readRegister24(CMD_ADC_READ);

    }
} MS5611;


#endif
