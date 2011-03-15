/*
 *  Tools.cpp
 *  bratPack
 *
 *  Created by Rune Madsen on 3/15/11.
 *  Copyright 2011 New York University. All rights reserved.
 *
 */

#include "Tools.h"

string Tools::getEscapedPath(string command)
{
	vector <string> split = ofSplitString(command, " ");
	string result = "";
	
	for(int i = 0; i < split.size(); i++)
	{
		result += split[i];
		
		if(i < split.size() - 1)
		{
			result += "\\ ";
		}
	}
	
	return result;
}

string Tools::getFolderNameFromPath(string path)
{
	vector <string> split = ofSplitString(path, "/");
	return split[split.size() - 1];
}

