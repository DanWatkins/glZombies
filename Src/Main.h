//=======================================================================================================================|
// Created 2013.11.16 by Daniel L. Watkins
//
// Copyright (C) 2013-2014 Daniel L. Watkins
// This file is licensed under the MIT License.
//=======================================================================================================================|

#ifndef _MAIN_H
#define _MAIN_H

#include <iostream>
#include <io.h>
#include <fcntl.h>
#include <algorithm>

#include <fstream>
#include <istream>
#include <string>
#include <sstream>

#include <vector>
#include <list>

#include <cstdlib>
#include <ctime>
#include <cstdio>
#include <cstdlib>


#define WIN32_LEAN_AND_MEAN 1

//OpenGL related
#ifdef WIN32
	#pragma once
	#define _CRT_SECURE_NO_WARNINGS 1

	
	#include <Windows.h>

	#ifdef _DEBUG
		#pragma comment (lib, "glfw3-d.lib")
	#else
		#pragma comment (lib, "glfw3-r.lib")
	#endif

	#pragma comment (lib, "OpenGL32.lib")
#else
	#error "Non Windows toolchain detected"
#endif


#define GLFW_NO_GLU 1
#define GLFW_INCLUDE_GLCOREARB 1
#include "GL/glfw3.h"
#include "GL/gl3w.h"


//typedef common types
typedef char				Char;
typedef GLbyte				Int8;
typedef GLubyte				Uint8;
typedef GLshort				Int16;
typedef GLushort			Uint16;
typedef GLint				Int;
typedef GLuint				Uint;
typedef long long			Int64;
typedef unsigned long long	Uint64;

typedef GLfloat				Float;
typedef GLdouble			Double;
typedef GLboolean			Bool;


typedef std::string			String;


#ifdef WIN32

#include <memory>

#endif

#include "Constants.h"
#include "./Utility/Helper.h"
#include "./Utility/Vec2.h"
#include "./Utility/Mat3.h"
#include "./Utility/Timer.h"

#endif

