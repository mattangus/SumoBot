typedef enum colour
{
	black,
	white
} colour;

typedef enum direction
{
	dirLeft,
	dirRight
} direction;

/**********Constant***********/
static const int whiteThreshold = 50;//greater than this is white
static const float halfRoboWidthCm = 11.5/2.0;
static const float wheelRadius = 8.16;
static const float wheelCerc = 2.0*wheelRadius*PI;
static const int distanceThreshold =150;
static const int turnSpeed = 35;
static const int attackSpeed = 50;
static const int backSpeed = 20;

void mainloop();

/**********States**********/
float startState();
int turnState(direction dir,bool* cancel);
void counterTurnState(int distance, direction dir,bool* cancel);
void attackState(bool* cancel);
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
bool checkEdge();
bool checkBack();
void move(int leftVal, int rightVal);
void setup();
colour getCurrentColour();

/**********Display helpers*********/
int lineNum = 0;
void displayInfo(float custom);
void displayInfo();
