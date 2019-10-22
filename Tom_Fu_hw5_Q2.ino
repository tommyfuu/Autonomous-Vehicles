//Tom Chenlian Fu
//Time spent: 1h
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
int frequency[18] = {294, 294, 392, 587, 523, 494, 440, 784, 587, 523, 494, 440, 784, 587, 523, 494, 523, 440};
int duration[18] = {220, 220, 970, 470, 135, 135, 135, 970, 470, 135, 135, 135, 970, 470, 135, 135, 135, 1470};
int pauseBetweenNotes = 300;


 void setup() {
  // put your setup code here, to run once:
    Serial.begin(9600);
  initSensors();//initialize sensor, in this case, the DistanceSensor
  randomSeed(analogRead(0));
 }
 
  void initSensors() {
    pinMode(Phototransistor, INPUT);//initialize the phototransistor to INPUT

  }

  void loop() {
    // put your main code here, to run repeatedly:
    float photo = analogRead(Phototransistor);//keep detecting the light from the photootransistor

    while (photo > 100) {
      photo = analogRead(A5);

      for (int thisNote = 0; thisNote < 18; thisNote ++) {
        int duration_1 = duration[thisNote]; // This function sets the duration of each note to the time we want
        tone(4, frequency[thisNote],duration_1); // This function sets the tone so that it gets the right output
        //delay(duration_1); //delay for the time we want after each note
        
      }
    }

    tone(4, 400);//after detecting the hand, play the second note
    delay(1000);//delay the second note for 1000 ms
    noTone(4);


  }
