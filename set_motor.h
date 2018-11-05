#ifndef _SET_MOTOR_H_
#define _SET_MOTOR_H_
#include"Arduino.h"
int ENA = 8;
int IN1 = 9;
int IN2 = 10;
int IN3 = 11;
int IN4 = 12;
int ENB = 13;
void UP_RIGHT(unsigned int par_valule){
  digitalWrite(ENA,HIGH);
  analogWrite(IN1,abs(par_valule));
  analogWrite(IN2,-abs(par_valule));
}
void UP_LEFT(unsigned int par_valule){
  digitalWrite(ENB,HIGH);
  analogWrite(IN3,-abs(par_valule));
  analogWrite(IN4,abs(par_valule));
}


#endif
