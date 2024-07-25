#include "EasyStepper.h"

EasyStepper stepperZ;
EasyStepper stepperX;
EasyStepper stepperY;
EasyStepper stepperC;

#define releuLaser 10

#define btnY A4
#define btnX A5
#define btnZ A6

int posZ, posX, posY, posC;

void setup(){
  stepperZ.attach(2, 3, A0, 200*5.18*2, 1.8/5.18/2);

  stepperX.attach(4, 5, A1, 200*5.18*2, 1.8/5.18/2); 

  stepperY.attach(6, 7, A2, 200*2, 1.8/2); 
  stepperC.attach(8, 9, A3, 200*5.18*2, 1.8/5.18/2);

  pinMode(releuLaser, OUTPUT);
  digitalWrite(releuLaser, LOW);

  homing();


  Serial.begin(9600);
}

void buttonWait(byte data){
  while(1){
    if (data == 'B') {
      break;
    }
  }
}




void loop(){

  byte data;
  
  while(Serial.available()){
    data=Serial.read();
    if(data == '1'){stepperX.enable(); stepperX.moveConstDeg(1, 180, 150); stepperX.disable();} 
    if(data == '2'){stepperX.enable(); stepperX.moveConstDeg(0, 180,  150); stepperX.disable();} 
    if(data == '3'){stepperY.enable(); stepperY.moveAccDeg(1, 90, 0.25, 3000); stepperY.disable();} 
    if(data == '4'){stepperY.enable(); stepperY.moveAccDeg(0, 90, 0.25, 3000); stepperY.disable();} 
    if(data == '5'){stepperZ.enable(); stepperZ.moveConstDeg(0, 180, 150); stepperZ.disable();} 
    if(data == '6'){stepperZ.enable(); stepperZ.moveConstDeg(1, 180, 150); stepperZ.disable();} 
    if(data == '7'){stepperC.enable(); stepperC.moveAccDeg(0, 30 , 0.3, 1000);} 
    if(data == '8'){stepperC.enable(); stepperC.moveAccDeg(1, 30, 0.3, 1000);} 
    if(data == '9') homing();
    if(data == 'A'){
      for(int i=1;i<=12;i++){ // 12 poze
        digitalWrite(releuLaser, HIGH);
        while(1){
          byte data=Serial.read();
          if (data == 'B') {
            break;
          }
          if(data == '1'){stepperX.enable(); stepperX.moveConstDeg(1, 180, 150); stepperX.disable();} 
          if(data == '2'){stepperX.enable(); stepperX.moveConstDeg(0, 180,  150); stepperX.disable();} 
          if(data == '3'){stepperY.enable(); stepperY.moveAccDeg(1, 90, 0.25, 3000); stepperY.disable();} 
          if(data == '4'){stepperY.enable(); stepperY.moveAccDeg(0, 90, 0.25, 3000); stepperY.disable();} 
          if(data == '5'){stepperZ.enable(); stepperZ.moveConstDeg(0, 180, 150); stepperZ.disable();} 
          if(data == '6'){stepperZ.enable(); stepperZ.moveConstDeg(1, 180, 150); stepperZ.disable();} 
        }
        digitalWrite(releuLaser, LOW);

        delay(2000);
        stepperC.enable(); stepperC.moveAccDeg(1, 30, 0.3, 1000); 
        delay(1000);
      }
      stepperC.moveAccDeg(0, 360, 0.3, 1000);
    }
    if(data == 'C') digitalWrite(releuLaser, HIGH);
    if(data == 'D') digitalWrite(releuLaser, LOW);
    if(data == 'E') disableAll();
    if(data == 'F') enableAll();
    

  }
}


void motorTest(){
    stepperZ.enable();
    stepperZ.moveConstDeg(1,720,500);
    delay(1000);
    stepperZ.moveConstDeg(0,360,500);
    delay(1000);
    stepperZ.disable();

    stepperX.enable();
    stepperX.moveConstDeg(1,720,500);
    delay(1000);
    stepperX.moveConstDeg(0,360,500);
    delay(1000);
    stepperX.disable();

    stepperY.enable();
    stepperY.moveConstDeg(1,720,500);
    delay(1000);
    stepperY.moveConstDeg(0,360,500);
    delay(1000);
    stepperY.disable();

    stepperC.enable();
    stepperC.moveConstDeg(1,360,500);
    delay(1000);
    stepperC.moveConstDeg(0,360,500);
    delay(1000);
    stepperC.disable();
}

void homing(){

  enableAll();
  stepperC.disable();
  
  while(analogRead(btnZ) != 1023 || analogRead(btnX) != 1023 || analogRead(btnY) != 1023){


    if(analogRead(btnZ) != 1023) stepperZ.step(0, 150); else stepperZ.disable();
    if(analogRead(btnX) != 1023) stepperX.step(0, 150); else stepperX.disable();
    if(analogRead(btnY) != 1023) stepperY.step(1, 150); else stepperY.disable();

    if(analogRead(btnZ) == 1023 && analogRead(btnX) == 1023 && analogRead(btnY) == 1023) break;

    
  }
  
  stepperZ.disable();
  stepperX.disable();
  stepperY.disable();
  stepperC.disable();
}

void disableAll(){
  stepperZ.disable();
  stepperX.disable();
  stepperY.disable();
  stepperC.disable();
}

void enableAll(){
  stepperZ.enable();
  stepperX.enable();
  stepperY.enable();
  stepperC.enable();
}