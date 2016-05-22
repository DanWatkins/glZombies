//=======================================================================================================================|
// Created 2013.12.24 by Daniel L. Watkins
//
// Copyright (C) 2013-2016 Daniel L. Watkins
// This file is licensed under the MIT License.
//=======================================================================================================================|

#ifndef _glz_SPATIAL_H
#define _glz_SPATIAL_H

#include "Component.h"
#include "../EntityTemplate.h"

namespace glz
{
	namespace world
	{
		class SpatialSystem;

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

			 sf::Clock mTimeDelta;

			 void update() override;

		 public:
			 friend SpatialSystem;
			 Spatial(Vec2d pos, const EntityTemplate &et);
			 Spatial(Vec2d pos, Vec2d heading, Double mass, Double maxSpeed, Double maxForce, Double maxTurnRate); 
			 
			 Bool rotateToHeading(Vec2d pos);
			 void setHeading(Vec2d heading);

			 void setPos(Vec2d pos) { mPos = pos; }
			 void addPos(Vec2d pos) { mPos += pos; }
			 Vec2d getPos() const { return mPos; }
			 Vec2d getVelocity() const { return mVelocity; }
			 Vec2d getHeading() const { return mHeading; }
			 Vec2d getSide() const { return mSide; }

			 void setSteeringForce(Vec2d steeringForce) { mSteeringForce = steeringForce; }
			 void addSteeringForce(Vec2d steeringForce) { mSteeringForce += steeringForce; }
			 Vec2d getSteeringForce() const { return mSteeringForce; }

			 Double getMass() const { return mMass; }
			 Double getMaxSpeed() const { return mMaxSpeed; }
			 Double getMaxForce() const { return mMaxForce; }
			 Double getMaxTurnRate() const { return mMaxTurnRate; }
		 };


		 class SpatialUser
		 {
		 protected:
			 Spatial *mSpatial = nullptr;
		 };
	};
};

#endif

