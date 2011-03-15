#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup()
{
	project_list = new ProjectList();
	project_list->load_projects();
	
	btn = new NewProjectButton(100, 100, "newproject.png", project_list);
}

//--------------------------------------------------------------
void testApp::update()
{
	project_list->update();
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

