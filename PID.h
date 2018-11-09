#ifndef _PID_H_
#define _PID_H_

class PID{
  public:
  void init_pid();
  void set_pid(float,float,float);
  float caculation_pid(float,float);

  public:
  float KP;
  float KD;
  float KI;
  volatile float error;
  volatile float error_d;
  volatile float error_i;
  volatile float result;
  volatile float error_last;
};

void PID::init_pid(){
  KP=0;KI=0;KD=0;error = 0;error_d = 0;
  error_i =0 ;
}
void PID::set_pid(float kp,float ki,float kd){
  KP = kp;
  KI = ki;
  KD = kd;
}

float PID::caculation_pid(float target,float real){
  error = target - real;
  error_d = error-error_last;
  error_i = error_i+(target - real)*0.01;
  error_last = error;
  result = KP*error+KI*error_i+KD*error_d;
  return result;
}
PID pid;
#endif
