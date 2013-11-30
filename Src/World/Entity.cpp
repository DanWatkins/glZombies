//=======================================================================================================================|
// Created 2013.11.20 by Daniel L. Watkins
//
// Copyright (C) 2013 Daniel L. Watkins
//=======================================================================================================================|

#include "Entity.h"

namespace glz
{
	namespace world
	{
		//==================================================================|
		Entity::Entity()
		{
		}


		//==================================================================|
		Entity::~Entity()
		{
			//delete all components
			for (Uint n=0; n<mComponents.size(); n++)
				delete mComponents[n];
		}


		//==================================================================|
		void Entity::update()
		{
			for (Uint n=0; n<mComponents.size(); n++)
				mComponents.at(n)->update();
		}


		//==================================================================|
		void Entity::addComponent(Component *component)
		{
			//TODO eventually there may be a way to check uniqueness of components


			component->setHost(this);
			mComponents.push_back(component);
		}
	};
};