//=======================================================================================================================|
// Created 2013.11.16 by Daniel L. Watkins
//
// Copyright (C) 2013-2016 Daniel L. Watkins
// This file is licensed under the MIT License.
//=======================================================================================================================|

#ifndef _OPENGL_WINDOW_H
#define _OPENGL_WINDOW_H

#include "Core.h"

namespace glz
{
	class GLFWInput;



	/**
	 * Creates a cross-platform OpenGL 4.x rendering context
	 * Provides a runtime loop and keyboard input callbacks
	 * Class is intended to be inherited from by client applications
	 */
	class OpenGLWindow
	{
	private:
		Int mWidth, mHeight;
		String mTitle;
		GLFWwindow *mWindow = nullptr;
		Vec2f mAspectScale, mZoom;
		Bool mShouldTerminate;

	protected:
		Uint mProgram;


	public:
		virtual ~OpenGLWindow()
		{
		}

		friend GLFWInput;

		OpenGLWindow();
		Int init(Int width=gDefaultWindowWidth, Int height=gDefaultWindowHeight, String title=gWindowTitle);

		Uint getProgram() const { return mProgram; }
		Int getWidth() const { return mWidth; }
		Int getHeight() const { return mHeight; }
		String getTitle() const { return mTitle; }
		Bool isWindow(GLFWwindow *window) const { return window == mWindow; }
		Vec2f getAspectScale() const { return mAspectScale; }

		void setZoom(Vec2f zoom);
		void addZoom(Vec2f zoom);

		void terminate() { mShouldTerminate = true; }

	protected:
		virtual void onStartup() = 0;
		virtual void onUpdate(Double timeSinceStartup) = 0;
		virtual void onKey(Int key, Int action) = 0;
		virtual void onResize(Int width, Int height) = 0;
		virtual void onTerminate() = 0;

	private:
		void _onResize(Int width, Int height);
	};
};


#endif

