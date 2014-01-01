//=======================================================================================================================|
// Created 2013.12.31 by Daniel L. Watkins
//
// Copyright (C) 2013 Daniel L. Watkins
//=======================================================================================================================|

#include "Spatial.h"

namespace glz
{
	namespace world
	{
		Spatial::Spatial(Vec2d pos)
		: mPos(pos), mMass(10.0), mMaxSpeed(2.0), mMaxForce(1.0), mMaxTurnRate(1.0)
		{

		}


		Spatial::Spatial(Vec2d pos, Vec2d heading, Double mass, Double maxSpeed, Double maxForce, Double maxTurnRate)
			: mPos(pos), mHeading(heading), mMass(mass), mMaxSpeed(maxSpeed), mMaxForce(maxForce), mMaxTurnRate(maxTurnRate)
		{

		}


		void Spatial::setHeading(Vec2d heading)
		{
			mHeading = heading;
			mSide = mHeading.perp();
		}


		Bool Spatial::rotateToHeading(Vec2d pos)
		{
			Vec2d toTarget = Vec2d(pos-mPos);
			toTarget.normalize();

			Double angle = acos(mHeading.dot(pos));

			if (angle < 0.000001)
				return true;

			if (angle > mMaxTurnRate)
				angle = mMaxTurnRate;

			Mat3d rotationMat;
			rotationMat.rotate(angle*mHeading.sign(toTarget));
			rotationMat.transformVec2d(mHeading);
			rotationMat.transformVec2d(mVelocity);

			mSide = mHeading.perp();

			return false;
		}
	};
};