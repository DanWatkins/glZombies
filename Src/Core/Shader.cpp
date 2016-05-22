//=======================================================================================================================|
// Created 2013.11.16 by Daniel L. Watkins
//
// Copyright (C) 2013-2016 Daniel L. Watkins
// This file is licensed under the MIT License.
//=======================================================================================================================|

#include "Shader.h"

namespace glz
{
	namespace Shader
	{
		GLuint loadShader(String filename, GLenum shaderType)
		{
			unsigned int result = 0;
			FILE *file;
			char *data;
			size_t filesize;


			file = fopen(filename.c_str(), "rb");

			if (!file)
				return 0;

			fseek(file, 0, SEEK_END);
			filesize = ftell(file);
			fseek(file, 0, SEEK_SET);

			data = new char[filesize + 1];

			if (!data)
				return result;

			fread(data, 1, filesize, file);
			data[filesize] = 0;
			fclose(file);

			result = glCreateShader(shaderType);

			if (!result)
				return result;

			glShaderSource(result, 1, &data, nullptr);
			delete[] data;

			glCompileShader(result);


			//check for errors
			int status = 0;
			glGetShaderiv(result, GL_COMPILE_STATUS, &status);

			if (!status)
			{
				char buffer[8192];
				glGetShaderInfoLog(result, 8192, nullptr, buffer);

				std::cout << filename << ":" << buffer << std::endl;

				glDeleteShader(result);
			}

			return result;
		}

		
		unsigned int linkFromShaders(const unsigned int *shaders, int shaderCount)
		{
			unsigned int program;
			program = glCreateProgram();

			for (int n = 0; n < shaderCount; n++)
				glAttachShader(program, shaders[n]);

			glLinkProgram(program);


			//check for errors
			int status;
			glGetProgramiv(program, GL_LINK_STATUS, &status);

			if (!status)
			{
				char buffer[8192];
				glGetProgramInfoLog(program, 8192, nullptr, buffer);
				std::cout << buffer << std::endl;

				glDeleteProgram(program);
				return 0;
			}


			//delete shaders
			for (int n = 0; n < shaderCount; n++)
				glDeleteShader(shaders[n]);

			return program;
		}
	};
};