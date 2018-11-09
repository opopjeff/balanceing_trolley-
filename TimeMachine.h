//产生方波信号
#ifndef _TIMEMACHINE_H_
#define _TIMEMACHINE_H_
unsigned int count = 0;
int period = 1000;
float square_wave(int val){
  if(++count > period)
  count = 0;
  if(count <= period/2)
  return val;
  else
  return -val;
}
#endif
