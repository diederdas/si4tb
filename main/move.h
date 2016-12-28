void moveForward(int);

#define moveForwardCM(cm) moveForward((int)((float)cm * 10.0))
#define moveBackCM(cm) moveBack((int)((float)cm * 10.0))

#define moveLeftSpeed(cm) moveLeft((int)((float)cm * 250))
#define moveRightSpeed(cm) moveRight((int)((float)cm * 250))

void rotate(int);

void stop();

void moveForwardInf();
