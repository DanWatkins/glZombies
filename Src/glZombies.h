//=======================================================================================================================|
// Created 2013.11.16 by Daniel L. Watkins
//
// Copyright (C) 2013-2014 Daniel L. Watkins
// This file is licensed under the MIT License.
//=======================================================================================================================|

#ifndef _GL_ZOMBIES_H
#define _GL_ZOMBIES_H

#include "Main.h"
#include "./Core/OpenGLWindow.h"
#include "./Render/Render.h"
#include "./World/World.h"

namespace glz
{
	/**
	 * Represents the main application
	 */
	class glZombies : public OpenGLWindow
	{
	private:
		world::World mWorld;
		world::Camera mCamera;

		void onStartup();
		void onUpdate(Double currentTime);
		void onKey(Int key, Int action);
		void onResize(Int width, Int height);
		void onTerminate() {}

		void loadShaders();

	public:
		glZombies();
	};
};

#endif

