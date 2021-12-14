#include <Servo.h>


Servo leftUp;  // create servo object to control a servo
Servo leftDown;
Servo rightUp, rightDown;


void setup() {
  leftUp.attach(8);  // attaches the servo on pin 9 to the servo object
  leftDown.attach(9);
  rightUp.attach(10);
  rightDown.attach(11);
}

void loop() {
  leftUp.write(40);
  rightUp.write(180);
  leftDown.write(90);
  rightDown.write(90);

  delay(800);

  
  leftDown.write(0);
  rightDown.write(180);
  delay(400);

  leftUp.write(180);
  rightUp.write(40);
  delay(500);

  leftDown.write(90);
  rightDown.write(90);
  delay(400);

//  leftDown.write(60);
//  rightDown.write(60);
//  delay(500);
  
}
