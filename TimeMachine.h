//产生方波信号
#ifndef _TIMEMACHINE_H_
#define _TIMEMACHINE_H_
unsigned int count;
int period = 2000;
float square_wave(unsigned long val){
  if(count<=period/2){
    count++;
    return val;
  }
  if(count<period){
    count++;
    return -val;
  }
  else {
    count = 0;
  }
}
#endif
