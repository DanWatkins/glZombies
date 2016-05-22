//=======================================================================================================================|
// Created 2014.01.04 by Daniel L. Watkins
//
// Copyright (C) 2013-2016 Daniel L. Watkins
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
			mScript.load(String(g_default_path_data_g_default_path_ai) + mDetails->getType() + ".ai");
			mScript.bindToLua();
		}


		void AI::update()
		{
			mScript.script_update(&mSteeringBehaviors);
			mSpatial->setSteeringForce(mSteeringBehaviors.computeSteeringForce());
			mSteeringBehaviors.clear();
			++mTimesUpdated;

			mTimeDelta.restart();
		}
	};
};