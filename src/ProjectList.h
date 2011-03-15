#pragma once

#include "Project.h"
#include "ofxXmlSettings.h"

class ProjectList
{
	
public:
	
	ProjectList(); 
	
	void load_projects();
	void save_project(Project * p);
	void update(); 
	void draw(); 
	
private:
	
	vector <Project *> projects;
	ofxXmlSettings _xml;
	
	ofPoint pos;
	
};