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
void event_right();
void event_left();
void control();
MPU6050 Mpu6050;
PID pid_posion;

//************************************
static float angle_z,speed_x,a_z,res,angle;
int16_t ax, ay, az,gx, gy, gz;
//************************************
void encode_init(){
  
  Wire.begin();
  Mpu6050.initialize();
  pid_posion.pid_init();
  motor_init();
  attachInterrupt(0,event_right,CHANGE);
  attachInterrupt(1,event_left,CHANGE);
  FlexiTimer2::set(10,1.0/1000,control);
  FlexiTimer2::start();
  pinMode(PWM1_RIGHT,INPUT);
  pinMode(PWM1_LEFT,INPUT);
  pinMode(PWM2_RIGHT,INPUT);
  pinMode(PWM2_LEFT,INPUT);
  pid_posion.set_pid(20,1,10);

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
   
   speed_x = gx*250.0/32767;  //绕x轴方向旋转的角速度
  a_z = az*2.0*9.8/32767;   //z轴方向上的加速度
  angle_z = atan2(ay,az)*180.0/PI; //z轴的角度，（依靠两个重力的夹角计算得到）
  first_old_complementary_filter(angle_z,speed_x);
  res = pid_posion.caculate(angle_z1,0) +speed_x * 0.01 ;
  //UP_RIGHT(res);
  //UP_LEFT(res);
  Serial.print(gx);
  Serial.print("\t");
  Serial.print(angle_z1);
  Serial.print("\t");
  Serial.println(0);
  count_right = 0;
  count_left = 0;
}

#endif
