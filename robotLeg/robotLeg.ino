#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>

Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();

#define SERVOMIN  350
#define SERVOMAX  625

void setup() {
  Serial.begin(9600);
  Serial.println("Start");

  pwm.begin();
  pwm.setPWMFreq(60);

  yield();
}

void startWalking(){
    pwm.setPWM(2, 0, 160);
    pwm.setPWM(3, 0, 420);
    //420 lul
}
void stopWalking(){
    pwm.setPWM(2, 0, 250);
    pwm.setPWM(3, 0, 550);
}
void loop() {
    startWalking();
    delay(500);
    for (uint16_t pulselen = SERVOMAX; pulselen > SERVOMIN; pulselen--) {
        pwm.setPWM(1, 0, pulselen);
    }
    delay(500);
    stopWalking();
    delay(500);
    for (uint16_t pulselen = SERVOMIN; pulselen < SERVOMAX; pulselen++) {
        pwm.setPWM(1, 0, pulselen);

    }
    delay(500);
    
}
