//=======================================================================================================================|
// Created 2013.11.16 by Daniel L. Watkins
//
// Copyright (C) 2013-2014 Daniel L. Watkins
// This file is licensed under the MIT License.
//=======================================================================================================================|

#include "Main.h"
#include "glZombies.h"

using namespace glz;

Int main()
{
	glZombies *app = new glZombies;
	return app->init(1600, 900, gWindowTitle);
}