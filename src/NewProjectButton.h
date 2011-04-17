#pragma once

#include "ofxMSAInteractiveObject.h"
#include "ofxFileDialog.h"
#include "ProjectList.h"
#include "Project.h"

class NewProjectButton : public ofxMSAInteractiveObject
{
	
public:
	
	NewProjectButton(int xPos, int yPos, string img_name, ProjectList * pl); 
	
	void update(); 
	void draw(); 
	
	void onPress(int x, int y, int button);
	
private:
	
	ofImage button;
	std::vector<string> files;
	ProjectList * project_list;
	
	string getFolderNameFromPath(string path);
	string getEscapedPath(string path);
};
