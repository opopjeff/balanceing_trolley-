#include <FlexiTimer2.h>
#include"ANO_Tech.h"
#include"TimeMachine.h"
#include"set_motor.h"
#include"PID.h"
#include"Receive.h"

float square_output;
int count_right = 0 ;
int count_left = 0;
double speeded_right = 0;
double speeded_left = 0;
int PWM1_RIGHT = 2;
int PWM2_RIGHT = 5;
int PWM1_LEFT = 3;
int PWM2_LEFT = 4;
float UPUP_right;
float UPUP_left;
void setup() {
FlexiTimer2::set(5,1.0/1000,caculation);
pid.init_pid();
Serial.begin(500000);
attachInterrupt(0,event_right,CHANGE);
attachInterrupt(1,event_left,CHANGE);
pid.set_pid(1500,2,1);
pid.i_max(20);
FlexiTimer2::start();
}
void loop() {

square_output = square_wave(4);
UPUP_right = pid.caculation_pid(square_output,speeded_right);
UP_RIGHT(UPUP_right);
UPUP_left = pid.caculation_pid(square_output,speeded_left);
UP_LEFT(UPUP_left);
ANO_DT_Send_Senser(square_output,speeded_right,pid.KP,pid.KI,pid.KD,speeded_left,0,0,0);
while(Serial.available()){
  para_val();
}
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
  speeded_left = (((double)count_left*100)/374);
  //Serial.println(speeded);
  count_right = 0;
}


