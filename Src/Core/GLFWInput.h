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
		static void keyboardCallback(int action, int key, int a, int b, int c);
	};
};


#endif

