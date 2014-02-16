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


		Vec2d SteeringBehaviors::computeSteeringForce()
		{
			mSteeringForce.clear();

			BehaviorList::iterator iter = mSteeringBehaviorList.begin();
			while (iter != mSteeringBehaviorList.end())
			{
				mSteeringForce += (*iter).force;

				++iter;
			}

			return mSteeringForce;
		}


		void SteeringBehaviors::clear()
		{
			mSteeringBehaviorList.clear();
		}


		void SteeringBehaviors::seek(Vec2d pos)
		{
			Vec2d targetVelocity = Vec2d(pos-mSpatial->getPos()) * mSpatial->getMaxSpeed();
			targetVelocity.normalize();
			targetVelocity -= mSpatial->getVelocity();

			mSteeringBehaviorList.push_back({ Behavior::Seek, targetVelocity });
		}


		void SteeringBehaviors::flee(Vec2d pos)
		{
			Vec2d targetVelocity = Vec2d(mSpatial->getPos()-pos) * mSpatial->getMaxSpeed();
			targetVelocity.normalize();
			targetVelocity -= mSpatial->getVelocity();

			mSteeringBehaviorList.push_back({ Behavior::Flee, targetVelocity });
		}


		void SteeringBehaviors::arrive(Vec2d pos)
		{
			const Double deceleration = 2.0;
			const Double decelerationTweaker = 0.3;

			Vec2d toTarget = pos-mSpatial->getPos();
			Double distance = toTarget.length();

			if (distance > 0)
			{
				Double speed = distance / (deceleration*decelerationTweaker);
				speed = speed < mSpatial->getMaxSpeed() ? speed : mSpatial->getMaxSpeed();

				Vec2d desiredVelocity = toTarget * speed;
				desiredVelocity /= distance;
				desiredVelocity -= mSpatial->getVelocity();

				mSteeringBehaviorList.push_back({Behavior::Arrive, desiredVelocity});
			}
		}
	};
};