/*
 *  ofxFileDialog.cpp
 *  ofxFileDialogExample
 *
 *  Created by Philip Whitfield on 5/19/10.
 *  Copyright 2010 undef.ch. All rights reserved.
 *
 */

#include "ofxFileDialog.h"

#ifdef TARGET_OS_MAC
extern strVec openMacDialog(dialogSettings s);
#endif

strVec openDialog(dialogSettings settings){
#ifdef TARGET_OS_MAC
	return openMacDialog(settings);
#endif
#ifdef TARGET_OS_WIN32
	//windows specific code here
#endif
#ifdef TARGET_OS_UNIX
	//unix specific code here
#endif	
};

string getFileType(string s){
	string ret = FOLDER;
	size_t found=s.rfind(".");
	if (found!=string::npos)
		ret = s.substr(found+1);
	return ret;
}

string getFileName(string s){
	size_t found;
	found=s.find_last_of("/\\");
	return s.substr(found+1);
}

bool isFolder(string s){
	if(getFileType(s).compare(FOLDER)==0)
		return true;
	return false;
}