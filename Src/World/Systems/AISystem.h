//=======================================================================================================================|
// Created 2014.01.04 by Daniel L. Watkins
//
// Copyright (C) 2013-2014 Daniel L. Watkins
// This file is licensed under the MIT License.
//=======================================================================================================================|

#ifndef _glz_AI_SYSTEM_H
#define _glz_AI_SYSTEM_H

#include "System.h"
#include "../Components/AI.h"

namespace glz
{
	namespace world
	{
		class AISystem : public System
		{
		private:
			Weak<SpatialSystem> mSpatialSystem;

		public:
			AISystem(Weak<SpatialSystem> spatialSystem);

			void createAI(Int entity);
		};
	};
};

#endif

