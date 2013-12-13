//=======================================================================================================================|
// Created 2013.11.19 by Daniel L. Watkins
//
// Copyright (C) 2013 Daniel L. Watkins
//=======================================================================================================================|

#ifndef _glz_GLFWINPUT_H
#define _glz_GLFWINPUT_H

#include "../Main.h"
#include "OpenGLWindow.h"



namespace glz
{
	class OpenGLWindow;


	//==================================================================|
	// -Used for delegating keyboard input from GLFW to OpenGLWindow
	//  class objects.
	//  -Because GLFW is a C API, pointers to class methods cannot be
	//   passed to GLFW. So this static class is needed as a middle man.
	//==================================================================|
	class GLFWInput
	{
	private:
		static std::vector<OpenGLWindow*> mWindows;;

		GLFWInput() {};
		GLFWInput(GLFWInput const&) {}
		void operator=(GLFWInput const&) {}


	public:
		static GLFWInput& instance();

		//==================================================================|
		// -Adds @window as a "subscriber" to keyboard messages
		//==================================================================|
		static void addWindow(OpenGLWindow *window);


		//==================================================================|
		// -Called by GLFW whenever a keyboard message occurs
		// -Relays the message to all subscriber windows
		//==================================================================|
		static void keyboardCallback(Int action, Int key, Int a, Int b, Int c);


		//==================================================================|
		// -Called by GLFW whenever a window is resized
		// -Relays the message to the window that was resized
		//==================================================================|
		static void windowResizeCallback(GLFWwindow *window, Int width, Int height);
	};
};


#endif

