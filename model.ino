#include <FlexiTimer2.h>

#include"encode.h"


void setup() {
encode_init();
Serial.begin(38400);
}

void loop() {
  Mpu6050.getMotion6(&ax, &ay, &az, &gx, &gy, &gz);
}




