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
		SteeringBehaviors::SteeringBehaviors(AI *ai, Spatial *spatial)
		{
			mAi = ai;
			mSpatial = spatial;
		}


		Bool SteeringBehaviors::accumulateForce(Vec2d &totalForce, Vec2d forceToAdd)
		{
			Double magnitudeRemaining = mSpatial->getMaxForce() - totalForce.length();

			if (magnitudeRemaining <= 0.0)
				return false;

			Double magnitudeToAdd = forceToAdd.length();

			if (magnitudeToAdd < magnitudeRemaining)
				totalForce += forceToAdd;
			else
			{
				Vec2d truncated(forceToAdd);
				truncated.normalize();
				truncated *= magnitudeRemaining;
				totalForce += truncated;
			}

			return true;
		}


		Vec2d SteeringBehaviors::computeSteeringForce()
		{
			Vec2d steeringForce;

			//sort with descending priority
			mSteeringBehaviorList.sort();

			BehaviorList::iterator iter = mSteeringBehaviorList.begin();
			while (iter != mSteeringBehaviorList.end())
			{
				accumulateForce(steeringForce, iter->force);
				++iter;
			}

			return steeringForce;
		}


		void SteeringBehaviors::clear()
		{
			mSteeringBehaviorList.clear();
		}


		void SteeringBehaviors::seek(Vec2d pos, RequestPriority priority)
		{
			Vec2d targetVelocity = Vec2d(pos-mSpatial->getPos());
			targetVelocity.normalize();
			targetVelocity * mSpatial->getMaxSpeed();
			targetVelocity -= mSpatial->getVelocity();

			mSteeringBehaviorList.push_back({ targetVelocity, priority });
		}


		void SteeringBehaviors::flee(Vec2d pos, RequestPriority priority)
		{
			Vec2d targetVelocity = Vec2d(mSpatial->getPos()-pos);
			targetVelocity.normalize();
			targetVelocity *= mSpatial->getMaxSpeed();
			targetVelocity -= mSpatial->getVelocity();

			mSteeringBehaviorList.push_back({ targetVelocity, priority });
		}


		void SteeringBehaviors::arrive(Vec2d pos, RequestPriority priority)
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

				mSteeringBehaviorList.push_back({ desiredVelocity, priority });
			}
		}


		void SteeringBehaviors::pursuit(AI *target, RequestPriority priority)
		{
			Spatial *spatial = target->mSpatial;
			Vec2d toTarget = spatial->getPos();
			toTarget.normalize();
			Double relativeHeading = mSpatial->getHeading().dot(spatial->getHeading());

			if (toTarget.dot(mSpatial->getHeading()) > 0.0  &&  relativeHeading < -0.95)
				return seek(spatial->getPos());

			Double lookAheadTime = toTarget.length() / (mSpatial->getMaxSpeed() + spatial->getVelocity().length());
			
			return seek(spatial->getPos() + spatial->getVelocity()* lookAheadTime, priority);
		}


		void SteeringBehaviors::wander(RequestPriority priority)
		{
			Double wanderRadius = 1.2;
			Double wanderDistance = 2.0;
			Double wanderJitterPerSec = 80.0;

			Double jitterAmount = wanderJitterPerSec * mAi->mTimeDelta.getElapsedTime().asSeconds();

			mWanderTarget += Vec2d(randClamped() * jitterAmount,
									randClamped() * jitterAmount);

			mWanderTarget.normalize();
			mWanderTarget *= wanderRadius;

			Vec2d targetLocal = mWanderTarget + Vec2d(wanderDistance, 0.0);
			//Vec2d targetWorld = targetLocal += mSpatial->getPos();

			//return targetWorld - mSpatial->getPos();

			//to world space
			Vec2d transPoint = targetLocal;
			Mat3d matTransform;
			matTransform.rotate(mSpatial->getHeading(), mSpatial->getSide());
			matTransform.translate(mSpatial->getPos().x, mSpatial->getPos().y);
			matTransform.transformVec2d(transPoint);

			Vec2d totalPoint = transPoint - mSpatial->getPos();
			mSteeringBehaviorList.push_back({ totalPoint, priority });
		}
	};
};