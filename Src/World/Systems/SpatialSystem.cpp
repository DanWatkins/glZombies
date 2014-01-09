//=======================================================================================================================|
// Created 2013.12.24 by Daniel L. Watkins
//
// Copyright (C) 2013-2014 Daniel L. Watkins
// This file is licensed under the MIT License.
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


		void SpatialSystem::update(Double timeDelta)
		{

		}
	};
};