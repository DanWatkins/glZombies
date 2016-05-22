//=======================================================================================================================|
// Created 2013.11.20 by Daniel L. Watkins
//
// Copyright (C) 2013-2016 Daniel L. Watkins
// This file is licensed under the MIT License.
//=======================================================================================================================|

#ifndef _glz_COMPONENT_H
#define _glz_COMPONENT_H

#include "../../Main.h"

namespace glz
{
	namespace world
	{
		class System;

		/**
		 * Represents a component or module that resides in a System instance.
		 * Game entities are represented by various Components inside of System instances.
		 * There is no entity class, so entities are a "concept" established by Components
		 * with @mHost refering to the entity they represent.
		 */
		class Component
		{
		private:
			int mHost = -1;
			System *mSystem = nullptr;

			virtual void init() {}
			virtual void update() = 0;

			void setHost(int host) { mHost = host; }
			void setSystem(System *system) { mSystem = system; }

		public:
			friend System;

			virtual ~Component()
			{
			}

			int getHost() const { return mHost; }
			System *getSystem() const { return mSystem; }
		};
	};
};

#endif

