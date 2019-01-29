#ifndef _SET_MOTOR_H_
#define _SET_MOTOR_H_
#include"Arduino.h"
int ENA = 12;
int IN1 = 5;
int IN2 = 6;
int IN3 = 10;
int IN4 = 9;
int ENB = 13;
void motor_init(){
  pinMode(ENA,OUTPUT);
  pinMode(ENB,OUTPUT);
  pinMode(IN1,OUTPUT);
  pinMode(IN2,OUTPUT);
  pinMode(IN3,OUTPUT);
  pinMode(IN4,OUTPUT);
  
}
void UP_RIGHT(int par_valule){
  digitalWrite(ENA,HIGH);
  
  if(par_valule>=0){
    if(par_valule>255) par_valule = 255;
  
  analogWrite(IN1,abs(par_valule));
  analogWrite(IN2,0);}
  else{
    if(par_valule<-255) par_valule = -255;
  
    analogWrite(IN1,0);
    analogWrite(IN2,abs(par_valule));
  }
}
void UP_LEFT(int par_valule){
  digitalWrite(ENB,HIGH);
  if(par_valule<-255) par_valule = -255;
  if(par_valule>255) par_valule = 255;
  if(par_valule>=0){

  analogWrite(IN3,abs(par_valule));
  analogWrite(IN4,0);}
  else{
    analogWrite(IN3,0);
    analogWrite(IN4,abs(par_valule));
  }
}

#endif
