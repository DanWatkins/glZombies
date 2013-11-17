//=======================================================================================================================|
// Created 2013.11.16 by Daniel L. Watkins
//
// Copyright (C) 2013 Daniel L. Watkins
//=======================================================================================================================|

#ifndef _OPENGL_APPLICATION_H
#define _OPENGL_APPLICATION_H

#include "Main.h"

namespace glz
{
	class OpenGLApplication
	{
	private:
		Int mWidth, mHeight;
		String mTitle;


	public:
		OpenGLApplication();
		Int init(Int width=gDefaultWindowWidth, Int height=gDefaultWindowHeight, String title=gDefaultWindowTitle);

	protected:
		virtual void startup() = 0;
		virtual void render(Double currentTime) = 0;
		virtual void terminate() = 0;

	public:
		Int getWidth() { return mWidth; }
		Int getHeight() { return mHeight; }
		String getTitle() { return mTitle; }
	};
};

#endif

