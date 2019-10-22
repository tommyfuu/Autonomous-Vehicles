bool array_1[31];
bool array_2[31];
bool GoldCode[31];
int CorrelateNo;
//bool Correlate[31];
bool GoldCode1[31];
bool GoldCode2[31];
bool GoldCode3[31];
bool GoldCode4[31];
bool GoldCode5[31];
bool GoldCode6[31];
bool GoldCode7[31];
bool GoldCode8[31];



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
  bool array_in[31];
  bool array_out[31];
  int N;
 
  
  LFSR1(seed_0);

  LFSR2(seed_1);
  GC(array_1, array_2, GoldCode1);
  //Serial.println();

  LFSR2(seed_2);
  GC(array_1, array_2, GoldCode2);
  //Serial.println();

  LFSR2(seed_3);
  GC(array_1, array_2, GoldCode3);
  //Serial.println();

  LFSR2(seed_4);
  GC(array_1, array_2, GoldCode4);
  //Serial.println();

  LFSR2(seed_5);
  GC(array_1, array_2, GoldCode5);
  //Serial.println();

  LFSR2(seed_6);
  GC(array_1, array_2, GoldCode6);
  //Serial.println();

  LFSR2(seed_7);
  GC(array_1, array_2, GoldCode7);
  //Serial.println();

  LFSR2(seed_8);
  GC(array_1, array_2, GoldCode8);
  //Serial.println();

  findmax(GoldCode1, GoldCode1,array_out, 0);
  Serial.println();

  findmax(GoldCode1, GoldCode2,array_out, 0);
  Serial.println();

  findmax(GoldCode1, GoldCode3,array_out, 0);
  Serial.println();

  findmax(GoldCode1, GoldCode4,array_out, 0);
  Serial.println();

  findmax(GoldCode1, GoldCode5,array_out, 0);
  Serial.println();

  findmax(GoldCode1, GoldCode6,array_out, 0);
  Serial.println();

  findmax(GoldCode1, GoldCode7,array_out, 0);
  Serial.println();

  findmax(GoldCode1, GoldCode8,array_out, 0);
  Serial.println();

  findmax(GoldCode2, GoldCode2,array_out, 0);
  Serial.println();

  findmax(GoldCode2, GoldCode3,array_out, 0);
  Serial.println();

  findmax(GoldCode2, GoldCode4,array_out, 0);
  Serial.println();

  findmax(GoldCode2, GoldCode5,array_out, 0);
  Serial.println();

  findmax(GoldCode2, GoldCode6,array_out, 0);
  Serial.println();

  findmax(GoldCode2, GoldCode7,array_out, 0);
  Serial.println();

  findmax(GoldCode2, GoldCode8,array_out, 0);
  Serial.println();

  findmax(GoldCode3, GoldCode3,array_out, 0);
  Serial.println();

  findmax(GoldCode3, GoldCode4,array_out, 0);
  Serial.println();

  findmax(GoldCode3, GoldCode5,array_out, 0);
  Serial.println();

  findmax(GoldCode3, GoldCode6,array_out, 0);
  Serial.println();

  findmax(GoldCode3, GoldCode7,array_out, 0);
  Serial.println();

  findmax(GoldCode3, GoldCode8,array_out, 0);
  Serial.println();
  
  findmax(GoldCode4, GoldCode4,array_out, 0);
  Serial.println();

  findmax(GoldCode4, GoldCode5,array_out, 0);
  Serial.println();

  findmax(GoldCode4, GoldCode6,array_out, 0);
  Serial.println();

  findmax(GoldCode4, GoldCode7,array_out, 0);
  Serial.println();

  findmax(GoldCode4, GoldCode8,array_out, 0);
  Serial.println();

  findmax(GoldCode5, GoldCode5,array_out, 0);
  Serial.println();

  findmax(GoldCode5, GoldCode6,array_out, 0);
  Serial.println();

  findmax(GoldCode5, GoldCode7,array_out, 0);
  Serial.println();

  findmax(GoldCode5, GoldCode8,array_out, 0);
  Serial.println();

   findmax(GoldCode6, GoldCode6,array_out, 0);
  Serial.println();

  findmax(GoldCode6, GoldCode7,array_out, 0);
  Serial.println();

  findmax(GoldCode6, GoldCode8,array_out, 0);
  Serial.println();

  findmax(GoldCode7, GoldCode7,array_out, 0);
  Serial.println();

  findmax(GoldCode7, GoldCode8,array_out, 0);
  Serial.println();

  
  findmax(GoldCode8, GoldCode8,array_out, 0);
  Serial.println();

//  offset_Nbits(GoldCode1,array_out, N);
//  Correlate(GoldCode1, array_out);
//  Serial.println();

//  offset_Nbits(GoldCode2,array_out, N);
//  Correlate(GoldCode1, array_out);
//  Serial.println();

  
//   
}

void LFSR1(bool seed[]) {
  //  LFSR1(bool seed[]) returns the 1+ x2 +x3 +x4 + x5 for seed_0[5] and stores them in seed
  bool array_t[5];
  array_1[0] = seed[4];
  for (int i = 1; i < 31; i++) {
    for (int j = 0; j < 5; j++) {
      array_t[j ] = seed[j - 1];
    }
    array_t[0] = ((seed[1] xor seed[2]) xor seed[3]) xor seed[4];
    for (int k = 0; k < 5; k++) {
      seed[k] = array_t[k];
    }
    array_1[i] = array_t[4];
  }
}

void LFSR2(bool seed[5]) {
  //  LFSR2(bool seed[]) returns the x3 +x5 for seed_1-8[5] and stores them in seed
  bool array_t[5];
  array_2[0] = seed[4];
  for (int i = 1; i < 31; i++) {
    array_t[0] = seed[2] xor seed[4];
    for (int j = 1; j < 5; j++) {
      array_t[j] = seed[j - 1];
    }

    for (int k = 0; k < 5; k++) {
      seed[k] = array_t[k];
      //Serial.print(seed[k]);
    }
    array_2[i] = array_t[4];
  }
}


void GC(bool arr1[], bool arr2[], bool GoldCode[]) {
  // GC(bool arr1[], bool arr2[]) compares the output of LFSR2 and LFSR1 using xor and print the output
  for (int i = 0; i < 31; i++) {
    GoldCode[i] = arr1[i] xor arr2[i];
    //Serial.print(GoldCode[i]);
  }

}

int Correlate(bool GoldCode_1[], bool GoldCode_2[]) {
  //Correlate compares the two input Gold codes and return +1 if they are the same and -1 if they are false. Their results are added together to get "sum"
  int sum(0);
  for (int i = 0; i < 31; i++) {
    if (GoldCode_1[i] == GoldCode_2[i]) {
      sum += 1;
    }
    else {
      sum += -1;
    }
  }
  //Serial.println(sum);
  return sum;
}


void offset_onebit(bool array_in[]) {
  //offset_onebit shift the original Goldcode's last digit to the first digit of the new code and shift the rest to the right by one position
  bool lastbit = array_in[30];
  for (int i = 30; i > 0; i--) {
    array_in[i] = array_in[i - 1];
  }
  array_in[0] = lastbit;
}

void offset_Nbits(bool array_in[], bool array_out[], int N) {
  //offset_Nbits call the offset_onebit to shift Gold codes to all the possible situations
  bool temp[31];
  for (int i = 0; i < 31; i++) {
    temp[i] = array_in[i];
  }
  for (int i = 0; i < N; i++) {
    offset_onebit(temp);
  }
  for (int i = 0; i < 31; i++) {
    array_out[i] = temp[i];
  }
}

int findmax(bool array_in[],bool array_in2[], bool array_out[], int N){
  //findmax finds the maximum output of the results produced by comparing two Gold Codes
  int maximum = 0;
  int temp = 0;
  for(int N = 31; N>0;N--){
    bool array_out[31];
    offset_Nbits(array_in2, array_out,N);
    temp = Correlate(array_in, array_out);
    if (abs(temp) > abs(maximum)){
      maximum = temp;
    }
  }
  Serial.println(maximum);
  return maximum;
}



//void Call(bool Correlate_1, bool Correlate_2){
//  for(int i = 0; i <= 8; i++){
//    offSet(array_1, array_2, total, CorrelateCal[j]);
//  }
//    for(int j = 0; j <= 8; j++){
//    offSet(array_1, array_2, total, CorrelateCal[j]);
//  }
//}


void loop() {
  // put your main code here, to run repeatedly:

}
