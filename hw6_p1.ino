/** 
 * @file hw6_p1.ino 
 * @brief broadcast a given GC at 4kHz, for detection and correlation debugging only
 * @author Yizhe Chang(yichang@g.hmc.edu) 
 * @version 0.1 
 * @date complete: 10- 31 -2018 
 * @time used: x hr x min
 */

#include"GC_gen.h" //strict in C, not need for Arduino
#include"GC_flash.h"

#define numGCs 9
#define numRegs 5
#define numGCBits 31
#define GCLED 10
#define ReflectanceSensor A4


bool seed1[numRegs] = {0,0,0,0,1};
bool seed2[numGCs][numRegs] = {{0,0,0,0,1},
                               {0,0,0,1,0}, 
                               {0,0,0,1,1},
                               {0,0,1,0,0},
                               {0,0,1,0,1},
                               {0,0,1,1,0},
                               {0,0,1,1,1},
                               {0,1,0,0,0},
                               {0,1,0,0,1}};

bool tap1[numRegs] = {0, 1, 1, 1, 1}; //You can also initialize it by tap1[] = {0,1,1,1,1};
bool tap2[numRegs] = {0, 0, 1, 0, 1};
bool GC_result[numGCs][numGCBits]; //GC result stored here
bool Team;
int refl;
int stage;

unsigned long currentTime;
void setup() {
  stage = 0;
  pinMode(GCLED,OUTPUT);
  pinMode(5,OUTPUT);

  Serial.begin(9600);
  for(int i = 0; i < numGCs; i++){
    GC_gen(seed1, seed2[i], tap1, tap2, GC_result[i]);
  }
  currentTime = micros(); //initialize currentTime, do we need this?
  initSensors();
  initMotors();
  if (digitalRead(3) == 0)
  {
    Team = true;
  }
  else
  {
    Team = false;
  }
  Serial.println(Team);
//  if (Team == true)
//  {
//    GC_reverse();
//  }
}

void loop() {




  refl = analogRead(ReflectanceSensor);
  if(stage == 0)
  {
    
    if(refl < 850) {//white
      //refl = analogRead(ReflectanceSensor);
      forward();
      //while(analogRead(ReflectanceSensor) < 700 && analogRead(ReflectanceSensor) >630){}
    
    }
    else{
      delay(20);
      turnL();
      while(analogRead(ReflectanceSensor) > 800){
        Serial.println(analogRead(ReflectanceSensor));
        stage = 1;
      }
      halt();
      //Serial.println(analogRead(ReflectanceSensor));
      stage = 1;
//      digitalWrite(5,HIGH);
    }
//    else if(refl < 970 && refl > 890){
//      turnL();
//      //while(analogRead(ReflectanceSensor) > 890){}
//    }
//    else{
//      stage = 1;
//      halt();
//      digitalWrite(5,HIGH);
//    }
  }

  else if(stage == 1)
  {
    for(int i = 4; i<9; i++){
      for(int k = 0; k < 2; k++){
        currentTime = broadcastGC(GC_result[i], currentTime, Team); //we are broadcasting GC[0](seed 00001),change the index to broadcast others 
//        currentTime = broadcastGC(GC_result[i], currentTime, Team); //we are broadcasting GC[0](seed 00001),change the index to broadcast others
//        currentTime = broadcastGC(GC_result[i], currentTime, Team); //we are broadcasting GC[0](seed 00001),change the index to broadcast others
      }
      if(refl < 1100 && refl > 900) 
  {
    turnL();
  }
  else if(refl < 880 && refl >700)
  {
    turnR();
    }
  }
    }
//  if(refl < 1100 && refl > 1000) 
//  {
//    turnL();
//  }
//  else if(refl < 880 && refl >700)
//  {
//    turnR();
//    }
//  }

// else if(stage == 2)
//  {
//    for(int i = 4; i<9; i++){
//      for(int k = 0; k < 4; k++){
//        currentTime = broadcastGC(GC_result[i], currentTime, Team); //we are broadcasting GC[0](seed 00001),change the index to broadcast others 
//    //currentTime = broadcastGC(GC_result[i], currentTime, Team); //we are broadcasting GC[0](seed 00001),change the index to broadcast others
//    //currentTime = broadcastGC(GC_result[i], currentTime, Team); //we are broadcasting GC[0](seed 00001),change the index to broadcast others
//      }
//    }
//  if(refl >1000) //Black, going straight
//  {
//    forward();
//  }
//  else if(refl < 900) //A bit to the white, going right
//  {
//    turnR();
//    }
//  }
  
  
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
//forward();
}
