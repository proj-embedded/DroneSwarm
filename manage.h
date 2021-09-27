#ifndef PICO_DRONE_MANAGE_H
#define PICO_DRONE_MANAGE_H

#include <Wire.h>
#include <Servo.h>

#include "esc.h"
#include "mpu6050.h"
#include "hmc5883l.h"
#include "ms5611.h"
#include "vl53l1x.h"
#include "pmw3901.h"
#include "esp8266.h"


const double DT = 0.001f;

typedef struct Pid 
{
  const double stable_kp, stable_ki, rate_kp, rate_ki, rate_kd;
  double p, i, d;
  double errAngle, errRate, errPrev;
  double de;
  double control;
 
} PID;

PID roll =  {0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f};
PID pitch = {0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f};
PID yaw = {0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f};


void pid()
{
  // write code for pid tune..
}

#endif
