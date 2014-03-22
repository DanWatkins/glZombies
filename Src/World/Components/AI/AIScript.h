//=======================================================================================================================|
// Created 2014.01.21 by Daniel L. Watkins
//
// Copyright (C) 2013-2014 Daniel L. Watkins
// This file is licensed under the MIT License.
//=======================================================================================================================|

#ifndef _glz_AI_SCRIPT
#define _glz_AI_SCRIPT

#include "AIScriptRelay.h"
#include "SteeringBehaviors.h"

namespace glz
{
	namespace world
	{
		class AI;

		/**
		 * Represents a script for artificial intelligence updates.
		 * bindToLua() must be called to bind CPP methods to the script.
		 * Calling script_update() will call "update()" in the script.
		 * The script will call methods such as "ai_seek(x, y)" to add steering forces
		 * to the SteeringBehaviors object passed to script_update.
		 */
		class AIScript : public Script
		{
		private:
			SteeringBehaviors *mSteeringBehaviors;
			AI *mAI;
			std::list<AI*> mRecentAiReferences;

		public:
			friend AIScriptRelay;
			AIScript(AI *ai) { mAI = ai; }
			AIScript(AI *ai, String filepath);
			~AIScript();

			void bindToLua();
			void script_update(SteeringBehaviors *behaviors);

			void addRecentAiReference(AI *aiReference);
			AI *getRecentAiReference(Int id);
		};
	};
};


#endif

