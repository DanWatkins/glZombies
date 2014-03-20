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


		void AISystem::generateBuckets()
		{
			const Int updatesPerSecond = 10;
			const Int targetFPS = 60;
			Int aiCount = mComponents.size();
			Double bucketSize = (Double)aiCount / targetFPS * updatesPerSecond;
		
			ComponentList::iterator iter = mComponents.begin();
			Bucket currentBucket; 
			Double currentSize = 0.0;

			while (iter != mComponents.end())
			{
				AI *ai = (AI*)(*iter);
				currentBucket.push_back(ai);

				currentSize += 1.0;

				if (currentSize >= bucketSize)
				{
					currentSize -= bucketSize;
					mUpdateBuckets.push_back(currentBucket);
					currentBucket.clear();
				}

				++iter;
			}

			if (!currentBucket.empty())
				mUpdateBuckets.push_back(currentBucket);
		}


		void AISystem::update(Double timeDelta)
		{
			if (mUpdateBuckets.empty())
				generateBuckets();

			if (!mUpdateBuckets.empty())
			{
				Bucket currentBucket = mUpdateBuckets.front();
				Bucket::iterator iter = currentBucket.begin();

				while (iter != currentBucket.end())
				{
					(*iter)->update(timeDelta);
					//TODO instead of a time delta, just use a current time to calculate the time delta since the time delta wont be accurate

					++iter;
				}

				mUpdateBuckets.pop_front();
			}

			/*ComponentList::iterator aiCmp = mComponents.begin();
			while (aiCmp != mComponents.end())
			{
				AI *ai = (AI*)*aiCmp;
				ai->update(timeDelta);

				++aiCmp;
			}*/
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