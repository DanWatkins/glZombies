//=======================================================================================================================|
// Created 2014.01.04 by Daniel L. Watkins
//
// Copyright (C) 2013-2014 Daniel L. Watkins
// This file is licensed under the MIT License.
//=======================================================================================================================|

#include "AISystem.h"

namespace glz
{
	namespace world
	{
		AISystem::AISystem(DetailsSystem *detailsSystem,
						   SpatialSystem *spatialSystem)
		{
			mDetailsSystem = detailsSystem;
			mSpatialSystem = spatialSystem;
		}


		void AISystem::createAI(Int entity)
		{
			Details *details = (Details*)mDetailsSystem->getComponentForEntity(entity);
			Spatial *spatial = (Spatial*)mSpatialSystem->getComponentForEntity(entity);
			addComponent(entity, new AI(details, spatial));
		}


		void AISystem::update(Double timeDelta)
		{
			ComponentList::iterator aiCmp = mComponents.begin();
			while (aiCmp != mComponents.end())
			{
				AI *ai = (AI*)*aiCmp;
				ai->update(timeDelta);

				++aiCmp;
			}
		}



		AI *AISystem::findNearestAi(Vec2d pos)
		{
			#undef max
			Double closest = std::numeric_limits<Double>::max();
			AI *closestAi = NULL;
			Bool foundClosest = false;

			ComponentList::iterator aiSearchCmp = mComponents.begin();
			while (aiSearchCmp != mComponents.end())
			{
				AI *aiSearch = (AI*)*aiSearchCmp;
				Double testDistance = pos.distance(aiSearch->mSpatial->getPos());
				if (testDistance < closest)
				{
					closest = testDistance;
					closestAi = aiSearch;
					foundClosest = true;
				}
				++aiSearchCmp;
			}



			return closestAi;
		}


		AI *AISystem::findNearestAi(Vec2d pos, String type)
		{
			#undef max
			Double closest = std::numeric_limits<Double>::max();
			AI *closestAi;
			Bool foundClosest = false;

			ComponentList::iterator aiSearchCmp = mComponents.begin();
			while (aiSearchCmp != mComponents.end())
			{
				AI *aiSearch = (AI*)*aiSearchCmp;
				if (aiSearch->mDetails->getType() == type)
				{
					Double testDistance = pos.distance(aiSearch->mSpatial->getPos());
					if (testDistance < closest)
					{
						closest = testDistance;
						closestAi = aiSearch;
						foundClosest = true;
					}
				}

				++aiSearchCmp;
			}

			return closestAi;
		}


	};
};