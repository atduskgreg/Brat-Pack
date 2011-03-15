#include "NewProjectButton.h"

NewProjectButton::NewProjectButton(int xPos, int yPos, string img_name, ProjectList * pl)
{
	project_list = pl;
	
	enableMouseEvents();
	disableAppEvents();
	
	button.loadImage(img_name);

	setPos(xPos, yPos);
	setSize(button.width, button.height);
}

void NewProjectButton::update()
{
}

void NewProjectButton::draw()
{	
	ofSetColor(255, 255, 255);
	ofEnableAlphaBlending();
	button.draw(x, y);
	ofDisableAlphaBlending();
}

void NewProjectButton::onPress(int x, int y, int button)
{
	dialogSettings s;
	s.canChooseFolders = true;
	s.canChooseFiles = false;
	s.allowMultipleSelection = false;
	files = openDialog(s);
	string command = ofToDataPath("ruby/new_sinatra_app.rb", true);
	vector <string> split = ofSplitString(command, " ");
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
	
	system(result.c_str());
	
	cout << result << endl;
	
	Project * p = new Project();
	p->folder = files[0];
	project_list->save_project(p);
}

