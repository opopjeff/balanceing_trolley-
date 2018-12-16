#include <FlexiTimer2.h>
#include"ANO_Tech.h"
#include"TimeMachine.h"
#include"set_motor.h"
#include"PID.h"
#include"Receive.h"
#include"encode.h"

float square_output = 255;

void setup() {
encode_init();
pid.init_pid();
Serial.begin(500000);

}
void loop() {
//UP_RIGHT(square_output);
UP_LEFT(square_output);
ANO_DT_Send_Senser(speeded_right,speeded_left,0,0,0,0,0,0,0);
}




