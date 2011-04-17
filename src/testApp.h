#ifndef _TEST_APP
#define _TEST_APP

#include "ofMain.h"
#include "CustomButton.h"
#include "ProjectList.h"
#include "ofxFileDialog.h"

class testApp : public ofBaseApp {

	public:
		void setup();
		void update();
		void draw();

		void keyPressed  (int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void windowResized(int w, int h);
	private:
	
	ProjectList * project_list;
	std::vector<string> files;
	
	CustomButton * btn;
	
	void openFolderDialog();
	void generateProject();
};

#endif
