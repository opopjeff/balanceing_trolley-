#ifndef _MOTOR_ENCODE_H_
#define _MOTOR_ENCODE_H_
#include"Arduino.h"
#include <FlexiTimer2.h>
int PWM1_RIGHT = 2;
int PWM2_RIGHT = 5;
int PWM1_LEFT = 3;
int PWM2_RIGHT = 4;
int count_right = 0;
int count_left = 0;
float motor_encode_init(){
  FlexiTimer2::set(100,1.0/1000,main_loop);
  FlexiTimer2::start();
  attachInterrupt(0,event_right,RISING);
  attachInterrupt(1,event_left,RISING);
}
void event_right(){
  count_right++;
}

void event_left(){
  count_left++;
}
float main_loop(float data[2]){
  data[0] = (float)count_right/374/(0.1);
  data[1] = (float)count)left/374(0.1);
  return data[2];
}
#endif
