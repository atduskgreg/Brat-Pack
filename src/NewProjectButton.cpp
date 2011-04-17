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
	string result = "ruby " + Tools::getEscapedPath(command) + " '" + command + "' '" +  files[0] + "'";
	system(result.c_str());
	
	Project * p = new Project();
	p->path = files[0];
	p->name = Tools::getFolderNameFromPath(files[0]);
	project_list->save_project(p);
}

