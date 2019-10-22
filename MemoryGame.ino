/**
   @file game.ino
   @Memory Game
   @author Tom Chenlian Fu, Yizhe Chang(yichang@g.hmc.edu)


   @version 0.1
   @date complete: 09-30 -2018
   @time used: 2 hr 25  min
*/
int result;
bool newGame = true;
int array_1[8];
int array_2[8];


void setup() {
 //Here I set up the program by setting the Pin output and initiate analognRead by randomizing it.
  // put your setup code here, to run once:
  Serial.begin(9600);
  //Serial.println("Serial ready"); //for debugging
  randomSeed(analogRead(0));
  pinMode(13, OUTPUT); //D13 Red LED
  pinMode(5, OUTPUT);//D5 Green LED



}
void loop() {
  //Here I set a loop for calling four helper functions to complete the loop.
  if (newGame == true) {
    generateLEDFlashes();
    getUserResponse();
    correlate();
    Serial.print("result");
    Serial.print(result);
    newGame = false;
  }
  else {
    promptUser();

  }

}
void generateLEDFlashes() {
  // Here I set the program to have eight randomized LED flashes and store them in array.
  int i = 0;
  int outputtoPin;
  while (i < 8) {
    outputtoPin = random(0, 2);
    if (outputtoPin == 0) {
      analogWrite(13, 255);
      delay(2000);
      analogWrite(13, 0);
      array_1[i] = 0;
      Serial.print(array_1[i]);
      i++;
    }
    else if (outputtoPin == 1) {
      analogWrite(5, 255);
      delay(2000);
      analogWrite(5, 0);
      array_1[i] = 1;
      Serial.print(array_1[i]);
      i++;
    }
  }
}


void getUserResponse() {
  //Here I set up a program to store the user's eight inputs 
  int a;
  while (j < 8) {
    Serial.println("tomisagenius");
    while (Serial.available() == 1) {}
    while (Serial.available() == 0) {} //if no input, while loop forever
    a = Serial.parseInt(); //do something if the user give an input
    if (a == 0 || a == 1)  {
      array_2[j] = a;
      Serial.println(array_2[j]);
      Serial.println(j);
      delay(50);
      j++;
    }

  }
}

void correlate() {
  //Here I compare the user's inputs with the right answer. And return the user's score.
  int j = 0;
  for (int k(0); k < 8 ; k++) {
    if (array_2[k] == array_1[k]) {
      result++;
    }
    else {
      result--;
    }

  }
}

void promptUser() {
  //Here I reinitiate the function.
  while (Serial.available() == 0) {} //if no input, while loop forever
  int a = Serial.parseInt(); //do something if the user give an input
  Serial.println("Do you wanna play it again? Enter 1 ");
  if (a == 1) {
    newGame = true;
  }


}
