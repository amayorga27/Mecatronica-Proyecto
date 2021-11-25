const int sensorPin = 9;

void setup() {
  Serial.begin(9600);   //iniciar puerto serie
  pinMode(sensorPin , INPUT);  //definir pin como entrada
  pinMode(LED_BUILTIN, OUTPUT);
}
 
void loop(){
  int value = 0;
  value = digitalRead(sensorPin );  //lectura digital de pin
 
  if (value == HIGH) {
      digitalWrite(LED_BUILTIN, HIGH);
  }
  delay(100);
  digitalWrite(LED_BUILTIN, LOW);
}
