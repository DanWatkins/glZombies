//=======================================================================================================================|
// Created 2013.12.23 by Daniel L. Watkins
//
// Copyright (C) 2013 Daniel L. Watkins
//=======================================================================================================================|

#ifndef _glz_SYSTEM_H
#define _glz_SYSTEM_H

#include "../Components/Component.h"

namespace glz
{
	namespace world
	{
		class Camera;
		typedef std::list<Shared<Component>> ComponentList;

		class System
		{
		private:
			ComponentList mComponents;


		protected:
			void addComponent(Int entity, Shared<Component> component)
			{
				component->setHost(entity);
				mComponents.push_back(component);
			}


		public:
			friend Camera;

			Shared<Component> getComponentForEntity(Int entity)
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
};

#include "SpatialSystem.h"
#include "DrawableSystem.h"

#endif

