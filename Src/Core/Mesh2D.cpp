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
		mRotation	= 0.0f;
	}


	//==================================================================|
	bool Mesh2D::loadFromFile(String filepath)
	{
		if (!loadComponentsFromGLZM2File(filepath))
			return false;

		//set up vertex buffer object and vertex array object for each component
		for (int n=0; n<mComponents.size(); n++)
		{
			Component *cmp = &mComponents[n];
			
			glGenVertexArrays(1, &cmp->vao);
			glBindVertexArray(cmp->vao);

			glGenBuffers(1, &cmp->vbo);
			glBindBuffer(GL_ARRAY_BUFFER, cmp->vbo);

			glBufferData(	GL_ARRAY_BUFFER,
							cmp->vertexData.size()*sizeof(Float),
							&cmp->vertexData[0],
							GL_STREAM_DRAW);

			glEnableVertexAttribArray(0);
			glVertexAttribPointer(0, gValuesPerPoint, GL_FLOAT, GL_FALSE, 0, 0);
		}

		glBindVertexArray(0);

		return true;
	}


	//==================================================================|
	void Mesh2D::draw(GLuint &program)
	{
		glUseProgram(program);

		for (int n=0; n<mComponents.size(); n++)
		{
			Component *cmp = &mComponents[n];

			glBindVertexArray(cmp->vao);

			glUniform4f(glGetUniformLocation(program, "offset"), mNdcPos.x, mNdcPos.y, 0.0, 0.0);
			glUniform1f(glGetUniformLocation(program, "rotation"), mRotation);

			glDrawArrays(cmp->drawMode, 0, cmp->vertexData.size()/gValuesPerPoint);
		}

		glBindVertexArray(0);
		glUseProgram(0);
	}


	//==================================================================|
	bool Mesh2D::loadComponentsFromGLZM2File(String filepath)
	{
		std::ifstream file(filepath, std::ifstream::in);

		if (!file.is_open())
		{
			std::cout << "Unable to read vertex data from " << filepath.c_str() << std::endl;
			return false;
		}

		char token[64];

		while (!file.eof())
		{
			file >> token;

			if (strcmp(token,"<lines>") == 0)
			{
				Component newComponent;
				newComponent.drawMode = GL_LINE_STRIP;

				file >> token;

				while (!file.eof()  &&  strcmp(token,"</lines>") != 0)
				{
					newComponent.vertexData.push_back(toFloat(token));
					file >> token;
				}

				mComponents.push_back(newComponent);
			}
			else if (strcmp(token,"<triangle>") == 0)
			{
				Component newComponent;
				newComponent.drawMode = GL_TRIANGLES;

				file >> token;

				while (!file.eof()  &&  strcmp(token,"</triangle>") != 0)
				{
					newComponent.vertexData.push_back(toFloat(token));
					file >> token;
				}

				mComponents.push_back(newComponent);
			}
		}

		return true;
	}
};