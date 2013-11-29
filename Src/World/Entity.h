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

		class Entity
		{
		private:
			friend World;

			String mId;
			Vec2d mPos;			//position in world space
			ComponentVector mComponents;


			Entity(String id) { mId = id; }
			
			void addComponent(Component *component);


		public:
			~Entity();

			//accessor and mutator
			String getId() { return mId; }

			void setPos(Vec2d pos) { mPos = pos; }
			Vec2d getPos() { return mPos; }
		};
	}
};


#endif

