#include <FlexiTimer2.h>
#include"ANO_Tech.h"
#include"TimeMachine.h"
#include"set_motor.h"
#include"PID.h"

float square_output;
int count_right = 0 ;
int count_left = 0;
double speeded = 0;
int PWM1_RIGHT = 2;
int PWM2_RIGHT = 5;
int PWM1_LEFT = 3;
int PWM2_LEFT = 4;
float UPUP;
void setup() {
FlexiTimer2::set(10,1.0/1000,caculation_right);
pid.init_pid();
Serial.begin(500000);
attachInterrupt(0,event_right,CHANGE);
pid.set_pid(200,2,0);
FlexiTimer2::start();
}
void loop() {
square_output = square_wave(5);
UPUP = pid.caculation_pid(square_output,speeded);
UP_RIGHT(UPUP);
ANO_DT_Send_Senser(square_output,speeded,0,0,0,0,0,0,0);
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

void caculation_right(){
  speeded = (((double)count_right/374)*50);
  count_right = 0;
}

