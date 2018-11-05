#include <FlexiTimer2.h>
#include"ANO_Tech.h"
#include"TimeMachine.h"
#include"set_motor.h"
#include"motor_encode.h"

int PWM1_RIGHT = 2;
int PWM2_RIGHT = 5;
int PWM1_LEFT = 3;
int PWM2_LEFT = 4;

void setup() {
FlexiTimer2::set(100,1.0/1000,caculation_right);
Serial.begin(500000);
FlexiTimer2::start();
attachInterrupt(0,event_right,RISING);
UP_RIGHT(255);
}

void loop() {

square_output = square_wave(50);
}
