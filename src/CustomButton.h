#pragma once

#include "ofxMSAInteractiveObject.h"

class CustomButton : public ofxMSAInteractiveObject
{
	
public:
	
	CustomButton(string img_name); 

	void update(); 
	void draw(); 
	
	bool isMousePressed();
	
private:
	
	void onPress(int x, int y, int button);
	
	ofImage button;
	bool pressed;
};
