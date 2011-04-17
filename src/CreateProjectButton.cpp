#include "CreateProjectButton.h"

CreateProjectButton::CreateProjectButton(int xPos, int yPos, string img_name)
{
	enableMouseEvents();
	
	button.loadImage(img_name);
	
	setPos(xPos, yPos);
	setSize(button.width, button.height);
}

void AbstractButton::update()
{
}

void AbstractButton::draw()
{	
	ofSetColor(255, 255, 255);
	ofEnableAlphaBlending();
	button.draw(x, y);
	ofDisableAlphaBlending();
}

void AbstractButton::onPress(int x, int y, int button)
{
	dialogSettings s;
	s.canChooseFolders = true;
	s.canChooseFiles = false;
	s.allowMultipleSelection = false;
	files = openDialog(s);
	string command = ofToDataPath("ruby/new_sinatra_app.rb", true);
	vector <string> split = ofSplitString(command, " ");
	cout << split.size();
	string result = "ruby ";
	
	for(int i = 0; i < split.size(); i++)
	{
		result += split[i];
		
		if(i < split.size() - 1)
		{
			result += "\\ ";
		}
	}
	
	result += " '" + command + "' '" +  files[0] + "'";
	
	
	cout << result << endl;
	system(result.c_str());
	
	cout << system("ruby -v") << endl;
}



