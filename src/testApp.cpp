#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup()
{
	project_list = new ProjectList();
	project_list->load_projects();
	
	btn = new CustomButton("newproject.png");
	btn->setPos(10, 10);
}

//--------------------------------------------------------------
void testApp::update()
{
	project_list->update();
	
	if(btn->isMousePressed())
	{
		openFolderDialog();
	}
}

void testApp::openFolderDialog()
{
	dialogSettings s;
	s.canChooseFolders = true;
	s.canChooseFiles = false;
	s.allowMultipleSelection = false;
	files = openDialog(s);
	
	if(files.size() > 0)
	{
		generateProject();
	}
}

void testApp::generateProject()
{	
	string command = ofToDataPath("ruby/new_sinatra_app.rb", true);
	string result = "ruby " + Tools::getEscapedPath(command) + " '" + command + "' '" +  files[0] + "'";
	system(result.c_str());
	
	Project * p = new Project();
	p->path = files[0];
	p->name = Tools::getFolderNameFromPath(files[0]);
	project_list->save_project(p);
}

//--------------------------------------------------------------
void testApp::draw()
{
	project_list->draw();
	btn->draw();
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){

}

//--------------------------------------------------------------
void testApp::keyReleased(int key){

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button)
{
}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){

}

