void moveForward(int);

#define moveForwardSpeed(cm) moveForward((int)((float)cm * 10.0))
#define moveBackSpeed(cm) moveBack((int)((float)cm * 10.0))

#define moveLeftSpeed(cm) moveLeft((int)((float)cm * 1))
#define moveRightSpeed(cm) moveRight((int)((float)cm * 1))

void stop();
