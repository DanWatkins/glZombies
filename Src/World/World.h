//=======================================================================================================================|
// Created 2013.11.24 by Daniel L. Watkins
//
// Copyright (C) 2013 Daniel L. Watkins
//=======================================================================================================================|

#ifndef _glz_WORLD_H
#define _glz_WORLD_H

#include "../Core/Core.h"

#include "Camera.h"
#include "./Components/Component.h"
#include "./Systems/System.h"
#include "Entity.h"

namespace glz
{
	namespace world
	{
		class Component;
		class System;
		class Camera;


		//============================================================================|
		// Represents a global container for all the entities being processed
		//============================================================================|
		class World
		{
		private:
			Int mIdTrack;
			Uint mWidth, mHeight;
			OpenGLWindow *mWindow;
			std::vector<Shared<Entity>> mTemplateEntities;

			//systems
			Shared<SpatialSystem> mSpatialSystem;
			Shared<DrawableSystem> mDrawableSystem;

			World() {}

		public:
			friend Camera;

			World(OpenGLWindow *window);
			
			void init();
			void loadWorldFile(String filepath);
			void update();

			Shared<Entity> getTemplateEntity(String name);

			Uint getWidth() { return mWidth; }
			Uint getHeight() { return mHeight; }

		private:
			void loadTemplateEntities();
			void loadTemplateEntity(String filepath);

			

			//============================================================================|
			// Creates a new Entity instance based on template Entity with @templateName
			// and adds it to @mEntities
			//============================================================================|
			Int createEntityFromTemplate(String templateName);
		};
	};
};

#endif

