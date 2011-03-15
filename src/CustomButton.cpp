#include "CustomButton.h"

CustomButton::CustomButton(string img_name)
{	
	pressed = false;
	
	enableMouseEvents();
	disableAppEvents();
	
	button.loadImage(img_name);
	
	setSize(button.width, button.height);
}

void CustomButton::update()
{
}

void CustomButton::draw()
{	
	ofSetColor(255, 255, 255);
	ofEnableAlphaBlending();
	button.draw(x, y);
	ofDisableAlphaBlending();
}

void CustomButton::onPress(int x, int y, int button)
{
	pressed = true;
}

bool CustomButton::isMousePressed()
{
	if(pressed)
	{
		pressed = false;
		return true;
	}
	
	return false;
}

