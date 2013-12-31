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

		/**
		 * Represents a component manager that is supposed to be derived to provide
		 * specific functionality and to store specialized Component objects.
		 * 
		 * Note: derived classes should provide a method for creating their
		 * specialized type of Component in the form of this:
		 *   void createSpecificComponentName(Type attribute);
		 */
		class System
		{
		private:
			ComponentList mComponents;

		protected:
			void addComponent(Int entity, Shared<Component> component);

		public:
			friend Camera;

			Shared<Component> getComponentForEntity(Int entity);
		};
	};
};

#include "SpatialSystem.h"
#include "DrawableSystem.h"

#endif

