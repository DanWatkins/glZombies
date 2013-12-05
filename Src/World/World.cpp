//=======================================================================================================================|
// Created 2013.11.24 by Daniel L. Watkins
//
// Copyright (C) 2013 Daniel L. Watkins
//=======================================================================================================================|

#include "World.h"
#include <dirent.h>
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
		void World::init(Uint currentRenderingProgram)
		{
			mCurrentRenderProgram = currentRenderingProgram;

			loadTemplateEntities();
		}


		//==================================================================|
		void World::loadWorldFile(String filepath)
		{
			std::ifstream file(filepath, std::ifstream::in);

			if (!file.is_open())
			{
				std::cout << "Unable to read world data from " << filepath.c_str() << std::endl;
				return;
			}

			Char token[64];
			Entity templateEntity;

			while (!file.eof())
			{
				file >> token;

				//add a mesh to the entity?
				if (String(token) == "#entity")
				{
					file >> token;
					createEntityFromTemplate(token);
				}
			}
		}


		//==================================================================|
		void World::update()
		{
			for (Uint n=0; n<mEntities.size(); n++)
				mEntities.at(n).update();
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
		void World::loadTemplateEntities()
		{
			DIR *dir;
			struct dirent *ent;
			std::vector<String> files;
			if ((dir = opendir ("./Data/Entities/")) != NULL)
			{
				while ((ent = readdir (dir)) != NULL)
				{
					files.push_back(String("./Data/Entities/") + String(ent->d_name));
					loadTemplateEntity(String("./Data/Entities/") + String(ent->d_name));
				}
				closedir (dir);
			}
		}


		//==================================================================|
		void World::loadTemplateEntity(String filepath)
		{
			std::ifstream file(filepath, std::ifstream::in);

			if (!file.is_open())
			{
				std::cout << "Unable to read entity data from " << filepath.c_str() << std::endl;
				return;
			}

			Char token[64];
			Entity templateEntity;

			while (!file.eof())
			{
				file >> token;


				//add a mesh to the entity?
				if (String(token) == "#mesh")
				{
					file >> token;
					templateEntity.addComponent(new Drawable(filepath, mCurrentRenderProgram));
				}
			}

			mTemplateEntities.push_back(templateEntity);
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