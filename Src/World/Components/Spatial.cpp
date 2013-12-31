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
		Spatial::Spatial(Vec2d pos, Vec2d heading, Double mass, Double maxSpeed, Double maxForce, Double maxTurnRate)
			: mPos(pos), mHeading(heading), mMass(mass), mMaxSpeed(maxSpeed), mMaxForce(maxForce), mMaxTurnRate(maxTurnRate)
		{

		}


		Bool Spatial::setHeading(Vec2d heading)
		{
			mHeading = heading;
			mSide = mHeading.perp();
		}


		Bool Spatial::rotateToHeading(Vec2d pos)
		{
			//TODO Vec2d toTarget = Vec2d(pos-mPos).normalize();

			Double angle = acos(mHeading.dot(pos));

			if (angle < 0.000001)
				return true;

			if (angle > mMaxTurnRate)
				angle = mMaxTurnRate;

			/*
			Mat2d rotationMatrix;

			//TODO TODO
			*/
		}
	};
};