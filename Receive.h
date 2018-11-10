#ifndef _RECEIVE_H_
#define _RECEIVE_H_
#include"PID.h"

void para_val(){
  float kp,ki,kd;
   kp = Serial.parseFloat();
  kd = Serial.parseFloat();
  ki = Serial.parseFloat();
  pid.set_pid(kp,ki,kd);}


#endif
