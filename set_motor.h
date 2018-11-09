#ifndef _SET_MOTOR_H_
#define _SET_MOTOR_H_
#include"Arduino.h"
int ENA = 8;
int IN1 = 9;
int IN2 = 10;
int IN3 = 11;
int IN4 = 12;
int ENB = 13;
void UP_RIGHT(int par_valule){
  digitalWrite(ENA,HIGH);
  
  if(par_valule>=0){
    if(par_valule>255){
    par_valule = 255;
  }
  analogWrite(IN1,abs(par_valule));
  analogWrite(IN2,0);}
  else{
    if(par_valule<-255){
    par_valule = -255;
  }
    analogWrite(IN1,0);
    analogWrite(IN2,abs(par_valule));
  }
}
void UP_LEFT(int par_valule){
  digitalWrite(ENB,HIGH);
   if(abs(par_valule)>255){
    par_valule = 255;
  }
  if(par_valule>=0){
  analogWrite(IN3,abs(par_valule));
  analogWrite(IN4,0);}
  else{
    analogWrite(IN3,0);
  analogWrite(IN4,abs(par_valule));
  }
}


#endif
