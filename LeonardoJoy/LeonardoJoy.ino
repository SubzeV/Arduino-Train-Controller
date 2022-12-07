#include "Joystick.h"

Joystick_ Joystick;

const unsigned long cycleDelta = 10;
unsigned long nextTime = 0;

void setup() {

  Joystick.setThrottleRange(0, 1023);

  //auto send mode false
  Joystick.begin(false);
}

void loop() {

  if (millis() >= nextTime) {

    Joystick.setXAxis(analogRead(A0));
    Joystick.setYAxis(analogRead(A1));
    Joystick.setZAxis(analogRead(A2));
    Joystick.setThrottle(analogRead(A3));

    Joystick.sendState();

    nextTime = millis() + cycleDelta;
  }

}
