/*
 *  ofxFileDialog.h
 *  ofxFileDialogExample
 *
 *  Created by Philip Whitfield on 5/19/10.
 *  Copyright 2010 undef.ch. All rights reserved.
 *
 */

#ifndef _CLASS_ofxFileDialog_
#define _CLASS_ofxFileDialog_

#import "ofMain.h"

#define FOLDER "ofxFileDialogFolder"

typedef std::vector<std::string> strVec;

struct dialogSettings{
	dialogSettings(){
		canChooseFiles = canChooseFolders = true;
		allowMultipleSelection = false;
	}
	bool canChooseFiles;
	bool canChooseFolders;
	bool allowMultipleSelection;
	strVec fileTypes;
};

strVec openDialog(dialogSettings settings = dialogSettings());
string getFileType(string);
string getFileName(string);
bool isFolder(string s);
#endif