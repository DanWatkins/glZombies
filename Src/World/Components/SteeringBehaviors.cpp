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
		SteeringBehaviors::SteeringBehaviors(Weak<Spatial> spatial)
		{
			mSpatial = spatial;
		}


		Vec2d SteeringBehaviors::Seek(Vec2d pos)
		{
			Vec2d targetVelocity = Vec2d(pos-mSpatial.lock()->getPos()) * mSpatial.lock()->getMaxSpeed();
			targetVelocity.normalize();

			return targetVelocity - mSpatial.lock()->getVelocity();
		}


		Vec2d SteeringBehaviors::ComputeSteeringForce()
		{
			return mSteeringForce;
		}
	};
};