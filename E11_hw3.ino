bool array_1[31];
bool array_2[31];
bool GoldCode[31];


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  bool seed_0[5] = {0, 0, 0, 0, 1};
  bool seed_1[5] = {0, 0, 0, 0, 1};
  bool seed_2[5] = {0, 0, 0, 1, 0};
  bool seed_3[5] = {0, 0, 0, 1, 1};
  bool seed_4[5] = {0, 0, 1, 0, 0};
  bool seed_5[5] = {0, 0, 1, 0, 1};
  bool seed_6[5] = {0, 0, 1, 1, 0};
  bool seed_7[5] = {0, 0, 1, 1, 1};
  bool seed_8[5] = {0, 1, 0, 0, 0};

  LFSR1(seed_0);
  
  LFSR2(seed_1);
  GC(array_1, array_2);
  Serial.println();
  
//  LFSR2(seed_2);
//  GC(array_1, array_2);
//  Serial.println();
//  
//  LFSR2(seed_3);
//  GC(array_1, array_2);
//  Serial.println();
//  
//  LFSR2(seed_4);
//  GC(array_1, array_2);
//  Serial.println();
//  
//  LFSR2(seed_5);
//  GC(array_1, array_2);
//  Serial.println();
//  
//  LFSR2(seed_6);
//  GC(array_1, array_2);
//  Serial.println();
//  
//  LFSR2(seed_7);
//  GC(array_1, array_2);
//  Serial.println();
//  
//  LFSR2(seed_8);
//  GC(array_1, array_2);
}

void LFSR1(bool seed[]) {
  bool array_t[5];
  array_1[0] = seed[4];
  for (int i = 1; i < 31; i++) {
    for (int j = 0; j < 5; j++) {
      array_t[j ] = seed[j-1];
    }
    array_t[0] = ((seed[1] xor seed[2]) xor seed[3]) xor seed[4];
    for (int k = 0; k <5; k++){
      seed[k] = array_t[k];
    }
    array_1[i] = array_t[4];
   }
}

void LFSR2(bool seed[5]) {
  bool array_t[5];
  array_2[0] = seed[4];
  for (int i = 1; i < 31; i++) {
    array_t[0] = seed[2] xor seed[4];
    for (int j = 1; j < 5; j++) {
      array_t[j] = seed[j-1];
    }
    
    for (int k = 0; k <5; k++){
      seed[k] = array_t[k];
      //Serial.print(seed[k]);
    }
    array_2[i] = array_t[4];
   }
}


 void GC(bool arr1[], bool arr2[]) {
    for(int i = 0; i<31; i++){
      GoldCode[i] = arr1[i] xor arr2[i];
      Serial.print(GoldCode[i]);
    }
    
 }


void loop() {
  // put your main code here, to run repeatedly:

}
