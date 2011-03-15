#pragma once

#include "ofxMSAInteractiveObject.h"
#include "ofxFileDialog.h"

class MyButton : public ofxMSAInteractiveObject
{
	
public:
	
	MyButton(int xPos, int yPos, string img_name); 
	
	void update(); 
	void draw(); 
	
	void onPress(int x, int y, int button);
	
private:
	
	ofImage button;
	std::vector<string> files;
};
