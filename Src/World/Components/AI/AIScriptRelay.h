//=======================================================================================================================|
// Created 2014.02.07 by Daniel L. Watkins
//
// Copyright (C) 2013-2014 Daniel L. Watkins
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
			void operator ==(const AIScriptRelay &relay) {}

			static String getTopString(lua_State *lua);

			//Lua to CPP
			static Int cpp_seek(lua_State *lua);
			static Int cpp_flee(lua_State *lua);
			static Int cpp_arrive(lua_State *lua);

			static Int cpp_nearestEntityPos(lua_State *lua);
			static Int cpp_nearestEntityPos(lua_State *lua, String type);

			static Int cpp_nearestEntityId(lua_State *lua);
			static Int cpp_nearestEntityId(lua_State *lua, String type);

		public:
			static AIScriptRelay &instance();

			void lock(AIScript *script);
			void unlock(AIScript *script);
			Bool isLocked() { return (Bool)mCurrentScript; }

			void bindToLua(AIScript *script);

			//CPP to Lua
			static void script_update();
		};
	};
};

#endif

