//=======================================================================================================================|
// Created 2013.11.16 by Daniel L. Watkins
//
// Copyright (C) 2013 Daniel L. Watkins
//=======================================================================================================================|

#ifndef _SHADER_H
#define _SHADER_H

#include "Main.h"

namespace Shader
{
	GLuint loadShader(const char *filename, GLenum shaderType = GL_FRAGMENT_SHADER, bool checkErrors = true);
	GLuint linkFromShaders(const GLuint *shaders, int shaderCount, bool checkErrors = true);
}


#endif

