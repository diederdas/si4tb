#include "pins.h"
#include "move.h"

void stop() {
    digitalWrite(ENA,LOW);
    digitalWrite(ENB,LOW);
    //dir = DIR_STOP;
}

void moveForwardInf() {
    digitalWrite(ENA,HIGH);
    digitalWrite(ENB,HIGH);
    digitalWrite(IN1,LOW);
    digitalWrite(IN2,HIGH);
    digitalWrite(IN3,LOW);
    digitalWrite(IN4,HIGH);
}

void moveForward(int wait) {
    moveForwardInf();
    delay(wait);
    stop();
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
    stop();
}

void moveLeft(int wait) {
    digitalWrite(ENA,HIGH);
    digitalWrite(ENB,HIGH);
    digitalWrite(IN1,LOW);
    digitalWrite(IN2,HIGH);
    digitalWrite(IN3,HIGH);
    digitalWrite(IN4,LOW);
    delay(wait);
    stop();
}

void moveRight(int wait) {
    digitalWrite(ENA,HIGH);
    digitalWrite(ENB,HIGH);
    digitalWrite(IN1,HIGH);
    digitalWrite(IN2,LOW);
    digitalWrite(IN3,LOW);
    digitalWrite(IN4,HIGH);
    
    delay(wait);
    stop();
}

void rotate(int degree) {
    if (degree > 0) {
        moveRight((int)(2.7 * degree));
    } else if (degree < 0) {
        degree *= -1;
        moveLeft((int)(2.7 * degree)); 
    }
    delay((int)(1.4 * degree));
} 

