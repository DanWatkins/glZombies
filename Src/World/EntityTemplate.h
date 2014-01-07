//=======================================================================================================================|
// Created 2013.11.20 by Daniel L. Watkins
//
// Copyright (C) 2013-2014 Daniel L. Watkins
// This file is licensed under the MIT License.
//=======================================================================================================================|

#ifndef _glz_ENTITY_TEMPLATE_H
#define _glz_ENTITY_TEMPLATE_H

#include "../Main.h"

namespace glz
{
	namespace world
	{
		/**
		 * Represents a template for creating entity instances
		 */
		struct EntityTemplate
		{
			String name;
			String type;
			Vec2d worldPos;
			
			String meshFilepath;
		};
	}
};


#endif

