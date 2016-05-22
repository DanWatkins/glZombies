//=======================================================================================================================|
// Created 2013.12.24 by Daniel L. Watkins
//
// Copyright (C) 2013-2016 Daniel L. Watkins
// This file is licensed under the MIT License.
//=======================================================================================================================|

#include "SpatialSystem.h"
#include <functional>

namespace glz
{
	namespace world
	{
		void SpatialSystem::createSpatial(int entity, Vec2d pos, const EntityTemplate &entityTemplate)
		{
			addComponent(entity, new Spatial(pos, entityTemplate));
		}


		void SpatialSystem::update()
		{
			std::for_each(mComponents.begin(), mComponents.end(), [&](Component* cmp)
			{
				static_cast<Spatial*>(cmp)->update();
			});
		}
	};
};