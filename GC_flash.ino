#include"GC_flash.h"

unsigned long broadcastGC(bool GC[], unsigned long oldGoalTime, bool flipped){
  unsigned long goalTime = oldGoalTime;
  for(int i = 0; i < 31; i++){
    if(GC[i] != flipped){
      digitalWrite(GCLED, HIGH);
    }
    else{
      digitalWrite(GCLED, LOW);
    }
    while(micros() < goalTime);
    goalTime = goalTime + 250;
  }
  return goalTime;
}
