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

			 Double mMass;
			 Double mMaxSpeed;
			 Double mMaxForce;
			 Double mMaxTurnRate;


		 public:
			 Spatial(Vec2d pos, Vec2d heading, Double mass, Double maxSpeed, Double maxForce, Double maxTurnRate);
			 
			 Bool rotateToHeading(Vec2d pos);
			 Bool setHeading(Vec2d heading);

			 void setPos(Vec2d pos) { mPos = pos; }
			 void addPos(Vec2d pos) { mPos += pos; }
			 Vec2d getPos() { return mPos; }
		 };
	};
};

#endif

