#ifndef _FILTER_H_
#define _FILTER_H_

static float angle_z1 ;//经过互补滤波后得到的角度值
float K1 = 0.05,dt = 0.005;
void first_old_complementary_filter(float,float);

void first_old_complementary_filter(float angle_z,float speed_x){    //一阶互补滤波
  angle_z1 = K1*angle_z + (1 - K1)*(angle_z1 + speed_x *dt);
}

#endif
