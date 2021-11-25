#include <Servo.h>
long randNumber;

int comportamiento = 0;

const int speakerPin = 3; //buzzer to arduino pin 3
const int sensorPin = 4;

Servo leftUp, leftDown, rightUp, rightDown;  // create servo object to control a servo

void setup() {
  Serial.begin(9600);   //iniciar puerto serie
  
  pinMode(sensorPin , INPUT);  //definir pin como entrada
  pinMode(speakerPin, OUTPUT); // Set buzzer
  pinMode(LED_BUILTIN, OUTPUT);
  randomSeed(analogRead(0));
  
  leftUp.attach(8);  // attaches the servo on pin 8 to the servo object
  leftDown.attach(11);
  rightUp.attach(10);
  rightDown.attach(9);
}


void phrase1() {
    
    int k = random(1000,2000);
    digitalWrite(LED_BUILTIN, HIGH);
    for (int i = 0; i <=  random(100,2000); i++){
        
        tone(speakerPin, k+(-i*2));          
        delay(random(.9,2));             
    } 
    digitalWrite(LED_BUILTIN, LOW);   
    for (int i = 0; i <= random(100,1000); i++){
        
        tone(speakerPin, k + (i * 10));          
        delay(random(.9,2));             
    }
} 

void phrase2() {
    
    int k = random(1000,2000);
    digitalWrite(LED_BUILTIN, HIGH);  
    for (int i = 0; i <= random(100,2000); i++){
        
        tone(speakerPin, k+(i*2));          
        delay(random(.9,2));             
    } 
    digitalWrite(LED_BUILTIN, LOW);   
    for (int i = 0; i <= random(100,1000); i++){
        
        tone(speakerPin, k + (-i * 10));          
        delay(random(.9,2));             
    } 
}

void speak() {
  int K = 2000;
    switch (random(1,7)) {
        
        case 1:phrase1(); break;
        case 2:phrase2(); break;
        case 3:phrase1(); phrase2(); break;
        case 4:phrase1(); phrase2(); phrase1();break;
        case 5:phrase1(); phrase2(); phrase1(); phrase2(); phrase1();break;
        case 6:phrase2(); phrase1(); phrase2(); break;
    }
    for (int i = 0; i <= random(3, 9); i++){
        
        digitalWrite(LED_BUILTIN, HIGH);  
        tone(speakerPin, K + random(-1700, 2000));          
        delay(random(70, 170));  
        digitalWrite(LED_BUILTIN, LOW);           
        noTone(speakerPin);         
        delay(random(0, 30));             
    } 
    noTone(speakerPin);
}

void stand() {
  leftUp.write(60);
  rightUp.write(180);
  leftDown.write(90);
  rightDown.write(90);

  leftDown.write(0);
  rightDown.write(180);
  delay(300);
}

void walk() {
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
}


void dance() {
  leftUp.write(180);
  rightUp.write(180);
  leftDown.write(90);
  rightDown.write(90);
  delay(500);

  leftUp.write(40);
  rightUp.write(40);
  leftDown.write(90);
  rightDown.write(90);
  delay(500);
  
  leftUp.write(40);
  rightUp.write(40);
  leftDown.write(180);
  rightDown.write(0);
  delay(500);
  
  leftUp.write(40);
  rightUp.write(40);
  leftDown.write(90);
  rightDown.write(90);
  delay(500);
  
  leftUp.write(180);
  rightUp.write(180);
  leftDown.write(90);
  rightDown.write(90);
  delay(500);
  
  leftUp.write(180);
  rightUp.write(180);
  leftDown.write(180);
  rightDown.write(0);
  delay(500);
  
  leftUp.write(180);
  rightUp.write(180);
  leftDown.write(90);
  rightDown.write(90);
}

void greet() {    // Por hacer
  stand();
  
  leftUp.write(180);
  rightUp.write(180);
  leftDown.write(90);
  rightDown.write(90);
  delay(500);
  
  stand();
}




void loop(){
  int value = 0;
  value = digitalRead(sensorPin );  //lectura digital de pin
  
  if (value == HIGH) {
      digitalWrite(LED_BUILTIN, HIGH);
      comportamiento++;
      delay(600);
  }
  digitalWrite(LED_BUILTIN, LOW);
  if (comportamiento == 3)  comportamiento = 0;

  switch(comportamiento) {
    case 0:
      walk();
      break;
    case 1:
      dance();
      break;
    case 2:
      stand();
      speak();
      break;
  }
  
  
}
