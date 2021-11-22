#include <Servo.h>

#define echoPin 2 
#define trigPin 3 

Servo leftUp;  // create servo object to control a servo
Servo leftDown;
Servo rightUp, rightDown;


void setup() {
  leftUp.attach(9);  // attaches the servo on pin 9 to the servo object
  leftDown.attach(10);
  rightUp.attach(11);
  rightDown.attach(6);

  pinMode(trigPin, OUTPUT); // Sets the trigPin as an OUTPUT
  pinMode(echoPin, INPUT); // Sets the echoPin as an INPUT
  Serial.begin(9600);
}


void measure() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(1);
  // Sets the trigPin HIGH (ACTIVE) for 10 microseconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(2);
  digitalWrite(trigPin, LOW);
  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(echoPin, HIGH);
  // Calculating the distance
  distance = duration * 0.034 / 2; // Speed of sound wave divided by 2 (go and back)
  // Displays the distance on the Serial Monitor
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");
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

  measure();

//  leftDown.write(60);
//  rightDown.write(60);
//  delay(500);
  
}
