//=======================================================================================================================|
// Created 2013.12.14 by Daniel L. Watkins
//
// Copyright (C) 2013-2014 Daniel L. Watkins
// This file is licensed under the MIT License.
//=======================================================================================================================|

#include "Rectangle.h"

namespace glz
{
	void Rectangle::init(Vec2f pos1, Vec2f pos2, Bool filled)
	{
		clearParts();

		if (filled)
		{
			//triangle 1
			Part part1;

			part1.vertexData.push_back(pos1.x);
			part1.vertexData.push_back(pos1.y);

			part1.vertexData.push_back(pos2.x);
			part1.vertexData.push_back(pos1.y);

			part1.vertexData.push_back(pos1.x);
			part1.vertexData.push_back(pos2.y);

			part1.drawMode = GL_TRIANGLES;
			part1.configure();
			addPart(part1);


			//triangle 2
			Part part2;

			part2.vertexData.push_back(pos2.x);
			part2.vertexData.push_back(pos2.y);

			part2.vertexData.push_back(pos2.x);
			part2.vertexData.push_back(pos1.y);

			part2.vertexData.push_back(pos1.x);
			part2.vertexData.push_back(pos2.y);

			part2.drawMode = GL_TRIANGLES;
			part2.configure();
			addPart(part2);
		}
		else
		{
			Part part;

			part.vertexData.push_back(pos1.x);
			part.vertexData.push_back(pos1.y);

			part.vertexData.push_back(pos2.x);
			part.vertexData.push_back(pos1.y);

			part.vertexData.push_back(pos2.x);
			part.vertexData.push_back(pos2.y);

			part.vertexData.push_back(pos1.x);
			part.vertexData.push_back(pos2.y);

			part.drawMode = GL_LINE_LOOP;
			part.configure();
			addPart(part);
		}
	}
};