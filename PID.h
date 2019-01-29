#ifndef _PID_H_
#define _PID_H_

class PID{
  public:
      void pid_init();
      float caculate(float , float);
      void set_pid(float , float , float);

   public:
      float KP,KD,KI;
      float error_p;
      float error_i;
      float error_d;
      float error_last;
      float result;  
};

void PID::pid_init(){
  KP = 0;
  KD = 0;
  KI = 0;
  error_p = 0;
  result = 0;
  error_d = 0;
  error_i = 0;
  error_last = 0;
}


void PID::set_pid(float kp,float kd,float ki){
  KP = kp;
  KD = kd;
  KI = ki;
}

float PID::caculate(float real,float target){
 error_p = target - real;
 error_i = error_i + (target - real)*0.01;
 error_d = (error_p - error_last);
 error_last = error_p;

 result = error_p*KP + error_i*KI+error_d*KD;
 
 result = (result>255)?255:result;
 result = (result<-255)?-255:result;

 return result;
}


#endif
