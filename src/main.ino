#include <Servo.h>

Servo myservo;

float distance() {
    digitalWrite(TRIG, LOW);
    delayMicroseconds(2);
    digitalWrite(TRIG, HIGH);
    delayMicroseconds(20);
    digitalWrite(TRIG, LOW);

    float fdistance = pulseIn(ECHO, HIGH);
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

void loop() {
    distance()
}