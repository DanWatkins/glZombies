//=======================================================================================================================|
// Created 2014.02.07 by Daniel L. Watkins
//
// Copyright (C) 2013-2016 Daniel L. Watkins
// This file is licensed under the MIT License.
//=======================================================================================================================|

#ifndef _glz_AI_SCRIPT_RELAY_H
#define _glz_AI_SCRIPT_RELAY_H

#include "../../../Script/Script.h"

namespace glz
{
	namespace world
	{
		class AIScript;
		class AI;

		/**
		 * Manages binding of AIScript instances to Lua's C-API.
		 * AIScripts using this class must call lock(this) before using anything
		 * and are responsible for calling unlock(this) when they are done.
		 */
		class AIScriptRelay
		{
		private:
			static AIScript *mCurrentScript;

			AIScriptRelay() {}
			AIScriptRelay(const AIScriptRelay &relay) {}

			static String getTopString(lua_State *lua);

			static AI *nearestEntity();
			static AI *nearestEntity(String type);

			//Lua to CPP
			static int cpp_seek(lua_State *lua);
			static int cpp_flee(lua_State *lua);
			static int cpp_arrive(lua_State *lua);
			static int cpp_pursuit(lua_State *lua);
			static int cpp_wander(lua_State *lua);

			static int cpp_nearestEntityPos(lua_State *lua);
			static int cpp_nearestEntityPos(lua_State *lua, String type);

			static int cpp_nearestEntityId(lua_State *lua);
			static int cpp_nearestEntityId(lua_State *lua, String type);

			static int cpp_leastDenseSector(lua_State *lua);
			static int cpp_leastDenseSector(lua_State *lua, std::vector<String> typeMask, int sectors);

		public:
			static AIScriptRelay &instance();

			static void lock(AIScript *script);
			static void unlock(AIScript *script);

			static bool isLocked() { return mCurrentScript != nullptr; }

			void bindToLua(AIScript *script) const;

			//CPP to Lua
			static void script_update();
		};
	};
};

#endif

