#include <FlexiTimer2.h>
#include"encode.h"
//#include"Receive.h"
void setup() {
encode_init();
Serial.begin(38400);
}

void loop() {
  Mpu6050.getMotion6(&ax, &ay, &az, &gx, &gy, &gz);
  KalFilter.Angletest(ax, ay, az, gx, gy, gz, dt, Q_angle, Q_gyro, R_angle, C_0, K1);          //通过卡尔曼滤波获取角度
  //while(Serial.available())
    //ParameterReceive();
}




