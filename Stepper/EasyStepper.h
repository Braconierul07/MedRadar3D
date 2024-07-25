#ifndef EasyStepper_h
#define EasyStepper_h

namespace easystepper{
  class EasyStepper{
    private:
    uint8_t dirPin;
    uint8_t stepPin;
    uint8_t enPin;
    int stepsPerRev;
    float degPerStep;
    bool dir;
    float rev;
    float deg;
    int speed;
    float waitTime;
    int accelTerm;
    int roundedWaitTime;

    public:
    void attach(uint8_t dirPin, uint8_t stepPin, uint8_t enPin, int stepsPerRev, float degPerStep);

    void moveConst(bool dir, float rev, int speed); 
    void moveConstDeg(bool dir, float deg, int speed);

    void step(bool dir, int speed);

    void moveAcc(bool dir, float rev, float waitTime, int accelTerm);
    void moveAccDeg(bool dir, float deg, float waitTime, int accelTerm);
    
    void moveDec(bool dir, float rev, float waitTime, int accelTerm);
    void moveDecDeg(bool dir, float deg, float waitTime, int accelTerm);

    void enable();
    void disable();
  };
}

using namespace easystepper;

#endif
