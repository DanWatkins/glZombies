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
		//============================================================================|
		// Represents a global container for all the entities being processed
		//============================================================================|
		class World
		{
		private:
			std::vector<Entity> mTemplateEntities;
			std::vector<Entity> mEntities;
			Int mIdTrack;

			Uint mCurrentRenderProgram;

		public:
			World();
			
			void init(Uint currentRenderProgram);
			void loadWorldFile(String filepath);
			void update();

		private:
			//============================================================================|
			// Searches for and returns an Entity in @mTemplateEntities with a matching id
			//============================================================================|
			Entity *getTemplateEntity(String id);


			//============================================================================|
			// Searches for and returns an Entity in @mEntities with a matching id
			//============================================================================|
			Entity *getEntity(String id);



			void loadTemplateEntities();
			void loadTemplateEntity(String filepath);

			


			//============================================================================|
			// Creates a new Entity instance based on template Entity with @templateId and
			// adds it to @mEntities
			//============================================================================|
			void createEntityFromTemplate(String templateId);


		
		};
	};
};


#endif

