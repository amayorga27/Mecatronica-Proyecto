#include <Servo.h>


Servo myservo1;  // create servo object to control a servo
Servo myservo2;  // create servo object to control a servo

// constants won't change. They're used here to set pin numbers:
const int buttonPin1 = 2;     // the number of the pushbutton pin
const int buttonPin2 = 3;     // the number of the pushbutton pin

int buttonState1 = 0;         // variable for reading the pushbutton status
int buttonState2 = 0;         // variable for reading the pushbutton status

void setup() {
  pinMode(buttonPin1, INPUT);
  pinMode(buttonPin2, INPUT);
  myservo1.attach(9);  // attaches the servo on pin 9 to the servo object
  myservo2.attach(10);  // attaches the servo on pin 9 to the servo object
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {

  buttonState1 = digitalRead(buttonPin1);
  buttonState2 = digitalRead(buttonPin2);

  if (buttonState1 == HIGH) {
    myservo1.write(180);
  } else {
    myservo1.write(90);
  }

  
  if (buttonState2 == HIGH) {
    myservo2.write(180);
  } else {
    myservo2.write(60);
  }
  
/*
  if (buttonState1 == HIGH) {
    for(int i=0; i<270; i++){
      myservo1.write(i);
     Serial. print(i);
      delay(20);
    }
      myservo1.write(60);
      delay(20);
//    myservo1.write(180);
  } 
  if (buttonState2 == HIGH) {
    for(int i=0; i<270; i++){
      myservo2.write(i);
      Serial.print(i);
      delay(20);
    }
      myservo2.write(180);
      delay(20);
//    myservo2.write(180);

  }
*/  
}
