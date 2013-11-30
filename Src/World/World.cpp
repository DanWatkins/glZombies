//=======================================================================================================================|
// Created 2013.11.24 by Daniel L. Watkins
//
// Copyright (C) 2013 Daniel L. Watkins
//=======================================================================================================================|

#include "World.h"
#include "Components\Drawable.h"

namespace glz
{
	namespace world
	{
		//==================================================================|
		World::World()
		{
			mIdTrack = 0;
		}


		//==================================================================|
		Entity *World::getTemplateEntity(String id)
		{
			for (Uint n=0; n<mTemplateEntities.size(); n++)
			{
				if (mTemplateEntities.at(n).getId() == id)
					return &mTemplateEntities.at(n);
			}

			return NULL;
		}


		//==================================================================|
		Entity *World::getEntity(String id)
		{
			for (Uint n=0; n<mEntities.size(); n++)
			{
				if (mEntities.at(n).getId() == id)
					return &mEntities.at(n);
			}

			return NULL;
		}


		//==================================================================|
		bool World::loadTemplateEntity(String filepath)
		{
			std::ifstream file(filepath, std::ifstream::in);

			if (!file.is_open())
			{
				std::cout << "Unable to read entity data from " << filepath.c_str() << std::endl;
				return false;
			}

			char token[64];
			Entity templateEntity;

			while (!file.eof())
			{
				file >> token;

				if (token == "#mesh")
				{
					file >> token;
					templateEntity.addComponent(new Drawable(filepath, mCurrentRenderProgram));
				}
			}

			return true;
		}


		//==================================================================|
		void World::createEntityFromTemplate(String templateId)
		{
			Entity *templateEntity = getTemplateEntity(templateId);

			mIdTrack++;
			Entity newEntity;
			//TODO //newEntity.setId(toString(mIdTrack));
			mEntities.push_back(newEntity);
		}
	};
};