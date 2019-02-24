//编码器数据读取
#ifndef _ENCODE_H_
#define _ENCODE_H_
#include"Arduino.h"
#include"Filter.h"
#include "MPU6050.h"
#include "Wire.h"
#include "I2Cdev.h"
#include"PID.h"
#include"set_motor.h"


int PWM1_RIGHT = 2;
int PWM2_RIGHT = 7;
int PWM1_LEFT = 3;
int PWM2_LEFT = 4;
static long count_right = 0;
static long count_left = 0;
int speed_id = 0;

void event_right();
void event_left();
void control();
MPU6050 Mpu6050;
PID pid;

//************************************
static float angle,Gyro_x,res;
int16_t ax, ay, az,gx, gy, gz;
//************************************
void encode_init(){
  
  Wire.begin();
  Mpu6050.initialize();
  
  motor_init();
  attachInterrupt(0,event_right,CHANGE);
  attachInterrupt(1,event_left,CHANGE);
  FlexiTimer2::set(5,1.0/1000,control);
  FlexiTimer2::start();
  pinMode(PWM1_RIGHT,INPUT);
  pinMode(PWM1_LEFT,INPUT);
  pinMode(PWM2_RIGHT,INPUT);
  pinMode(PWM2_LEFT,INPUT);
//=======================================
  pid.PID_init();
  pid.set_Balance_PID(22, 1);
  pid.set_Speed_PID( 100, 5);
//=======================================
}

void event_right(){
  
      if(digitalRead(PWM1_RIGHT)==0)  {
        if(digitalRead(PWM2_RIGHT) == 0) count_right++;
        else count_right--;
        }
      else {
        if(digitalRead(PWM2_RIGHT) == 0) count_right--;
        else count_right++;
      }
}

  void event_left(){
  
  if(digitalRead(PWM1_LEFT)==0)  {
        if(digitalRead(PWM2_LEFT) == 0) count_left--;
        else count_left++;
        }
      else {
        if(digitalRead(PWM2_LEFT) == 0) count_left++;
        else count_left--;
      }
}

void control(){
   angle = KalFilter.angle;  //卡尔曼滤波后得到的角度
   Gyro_x = KalFilter.Gyro_x; //卡尔曼滤波后得到的x轴角速度
   res = -pid.balance_PD(angle ,Gyro_x); //直立PD控制，控制周期5ms
   if(speed_id++ >8){ //速度PI，控制周期40ms
    speed_id = 0;
    res += pid.speed_PI(count_right , count_left); 
   }
   UP_RIGHT(res);
   UP_LEFT(res);

  count_right = 0;
  count_left = 0;
}

#endif
