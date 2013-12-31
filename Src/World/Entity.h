//=======================================================================================================================|
// Created 2013.11.20 by Daniel L. Watkins
//
// Copyright (C) 2013 Daniel L. Watkins
//=======================================================================================================================|

#ifndef _glz_ENTITY_H
#define _glz_ENTITY_H

#include "World.h"

namespace glz
{
	namespace world
	{
		/**
		 * Represents a template for creating entity instances
		 */
		struct Entity
		{
			Vec2d worldPos;
			String name;
			String meshFilepath;
		};
	}
};


#endif

