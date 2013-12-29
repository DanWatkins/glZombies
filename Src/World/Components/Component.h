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
		class Component
		{
		private:
			Int mHost;


		public:
			Component() {}
			virtual ~Component() {}

			void setHost(Int host) { mHost = host; }
			Int getHost() { return mHost; }			
		};
	};
};

#include "Drawable.h"

#endif

