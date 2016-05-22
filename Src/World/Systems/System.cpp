//=======================================================================================================================|
// Created 2013.12.29 by Daniel L. Watkins
//
// Copyright (C) 2013-2016 Daniel L. Watkins
// This file is licensed under the MIT License.
//=======================================================================================================================|

#include "System.h"

namespace glz
{
	namespace world
	{
		System::~System()
		{
			std::for_each(mComponents.begin(), mComponents.end(), std::default_delete<Component>());
			std::cout << "System destroyed" << std::endl;
		}


		void System::addComponent(Int entity, Component *component)
		{
			component->setHost(entity);
			component->setSystem(this);
			component->init();
			mComponents.push_back(component);
		}


		Component *System::getComponentForEntity(Int entity)
		{
			ComponentList::iterator iter = mComponents.begin();
			while (iter != mComponents.end())
			{
				if ((*iter)->getHost() == entity)
					return *iter;

				++iter;
			}

			return NULL;
		}
	};
};