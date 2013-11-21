//=======================================================================================================================|
// Created 2013.11.20 by Daniel L. Watkins
//
// Copyright (C) 2013 Daniel L. Watkins
//=======================================================================================================================|

#ifndef _glz_COMPONENT_H
#define _glz_COMPONENT_H

#include "../Main.h"


namespace glz
{
	namespace world
	{
		class Entity;

		class Component
		{
		private:
			Entity *mHost;


		public:
			friend Entity;

			Component() {}
			virtual ~Component() {}


		protected:
			void setHost(Entity *host) { mHost = host; }
			Entity *getHost() { return mHost; }
		};
	};
};

#endif

