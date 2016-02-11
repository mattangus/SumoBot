typedef enum colour
{
	black,
	white,
	off
} colour;

static const int whiteThreshold = 50;//greater than this is white
static const int offThreshold = 25; //less than this is off the table
void mainloop(float startRatio);
void move(int leftVal, int rightVal);
colour getCurrentColour();
void displayInfo(float ratio);
float startState();
void turnState();
void runState();
void moveRatio(float ratio);
