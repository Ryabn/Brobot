#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>

Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();

#define SERVOMIN  400 // this is the 'minimum' pulse length count (out of 4096)
#define SERVOMAX  600 // this is the 'maximum' pulse length count (out of 4096)

void setup() {
  Serial.begin(9600);
  Serial.println("Start");

  pwm.begin();
  pwm.setPWMFreq(60);

  yield();
}

void startWalking(){
    
}
void stopWalking(){
    
}
void loop() {
    for (uint16_t pulselen = SERVOMAX; pulselen > SERVOMIN; pulselen--) {
        pwm.setPWM(1, 0, pulselen);
        pwm.setPWM(2, 0, pulselen-300);
        pwm.setPWM(3, 0, pulselen-150);
    }
    delay(2000);
    /*
    for (uint16_t pulselen = SERVOMIN; pulselen < SERVOMAX; pulselen++) {
        //pwm.setPWM(1, 0, pulselen);
        //pwm.setPWM(2, 0, pulselen-300);
        pwm.setPWM(3, 0, pulselen-150);
    }
    delay(2000);
    */
}
