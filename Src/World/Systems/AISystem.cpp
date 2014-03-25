//=======================================================================================================================|
// Created 2014.01.04 by Daniel L. Watkins
//
// Copyright (C) 2013-2014 Daniel L. Watkins
// This file is licensed under the MIT License.
//=======================================================================================================================|

#include "AISystem.h"
#include "../Components/AI/AI.h"

//TODO consider grouping System and Component pairs in the same folder instead of
//grouping all Systems into one folder and all Components in another

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
			const Int updatesPerSecond = 6;
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


		void AISystem::update()
		{
			if (mUpdateBuckets.empty())
				generateBuckets();

			if (!mUpdateBuckets.empty())
			{
				Bucket currentBucket = mUpdateBuckets.front();
				Bucket::iterator iter = currentBucket.begin();

				while (iter != currentBucket.end())
				{
					(*iter)->update();
					//TODO instead of a time delta, just use a current time to calculate the time delta since the time delta wont be accurate

					if ((*iter)->mDetails->getType() == "human")
					{
						std::vector<String> types;
						types.push_back("zombie");

						Vec2d d = this->findLeastDenseSector(*iter, 4, types, true);
					}

					++iter;
				}

				mUpdateBuckets.pop_front();
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
				Vec2d testPos = aiSearch->mSpatial->getPos();
				Double testDistance = pos.distance(testPos);

				if (testDistance < closest  &&  pos != testPos)
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
			AI *closestAi = NULL;
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


		Vec2d AISystem::findLeastDenseSector(AI *target, Int sectors, std::vector<String> typeMasks, Bool subdivideOnCollision)
		{
			typedef std::list<AI*> Sector;
			typedef std::vector<Sector> SectorList;
			SectorList sectorList;
			Double sectorSize = TWO_PI/sectors;
			Vec2d targetPos = target->mSpatial->getPos();


			//populate the sectorList
			for (Int n=0; n<sectors; n++)
				sectorList.push_back(Sector());


			//go through each AI and see which sector it belongs in (if it matches a type in @typeMasks)
			ComponentList::iterator iter = mComponents.begin();
			while (iter != mComponents.end())
			{
				AI *ai = (AI*)*iter;
				String type = ai->mDetails->getType();

				//only consider this AI if has a type to consider
				if (std::find(typeMasks.begin(), typeMasks.end(), type) != typeMasks.end())
				{
					Vec2d aiPos = ai->mSpatial->getPos();


					// 1) Get local space position
					Vec2d localPos = aiPos - targetPos;

					// 2) Normalize local space position
					localPos.normalize();

					// 3) Calculate angle relative to (1,0)
					Double angle = acos(localPos.dot(Vec2d(1.0,0.0)));

					if (localPos.y < 0)
						angle = TWO_PI-angle;

					// 4) Get sector index
					Int sectorIndex = (Int)(angle/sectorSize);

					// 5) Add to appropriate sector
					sectorList[sectorIndex].push_back(ai);
				}

				++iter;
			}

			return Vec2d(0.0, 0.0);
		}
	};
};