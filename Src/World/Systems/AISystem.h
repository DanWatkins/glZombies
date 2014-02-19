//=======================================================================================================================|
// Created 2014.01.04 by Daniel L. Watkins
//
// Copyright (C) 2013-2014 Daniel L. Watkins
// This file is licensed under the MIT License.
//=======================================================================================================================|

#ifndef _glz_AI_SYSTEM_H
#define _glz_AI_SYSTEM_H

#include "System.h"
#include "DetailsSystem.h"
#include "../Components/AI/AI.h"

namespace glz
{
	namespace world
	{
		typedef std::list<AI*> AIList;

		class AISystem : public System, DetailsSystemUser, SpatialSystemUser
		{
		private:


		public:
			AISystem(DetailsSystem *detailsSystem,
					 SpatialSystem *spatialSystem);

			void createAI(Int entity);
			void update(Double timeDelta);

			AI *findNearestAi(Vec2d pos);
			AI *findNearestAi(Vec2d pos, String type);
		};


		class AISystemUser
		{
		protected:
			AISystem *mAISystem;
		};
	};
};

#endif

