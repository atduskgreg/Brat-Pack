/*
 *  ofxFileDialogMac.mm
 *  ofxFileDialogExample
 *
 *  Created by Philip Whitfield on 5/19/10.
 *  Copyright 2010 undef.ch. All rights reserved.
 *
 */
#include "ofMain.h"
#ifdef TARGET_OS_MAC
#include "ofxFileDialog.h"

#import <Cocoa/Cocoa.h>

strVec openMacDialog(dialogSettings s){
	strVec ret;
	
	
	NSOpenPanel* openDlg = [NSOpenPanel openPanel];
	if(s.canChooseFiles)
		[openDlg setCanChooseFiles:YES];
	else
		[openDlg setCanChooseFiles:NO];
	
	if(s.canChooseFolders)
		[openDlg setCanChooseDirectories:YES];
	else
		[openDlg setCanChooseDirectories:NO];
	
	if(s.allowMultipleSelection)
		[openDlg setAllowsMultipleSelection:YES];
	else
		[openDlg setAllowsMultipleSelection:NO];
	
	NSArray* fileTypes = nil;
	if(s.fileTypes.size()>0){
		fileTypes = [[NSMutableArray alloc] initWithCapacity:s.fileTypes.size()];
		for(int i=0;i<s.fileTypes.size();i++){
			const char* str = s.fileTypes[i].c_str();
			[fileTypes addObject: [NSString stringWithCString:str length:strlen(str)]];
		}
	}
	
	if ( [openDlg runModalForDirectory:nil file:nil types:fileTypes] == NSOKButton )
	{
		
		NSArray* files = [openDlg filenames];
		for(int i = 0; i < [files count]; i++ )
		{
			NSString* fileName = [files objectAtIndex:i];
			ret.push_back([fileName UTF8String]);
		}
	}
	return ret;
};

#endif