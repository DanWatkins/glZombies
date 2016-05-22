//=======================================================================================================================|
// Created 2013.12.23 by Daniel L. Watkins
//
// Copyright (C) 2013-2016 Daniel L. Watkins
// This file is licensed under the MIT License.
//=======================================================================================================================|

#ifndef _glz_SYSTEM_H
#define _glz_SYSTEM_H

#include "../Components/Component.h"

namespace glz
{
	namespace world
	{
		class Camera;
		typedef std::list<Component*> ComponentList;

		/**
		 * Represents a component manager that is supposed to be derived to provide
		 * specific functionality and to store specialized Component objects.
		 * 
		 * Note: derived classes should provide a method for creating their
		 * specialized type of Component in the form of this:
		 *   void createSpecificComponentName(Type attribute);
		 */

		//TODO there is no reason to have this base class. It's just annoying.
		//At least remove the component list from here an let derived systems implement that

		class System
		{
		protected:
			ComponentList mComponents;

			void addComponent(int entity, Component *component);

		public:
			friend Camera;
			virtual ~System();

			Component *getComponentForEntity(int entity);
			virtual void update() = 0;
		};
	};
};

#include "SpatialSystem.h"
#include "DrawableSystem.h"

#endif

