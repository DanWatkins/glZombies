//=======================================================================================================================|
// Created 2013.11.16 by Daniel L. Watkins
//
// Copyright (C) 2013-2016 Daniel L. Watkins
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
#include <deque>

#include <thread>

#include <cstdlib>
#include <ctime>
#include <cstdio>
#include <cstdlib>

extern "C"
{
#include <lua.h>
#include <lualib.h>
#include <lauxlib.h>
}

#include <SFML/System.hpp>

#define WIN32_LEAN_AND_MEAN 1

#ifdef WIN32
#pragma once
#define _CRT_SECURE_NO_WARNINGS 1

#include <Windows.h>
#pragma comment (lib, "OpenGL32.lib")

#else
#error "Non Windows toolchain detected"
#endif


#define GLFW_NO_GLU 1
#define GLFW_INCLUDE_GLCOREARB 1
#include <GLFW/glfw3.h>
#include <GL/gl3w.h>

struct Color { float r, g, b, a; };

typedef std::string String;

#ifdef WIN32
#include <memory>
#endif

#include "Constants.h"
#include "./Utility/Helper.h"
#include "./Utility/Vec2.h"
#include "./Utility/Mat3.h"
#include "./Script/Script.h"

#endif

