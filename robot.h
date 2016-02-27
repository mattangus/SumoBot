typedef enum colour
{
	black,
	white,
	off
} colour;

typedef enum direction
{
	dirLeft,
	dirRight
} direction;

/**********Constant***********/
static const int whiteThreshold = 50;//greater than this is white
static const int offThreshold = 25; //less than this is off the table
static const float halfRoboWidthCm = 11.5/2.0;
static const float wheelRadius = 8.16;
static const float wheelCerc = 2.0*wheelRadius*PI;
static const int distanceThreshold =150;

void mainloop();

/**********States**********/
float startState();
int turnState(direction dir);
void counterTurnState(int distance, direction dir);
void attackState();
void runState();
void initialState();

/****Helper functions****/
void resetMotor(int motorNum);
float getMotorDistance(int motorNum);
void rotate(float radius, int speed, direction dir);
void moveRatio(float ratio);
void moveBackwards();
void rotateRight(int degrees);
void rotateLeft(int degrees);
void checkEdge();
void checkBack();
void move(int leftVal, int rightVal);
void setup();
colour getCurrentColour();

/**********Display helpers*********/
int lineNum = 0;
void displayInfo(float custom);
void displayInfo();
