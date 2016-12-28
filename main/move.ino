#include "pins.h"
#include "move.h"

void stop() {
    digitalWrite(ENA,LOW);
    digitalWrite(ENB,LOW);
    //dir = DIR_STOP;
}

void moveForward(int wait) {
    digitalWrite(ENA,HIGH);
    digitalWrite(ENB,HIGH);
    digitalWrite(IN1,LOW);
    digitalWrite(IN2,HIGH);
    digitalWrite(IN3,LOW);
    digitalWrite(IN4,HIGH);
    //dir = DIR_FORWARD;
    delay(wait);
}

void moveBack(int wait) {
    digitalWrite(ENA,HIGH);
    digitalWrite(ENB,HIGH);
    digitalWrite(IN1,HIGH);
    digitalWrite(IN2,LOW);
    digitalWrite(IN3,HIGH);
    digitalWrite(IN4,LOW);
    //dir = DIR_FORWARD;
    delay(wait);
}

void moveLeft(int wait) {
    digitalWrite(ENA,HIGH);
    digitalWrite(ENB,HIGH);
    digitalWrite(IN1,LOW);
    digitalWrite(IN2,HIGH);
    digitalWrite(IN3,HIGH);
    digitalWrite(IN4,LOW);
    delay(wait);
}

void moveRight(int wait) {
    digitalWrite(ENA,HIGH);
    digitalWrite(ENB,HIGH);
    digitalWrite(IN1,HIGH);
    digitalWrite(IN2,LOW);
    digitalWrite(IN3,LOW);
    digitalWrite(IN4,HIGH);
    delay(wait);
}

