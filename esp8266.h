#ifndef PICO_DRONE_ESP8266_H
#define PICO_DRONE_ESP8266_H

class PicoDroneESP8266
{
  public:
  void begin()
  {
    Serial1.begin(115200);
  }
} ESP8266;


#endif
