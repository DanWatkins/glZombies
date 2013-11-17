//=======================================================================================================================|
// Created 2013.11.16 by Daniel L. Watkins
//
// Copyright (C) 2013 Daniel L. Watkins
//=======================================================================================================================|

#ifndef _OPENGL_APPLICATION_H
#define _OPENGL_APPLICATION_H

#include "Main.h"

class OpenGLApplication
{
public:
	int init();

protected:
	virtual void startup() = 0;
	virtual void render(double currentTime) = 0;
	virtual void terminate() = 0;
};


#endif

