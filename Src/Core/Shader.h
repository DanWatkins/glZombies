//=======================================================================================================================|
// Created 2013.11.16 by Daniel L. Watkins
//
// Copyright (C) 2013 Daniel L. Watkins
//=======================================================================================================================|

#ifndef _SHADER_H
#define _SHADER_H

#include "Main.h"

namespace glz
{
	namespace Shader
	{
		Uint loadShader(const char *filename, GLenum shaderType = GL_FRAGMENT_SHADER, Bool checkErrors = true);
		Uint linkFromShaders(const Uint *shaders, Int shaderCount, Bool checkErrors = true);
	};
};

#endif

