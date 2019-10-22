/**
   @file ps1_1_1_Tom_Fu.ino
   @brief learning or guessing comparison and logical operators in c
   @author  Tom Chenlian Fu(tfu@g.hmc.edu) (Collaborated with Vadim Mathys and Jenny Wathanakulchat) ,Yizhe Chang(yichang@g.hmc.edu)


   @version 0.1
   @date complete: 09-16-2018
   @total time spent:     0 hour 50   min
*/

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  //Serial.println("Serial ready"); //for debugging
  pinMode(13, OUTPUT); //D13 Red LED
  pinMode(5, OUTPUT);//D5 Green LED

}

  int pressed;
  int greenBrightness;


void loop() {
  // put your main code here, to run repeatedly:
   
  if (Serial.available()){
    pressed = Serial.parseInt(); //see below for Serial.read()
    // now do something with it
    if (pressed == 1) {
      analogWrite(13, 255);//turn the red light on
    }
    else if (pressed == 2){
      analogWrite(13, 0);//turn the red light off
    }
    else if (pressed == 3){
      analogWrite(5, 255);//turn the green light on
      
  }
    else if (pressed == 4){
      analogWrite(5, 0);//turn the green light off
  }
    else if (pressed == 5){
      greenBrightness += 20;
      analogWrite(5, greenBrightness);//turn the green light brighter
  }
    else if (pressed == 6){
      greenBrightness -= 20;
      analogWrite(5, greenBrightness);//turn the green light less brighter
  }
  }
}
