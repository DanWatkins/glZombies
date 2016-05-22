//=======================================================================================================================|
// Created 2013.11.16 by Daniel L. Watkins
//
// Copyright (C) 2013-2016 Daniel L. Watkins
// This file is licensed under the MIT License.
//=======================================================================================================================|

#ifndef _SHADER_H
#define _SHADER_H

#include "Core.h"

namespace glz
{
	namespace Shader
	{
		unsigned int loadShader(String filename, GLenum shaderType);
		unsigned int linkFromShaders(const unsigned int *shaders, int shaderCount);
	};
};

#endif

