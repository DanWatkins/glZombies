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

			virtual void update(Double timeDelta) = 0;

		public:
			virtual ~Component() {}

			void setHost(Int host) { mHost = host; }
			Int getHost() { return mHost; }		
		};
	};
};

#endif

