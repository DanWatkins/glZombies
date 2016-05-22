//=======================================================================================================================|
// Created 2013.11.16 by Daniel L. Watkins
//
// Copyright (C) 2013-2016 Daniel L. Watkins
// This file is licensed under the MIT License.
//=======================================================================================================================|

#include "Main.h"
#include "glZombies.h"
#include <dirent.h>

using namespace glz;

int main()
{
	//list all available maps
	std::cout << "--------------------------------------------------" << std::endl;
	std::cout << "Available maps:" << std::endl << std::endl;

	DIR *dir;
	struct dirent *ent;
	if ((dir = opendir(gDefaultPathMaps.c_str())) != nullptr)
	{
		while ((ent = readdir(dir)) != nullptr)
		{
			if (ent->d_type == DT_REG)
				std::cout << ent->d_name << std::endl;
		}
		closedir(dir);
	}
	std::cout << "--------------------------------------------------" << std::endl << std::endl;

	//ask user which map to load
	std::cout << "Which map to open: ";
	String fileToOpen;
	std::cin >> fileToOpen;

	glZombies window;
	window.setFileToOpen(fileToOpen);

	return window.init(1600, 900, gWindowTitle);
}