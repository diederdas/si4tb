#include <Servo.h>
#include "pins.h"
#include "move.h"

#define MIN_DISTANCE 30

float fwd = 0, left = 0, left45 = 0, right45 = 0, right = 0, speed = 0;

unsigned long t1, t2;

Servo myservo;

float distance() {
    digitalWrite(TRIG, LOW);
    delayMicroseconds(10);
    digitalWrite(TRIG, HIGH);
    delay(60);
    digitalWrite(TRIG, LOW);

    float fdistance = pulseIn(ECHO, HIGH) / 58.0;
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
    fwd = distance();

    if (fwd < MIN_DISTANCE) {
        return 0;
    }

    return fwd / 2.0;
}

float measureRotate(int degree) {
    myservo.write(degree);
    delay(1000);
    return distance();
}

float rotateCorrect() {
    right = measureRotate(0);
    right45 = measureRotate(45);
    fwd = measureRotate(90);
    left45 = measureRotate(135);
    left = measureRotate(180);
    myservo.write(90);
    delay(1000);

    Serial.print("fwd = ");
    Serial.println(fwd);
    Serial.print("left =  ");
    Serial.println(left);
    Serial.print("right = ");
    Serial.println(right);

    if (fwd > MIN_DISTANCE && left45 > MIN_DISTANCE && right45 > MIN_DISTANCE) {
        Serial.print("forward ");
    } else if (left > right && left > MIN_DISTANCE && left45 > MIN_DISTANCE) {
        Serial.print("left ");
        rotate(-90);
        return 0;
    } else if (right > MIN_DISTANCE && right45 > MIN_DISTANCE) {
        Serial.print("right ");
        rotate(90);   
        return 0; 
    } else {
        Serial.print("back ");
        rotate(180);  
        return 0;
    }
    fwd = measureDriveDistance();
    Serial.println(fwd);
    return fwd;
}

float cm;

unsigned long now, limit;

void loop() {
    cm = rotateCorrect();
    if (cm > 0) {
        moveForwardInf();
        now = millis();
        limit = now + cm * 10 - 20; // minus error between readings
        Serial.print("waiting = ");
        Serial.println(limit - now);
        while ((now = millis()) < limit) {
            fwd = distance();
            if (fwd <= MIN_DISTANCE) {
                break;
            }
        }
        stop();
    }
}
