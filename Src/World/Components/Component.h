//=======================================================================================================================|
// Created 2013.11.20 by Daniel L. Watkins
//
// Copyright (C) 2013-2014 Daniel L. Watkins
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
			Int mHost;
			System *mSystem;

			virtual void init() {}
			virtual void update(Double timeDelta) = 0;

			void setHost(Int host) { mHost = host; }
			void setSystem(System *system) { mSystem = system; }

		public:
			friend System;

			virtual ~Component()
			{
				std::cout << "Component destroyed" << std::endl;
			}

			Int getHost() { return mHost; }
			System *getSystem() { return mSystem; }
		};
	};
};

#endif

