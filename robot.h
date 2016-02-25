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
static const int distanceThreshold = 40;
void mainloop();
void move(int leftVal, int rightVal);
void setup();
colour getCurrentColour();

float startState();
void turnState();
void attackState();
void resetMotor(int motorNum);
float getMotorDistance(int motorNum);
void rotate(float radius, int speed, int direction);
void runState();
void moveRatio(float ratio);

void initialState();
void moveBackwards();
void rotateRight(int degrees);
void rotateLeft(int degrees); 
void checkEdge();
void checkBack();
/**********Display helpers*********/
int lineNum = 0;
void displayInfo(float custom);
void displayInfo();