#include "Ticker.h"
#define SENSOR A0
#define LIMIT 900
bool flag = false;
int counter = 0;

void TimeToCheck();
void HowLong();

Ticker timer5(TimeToCheck, 1000, 0, MILLIS);
Ticker timer2(HowLong, 1, 0, MILLIS);

void setup() {
  Serial.begin(9600);
  pinMode(SENSOR, INPUT);
  timer5.start();
  timer2.start();
}

void loop() {
  int count = analogRead(SENSOR);
  // Serial.println(String(count));
  if (count > LIMIT && !flag){
    timer2.pause();
    flag = true;
  }
  if (count <= LIMIT && flag){
    timer2.resume();
    flag = false;
  }
  timer2.update();
  timer5.update();
}

void TimeToCheck(){
  int count = timer2.counter() - counter;
  Serial.println(String(1000 - count));
  counter = timer2.counter();
}

void HowLong(){}