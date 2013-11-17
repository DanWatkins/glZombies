//=======================================================================================================================|
// Created 2013.11.16 by Daniel L. Watkins
//
// Copyright (C) 2013 Daniel L. Watkins
//=======================================================================================================================|

#ifndef _SHADER_H
#define _SHADER_H

#include "../Main.h"

namespace glz
{
	namespace Shader
	{
		//==================================================================|
		// -Loads a GLSL shader from a text file, compiles as @shaderType,
		//  and returns a shader id
		//==================================================================|
		Uint loadShader(const char *filename,
						GLenum shaderType = GL_FRAGMENT_SHADER,
						Bool checkErrors = true);

		//==================================================================|
		// -Links an array of shaders and returns a program id
		//==================================================================|
		Uint linkFromShaders(const Uint *shaders,
							Int shaderCount,
							Bool checkErrors = true);
	};
};

#endif

