//=======================================================================================================================|
// Created 2014.01.04 by Daniel L. Watkins
//
// Copyright (C) 2013-2014 Daniel L. Watkins
// This file is licensed under the MIT License.
//=======================================================================================================================|

#include "AI.h"

namespace glz
{
	namespace world
	{
		AI::AI(Details *details, Spatial *spatial) : mSteeringBehaviors(spatial)
		{
			mDetails = details;
			mSpatial = spatial;
		}


		void AI::init()
		{
			mScript.load(String("./Data/AI/") + mDetails->getType() + ".ai");
		}


		void AI::update(Double timeDelta)
		{
			mScript.script_update();
			mSpatial->addSteeringForce(mSteeringBehaviors.computeSteeringForce());
			mSteeringBehaviors.clear();
		}
	};
};