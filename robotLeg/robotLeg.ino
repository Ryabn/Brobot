#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>

Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();

#define SERVOROTAMT 300


void setup() {
  Serial.begin(9600);
  Serial.println("Start");

  pwm.begin();
  pwm.setPWMFreq(60);

  yield();
}
void leg1Walk(){
    pwm.setPWM(0, 0, 230);
    delay(1000);
    for (uint16_t pulselen = 0; pulselen < SERVOROTAMT; pulselen++) {
        pwm.setPWM(0, 0, (pulselen + 230));
        
    }
    pwm.setPWM(0, 0, 530);
    
    pwm.setPWM(1, 0, 530);
    delay(1000);
    for (uint16_t pulselen = SERVOROTAMT; pulselen > 0; pulselen--) {
        pwm.setPWM(0, 0, (pulselen + 230));
        
    }
    delay(1000);
}
/*
//moves arm down to touch the ground when moving
void startWalking(){
    pwm.setPWM(0, 0, 230);
    pwm.setPWM(4, 0, 650);
    pwm.setPWM(8, 0, 550);
    //pwm.setPWM(12, 0, 300);
    //420 lul
}

//moves arm up to not touch the ground and resets to moving forward position
void stopWalking(){
    pwm.setPWM(8, 0, 250);
    pwm.setPWM(12, 0, 600);
}
*/
void loop() {
    leg1Walk();
    
}
