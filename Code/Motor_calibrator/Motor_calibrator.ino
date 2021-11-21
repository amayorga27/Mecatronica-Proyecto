#include <Servo.h>


Servo myservo;  // create servo object to control a servo

// constants won't change. They're used here to set pin numbers:
const int buttonPin1 = 2;     // the number of the pushbutton pin
const int buttonPin2 = 3;     // the number of the pushbutton pin

int buttonState1 = 0;         // variable for reading the pushbutton status
int buttonState2 = 0;         // variable for reading the pushbutton status

void setup() {
  pinMode(buttonPin1, INPUT);
  pinMode(buttonPin2, INPUT);
  myservo.attach(9);  // attaches the servo on pin 9 to the servo object
}

void loop() {

  buttonState1 = digitalRead(buttonPin1);
  buttonState2 = digitalRead(buttonPin2);
 
  if((buttonState1 == LOW) && (buttonState2 == LOW))
    myservo.write(0);
    
  if((buttonState1 == HIGH) && (buttonState2 == LOW))
    myservo.write(90);
    
  if((buttonState1 == LOW) && (buttonState2 == HIGH))
    myservo.write(40);
    
  if((buttonState1 == HIGH) && (buttonState2 == HIGH))
    myservo.write(180);
}
