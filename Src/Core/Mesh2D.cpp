//=======================================================================================================================|
// Created 2013.11.17 by Daniel L. Watkins
//
// Copyright (C) 2013 Daniel L. Watkins
//=======================================================================================================================|

#include "Mesh2D.h"

namespace glz
{
	//==================================================================|
	Mesh2D::Mesh2D()
	{
		mDrawMode	= GL_TRIANGLES;
		mVbo		= -1;
		mVao		= -1;

		mRotation	= 0.0f;
	}


	//==================================================================|
	bool Mesh2D::loadFromFile(String filepath)
	{
		if (!loadM2VertexDataFromFile(filepath))
			return false;

		//set up vertex buffer object and vertex array object
		glGenVertexArrays(1, &mVao);
		glBindVertexArray(mVao);

		glGenBuffers(1, &mVbo);
		glBindBuffer(GL_ARRAY_BUFFER, mVbo);
		glBufferData(GL_ARRAY_BUFFER, sizeof(mVertexData), &mVertexData[0], GL_STATIC_DRAW);

		glEnableVertexAttribArray(0);
		glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 0, 0);

		glBindVertexArray(0);

		return true;
	}


	//==================================================================|
	void Mesh2D::draw(GLuint &program)
	{
		glUseProgram(program);
		glBindVertexArray(mVao);

		glUniform4f(glGetUniformLocation(program, "offset"), mNdcPos.x, mNdcPos.y, 1.0, 1.0);
		glUniform1f(glGetUniformLocation(program, "rotation"), mRotation);

		glDrawArrays(mDrawMode, 0, 3);

		glBindVertexArray(0);
		glUseProgram(0);
	}


	//==================================================================|
	bool Mesh2D::loadM2VertexDataFromFile(String filepath)
	{
		std::ifstream file(filepath);

		if (!file.is_open())
		{
			std::cout << "Unable to read vertex data from " << filepath.c_str() << std::endl;
			return false;
		}

		//read draw mode
		file >> mDrawMode;

		//read vertex data
		Float token;
		mVertexData.clear();
		
		while (!file.eof())
		{
			file >> token;
			mVertexData.push_back(token);
		}

		return true;
	}
};