//=======================================================================================================================|
// Created 2013.11.24 by Daniel L. Watkins
//
// Copyright (C) 2013-2014 Daniel L. Watkins
// This file is licensed under the MIT License.
//=======================================================================================================================|

#include "World.h"
#include <dirent.h>

namespace glz
{
	namespace world
	{
		World::World(OpenGLWindow *window)
		{
			mIdTrack = 0;
			mWidth = 2;
			mHeight = 2;
			mWindow = window;

			mSpatialSystem = Shared<SpatialSystem>(new SpatialSystem);
			mDrawableSystem = Shared<DrawableSystem>(new DrawableSystem(mWindow));
		}


		void World::init()
		{
			loadTemplateEntities();
		}

		
		void World::loadWorldFile(String filepath)
		{
			std::ifstream file(filepath, std::ifstream::in);

			if (!file.is_open())
			{
				std::cout << "Unable to read world data from " << filepath.c_str() << std::endl;
				return;
			}

			Char token[64];

			while (!file.eof())
			{
				file >> token;

				//create a new entity instance?
				if (String(token) == "#entity")
				{	
					file >> token;
					Shared<Entity> entity = getTemplateEntity(token);

					Vec2d pos;
					file >> token; pos.x = toFloat(token);
					file >> token; pos.y = toFloat(token);
					
					mIdTrack++;
					mSpatialSystem->createSpatial(mIdTrack, pos);
					mDrawableSystem->createDrawable(mIdTrack, entity->meshFilepath);
				}
			}
		}


		void World::update()
		{
			
		}

		
		Shared<Entity> World::getTemplateEntity(String name)
		{
			for (Uint n=0; n<mTemplateEntities.size(); n++)
			{
				if (mTemplateEntities[n]->name == name)
					return mTemplateEntities[n];
			}

			return NULL;
		}

		
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

		
		void World::loadTemplateEntity(String filepath)
		{
			std::ifstream file(filepath, std::ifstream::in);

			if (!file.is_open())
			{
				std::cout << "Unable to read entity data from " << filepath.c_str() << std::endl;
				return;
			}

			Char token[64];
			Shared<Entity> templateEntity(new Entity);

			while (!file.eof())
			{
				file >> token;


				//add a mesh to the entity?
				if (String(token) == "#mesh")
				{
					file >> token;
					templateEntity->meshFilepath = token;
				}
				else if (String(token) == "#name")
				{
					file >> token;
					templateEntity->name = token;
				}
			}

			mTemplateEntities.push_back(templateEntity);
		}
	};
};