//=======================================================================================================================|
// Created 2014.01.04 by Daniel L. Watkins
//
// Copyright (C) 2013-2014 Daniel L. Watkins
// This file is licensed under the MIT License.
//=======================================================================================================================|

#include "SteeringBehaviors.h"

namespace glz
{
	namespace world
	{
		SteeringBehaviors::SteeringBehaviors(Spatial *spatial)
		{
			mSpatial = spatial;
		}


		void SteeringBehaviors::Seek(Vec2d pos)
		{
			Vec2d targetVelocity = Vec2d(pos-mSpatial->getPos()) * mSpatial->getMaxSpeed();
			targetVelocity.normalize();
			targetVelocity -= mSpatial->getVelocity();

			mSteeringBehaviorList.push_back({ SteeringBehavior::Seek, targetVelocity });
		}


		Vec2d SteeringBehaviors::ComputeSteeringForce()
		{
			SteeringBehaviorList::iterator iter = mSteeringBehaviorList.begin();
			while (iter != mSteeringBehaviorList.end())
			{
				mSteeringForce += (*iter).force;

				++iter;
			}

			return mSteeringForce;
		}
	};
};