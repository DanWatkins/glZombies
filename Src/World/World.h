//=======================================================================================================================|
// Created 2013.11.24 by Daniel L. Watkins
//
// Copyright (C) 2013 Daniel L. Watkins
//=======================================================================================================================|

#ifndef _glz_WORLD_H
#define _glz_WORLD_H

#include "../Main.h"
#include "Entity.h"


namespace glz
{
	namespace world
	{
		class World
		{
		private:
			std::vector<Entity> mTemplateEntities;
			std::vector<Entity> mEntities;

			Int mIdTrack;

		private:
			Entity *getTemplateEntity(String id);
			Entity *getEntity(String id);

			void createEntityFromTemplate(String templateId);


		public:
			World();
		};
	};
};


#endif

