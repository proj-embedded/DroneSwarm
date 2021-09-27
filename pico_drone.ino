/*
 * SerialUSB -> USB (Default)
 * Serial1   -> TX 0, RX 1 (Default)
 * Serial2   -> TX 8, RX 9 (Addon)
 * SPI       -> 2, 3, 4, 5 (Default)
 * Wire      -> 6, 7 (Default)
 * 
 * Serial1 -> Maybe ESP8266 UART
 * Serial2 -> Maybe PMW3901 UART
*/

#include "manage.h"

void setup() {
  // I2C
  Wire.begin();
  Wire.setClock(400000L);
  // ESC
  ESC.begin();
  // GY-86
  MPU6050.begin();
  HMC5883L.begin();
  MS5611.begin();
  // Wifi
  ESP8266.begin();
  // Hover
  VL53L1X.begin();
  PMW3901.begin();
}

void loop() {


  /*
  1. 10-Axis READ
   - MPU6050 (Roll, Pitch, Yaw)
   - HMC5883L (Yaw)
   - MS5611 (Throttle)
  2. VL53L1X READ
   - GetDistance (Throttle)
  3. PMW3901 READ
   - GetXY Tune (Roll, Pitch)
  4. ESP8266 READ
   - Get SetPoint (All)
  5. PID Tuning
   - Sum..
  */
}
