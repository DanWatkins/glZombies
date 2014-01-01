//=======================================================================================================================|
// Created 2013.12.14 by Daniel L. Watkins
//
// Copyright (C) 2013-2014 Daniel L. Watkins
// This file is licensed under the MIT License.
//=======================================================================================================================|

#include "Circle.h"

namespace glz
{
	void Circle::init(Float radius, Int segments)
	{
		clearParts();

		Float theta = 2.0f * (float)glz::PI / (Float)segments;
		Float cs = std::cosf(theta);
		Float sn = std::sinf(theta);
		Float t = 0.0f;

		Float x = radius;
		Float y = 0.0f;

		Part part;

		for (Int i=0; i<segments; i++)
		{
			part.vertexData.push_back(x);
			part.vertexData.push_back(y);

			t=x;
			x = cs*x - sn*y;
			y = sn*t + cs*y;
		}

		part.drawMode = GL_LINE_LOOP;
		part.configure();
		addPart(part);
	}
};