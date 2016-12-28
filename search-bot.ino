//www.elegoo.com
//2016.09.12

#include <Servo.h> //servo library
Servo myservo; // create servo object to control servo
int Echo = A4;  
int Trig = A5; 
int in1 = 9;
int in2 = 8;
int in3 = 7;
int in4 = 6;
int ENA = 10;
int ENB = 5;
int ABS = 130;
float rightDistance = 0,leftDistance = 0,middleDistance = 0 ;
float d45 = 0, d90 = 0, d135 = 0;

enum {
  DIR_FORWARD,
  DIR_BACK,
  DIR_LEFT,
  DIR_RIGHT,
  DIR_STOP
} dir;

void _mForward()
{ 
  dir = DIR_FORWARD;
  digitalWrite(ENA,HIGH);
  digitalWrite(ENB,HIGH);
  digitalWrite(in1,LOW);
  digitalWrite(in2,HIGH);
  digitalWrite(in3,LOW);
  digitalWrite(in4,HIGH);
  Serial.println("go forward!");
}

void _mBack()
{
  dir = DIR_BACK;
  digitalWrite(ENA,HIGH);
  digitalWrite(ENB,HIGH);
  digitalWrite(in1,HIGH);
  digitalWrite(in2,LOW);
  digitalWrite(in3,HIGH);
  digitalWrite(in4,LOW);
  Serial.println("go back!");
}

void _mleft()
{  
  dir = DIR_LEFT;
  digitalWrite(ENA,HIGH);
  digitalWrite(ENB,HIGH);
  digitalWrite(in1,LOW);
  digitalWrite(in2,HIGH);
  digitalWrite(in3,HIGH);
  digitalWrite(in4,LOW);
  Serial.println("Left");
}

void _mright()
{
  dir = DIR_RIGHT;
  digitalWrite(ENA,HIGH);
  digitalWrite(ENB,HIGH);
  digitalWrite(in1,HIGH);
  digitalWrite(in2,LOW);
  digitalWrite(in3,LOW);
  digitalWrite(in4,HIGH);
  Serial.println("Right");
}

void _mStop()
{
  dir = DIR_STOP;
  digitalWrite(ENA,LOW);
  digitalWrite(ENB,LOW);
  Serial.println("Stop!");
} 

int forwardCheck() {
  myservo.write(45);
  delay(1300);
  Serial.print("rgt = ");
  d45 = Distance_test();
  delay(200);
  
  myservo.write(90);
  delay(1300);
  Serial.print("fwd = ");
  d90 = Distance_test();
  delay(200);
  
  myservo.write(135);
  delay(1300);
  Serial.print("lft = ");
  d135 = Distance_test();
  delay(200);

  if (d45 < 512.0 || d90 < 512.0 || d135 < 512.0) {
    return 0;
  }
  return 1;
}

 /*Ultrasonic distance measurement Sub function*/
float Distance_test()   
{
  digitalWrite(Trig, LOW);   
  delayMicroseconds(2);
  digitalWrite(Trig, HIGH);  
  delayMicroseconds(20);
  digitalWrite(Trig, LOW);   
  float Fdistance = pulseIn(Echo, HIGH);  
  Serial.println(Fdistance);
  return Fdistance;
}  

void setup() 
{ 
  myservo.attach(3);// attach servo on pin 3 to servo object
  Serial.begin(9600);     
  pinMode(Echo, INPUT);    
  pinMode(Trig, OUTPUT);  
  pinMode(in1,OUTPUT);
  pinMode(in2,OUTPUT);
  pinMode(in3,OUTPUT);
  pinMode(in4,OUTPUT);
  pinMode(ENA,OUTPUT);
  pinMode(ENB,OUTPUT);
  pinMode(11,OUTPUT);
  _mStop();
} 

void loop() 
{ 
    myservo.write(90);//setservo position according to scaled value
    delay(15); 
    middleDistance = Distance_test();
    #ifdef send
    Serial.print("middleDistance=");
    Serial.println(middleDistance);
    #endif

    if(middleDistance<=1400.0)
    {     
      _mStop();
      delay(800);                         
      myservo.write(0);          
      delay(1200);      
      rightDistance = Distance_test();
      delay(500);

      #ifdef send
      Serial.print("rightDistance=");
      Serial.println(rightDistance);
      #endif

      myservo.write(180);           
      delay(1200); 
      leftDistance = Distance_test();
      delay(500);

      #ifdef send
      Serial.print("leftDistance=");
      Serial.println(leftDistance);
      #endif

      delay(500);
      myservo.write(90);              
      delay(1200);
      if(rightDistance>leftDistance)  
      {
        _mright();
        delay(250);
       }
       else if(rightDistance<leftDistance)
       {
        _mleft();
        delay(250);
       }
       else if((rightDistance<=1400.0)||(leftDistance<=1400.0))
       {
        _mBack();
        delay(90);
       }
       else
       {
        _mForward();
       }
    }  
    else
        _mForward();                     
}

