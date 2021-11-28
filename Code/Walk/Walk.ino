#include <Servo.h>


Servo leftUp;  // create servo object to control a servo
Servo leftDown;
Servo rightUp, rightDown;


void setup() {
  leftUp.attach(8);  // attaches the servo on pin 9 to the servo object
  leftDown.attach(11);
  rightUp.attach(10);
  rightDown.attach(9);
}

void loop() {
  leftUp.write(60);
  rightUp.write(180);
  leftDown.write(90);
  rightDown.write(90);

  delay(700);

  
  leftDown.write(0);
  rightDown.write(180);
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
