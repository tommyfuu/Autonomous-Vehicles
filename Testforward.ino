#define LPLUS 9
#define LMINUS 8
#define RPLUS 7
#define RMINUS 12
#define LEN 6
#define REN 11
#define DistanceSensor A1
#define ReflectanceSensor A4
#define Phototransistor A5



void initMotors(){
  pinMode(LPLUS, OUTPUT);
  pinMode(LMINUS, OUTPUT);
  pinMode(RPLUS, OUTPUT);
  pinMode(RMINUS, OUTPUT);
  pinMode(LEN, OUTPUT);
  pinMode(REN, OUTPUT);
}




void halt(){
  digitalWrite(LEN, HIGH);
  digitalWrite(LPLUS, LOW);
  digitalWrite(LMINUS,LOW);
  digitalWrite(REN, HIGH);
  digitalWrite(RPLUS,LOW);
  digitalWrite(RMINUS,LOW);
}

void forward(){
  digitalWrite(LEN, HIGH);
  digitalWrite(LPLUS, HIGH);
  digitalWrite(LMINUS,LOW);
  digitalWrite(REN, HIGH);
  digitalWrite(RPLUS,HIGH);
  digitalWrite(RMINUS,LOW);
}


void backward(){
  digitalWrite(LEN, HIGH);
  digitalWrite(LPLUS, LOW);
  digitalWrite(LMINUS,HIGH);
  digitalWrite(REN, HIGH);
  digitalWrite(RPLUS,LOW);
  digitalWrite(RMINUS,HIGH);
  
}
void turnL(){
  digitalWrite(LEN,HIGH);
  digitalWrite(LPLUS, HIGH);
  digitalWrite(LMINUS,HIGH);
  digitalWrite(REN, HIGH);
  digitalWrite(RPLUS,HIGH);
  digitalWrite(RMINUS,LOW);
  

}
void turnR(){
  digitalWrite(LEN, HIGH);
  digitalWrite(LPLUS, HIGH);
  digitalWrite(LMINUS,LOW);
  digitalWrite(REN, HIGH);
  digitalWrite(RPLUS,HIGH);
  digitalWrite(RMINUS,HIGH);

  

}


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  initMotors();
  
}

void loop() {
  // put your main code here, to run repeatedly:
forward();
}
