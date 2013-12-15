//=======================================================================================================================|
// Created 2013.12.14 by Daniel L. Watkins
//
// Copyright (C) 2013 Daniel L. Watkins
//=======================================================================================================================|

#ifndef _glz_RECTANGLE_H
#define _glz_RECTANGLE_H

#include "Render.h"

namespace glz
{
	class Rectangle : public Mesh2D
	{
	public:
		void init(Vec2f pos1, Vec2f pos2);
	};
};

#endif

