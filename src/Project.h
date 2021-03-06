#pragma once

#include "ofMain.h"
#include "CustomButton.h"
#include "Tools.h"

class Project
{
	
public:
	
	Project(); 
	
	void setPos(int newX, int newY);
	
	string getURL();
	
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
	
	string getEscapedPath(string command);
	
	ofTrueTypeFont font;
	
};