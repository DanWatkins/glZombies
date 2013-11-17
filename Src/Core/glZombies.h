//=======================================================================================================================|
// Created 2013.11.16 by Daniel L. Watkins
//
// Copyright (C) 2013 Daniel L. Watkins
//=======================================================================================================================|

#ifndef _GL_ZOMBIES_H
#define _GL_ZOMBIES_H

#include "Main.h"
#include "OpenGLApplication.h"

namespace glz
{
	class glZombies : public OpenGLApplication
	{
	private:
		GLuint mProgram;

	public:
		glZombies();


	private:
		//virtual from OpenGLApplication
		void startup();
		void render(double currentTime);
		void terminate();

		//general
		void loadShaders();
	};
};

#endif

