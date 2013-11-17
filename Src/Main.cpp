//=======================================================================================================================|
// Created 2013.11.16 by Daniel L. Watkins
//
// Copyright (C) 2013 Daniel L. Watkins
//=======================================================================================================================|

#include "Main.h"
#include "./Core/glZombies.h"

using namespace glz;

int main()
{
	glZombies *app = new glZombies;
	return app->init();
}