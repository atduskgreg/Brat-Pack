#include "MyButton.h"

MyButton::MyButton(int xPos, int yPos)
{
	enableMouseEvents();
	
	button.loadImage("button.png");

	setPos(xPos, yPos);
	setSize(button.width, button.height);
}

void MyButton::update()
{
}

void MyButton::draw()
{	
	ofEnableAlphaBlending();
	button.draw(x, y);
	ofDisableAlphaBlending();
}

void MyButton::onPress(int x, int y, int button)
{
	dialogSettings s;
	s.canChooseFolders = true;
	s.canChooseFiles = false;
	s.allowMultipleSelection = false;
	files = openDialog(s);
	string command = ofToDataPath("ruby/new_sinatra_app.rb", true) + " " + files[0];
	system(command.c_str());
}

