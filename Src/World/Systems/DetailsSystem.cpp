//=======================================================================================================================|
// Created 2014.01.05 by Daniel L. Watkins
//
// Copyright (C) 2013-2014 Daniel L. Watkins
// This file is licensed under the MIT License.
//=======================================================================================================================|

#include "DetailsSystem.h"

namespace glz
{
	namespace world
	{
		void DetailsSystem::createDetail(Int entity, const EntityTemplate &et)
		{
			Shared<Details> detail(new Details(et.name, et.type));
			addComponent(entity, detail);
		}
	};
};