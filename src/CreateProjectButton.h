#pragma once

#include "ofMain.h"
#include "AbstractButton.h"

class CreateProjectButton : public AbstractButton
{
	
public:
	
	CreateProjectButton(); 
	
	void update(); 
	void draw(int xPos, int yPos); 
	
private:
	
	void onPress(int x, int y, int button);
	
};