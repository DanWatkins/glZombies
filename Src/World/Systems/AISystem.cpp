//=======================================================================================================================|
// Created 2014.01.04 by Daniel L. Watkins
//
// Copyright (C) 2013-2014 Daniel L. Watkins
// This file is licensed under the MIT License.
//=======================================================================================================================|

#include "AISystem.h"

namespace glz
{
	namespace world
	{
		AISystem::AISystem(Weak<SpatialSystem> spatialSystem)
		{
			mSpatialSystem = spatialSystem;
		}


		void AISystem::createAI(Int entity)
		{
			Weak<Spatial> spatial = std::dynamic_pointer_cast<Spatial>(mSpatialSystem.lock()->getComponentForEntity(entity));
			addComponent(entity, Shared<AI>(new AI(spatial)));
		}
	};
};