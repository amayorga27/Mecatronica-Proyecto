#include <Servo.h>

int comportamiento = 0;
long randNumber;
const int speakerPin = 3; //buzzer to arduino pin 3
const int sensorPin = 4;
const int pingPin = 7; // Trigger Pin of Ultrasonic Sensor
const int echoPin = 6; // Echo Pin of Ultrasonic Sensor

bool stand = false;
bool greeted = false;

Servo leftUp, leftDown, rightUp, rightDown;  // create servo object to control the servo

void setup() {
  Serial.begin(9600);   //iniciar puerto serie
  
  pinMode(sensorPin , INPUT);  //definir pin como entrada
  pinMode(speakerPin, OUTPUT); // Set buzzer
  pinMode(LED_BUILTIN, OUTPUT);
  randomSeed(analogRead(0));
  
  leftUp.attach(8);  // attaches the servo on pin 8 to the servo object
  leftDown.attach(9);
  rightUp.attach(10);
  rightDown.attach(11);
  
  stand = false;
  greeted = false;
}

long microsecondsToCentimeters(long microseconds) {
   return microseconds / 29 / 2;
}

bool obstacle(){
   long duration, cm;
   pinMode(pingPin, OUTPUT);
   digitalWrite(pingPin, LOW);
   delayMicroseconds(2);
   digitalWrite(pingPin, HIGH);
   delayMicroseconds(10);
   digitalWrite(pingPin, LOW);
   pinMode(echoPin, INPUT);
   duration = pulseIn(echoPin, HIGH);
   cm = microsecondsToCentimeters(duration);
   
   if (cm < 15 && cm !=0){
    digitalWrite(LED_BUILTIN, HIGH);
    return true;
   }
   else{
    digitalWrite(LED_BUILTIN, LOW);
    return false;
   }
   delay(100);
  
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
void standing(){
  leftUp.write(20);
  rightUp.write(120);
  leftDown.write(90);
  rightDown.write(90);
  delay(300);
  leftDown.write(0);
  rightDown.write(180);
  delay(300);
}

void one_step() {
  leftUp.write(0);
  rightUp.write(140);
  leftDown.write(90);
  rightDown.write(90);
  delay(800);
  
  leftDown.write(0);
  rightDown.write(180);
  delay(200);

  leftUp.write(140);
  rightUp.write(0);
  delay(300);

  leftDown.write(90);
  rightDown.write(90);
  delay(200);
}

void turn(){
  leftUp.write(140);
  rightUp.write(140);
  leftDown.write(90);
  rightDown.write(90);
  delay(800);
  
  leftDown.write(0);
  rightDown.write(180);
  delay(200);

  leftUp.write(0);
  rightUp.write(0);
  delay(300);

  leftDown.write(90);
  rightDown.write(90);
  delay(200);
}

void walk(){
  if (!obstacle()){
    one_step();
  } else {
    turn();
    turn();
//    turn();
  }
}

void dance(){
  dance1();
  if(obstacle()){
    angry();
  }
}

void dance1(){
  leftUp.write(110);
  rightUp.write(30);
  delay(300);

  leftDown.write(90);
  rightDown.write(90);
  delay(100);
  leftDown.write(0);
  rightDown.write(0);
  delay(300);
  leftDown.write(180);
  rightDown.write(180);
  delay(300);
}

void angry(){
  leftDown.write(90);
  rightDown.write(90);
  delay(100);
  leftUp.write(100);
  rightUp.write(0);
  delay(300);
  leftDown.write(0);
  rightDown.write(180);
  delay(200);
  
  leftUp.write(140);
  rightUp.write(40);
  delay(300);
  leftUp.write(100);
  rightUp.write(0);
  delay(300);
  leftUp.write(140);
  rightUp.write(40);
  delay(300);
  leftUp.write(100);
  rightUp.write(0);
  delay(300);
}

void greet(){
  leftDown.write(90);
  rightDown.write(90);
  delay(100);
  
  leftUp.write(30);
  rightUp.write(70);
  delay(300);

  
  rightDown.write(0);
  delay(400);
  leftUp.write(20);
  delay(100);
  leftUp.write(90);
  delay(100);
  leftUp.write(20);
  delay(100);
  leftUp.write(90);
  delay(100);
  leftUp.write(20);
  delay(100);
  leftUp.write(90);
  delay(100);
  leftUp.write(20);
  delay(100);
  leftUp.write(90);
  delay(100);
  leftUp.write(20);
  delay(100);
  leftUp.write(90);
  delay(100);
  leftUp.write(20);
  delay(100);
  leftUp.write(90);
  delay(100);
  leftUp.write(30);
  delay(100);
  leftDown.write(90);
  delay(600);

  
}


void loop(){
  int value = 0;

  if(!greeted){
    greet();
    greeted = true;
  }
  
  value = digitalRead(sensorPin );  //lectura digital de pin
  
  if (value == LOW) {
    digitalWrite(LED_BUILTIN, HIGH);
      comportamiento++;
      delay(600);
    digitalWrite(LED_BUILTIN, LOW);
  }
  if (comportamiento == 3)  comportamiento = 0;

  switch(comportamiento) {
    case 0:
      if (!stand){
        stand = true;
        standing();
      }
      break;
    case 1:
      stand = false;
      walk();
      break;
    case 2:
//      speak();
//      delay(400);
      dance();
      break;
      
//    case 3:
//      dance();
//      break;
  }
  
  
}
