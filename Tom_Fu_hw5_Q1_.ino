//Tom Chenlian Fu
//Time spent: 5h
//Oct.14th.2018


#define LPLUS 9
#define LMINUS 8
#define RPLUS 7
#define RMINUS 12
#define LEN 6
#define REN 11
#define DistanceSensor A1
#define ReflectanceSensor A4
#define Phototransistor A5
bool control;
unsigned long startTime;
unsigned long stopTime;



void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  initSensors();//initialize sensor, in this case, the DistanceSensor
  randomSeed(analogRead(0));

}

void initSensors() {
  pinMode(DistanceSensor, INPUT);//Initialize the DistanceSensor to input
}

void loop() {
  // put your main code here, to run repeatedly:

  float dist = analogRead(DistanceSensor);

  while (dist > 300) {
    dist = analogRead(A1);//Read distance from the DistanceSensor
    delay(500);
    //Serial.println(dist);
  }


  int duration_1 = random(300, 3000);//randomize the time for the first tone between 300 ms and 3000 ms
  tone(4, 200);//The first note plays
  Serial.println("playing first");
  delay(duration_1);//the time for delaying the first note
  noTone(4);
  tone(4, 400);//play second tone
  Serial.println("playing second");
  startTime = millis();

  bool control = true;
  
  while (control == true) {
    dist = analogRead(A1);
    if (dist > 300) {
      stopTime = millis();
      noTone(4);//stop playing right after the hand is moved away from the distance sensor
      Serial.println("Your reaction time is");
      Serial.println(stopTime - startTime);//at the same time of detecting that the hand is away, note down the reaction time
      control = false;
    }
  }
  //while (control) {
  //  if (dist > 300) {
  //    control = false;
  //    tone(4, 0);
  //    aftermovinghand = millis();
  //    Serial.println(aftermovinghand - anotherTime);
  //  }
  //  Serial.println(aftermovinghand - anotherTime);

}
