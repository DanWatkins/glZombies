//=======================================================================================================================|
// Created 2014.01.21 by Daniel L. Watkins
//
// Copyright (C) 2013-2014 Daniel L. Watkins
// This file is licensed under the MIT License.
//=======================================================================================================================|

#include "AIScript.h"

namespace glz
{
	namespace world
	{
		/**
		 * EntityScript stuff
		 */

		AIScript::AIScript(String filepath) : Script(filepath)
		{
		}

		AIScript::~AIScript()
		{
			AIScriptRelay::instance().unlock(this);
		}


		void AIScript::bindToLua()
		{
			AIScriptRelay::instance().bindToLua(this);
		}


		void AIScript::script_update(SteeringBehaviors *behaviors)
		{
			if (!AIScriptRelay::instance().isLocked())
			{
				AIScriptRelay::instance().lock(this);
				mSteeringBehaviors = behaviors; //TODO this should just be set in the constructor
				AIScriptRelay::instance().script_update();
				AIScriptRelay::instance().unlock(this);
			}
		}
	};
};