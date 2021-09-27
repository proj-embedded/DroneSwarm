#ifndef PICO_DRONE_PMW3901_H
#define PICO_DRONE_PMW3901_H

#ifdef ARDUINO_ARCH_MBED_RP2040
  UART Serial2(8, 9, NC, NC);
#endif

class PicoDronePMW3901
{
  public:
  void begin()
  {
    Serial2.begin(19200);
  }
};

PicoDronePMW3901 PMW3901;

#endif
