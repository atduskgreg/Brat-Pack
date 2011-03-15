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
	string command = ofToDataPath("ruby/new_sinatra_app.rb", true);
	vector <string> split = ofSplitString(command, " ");
	cout << split.size();
	string result = "";
	
	for(int i = 0; i < split.size(); i++)
	{
		result += split[i];
		
		if(i < split.size() - 1)
		{
			result += "\\ ";
		}
	}
	
	result += " " + command + " " + files[0];
	
	
	cout << result << endl;
	system(result.c_str());
	
	cout << system("ruby -v") << endl;
}

