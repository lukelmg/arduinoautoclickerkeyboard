#include <Mouse.h>
#include "Keyboard.h"

#define OSX 0
#define WINDOWS 1
#define UBUNTU 2

int platform = WINDOWS;

int state = 0;
void setup() {
  pinMode(2, INPUT_PULLUP);
  Mouse.begin();
  Keyboard.begin();
}

void autoClick() {
/*  Mouse.click();
  int mydelay = random(75, 95);
  delay(mydelay);
  */
  Keyboard.println("[This is a bot] SUB 2 DILL");
  delay(5);
}

void speedBridge() {
  Mouse.click(MOUSE_RIGHT);
  Keyboard.press(KEY_LEFT_SHIFT);
  delay(200); //260//200
  Keyboard.releaseAll();
  Mouse.click(MOUSE_RIGHT);
  delay(40); //25//75
}

void speedBridge2() {
  Mouse.click(MOUSE_RIGHT);
  delay(10);
  Keyboard.releaseAll();
  delay(65); //75
  Keyboard.press(KEY_LEFT_SHIFT);
  delay(190); //175
  
}

void loop() {
  int sensorVal = digitalRead(2);
 // Serial.println(sensorVal);

  if (state == 0 && sensorVal == 0) {
    state = 1;
    delay(500);
  } else if (state == 1 && sensorVal == 0) {
    state = 0;
    //Serial.println(state);
    delay(500);
  }

  if (state == 1) {
   autoClick();
   //speedBridge2();
  } else {
    Keyboard.releaseAll();
    Mouse.release();
  }
}
