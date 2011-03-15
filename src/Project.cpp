#include "Project.h"

Project::Project()
{	
	startPressed = false;
	stopPressed = false;
	
	pos.x = 0;
	pos.y = 0;
	
	running = false;
	
	start = new CustomButton("startserver.png");
	stop = new CustomButton("stopserver.png");
}

void Project::update()
{
	start->update();
	stop->update();
}

void Project::draw()
{
	ofSetColor(0, 0, 0);
	ofFill();
	ofDrawBitmapString(name, pos.x, pos.y);
	
	ofSetColor(255, 255, 255);
	ofEnableAlphaBlending();
	
	if(running)
	{
		stop->draw();
		
		if(stop->isMousePressed())
		{
			running = false;
			cout << "Stop server \n";
		}
	}
	else
	{
		start->draw();
		
		if(start->isMousePressed())
		{
			running = true;
			cout << "Stop server \n";
			
			// shell
		}
	}

	ofDisableAlphaBlending();
}

void Project::setPos(int newX, int newY) 
{ 
	pos.x = newX; 
	pos.y = newY;  
	start->setPos(pos.x + 200, pos.y);
	stop->setPos(pos.x + 335, pos.y);
}
