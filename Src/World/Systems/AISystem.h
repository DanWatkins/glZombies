//=======================================================================================================================|
// Created 2014.01.04 by Daniel L. Watkins
//
// Copyright (C) 2013-2016 Daniel L. Watkins
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
		class AISystem : public System, DetailsSystemUser, SpatialSystemUser
		{
		private:
			typedef std::list<AI*> Bucket;
			typedef std::list<AI*> Sector;
			typedef std::vector<Sector> SectorList;

			std::list<Bucket> mUpdateBuckets;

			void generateBuckets();
			static Double lds_calculateSectorDesnity(Sector &sector, AI *target);

		public:
			AISystem(DetailsSystem *detailsSystem,
					 SpatialSystem *spatialSystem);

			void createAI(Int entity);
			void update() override;

			AI *findNearestAi(Vec2d pos);
			AI *findNearestAi(Vec2d pos, String type);

			Vec2d findLeastDenseSector(AI *target, std::vector<String> typeMasks, Int sectors=8);
		};


		class AISystemUser
		{
		protected:
			AISystem *mAISystem;
		};
	};
};

#endif

