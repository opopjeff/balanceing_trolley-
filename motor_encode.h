#ifndef _MOTOR_ENCODE_H_
#define _MOTOR_ENCODE_H_
#include"Arduino.h"

int count_right =0;
int count_left =0;
float square_output;
void event_right(){
  count_right++;
}

void event_left(){
  count_left++;
}
void caculation_right(){
  float b = (float)count_right/374/0.10;
  count_right = 0;
  ANO_DT_Send_Senser(square_output,b,0,0,0,0,0,0,0);
}
void caculation_left(float time_s){
  float a =  (float)count_left/374/0.10;
  count_left = 0;
  ANO_DT_Send_Senser(square_output,a,0,0,0,0,0,0,0);
}

#endif
