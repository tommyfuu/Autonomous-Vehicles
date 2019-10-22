/**
   @file hahaha.ino
   @a song named "Hahaha" programmed with Arduino
   @author Tom Chenlian Fu  , Yizhe Chang(yichang@g.hmc.edu)


   @version 0.1
   @date complete: 09-24 -2018
   @time used: 6 hr   min
*/

int frequency[18] = {294, 294, 392, 587, 523, 494, 440, 784, 587, 523, 494, 440, 784, 587, 523, 494, 523, 440};
int duration[18] = {220, 220, 970, 470, 135, 135, 135, 970, 470, 135, 135, 135, 970, 470, 135, 135, 135, 1470};
int pauseBetweenNotes = 300;


void setup() {
  // Here I set up the function to play the music
  for (int thisNote = 0; thisNote < 18; thisNote ++) {
    int duration_1 = duration[thisNote]; // This function sets the duration of each note to the time we want
    tone(4, frequency[thisNote], duration_1); // This function sets the tone so that it gets the right output 
    delay(pauseBetweenNotes); //delay for the time we want after each note
    
  }
}
void loop() {
  // put your main code here, to run repeatedly:

}
