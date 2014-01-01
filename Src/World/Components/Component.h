//=======================================================================================================================|
// Created 2013.11.20 by Daniel L. Watkins
//
// Copyright (C) 2013 Daniel L. Watkins
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

		public:
			virtual ~Component() {}

			virtual void update(Double timeDelta) = 0;

			void setHost(Int host) { mHost = host; }
			Int getHost() { return mHost; }			
		};
	};
};

#include "Drawable.h"

#endif

