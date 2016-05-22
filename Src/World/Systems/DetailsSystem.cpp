//=======================================================================================================================|
// Created 2014.01.05 by Daniel L. Watkins
//
// Copyright (C) 2013-2016 Daniel L. Watkins
// This file is licensed under the MIT License.
//=======================================================================================================================|

#include "DetailsSystem.h"

namespace glz
{
	namespace world
	{
		void DetailsSystem::createDetails(int entity, EntityTemplate &et)
		{
			addComponent(entity, new Details(et.name, et.type));
		}
	};
};