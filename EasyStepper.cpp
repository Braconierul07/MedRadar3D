#include "Arduino.h"
#include "EasyStepper.h"

namespace easystepper{
  void EasyStepper::attach(uint8_t dirPin, uint8_t stepPin, uint8_t enPin, int stepsPerRev, float degPerStep){
    this->dirPin = dirPin;
    this->stepPin = stepPin;
    this->enPin = enPin;
    this->stepsPerRev = stepsPerRev;
    this->degPerStep = degPerStep;

    pinMode(this->stepPin, OUTPUT);
    pinMode(this->dirPin, OUTPUT);
    pinMode(this->enPin, OUTPUT);

    digitalWrite(this->stepPin, LOW);
    digitalWrite(this->dirPin, LOW); //??
    digitalWrite(this->enPin, LOW);
  }

  void EasyStepper::moveConst(bool dir, float rev, int speed){
    this->dir = dir;
    this->rev = rev;
    this->speed = speed;

    digitalWrite(dirPin, this->dir);
    for(int x = 0; x < this->rev * stepsPerRev; x++){
      digitalWrite(stepPin, HIGH);
      delayMicroseconds(this->speed);
      digitalWrite(stepPin, LOW);
      delayMicroseconds(this->speed);
    }
  }

  void EasyStepper::moveConstDeg(bool dir, float deg, int speed){
    this->dir = dir;
    this->deg = deg;
    this->speed = speed;

    digitalWrite(dirPin, this->dir);
    for(int x = 0; x < this->deg/degPerStep; x++){
      digitalWrite(stepPin, HIGH);
      delayMicroseconds(this->speed);
      digitalWrite(stepPin, LOW);
      delayMicroseconds(this->speed);
    }
      
  }

  void EasyStepper::step(bool dir, int speed){
    this->dir = dir;
    this->speed = speed;

    digitalWrite(dirPin, this->dir);
    digitalWrite(stepPin, HIGH);
    delayMicroseconds(this->speed);
    digitalWrite(stepPin, LOW);
    delayMicroseconds(this->speed);
  }

  void EasyStepper::moveAcc(bool dir, float rev, float waitTime, int accelTerm){
    this->dir = dir;
    this->rev = rev;
    this->waitTime = waitTime;
    this->accelTerm = accelTerm;

    digitalWrite(dirPin, this->dir);
    for(int x = 0; x < this->rev * stepsPerRev; x++){
      
      float dVelocity = waitTime * accelTerm;
      waitTime = 1/(dVelocity+1/waitTime);
      if(waitTime < 0.00025){
        waitTime = 0.00025;  
      }

      roundedWaitTime = round(waitTime*1000000);
      
      digitalWrite(stepPin, HIGH);
      delayMicroseconds(this->roundedWaitTime);
      digitalWrite(stepPin, LOW);
      delayMicroseconds(this->roundedWaitTime);
    }
  }

  void EasyStepper::moveAccDeg(bool dir, float deg, float waitTime, int accelTerm){ //
    this->dir = dir;
    this->deg = deg;
    this->waitTime = waitTime;
    this->accelTerm = accelTerm;

    digitalWrite(dirPin, this->dir);
    for(int x = 0; x < this->deg/degPerStep; x++){
      
      float dVelocity = waitTime * accelTerm;
      waitTime = 1/(dVelocity+1/waitTime);
      if(waitTime < 0.00025){
        waitTime = 0.00025;  
      }

      roundedWaitTime = round(waitTime*1000000);
      
      digitalWrite(stepPin, HIGH);
      delayMicroseconds(this->roundedWaitTime);
      digitalWrite(stepPin, LOW);
      delayMicroseconds(this->roundedWaitTime);
    }
  }

  void EasyStepper::moveDec(bool dir, float rev, float waitTime, int accelTerm){ //
    this->dir = dir;
    this->rev = rev;
    this->waitTime = waitTime;
    this->accelTerm = accelTerm;

    digitalWrite(dirPin, this->dir);
    for(int x = 0; x < this->rev * stepsPerRev; x++){
      
      float dVelocity = waitTime * -1 * accelTerm;
      waitTime = 1/(dVelocity+1/waitTime);
      if(waitTime > 0.003){
        waitTime = 0.003;  
      }

      roundedWaitTime = round(waitTime*1000000);
      
      digitalWrite(stepPin, HIGH);
      delayMicroseconds(this->roundedWaitTime);
      digitalWrite(stepPin, LOW);
      delayMicroseconds(this->roundedWaitTime);
    }
  }

  void EasyStepper::moveDecDeg(bool dir, float deg, float waitTime, int accelTerm){ //
    this->dir = dir;
    this->deg = deg;
    this->waitTime = waitTime;
    this->accelTerm = accelTerm;

    digitalWrite(dirPin, this->dir);
    for(int x = 0; x < this->deg/degPerStep; x++){
      
      float dVelocity = waitTime * -1 * accelTerm;
      waitTime = 1/(dVelocity+1/waitTime);
      if(waitTime > 0.003){
        waitTime = 0.003;  
      }

      roundedWaitTime = round(waitTime*1000000);
      
      digitalWrite(stepPin, HIGH);
      delayMicroseconds(this->roundedWaitTime);
      digitalWrite(stepPin, LOW);
      delayMicroseconds(this->roundedWaitTime);
    }
  }

  void EasyStepper::enable(){
    digitalWrite(enPin, LOW);
  }

  void EasyStepper::disable(){
   digitalWrite(enPin, HIGH);
  }
}
