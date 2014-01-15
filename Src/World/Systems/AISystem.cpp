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
		AISystem::AISystem(DetailsSystem *detailsSystem,
						   SpatialSystem *spatialSystem)
		{
			mDetailsSystem = detailsSystem;
			mSpatialSystem = spatialSystem;
		}


		void AISystem::createAI(Int entity)
		{
			Details *details = (Details*)mDetailsSystem->getComponentForEntity(entity);
			Spatial *spatial = (Spatial*)mSpatialSystem->getComponentForEntity(entity);
			addComponent(entity, new AI(details, spatial));
		}


		void AISystem::update(Double timeDelta)
		{
		}
	};
};