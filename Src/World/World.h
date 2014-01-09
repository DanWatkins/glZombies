//=======================================================================================================================|
// Created 2013.11.24 by Daniel L. Watkins
//
// Copyright (C) 2013-2014 Daniel L. Watkins
// This file is licensed under the MIT License.
//=======================================================================================================================|

#ifndef _glz_WORLD_H
#define _glz_WORLD_H

#include "../Core/Core.h"

#include "Camera.h"
#include "./Components/Component.h"
#include "./Systems/AISystem.h"
#include "./Systems/DrawableSystem.h"
#include "./Systems/SpatialSystem.h"
#include "EntityTemplate.h"

namespace glz
{
	namespace world
	{
		class Component;
		class System;
		class Camera;

		/**
		 * Represents a game world manager. Template entities are used to create entity instances
		 * which are represented through a registration in the various systems. There is no central
		 * location which stores the entities. An entity cannot be directly referenced either. When
		 * an entity instance is created, each system is told to create a component to represent
		 * part of the entity. Each component stores an id value for the entity it is to represent.
		 */
		class World
		{
		private:
			Int mIdTrack;
			Uint mWidth, mHeight;
			OpenGLWindow *mWindow;
			std::vector<Shared<EntityTemplate>> mTemplateEntities;

			Shared<AISystem> mAISystem;
			Shared<DetailsSystem> mDetailsSystem;
			Shared<SpatialSystem> mSpatialSystem;
			Shared<DrawableSystem> mDrawableSystem;

			World() {}

			void loadTemplateEntities();
			void loadTemplateEntity(String filepath);

			Int createEntityFromTemplate(String templateName);

		public:
			friend Camera;

			World(OpenGLWindow *window);
			
			void init();
			void loadWorldFile(String filepath);
			void update();

			Shared<EntityTemplate> getTemplateEntity(String name);

			Uint getWidth() { return mWidth; }
			Uint getHeight() { return mHeight; }
		};
	};
};

#endif

