//=======================================================================================================================|
// Created 2013.11.16 by Daniel L. Watkins
//
// Copyright (C) 2013 Daniel L. Watkins
//=======================================================================================================================|

#ifndef _OPENGL_WINDOW_H
#define _OPENGL_WINDOW_H

#include "../Main.h"

namespace glz
{
	class OpenGLWindow
	{
	private:
		Int mWidth, mHeight;
		String mTitle;


	public:
		OpenGLWindow();
		Int init(Int width=gDefaultWindowWidth, Int height=gDefaultWindowHeight, String title=gDefaultWindowTitle);


	protected:
		//==================================================================|
		// -Called after the window has been fully initialized
		//==================================================================|
		virtual void startup() = 0;

		//==================================================================|
		// -Called at the start of the window's update loop
		// -GLFW swaps buffers after this (double buffering)
		// -GLFW polls input events after this
		//==================================================================|
		virtual void update(Double currentTime) = 0;

		//==================================================================|
		// -Called when the window closes or encounters an error
		//==================================================================|
		virtual void terminate() = 0;


	public:
		Int getWidth() { return mWidth; }
		Int getHeight() { return mHeight; }
		String getTitle() { return mTitle; }
	};
};

#endif

