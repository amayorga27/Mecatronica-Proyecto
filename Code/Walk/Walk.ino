#include <Servo.h>


Servo leftUp;  // create servo object to control a servo
Servo leftDown;
Servo rightUp, rightDown;


void setup() {
  leftUp.attach(9);  // attaches the servo on pin 9 to the servo object
  leftDown.attach(10);
  rightUp.attach(11);
  rightDown.attach(6);
}

void loop() {
  leftUp.write(60);
  rightUp.write(180);
  leftDown.write(90);
  rightDown.write(90);

  delay(700);

  
  leftDown.write(180);
  rightDown.write(0);
  delay(200);

  leftUp.write(180);
  rightUp.write(60);
  delay(200);

  leftDown.write(90);
  rightDown.write(90);
  delay(200);

//  leftDown.write(60);
//  rightDown.write(60);
//  delay(500);
  
}
