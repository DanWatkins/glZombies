//=======================================================================================================================|
// Created 2013.11.17 by Daniel L. Watkins
//
// Copyright (C) 2013-2014 Daniel L. Watkins
// This file is licensed under the MIT License.
//=======================================================================================================================|

#include "Mesh2D.h"

namespace glz
{
	void Mesh2D::Part::configure()
	{
		std::vector<Float> combined;
		combined.assign(vertexData.begin(), vertexData.end());
		combined.insert(combined.end(), colorData.begin(), colorData.end());

		glGenVertexArrays(1, &this->vao);
		glBindVertexArray(this->vao);

		glGenBuffers(1, &this->vbo);
		glBindBuffer(GL_ARRAY_BUFFER, this->vbo);

		glBufferData(	GL_ARRAY_BUFFER,
						combined.size()*sizeof(Float),
						&combined[0],
						GL_STREAM_DRAW);

		glEnableVertexAttribArray(0);
		glEnableVertexAttribArray(1);
		glVertexAttribPointer(0, gValuesPerPoint, GL_FLOAT, GL_FALSE, 0, 0);
		glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, 0, (void*)(vertexData.size()*4));
	}


	Bool Mesh2D::loadFromFile(String filepath)
	{
		if (!loadComponentsFromGLZM2File(filepath))
			return false;

		//set up vertex buffer object and vertex array object for each component
		for (Uint n=0; n<mParts.size(); n++)
			(&mParts[n])->configure();

		glBindVertexArray(0);

		return true;
	}


	void Mesh2D::draw(OpenGLWindow *window, Float rotation)
	{
		draw(window, mNdcPos.x, mNdcPos.y, rotation);
	}


	void Mesh2D::draw(OpenGLWindow *window, Float x, Float y, Float rotation)
	{
		Uint program = window->getProgram();
		glUseProgram(program);

		for (Uint n=0; n<mParts.size(); n++)
		{
			Part *part = &mParts[n];
			

			glBindVertexArray(part->vao);

			Vec2f aspectScale = window->getAspectScale();

			glUniform4f(glGetUniformLocation(program, "aspectScale"), aspectScale.x, aspectScale.y, 1.0f, 1.0f);
			glUniform4f(glGetUniformLocation(program, "offset"), x, y, 0.0, 0.0);
			glUniform1f(glGetUniformLocation(program, "rotation"), rotation);

			glDrawArrays(part->drawMode, 0, part->vertexData.size()/gValuesPerPoint);
		}

		glBindVertexArray(0);
		glUseProgram(0);
	}


	Bool Mesh2D::loadComponentsFromGLZM2File(String filepath)
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
				Part newPart;
				newPart.drawMode = GL_LINE_STRIP;

				file >> token;

				while (!file.eof()  &&  strcmp(token,"</lines>") != 0)
				{
					newPart.vertexData.push_back(toFloat(token));
					file >> token;
				}

				mParts.push_back(newPart);
			}
			else if (strcmp(token,"<triangle>") == 0)
			{
				Part newPart;
				newPart.drawMode = GL_TRIANGLES;

				file >> token;

				while (!file.eof()  &&  strcmp(token,"</triangle>") != 0)
				{
					if (strcmp(token,"#vec2") == 0)
					{
						file >> token;
						newPart.vertexData.push_back(toFloat(token));
						file >> token;
						newPart.vertexData.push_back(toFloat(token));
					}
					else if (strcmp(token,"#col4") == 0)
					{
						for (Int n=0; n<4; n++)
						{
							file >> token;
							newPart.colorData.push_back(toFloat(token));
						}
					}

					file >> token;
				}

				mParts.push_back(newPart);
			}
		}

		return true;
	}
};