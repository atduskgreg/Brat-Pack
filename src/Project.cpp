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
			cout << "Start server \n";
			
			string command = ofToDataPath("ruby/apps/" + name, true);
			string result = getEscapedPath(command);
			
			system(result.c_str());
		}
	}

	ofDisableAlphaBlending();
}

void Project::setPos(int newX, int newY) 
{ 
	pos.x = newX; 
	pos.y = newY;  
	start->setPos(pos.x + 200, pos.y - 15);
	stop->setPos(pos.x + 335, pos.y - 15);
}
				   
string Project::getEscapedPath(string command)
{
	vector <string> split = ofSplitString(command, " ");
	string result = "";
	
	for(int i = 0; i < split.size(); i++)
	{
		result += split[i];
		
		if(i < split.size() - 1)
		{
			result += "\\ ";
		}
	}
	
	cout << result << endl;
	
	return result;
}
