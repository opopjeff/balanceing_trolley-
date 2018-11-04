#ifndef _SET_MOTOR_H_
#define _SET_MOTOR_H_
#include"Arduino.h"
int ENA = 8;
int IN1 = 9;
int IN2 = 10;
int IN3 = 11;
int IN4 = 12;
int ENB = 13;
void UP_RIGHT(unsigned int high,unsigned int low){
  digitalWrite(ENA,HIGH);
  analogWrite(IN1,high);
  analogWrite(IN2,low);
}
void UP_LEFT(unsigned int high,unsigned int low){
  digitalWrite(ENB,HIGH);
  analogWrite(IN3,low);
  analogWrite(IN4,high);
}


#endif
