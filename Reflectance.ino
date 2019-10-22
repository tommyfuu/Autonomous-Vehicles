//Tom Chenlian Fu
//Lab 6: Line Following Use
//Oct.16th.2018


#define LPLUS 9
#define LMINUS 8
#define RPLUS 7
#define RMINUS 12
#define LEN 6
#define REN 11
#define DistanceSensor A1
#define ReflectanceSensor A4
#define Phototransistor A5
#define SPEEDL 140
#define SPEEDR 100
int threshold = 55;




void initSensors() {
  pinMode(ReflectanceSensor, INPUT);
}

void initMotors(){
  pinMode(LPLUS, OUTPUT);
  pinMode(LMINUS, OUTPUT);
  pinMode(RPLUS, OUTPUT);
  pinMode(RMINUS, OUTPUT);
  pinMode(LEN, OUTPUT);
  pinMode(REN, OUTPUT);
  //digitalWrite(LEN, HIGH);
  //digitalWrite(REN, HIGH);
  analogWrite(LEN, SPEEDL);
  analogWrite(REN, SPEEDR);
}




void halt(){
  digitalWrite(LPLUS, LOW);
  digitalWrite(LMINUS,LOW);
  digitalWrite(RPLUS,LOW);
  digitalWrite(RMINUS,LOW);
}

void forward(){
  //analogWrite(LPLUS, 600);
  digitalWrite(LPLUS, LOW);
  digitalWrite(LMINUS,HIGH);
  //analogWrite(RPLUS, 300);
  digitalWrite(RPLUS,HIGH);
  digitalWrite(RMINUS,LOW);
}


void backward(){
  digitalWrite(LPLUS, LOW);
  digitalWrite(LMINUS,HIGH);
  digitalWrite(RPLUS,LOW);
  digitalWrite(RMINUS,HIGH);
  
}
void turnL(){
 // analogWrite(LEN,256);
  digitalWrite(LPLUS, HIGH);
  digitalWrite(LMINUS,HIGH);
 // analogWrite(REN,256);
  digitalWrite(RPLUS,HIGH);
  digitalWrite(RMINUS,LOW);
  

}

void turnR(){
  //analogWrite(LEN,256);
  digitalWrite(LPLUS, LOW);
  digitalWrite(LMINUS,HIGH);
  //analogWrite(REN,256);
  digitalWrite(RPLUS,HIGH);
  digitalWrite(RMINUS,HIGH);

  

}
