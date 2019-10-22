/** 
 * @file ps_1_1_Tom_Fu.ino
 * @printing Harris number fewer than 1000
 * @author  Tom Chenlian Fu(tfu@g.hmc.edu) (Collaborated with Vadim Mathys and Jenny Wathanakulchat) ,Yizhe Chang(yichang@g.hmc.edu)


 * @version 0.1 
 * @date complete: 09-1-2018
 * @total time spent:     1 hour    min
 */


int var_1 = 1;
int var_2 = 3; 
int temp;
int result;
void setup() {
  Serial.begin(9600);
  
while(var_1<1000){
    result = var_1;
    Serial.println(var_1);
    temp = var_2;
    var_2 = var_1 + var_2;
    var_1 = temp;
    }
}

void loop() {

}

 
