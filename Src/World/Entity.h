//=======================================================================================================================|
// Created 2013.11.20 by Daniel L. Watkins
//
// Copyright (C) 2013 Daniel L. Watkins
//=======================================================================================================================|

#ifndef _glz_ENTITY_H
#define _glz_ENTITY_H

#include "../Main.h"
#include "Component.h"

namespace glz
{
	namespace world
	{
		class World;
		typedef std::vector<Component*> ComponentVector;


		//============================================================================|
		// -Represents a thing that can be instantiated only inside of World instances
		// -Every component is updated when the Entity is updated
		//============================================================================|
		class Entity
		{
		private:
			friend World;

			String mId;
			Vec2d mPos;			//position in world space
			ComponentVector mComponents;




		public:
			~Entity();

			//accessor and mutator
			String getId() { return mId; }

			void setPos(Vec2d pos) { mPos = pos; }
			Vec2d getPos() { return mPos; }


		private:
			Entity();
			
			void setId(String id) { mId = id; }


			//============================================================================|
			// Updates the Entity and all components
			//============================================================================|
			void update();

			//============================================================================|
			// Adds a new Component to the Entity
			//============================================================================|
			void addComponent(Component *component);
		};
	}
};


#endif

