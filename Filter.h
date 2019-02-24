#ifndef _FILTER_H_
#define _FILTER_H_
#include <KalmanFilter.h>

//实例化一个卡尔曼滤波器对象，对象名称为 KalFilter
KalmanFilter KalFilter;

//卡尔曼滤波参数

float Q_angle = 0.001, Q_gyro = 0.005;
float R_angle = 0.5 , C_0 = 1;
float K1 = 0.05,dt = 0.005;
int addr = 0;


#endif
