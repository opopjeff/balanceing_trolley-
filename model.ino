#include"ANO_Tech.h"
#include"TimeMachine.h"
#include"set_motor.h"
#include"motor_encode.h"
float data[2];
float square_output;
void setup() {
Serial.begin(500000);
UP_RIGHT(232,50);
UP_LEFT(100,50);
}

void loop() {
data[2] =  motor_encode_init();
square_output = square_wave(50);
ANO_DT_Send_Senser(square_output,0,0,0,0,0,0,0,0);
}
