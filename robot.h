typedef enum colour
{
	black,
	white,
	off
} colour;

static const int whiteThreshold = 50;//greater than this is white
static const int offThreshold = 25; //less than this is off the table
static const float halfRoboWidthCm = 11.5/2.0;
static const float wheelRadius = 8.16;
static const float wheelCerc = 2.0*wheelRadius*PI;
void mainloop(float startRatio);
void move(int leftVal, int rightVal);
void setup();
colour getCurrentColour();
void displayInfo(float custom);
void displayInfo();
float startState();
void turnState();
void resetMotor(int motorNum);
float getMotorDistance(int motorNum);
void rotate(float degrees, int speed);
void runState();
void moveRatio(float ratio);
