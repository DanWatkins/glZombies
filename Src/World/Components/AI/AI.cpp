//=======================================================================================================================|
// Created 2014.01.04 by Daniel L. Watkins
//
// Copyright (C) 2013-2014 Daniel L. Watkins
// This file is licensed under the MIT License.
//=======================================================================================================================|

#include "AI.h"
#include "../../Systems/AISystem.h"

namespace glz
{
	namespace world
	{
		AI::AI(Details *details, Spatial *spatial) : mSteeringBehaviors(this, spatial), mScript(this)
		{
			mDetails = details;
			mSpatial = spatial;
		}


		void AI::init()
		{
			mTimesUpdated = 0;
			mScript.load(String(gDefaultPathAi) + mDetails->getType() + ".ai");
			mScript.bindToLua();
		}


		void AI::update()
		{
			mScript.script_update(&mSteeringBehaviors);
			mSpatial->setSteeringForce(mSteeringBehaviors.computeSteeringForce());
			mSteeringBehaviors.clear();
			++mTimesUpdated;

			//std::cout << "Timedelta is " << mTimeDelta.getElapsedTime().asSeconds() << std::endl;
			mTimeDelta.restart();
		}
	};
};