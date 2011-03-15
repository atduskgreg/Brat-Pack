#pragma once

#include "ofMain.h"
#include "CustomButton.h"

class Project
{
	
public:
	
	Project(); 
	
	void setPos(int newX, int newY);
	
	void update(); 
	void draw(); 
	
	string path;
	string name;
	
	bool running;
	
	CustomButton * start;
	CustomButton * stop;
	
	ofPoint pos;
	
private:
	
	bool startPressed;
	bool stopPressed;
	
};