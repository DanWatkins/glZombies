//=======================================================================================================================|
// Created 2013.11.16 by Daniel L. Watkins
//
// Copyright (C) 2013 Daniel L. Watkins
//=======================================================================================================================|

#ifndef _OPENGL_WINDOW_H
#define _OPENGL_WINDOW_H

#include "Core.h"

namespace glz
{
	class GLFWInput;


	
	// -Creates a cross-platform OpenGL 4.x rendering context
	// -Provides a runtime loop and keyboard input callbacks
	// -Class is intended to be inherited from by client applications
	
	class OpenGLWindow
	{
	private:
		Int mWidth, mHeight;
		String mTitle;
		GLFWwindow *mWindow;
		Vec2f mAspectScale;

	protected:
		Uint mProgram;


	public:
		friend GLFWInput;

		OpenGLWindow();
		Int init(Int width=gDefaultWindowWidth, Int height=gDefaultWindowHeight, String title=gDefaultWindowTitle);

		Uint getProgram() { return mProgram; }

		Int getWidth() { return mWidth; }
		Int getHeight() { return mHeight; }
		String getTitle() { return mTitle; }

		Bool isWindow(GLFWwindow *window) { return window == mWindow; }

		Vec2f getAspectScale() { return mAspectScale; }

	protected:
		
		// -Called after the window has been fully initialized
		
		virtual void onStartup() = 0;

		
		// -Called at the start of the window's update loop
		// -GLFW swaps buffers after this (double buffering)
		// -GLFW polls input events after this
		
		virtual void onUpdate(Double currentTime) = 0;

		
		// -Called whenever a keyboard event occurs by GLFW
		
		virtual void onKey(Int key, Int action) = 0;


		
		// -Called whenever the window is resized by GLFW
		
		virtual void onResize(Int width, Int height) = 0;

		
		// -Called when the window closes or encounters an error
		
		virtual void onTerminate() = 0;


	private:
		void _onResize(Int width, Int height);
	};
};


#endif

