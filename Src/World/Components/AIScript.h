//=======================================================================================================================|
// Created 2014.01.21 by Daniel L. Watkins
//
// Copyright (C) 2013-2014 Daniel L. Watkins
// This file is licensed under the MIT License.
//=======================================================================================================================|

#ifndef _glz_AI_SCRIPT
#define _glz_AI_SCRIPT

#include "../../Script/Script.h"
#include "AI.h"

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
			static Int setEntityName(lua_State *lua) { return 1; }

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




		class AIScript : public Script
		{
		private:
			

		public:
			friend AIScriptRelay;
			AIScript(String filepath);
			~AIScript();

			void bindToLua();

			void script_update();
		};
	};
};


#endif

