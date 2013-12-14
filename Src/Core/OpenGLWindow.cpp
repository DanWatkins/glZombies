//=======================================================================================================================|
// Created 2013.11.16 by Daniel L. Watkins
//
// Copyright (C) 2013 Daniel L. Watkins
//=======================================================================================================================|

#include "OpenGLWindow.h"

namespace glz
{
	//==================================================================|
	OpenGLWindow::OpenGLWindow()
	{
		mProgram = -1;
		mWidth = gDefaultWindowWidth;
		mHeight = gDefaultWindowHeight;
		mTitle = gDefaultWindowTitle;
		mWindow = NULL;
		mAspectScale = Vec2f(1.0f, 1.0f);
	}


	//==================================================================|
	Int OpenGLWindow::init(Int width, Int height, String title)
	{
		mWidth = width;
		mHeight = height;
		mTitle = title;

		if (!glfwInit())
			return -1;

		mWindow = glfwCreateWindow(width, height, title.c_str(), NULL, NULL);
		if (!mWindow)
		{
			terminate();
			glfwTerminate();
			return -1;
		}

		glfwMakeContextCurrent(mWindow);
		gl3wInit();

		//if (gl3wIsSupported(4, 4) == false)
		//	printf("Bad OpenGL version.\n");
		GLFWInput::instance();
		glfwSetKeyCallback(mWindow, reinterpret_cast<GLFWkeyfun>(GLFWInput::keyboardCallback));
		glfwSetWindowSizeCallback(mWindow, GLFWInput::windowResizeCallback);
		GLFWInput::instance().addWindow(this);

		onStartup();

		//get the aspect scale adjusted
		_onResize(mWidth, mHeight);

		while (!glfwWindowShouldClose(mWindow))
		{
			onUpdate(0.0); //TODO get a time value for this call

			glfwSwapBuffers(mWindow);
			glfwPollEvents();
		}

		onTerminate();
		glfwTerminate();

		return 0;
	}


	//==================================================================|
	void OpenGLWindow::_onResize(Int width, Int height)
	{
		mAspectScale = Vec2f(500.0f/width, 500.0f/height);
		mWidth = width;
		mHeight = height;

		onResize(width, height);
	}
};