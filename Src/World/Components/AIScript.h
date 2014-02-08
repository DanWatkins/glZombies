//=======================================================================================================================|
// Created 2014.01.21 by Daniel L. Watkins
//
// Copyright (C) 2013-2014 Daniel L. Watkins
// This file is licensed under the MIT License.
//=======================================================================================================================|

#ifndef _glz_AI_SCRIPT
#define _glz_AI_SCRIPT

#include "../../Script/Script.h"
#include "SteeringBehaviors.h"

namespace glz
{
	namespace world
	{
		class AIScript;

		class AIScriptRelay
		{
		private:
			static AIScript *mCurrentScript;

			AIScriptRelay() {}
			AIScriptRelay(const AIScriptRelay &relay) {}
			void operator ==(const AIScriptRelay &relay) {}

			static String getTopString(lua_State *lua);

			/**
			 * Callbacks from Lua scripts
			 */
			static Int cpp_seek(lua_State *lua);

		public:
			static AIScriptRelay &instance();

			void lock(AIScript *script);
			void unlock(AIScript *script);
			Bool isLocked() { return (Bool)mCurrentScript; }

			void bindToLua(AIScript *script);

			/**
			 * Methods to call from C++ to Lua
			 */
			static void script_update();
		};

		class AI;

		class AIScript : public Script
		{
		private:
			SteeringBehaviors *mSteeringBehaviors;

		public:
			friend AIScriptRelay;
			AIScript() {}
			AIScript(String filepath);
			~AIScript();

			void bindToLua();

			void script_update(SteeringBehaviors *behaviors);
		};
	};
};


#endif

