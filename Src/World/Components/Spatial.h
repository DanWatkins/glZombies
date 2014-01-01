//=======================================================================================================================|
// Created 2013.12.24 by Daniel L. Watkins
//
// Copyright (C) 2013 Daniel L. Watkins
//=======================================================================================================================|

#ifndef _glz_SPATIAL_H
#define _glz_SPATIAL_H

#include "Component.h"

namespace glz
{
	namespace world
	{
		/**
		 * Represents a Component that keeps track of a spatial body.
		 */
		 class Spatial : public Component
		 {
		 private:
			 Vec2d mPos;
			 Vec2d mVelocity;
			 Vec2d mHeading;
			 Vec2d mSide;
			 Vec2d mSteeringForce;

			 Double mMass;
			 Double mMaxSpeed;
			 Double mMaxForce;
			 Double mMaxTurnRate;

			 Double mTimeDelta;

		 public:
			 Spatial(Vec2d pos);
			 Spatial(Vec2d pos, Vec2d heading, Double mass, Double maxSpeed, Double maxForce, Double maxTurnRate);
			 
			 void update(Double timeDelta);
			 Bool rotateToHeading(Vec2d pos);
			 void setHeading(Vec2d heading);

			 void setPos(Vec2d pos) { mPos = pos; }
			 void addPos(Vec2d pos) { mPos += pos; }
			 Vec2d getPos() { return mPos; }
			 Vec2d getVelocity() { return mVelocity; }
			 Vec2d getHeading() { return mHeading; }
			 Vec2d getSide() { return mSide; }
			 void addSteeringForce(Vec2d steeringForce) { mSteeringForce += steeringForce; }
			 Vec2d getSteeringForce() { return mSteeringForce; }

			 Double getMass() { return mMass; }
			 Double getMaxSpeed() { return mMaxSpeed; }
			 Double getMaxForce() { return mMaxForce; }
			 Double getMaxTurnRate() { return mMaxTurnRate; }
		 };
	};
};

#endif

