#include "ProjectList.h"

ProjectList::ProjectList()
{

}

void ProjectList::update()
{
	
}

void ProjectList::draw()
{
	for (int i = 0; i < projects.size(); i++) 
	{
		projects[i]->draw();
	}
}

void ProjectList::load_projects()
{
	int xPos = 100;
	int yPos = 200;
	
	if(_xml.loadFile("projects.xml"))
	{
		if(_xml.pushTag("projects", 0))
		{
			for(int i = 0; i < _xml.getNumTags("project"); i++) 
			{
				Project * project = new Project();
				project->setPos(xPos, yPos + (30 * i));
				project->folder = _xml.getAttribute("project", "folder", "nothing", i);
				projects.push_back(project);
			}
			
			_xml.popTag();
		}
	}
	
	cout << ":::::::::::: LOADED PROJECTS ::::::::::::" << endl;
}

void ProjectList::save_project(Project * p)
{	
	projects.push_back(p);
	
	_xml.pushTag("projects", 0);
	
	int numtags = _xml.getNumTags("project");
	_xml.addTag("project");
	_xml.addAttribute("project", "folder", p->folder, numtags);
	
	_xml.popTag();
	
	_xml.saveFile("projects.xml");
	
	cout << ":::::::::::: THE PROJECT WAS SAVED ::::::::::::" << endl;
}


