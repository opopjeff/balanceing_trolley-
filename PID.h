#ifndef _PID_H_
#define _PID_H_

class PID{
  public :
    float Balance_KP;
    float Balance_KD;
    float Speed_KP;
    float Speed_KI;


   public:
     float balance_PD(float,float);//位置PD控制
     float speed_PI(long,long);//速度PI控制
     void PID_init();
     void set_Balance_PID(float,float);
     void set_Speed_PID(float,float);
};

void PID::PID_init(){
     Balance_KP =0 ;
     
     Balance_KD = 0;
     Speed_KP =0 ;
     Speed_KI = 0;
     
}

void PID::set_Balance_PID(float kp,float kd){
     Balance_KP = kp;
     Balance_KD = kd;
}
void PID::set_Speed_PID(float kp,float ki){
  Speed_KP = kp;
  Speed_KI = ki;
}

float PID::balance_PD(float angle , float speed_x){
  return Balance_KP * angle + Balance_KD * speed_x;
}

float PID::speed_PI(long count_right,long count_left){
  static float  Encoder_Least, Encoder ;
  static float Encoder_Integral , Velocity;

  Encoder_Least = ( count_right + count_left) - 0;    //获取最新的轮子速度和目标值的差
  Encoder = 0.7 * Encoder + 0.3 * Encoder_Least ; // 对编码器转速采用一阶低通滤波
  Encoder_Integral += Encoder ;  

  Encoder_Integral = (Encoder_Integral > 21000 ? 21000:Encoder_Integral);
  Encoder_Integral = (Encoder_Integral < -21000? -21000:Encoder_Integral);

  Velocity = Speed_KP * Encoder + Speed_KI * Encoder_Integral;
  return Velocity;
}
#endif
