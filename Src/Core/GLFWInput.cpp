//=======================================================================================================================|
// Created 2013.11.19 by Daniel L. Watkins
//
// Copyright (C) 2013 Daniel L. Watkins
//=======================================================================================================================|

#include "GLFWInput.h"

namespace glz
{
	std::vector<OpenGLWindow*> GLFWInput::mWindows;

	//==================================================================|
	GLFWInput& GLFWInput::instance()
	{
		static GLFWInput instance;

		return instance;
	}


	//==================================================================|
	void GLFWInput::addWindow(OpenGLWindow *window)
	{
		//ensure @window is not already a registered window
		for (Uint n=0; n<mWindows.size(); n++)
		{
			if (window == mWindows[n])
				return;
		}

		mWindows.push_back(window);
	}


	//==================================================================|
	void GLFWInput::keyboardCallback(int action, int key, int a, int b, int c)
	{
		for (Uint n=0; n<mWindows.size(); n++)
			mWindows[n]->onKey(key, action);
	}
};