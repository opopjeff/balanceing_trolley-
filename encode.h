//编码器数据读取
#ifndef _ENCODE_H_
#define _ENCODE_H_
#include"Arduino.h"
int PWM1_RIGHT = 2;
int PWM2_RIGHT = 5;
int PWM1_LEFT = 3;
int PWM2_LEFT = 4;
double speeded_right = 0;
double speeded_left = 0;
int count_right = 0 ;
int count_left = 0;
void event_right();
void event_left();
void caculation();
void encode_init(){
  attachInterrupt(0,event_right,CHANGE);
  attachInterrupt(1,event_left,CHANGE);
  FlexiTimer2::set(10,1.0/1000,caculation);
  FlexiTimer2::start();
}

void event_right(){
  if(digitalRead(PWM1_RIGHT) == HIGH){ //如果是上升沿触发
  if(digitalRead(PWM2_RIGHT)==LOW)
  count_right++;
  else count_right--;
  }
  else{
     if(digitalRead(PWM2_RIGHT)==LOW)
  count_right--;
  else count_right++;
  }
  }

  void event_left(){
  if(digitalRead(PWM1_LEFT) == HIGH){ //如果是上升沿触发
  if(digitalRead(PWM2_LEFT)==LOW)
  count_left++;
  else count_left--;
  }
  else{
     if(digitalRead(PWM2_LEFT)==LOW)
  count_left--;
  else count_left++;
  }
  }

  void caculation(){
  speeded_right = (((double)count_right*100)/374);
  count_right = 0;

  speeded_left = (((double)count_left*100)/374);
  count_left = 0;
}

#endif
