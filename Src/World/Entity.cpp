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
			mId		= "NULL";
			mName	= "NULL";
		}


		//==================================================================|
		void Entity::update()
		{
			for (Uint n=0; n<mComponents.size(); n++)
				mComponents.at(n)->update();
		}


		//==================================================================|
		void Entity::addComponent(Shared<Component> component)
		{
			//TODO eventually there may be a way to check uniqueness of components

			component->setHost(this);
			mComponents.push_back(component);
		}


		//==================================================================|
		Entity *Entity::clone()
		{
			Entity *clone = new Entity(*this);

			clone->mComponents.clear();

			for (Uint n=0; n<mComponents.size(); n++)
			{
				Shared<Component> componentClone(mComponents[n]->clone());
				clone->addComponent(componentClone);
			}

			return clone;
		}
	};
};