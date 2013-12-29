//=======================================================================================================================|
// Created 2013.12.24 by Daniel L. Watkins
//
// Copyright (C) 2013 Daniel L. Watkins
//=======================================================================================================================|

#ifndef _glz_SPATIAL_SYSTEM_H
#define _glz_SPATIAL_SYSTEM_H

#include "System.h"
#include "../Components/Spatial.h"

namespace glz
{
	namespace world
	{
		class SpatialSystem : public System
		{
		public:
			SpatialSystem() {}
			void createSpatial(Int entity, Vec2d pos);

			Shared<Spatial> getSpatialForEntity(Int entity);
		};
	};
};


#endif

