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
				/*String type = ai->mDetails->getType();
				Vec2d pos = ai->mSpatial->getPos();

				if (type == "zombie")
				{
					#undef max
					Double closest = std::numeric_limits<Double>::max();
					Vec2d closestPos;
					Bool foundClosest = false;

					//seek nearest human
					ComponentList::iterator aiSearchCmp = mComponents.begin();
					while (aiSearchCmp != mComponents.end())
					{
						AI *aiSearch = (AI*)*aiSearchCmp;
						if (aiSearch->mDetails->getType() == "human")
						{
							Double testDistance = pos.distance(aiSearch->mSpatial->getPos());
							if (testDistance < closest)
							{
								closest = testDistance;
								closestPos = aiSearch->mSpatial->getPos();
								foundClosest = true;
							}
						}

						++aiSearchCmp;
					}

					if (foundClosest)
						ai->mSteeringBehaviors.arrive(closestPos);
				}*/


				ai->update(timeDelta);

				++aiCmp;
			}
		}



		AI *AISystem::findNearestAi(Vec2d pos)
		{
			#undef max
			Double closest = std::numeric_limits<Double>::max();
			Vec2d closestPos;
			Bool foundClosest = false;

			ComponentList::iterator aiSearchCmp = mComponents.begin();
			while (aiSearchCmp != mComponents.end())
			{
				AI *aiSearch = (AI*)*aiSearchCmp;
				if (aiSearch->mDetails->getType() == "human")
				{
					Double testDistance = pos.distance(aiSearch->mSpatial->getPos());
					if (testDistance < closest)
					{
						closest = testDistance;
						closestPos = aiSearch->mSpatial->getPos();
						foundClosest = true;
					}
				}

				++aiSearchCmp;
			}

			return NULL;
		}
	};
};