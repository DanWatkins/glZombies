//=======================================================================================================================|
// Created 2014.01.21 by Daniel L. Watkins
//
// Copyright (C) 2013-2016 Daniel L. Watkins
// This file is licensed under the MIT License.
//=======================================================================================================================|

#include "AIScript.h"
#include "AI.h"

namespace glz
{
	namespace world
	{
		/**
		 * EntityScript stuff
		 */

		AIScript::AIScript(AI *ai, String filepath) : Script(filepath)
		{
			mAI = ai;
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

				//references are only needed during the update
				mRecentAiReferences.clear();
			}
		}


		void AIScript::addRecentAiReference(AI *aiReference)
		{
			if (aiReference)
			{
				//TODO should we check for duplicates?
				mRecentAiReferences.push_back(aiReference);
			}
		}


		AI *AIScript::getRecentAiReference(Int id)
		{
			std::list<AI*>::iterator iter = mRecentAiReferences.begin();

			while (iter != mRecentAiReferences.end())
			{
				AI *ai = *iter;

				if (ai->getHost() == id)
					return ai;

				++iter;
			}

			return nullptr;
		}
	};
};