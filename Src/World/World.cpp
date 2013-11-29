//=======================================================================================================================|
// Created 2013.11.24 by Daniel L. Watkins
//
// Copyright (C) 2013 Daniel L. Watkins
//=======================================================================================================================|

#include "World.h"

namespace glz
{
	namespace world
	{
		World::World()
		{
			mIdTrack = 0;
		}

		Entity *World::getTemplateEntity(String id)
		{
			for (Int n=0; n<mTemplateEntities.size(); n++)
			{
				if (mTemplateEntities.at(n).getId() == id)
					return &mTemplateEntities.at(n);
			}

			return NULL;
		}


		Entity *World::getEntity(String id)
		{
			for (Int n=0; n<mEntities.size(); n++)
			{
				if (mEntities.at(n).getId() == id)
					return &mEntities.at(n);
			}

			return NULL;
		}


		void World::createEntityFromTemplate(String templateId)
		{
			Entity *templateEntity = getTemplateEntity(templateId);

			mIdTrack++;
			Entity newEntity(String(mIdTrack));
		}
	};
};