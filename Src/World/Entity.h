//=======================================================================================================================|
// Created 2013.11.20 by Daniel L. Watkins
//
// Copyright (C) 2013 Daniel L. Watkins
//=======================================================================================================================|

#ifndef _glz_ENTITY_H
#define _glz_ENTITY_H

#include "World.h"
#include "Component.h"

namespace glz
{
	namespace world
	{
		class World;
		typedef std::vector<Shared<Component>> ComponentVector;  //TODO this could probably just be a raw pointer


		//============================================================================|
		// -Represents a thing that can be instantiated only inside of World instances
		// -Every component is updated when the Entity is updated
		//============================================================================|
		class Entity
		{
		private:
			friend World;

			String mId, mName;
			Vec2d mWorldPos;
			ComponentVector mComponents;


		public:
			//accessor and mutator
			String getId() { return mId; }

			void setName(String name) { mName = name; }
			String getName() { return mName; }

			void setWorldPos(Vec2d worldPos) { mWorldPos = worldPos; }
			Vec2d getWorldPos() { return mWorldPos; }


		private:
			friend Camera;
			Entity();
			
			void setId(String id) { mId = id; }


			//============================================================================|
			// Updates the Entity and all components
			//============================================================================|
			void update();

			//============================================================================|
			// Adds a new Component to the Entity
			//============================================================================|
			void addComponent(Shared<Component> component);

			Entity *clone();
		};
	}
};


#endif

