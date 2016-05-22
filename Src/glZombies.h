//=======================================================================================================================|
// Created 2013.11.16 by Daniel L. Watkins
//
// Copyright (C) 2013-2016 Daniel L. Watkins
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
		String mFileToOpen;

		void onStartup() override;
		void onUpdate(double currentTime) override;
		void onKey(int key, int action) override;
		void onResize(int width, int height) override;
		void onTerminate() override;

		void loadShaders();

	public:
		glZombies();

		void setFileToOpen(const String& fileToOpen) { mFileToOpen = fileToOpen; }
	};
};

#endif

