#define IN1 3 
#define IN2 4 
#define ENA 10 

void setup() { 
  pinMode(IN1,OUTPUT); 
  pinMode(IN2,OUTPUT); 
  pinMode(ENA,OUTPUT); 

 }
void loop(){
  digitalWrite(IN1,LOW); 
  digitalWrite(IN2,HIGH); 
  digitalWrite(ENA,HIGH); 
  delay(20000); 

  for (int i = 50; i < 255; ++i) { 
    digitalWrite(IN1,LOW); 
    digitalWrite(IN2,HIGH); 
    analogWrite(ENA,i); 
    delay(2000); 
  } //Speed Up 

 }

