//=======================================================================================================================|
// Created 2013.12.14 by Daniel L. Watkins
//
// Copyright (C) 2013 Daniel L. Watkins
//=======================================================================================================================|

#include "Rectangle.h"

namespace glz
{
	//==================================================================|
	void Rectangle::init(Vec2f pos1, Vec2f pos2)
	{
		clearParts();

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
};