#define LPLUS 9
#define LMINUS 8
#define RPLUS 7
#define RMINUS 12
#define LEN 6
#define REN 11
#define DistanceSensor A1
#define ReflectanceSensor A4
#define Phototransistor A5


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  initSensors();
  
}

void loop() {
  // put your main code here, to run repeatedly:
  TestReflectanceSensor();
}


void initSensors(){
  pinMode(DistanceSensor, INPUT);
  pinMode(ReflectanceSensor, INPUT);
  pinMode(Phototransistor, INPUT);

}


void TestReflectanceSensor(){
  float refl =analogRead(ReflectanceSensor);
  Serial.println(refl);
  delay(200);
}
