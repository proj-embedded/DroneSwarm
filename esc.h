#ifndef PICO_DRONE_ESC_H
#define PICO_DRONE_ESC_H

#define ESC_PWM_MAX 2000
#define ESC_PWM_MIN 1000

class PicoDroneESC
{
  private:
  Servo _esc[4];
  public:
  uint8_t Pin[4] = {18, 19, 20, 21};
  void begin()
  {
    for(uint8_t i = 0; i < 4; i++) _esc[i].attach(Pin[i], ESC_PWM_MIN, ESC_PWM_MAX);
  }

  void write(uint8_t i, int16_t raw)
  {
    _esc[i].writeMicroseconds(constrain(raw, ESC_PWM_MIN, ESC_PWM_MAX * 0.8)); // 80% cut
  }
} ESC;

#endif
