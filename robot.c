#pragma config(Sensor, S1,     LightSensor,    sensorLightActive)
#pragma config(Sensor, S2,     BumpSensor,     sensorTouch)
#pragma config(Sensor, S3,     DistanceSensor, sensorSONAR)
#pragma config(Motor,  motorA,          Middle,        tmotorNXT, PIDControl, encoder)
#pragma config(Motor,  motorB,          Right,         tmotorNXT, PIDControl, encoder)
#pragma config(Motor,  motorC,          Left,          tmotorNXT, PIDControl, encoder)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

#include "robot.h"


task main()
{
	setup();
	//wait1Msec(200); //wait 5 seconds
	//float radius = startState();
	//mainloop(ratio);
	//
	//trunState();
	//runState();
}

void mainloop(float startRatio)
{
	float pastRatio = startRatio;
	const float changeValue = 0.0001;
	const float otherChange = 0.00005;
	float actualChange;
	bool finished = false;
	while(!finished) {
		colour c = getCurrentColour();
		int dir = 0;
		if(c == white)
		{
			dir = 1;
			actualChange = otherChange;
		}
		else if(c == off)
		{
			dir = -1;
			actualChange = changeValue;
		}

		float currentRatio = pastRatio + (changeValue*dir);
		if(currentRatio < -1)
			currentRatio = -1;
		if(currentRatio > 1)
			currentRatio = 1;
		moveRatio(currentRatio);
		pastRatio = currentRatio;
		displayInfo();
	}
}

void moveRatio(float ratio)
{
	int base = -10;
	int change = 5;
	int left = base - (ratio*change);
	int right = base + (ratio*change);
	move(left,right);
}

float startState()
{
	bool finished = false;
	float radius = SensorValue[DistanceSensor]/2.0;

	while(!finished)
	{
		displayInfo();
	}
	return radius;
}
void turnState()
{
	nMotorEncoder[Left]=0;
	nMotorEncoder[Right]=0;

	//while
}
void runState()
{
}

void move(int leftVal, int rightVal)
{
	motor[Left]=leftVal;
	motor[Right]=rightVal;
}

void rotateAndTrack(float degrees, int speed)
{

}

void rotate(float degrees, int speed)
{
	nMotorEncoder[Left] = 0;
	move(speed,-speed); //positive => clockwise

	float targetDist = halfRoboWidthCm*degrees*PI/180;

	while(getMotorDistance(Left) < targetDist)
		displayInfo(getMotorDistance(Left));


	move(0,0);
}

void resetMotor(int motorNum)
{
	nMotorEncoder[motorNum] = 0;
}

float getMotorDistance(int motorNum)
{
	float curVal = nMotorEncoder[motorNum];
	return (curVal * wheelCerc)/360.0;
}

colour getCurrentColour()
{
	if(SensorValue[LightSensor] > whiteThreshold)
		return white;
	else if(SensorValue[LightSensor] < offThreshold)
		return off;
	return black;
}

void setup()
{
}

void displayInfo()
{
	nxtDisplayCenteredTextLine(0,"LMo %d",motor[Left]);
	nxtDisplayCenteredTextLine(1,"RMo %d",motor[Right]);
	nxtDisplayCenteredTextLine(2,"Sens %d",SensorValue[LightSensor]);
	nxtDisplayCenteredTextLine(3,"LEn %d",nMotorEncoder[Left]);
	nxtDisplayCenteredTextLine(4,"REn %d",nMotorEncoder[Right]);
}

void displayInfo(float custom)
{
	displayInfo();
	nxtDisplayCenteredTextLine(5,"custom %f",custom);
}
