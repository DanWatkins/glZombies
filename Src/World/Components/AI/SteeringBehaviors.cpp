//=======================================================================================================================|
// Created 2014.01.04 by Daniel L. Watkins
//
// Copyright (C) 2013-2014 Daniel L. Watkins
// This file is licensed under the MIT License.
//=======================================================================================================================|

#include "SteeringBehaviors.h"
#include "AI.h"

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
			Vec2d steeringForce;

			BehaviorList::iterator iter = mSteeringBehaviorList.begin();
			while (iter != mSteeringBehaviorList.end())
			{
				steeringForce += (*iter).force;

				++iter;
			}

			return steeringForce;
		}


		void SteeringBehaviors::clear()
		{
			mSteeringBehaviorList.clear();
		}



		void SteeringBehaviors::seek(Vec2d pos)
		{
			Vec2d targetVelocity = Vec2d(pos-mSpatial->getPos());
			targetVelocity.normalize();
			targetVelocity * mSpatial->getMaxSpeed();
			targetVelocity -= mSpatial->getVelocity();

			mSteeringBehaviorList.push_back({ Behavior::Seek, targetVelocity });
		}


		void SteeringBehaviors::flee(Vec2d pos)
		{
			Vec2d targetVelocity = Vec2d(mSpatial->getPos()-pos);
			targetVelocity.normalize();
			targetVelocity *= mSpatial->getMaxSpeed();
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


		void SteeringBehaviors::pursuit(AI *target)
		{
			Spatial *spatial = target->mSpatial;
			Vec2d toTarget = spatial->getPos();
			toTarget.normalize();
			Double relativeHeading = mSpatial->getHeading().dot(spatial->getHeading());

			if (toTarget.dot(mSpatial->getHeading()) > 0.0  &&  relativeHeading < -0.95)
				return seek(spatial->getPos());

			Double lookAheadTime = toTarget.length() / (mSpatial->getMaxSpeed() + spatial->getVelocity().length());
			
			return seek(spatial->getPos() + spatial->getVelocity()* lookAheadTime);
		}
	};
};