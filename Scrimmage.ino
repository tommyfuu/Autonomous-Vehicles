//Scrimmage

//Tom Fu and Caitlin Huang

//Tom Chenlian Fu
//Lab 6: Line Following
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
int threshold = 900;


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  initSensors();

}

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
void turnR(){
  digitalWrite(LEN,HIGH);
  digitalWrite(LPLUS, HIGH);
  digitalWrite(LMINUS,HIGH);
  digitalWrite(REN, HIGH);
  digitalWrite(RPLUS,HIGH);
  digitalWrite(RMINUS,LOW);
  

}
void turnL(){
  digitalWrite(LEN, HIGH);
  digitalWrite(LPLUS, HIGH);
  digitalWrite(LMINUS,LOW);
  digitalWrite(REN, HIGH);
  digitalWrite(RPLUS,HIGH);
  digitalWrite(RMINUS,HIGH);

  

}

void loop() {
  // put your main code here, to run repeatedly:

  float refl = analogRead(ReflectanceSensor);
  Serial.println(refl);

  //forward();

  if(refl < threshold) {
    //refl = analogRead(ReflectanceSensor);
    turnR();


  }

  else if(refl > threshold) {
    //refl = analogRead(ReflectanceSensor);
    forward();
    delay(50);
    turnL();
    delay(100);

  }
//
//  while (refl < threshold) {
//    //refl = analogRead(ReflectanceSensor);
//    turnR();
//    forward();
//
//  }
//    while (refl > threshold) {
//    //refl = analogRead(ReflectanceSensor);
//    forward();
//    delay(100);


//    }
}




#define AVERAGE Threshold
#define PhotoTransistor A5

int rawValue[31];
bool CorrelateStore[8][31];

void Detection() {
  //Get all the values
  unsigned long startTime = micros();
  unsigned long goalTime;
  for (int i = 0; i < 31; i++) {
    rawValue[i] = analogRead(PhotoTransistor);
    goalTime = startTime + 250;
    while (micros() < goalTime);
    startTime = goalTime;
  }

  //Calculate average to get the threshold
  int sum = 0;

  for (int j = 0; j < 31; j++ ) {
    sum += rawValue[j];
  }

  float average = sum / 31;

  //store every reading as binary numbers
  for (int k = 0; k < 31; k++) {
    if (rawValue[k] > average) {
      raw[k] = 0;
    }
    else {
      raw[k] = 1;
    }
  }
  //
  Serial.println("Detection value:");
  Serial.println();
    for(int i = 0; i<31; i++){
      Serial.print(raw[i]);
      Serial.print(" ");
    }

  return;


}



int correlation(bool GC1[], bool GC2[])
{
  int maxCor = -32768;
  //Serial.println("coore");
  for (int i = 0; i < 31; i++) //for each offset
  {
    bool tempGC[31];
    for (int j = 0; j < 31; ++j) {
      tempGC[j] = GC2[(j + i) % 31];//a temporary GC that temporarily stores the code after offsetting
    }

    int cor = 0;
    for (int j = 0; j < 31; j++) //for each element
    {

      if (GC1[j] == tempGC[j]) //update correlation
      {
        cor++;
      }
      else
      {
        cor--;
      }
  

      //Serial.println("YES");
//      Serial.print(cor);
//      Serial.print(" ");

      maxCor = max(maxCor, cor);

    }



//    int cor = 0;
//    for (int j = 0; j < 31; j++) //for each element
//    {
//      if (GC1[j] == GC2[j]) //update correlation
//      {
//        cor++;
//      }
//      else
//      {
//        cor--;
//      }
//      //    }
//
//      //Serial.println("YES");
//      Serial.print(cor);
//      Serial.print(" ");
//
//      maxCor = max(maxCor, cor);
//
//      //    if(cor > maxCor)
//      //    {
//      //      maxCor = cor;
//      //    }
//
//      int temp = GC1[30];
//      for (int k = 30; k > 0; k--) //offset by one
//      {
//        GC1[k] = GC1[k - 1];
//      }
//      GC1[0] = temp;
    }
//    Serial.println();
//    Serial.print("MAX: ");
//    Serial.println(maxCor);
//    Serial.println();
    return maxCor;
  }
