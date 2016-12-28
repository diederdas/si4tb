#include <Servo.h>
#include "pins.h"
#include "move.h"

#define MIN_DISTANCE 30

float d1 = 0, d2 = 0, speed = 0;

unsigned long t1, t2;

Servo myservo;

float distance() {
    digitalWrite(TRIG, LOW);
    delayMicroseconds(10);
    digitalWrite(TRIG, HIGH);
    delay(60);
    digitalWrite(TRIG, LOW);

    float fdistance = pulseIn(ECHO, HIGH) / 58.0;
    Serial.println(fdistance);
    return fdistance;
}

void setup() {
    myservo.attach(SERVOPIN);
    Serial.begin(9600);
    pinMode(ECHO, INPUT);
    pinMode(TRIG, OUTPUT);
    pinMode(IN1,OUTPUT);
    pinMode(IN2,OUTPUT);
    pinMode(IN3,OUTPUT);
    pinMode(IN4,OUTPUT);
    pinMode(ENA,OUTPUT);
    pinMode(ENB,OUTPUT);
}

float measureDriveDistance() {
    d1 = distance();

    d1 /= 2.0;

    if (d1 < MIN_DISTANCE) {
        return 0;
    }

    return d1;
}

float testSpeed() {
    d1 = distance();
    t1 = millis();
    moveForward(1000);
    d2 = distance();
    t2 = millis();
    stop();
    return (d1 - d2) / (t2 - t1); // cm per millisecond
}

void loop() {

    initialize();
}
