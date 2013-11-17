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
		mDrawMode = GL_TRIANGLES;
	}


	//==================================================================|
	void Mesh2D::load()
	{
		generateVertexData();

		glGenVertexArrays(1, &mVao);
		glBindVertexArray(mVao);

		glGenBuffers(1, &mVbo);
		glBindBuffer(GL_ARRAY_BUFFER, mVbo);
		glBufferData(GL_ARRAY_BUFFER, sizeof(mVertexData), &mVertexData[0], GL_STATIC_DRAW);

		glEnableVertexAttribArray(0);
		glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 0, 0);

		glBindVertexArray(0);
	}


	//==================================================================|
	void Mesh2D::draw(GLuint &program)
	{
		glUseProgram(program);
		glBindVertexArray(mVao);

		glDrawArrays(mDrawMode, 0, mVertexData.size());

		glBindVertexArray(0);
		glUseProgram(0);
	}


	//==================================================================|
	void Mesh2D::generateVertexData()
	{
		Float data[6] =
		{
			0.2f, 0.0f,
			0.0f, 0.2f,
			-0.2f, 0.0f
		};

		mVertexData.assign(data, data+6);
	}
};