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
	Vec2d v1(1.0, 0.0);
	Vec2d v2(0.0, 1.0);
	Vec2d v3(-1.0, 0.0);
	Vec2d v4(0.0, -1.0);

	/*Double angle = radToDeg(acos(v1.dot(v2)));
	angle = radToDeg(acos(v1.dot(v3)));
	angle = radToDeg(acos(v1.dot(v4)));

	angle = radToDeg(v1.angle(v2));
	angle = radToDeg(v1.angle(v3));
	angle = radToDeg(v1.angle(v4));*/


	glZombies *app = new glZombies;
	return app->init(1600, 900, gWindowTitle);
}