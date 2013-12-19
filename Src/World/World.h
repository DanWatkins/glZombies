//=======================================================================================================================|
// Created 2013.11.24 by Daniel L. Watkins
//
// Copyright (C) 2013 Daniel L. Watkins
//=======================================================================================================================|

#ifndef _glz_WORLD_H
#define _glz_WORLD_H

#include "../Core/Core.h"

namespace glz
{
	namespace world
	{
		class Entity;
		class Component;
		class Camera;

		typedef std::vector<Shared<Entity>> EntityVector;


		//============================================================================|
		// Represents a global container for all the entities being processed
		//============================================================================|
		class World
		{
		private:
			EntityVector mTemplateEntities;
			EntityVector mEntities;
			Int mIdTrack;

			Uint mWidth, mHeight;

			OpenGLWindow *mWindow;
			World() {}

		public:
			friend Camera;

			World(OpenGLWindow *window);
			
			void init();
			void loadWorldFile(String filepath);
			void update();


			Uint getWidth() { return mWidth; }
			Uint getHeight() { return mHeight; }

		private:
			//============================================================================|
			// Searches for and returns an Entity in @mTemplateEntities with a matching name
			//============================================================================|
			Shared<Entity> getTemplateEntity(String name);


			//============================================================================|
			// Searches for and returns an Entity in @mEntities with a matching id
			//============================================================================|
			Shared<Entity> getEntity(String id);



			void loadTemplateEntities();
			void loadTemplateEntity(String filepath);

			

			//============================================================================|
			// Creates a new Entity instance based on template Entity with @templateName
			// and adds it to @mEntities
			//============================================================================|
			Shared<Entity> createEntityFromTemplate(String templateName);
		};
	};
};

#include "Entity.h"
#include "Camera.h"


#endif

