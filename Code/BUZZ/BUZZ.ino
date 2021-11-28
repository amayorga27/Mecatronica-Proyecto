long randNumber;

const int speakerPin = 9; //buzzer to arduino pin 9


void setup(){
 
  pinMode(speakerPin, OUTPUT); // Set buzzer - pin 9 as an output
  pinMode(LED_BUILTIN, OUTPUT);
  randomSeed(analogRead(0));
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

void loop(){
 
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
    delay(random(1000, 2000));     
  
}
