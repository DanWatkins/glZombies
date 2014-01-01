//=======================================================================================================================|
// Created 2013.12.29 by Daniel L. Watkins
//
// Copyright (C) 2013-2014 Daniel L. Watkins
// This file is licensed under the MIT License.
//=======================================================================================================================|

#include "System.h"

namespace glz
{
	namespace world
	{
		void System::addComponent(Int entity, Shared<Component> component)
		{
			component->setHost(entity);
			mComponents.push_back(component);
		}


		Shared<Component> System::getComponentForEntity(Int entity)
		{
			ComponentList::iterator iter = mComponents.begin();
			while (iter != mComponents.end())
			{
				if ((*iter)->getHost() == entity)
					return *iter;

				++iter;
			}

			return Shared<Component>();
		}
	};
};