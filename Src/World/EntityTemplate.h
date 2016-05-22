//=======================================================================================================================|
// Created 2013.11.20 by Daniel L. Watkins
//
// Copyright (C) 2013-2016 Daniel L. Watkins
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
			String meshFilepath;


			//spatial
			Double mass, maxSpeed, maxForce, maxTurnRate;



			EntityTemplate()
			{
				name				= "";
				type				= "";
				meshFilepath		= "";

				mass				= 1.0;
				maxSpeed			= 1.0;
				maxForce			= 1.0;
				maxTurnRate			= 1.0;
			}
		};
	}
};


#endif

