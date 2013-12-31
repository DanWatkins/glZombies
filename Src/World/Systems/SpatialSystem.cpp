//=======================================================================================================================|
// Created 2013.12.24 by Daniel L. Watkins
//
// Copyright (C) 2013 Daniel L. Watkins
//=======================================================================================================================|

#include "SpatialSystem.h"

namespace glz
{
	namespace world
	{
		void SpatialSystem::createSpatial(Int entity, Vec2d pos)
		{
			addComponent(entity, Shared<Spatial>(new Spatial(pos)));
		}
	};
};