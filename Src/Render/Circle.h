//=======================================================================================================================|
// Created 2013.12.14 by Daniel L. Watkins
//
// Copyright (C) 2013 Daniel L. Watkins
//=======================================================================================================================|

#ifndef _glz_CIRCLE_H
#define _glz_CIRCLE_H

#include "Render.h"

namespace glz
{
	class Circle : public Mesh2D
	{
	public:
		void init(Float radius, Int segments=60);
	};
};


#endif

