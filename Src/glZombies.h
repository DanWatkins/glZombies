//=======================================================================================================================|
// Created 2013.11.16 by Daniel L. Watkins
//
// Copyright (C) 2013 Daniel L. Watkins
//=======================================================================================================================|

#ifndef _GL_ZOMBIES_H
#define _GL_ZOMBIES_H

#include "Main.h"
#include "./Core/OpenGLWindow.h"
#include "./Render/Render.h"
#include "./World/World.h"

namespace glz
{
	//============================================================================|
	// The actual glZombies main window class.
	//============================================================================|
	class glZombies : public OpenGLWindow
	{
	private:
		world::World mWorld;

	public:
		glZombies();


	private:
		//==================================================================|
		// -OpenGLWindow virtuals
		//==================================================================|
		void onStartup();
		void onUpdate(Double currentTime);
		void onKey(Int key, Int action);
		void onResize(Int width, Int height);
		void onTerminate() {}

		//==================================================================|
		// -Loads, compiles, and links certain shaders into @mProgram
		//==================================================================|
		void loadShaders();
	};
};

#endif

