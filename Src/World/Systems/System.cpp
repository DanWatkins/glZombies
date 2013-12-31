//=======================================================================================================================|
// Created 2013.12.29 by Daniel L. Watkins
//
// Copyright (C) 2013 Daniel L. Watkins
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