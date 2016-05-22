//=======================================================================================================================|
// Created 2014.02.07 by Daniel L. Watkins
//
// Copyright (C) 2013-2016 Daniel L. Watkins
// This file is licensed under the MIT License.
//=======================================================================================================================|

#include "AIScriptRelay.h"
#include "AIScript.h"

namespace glz
{
	namespace world
	{
		AIScript *AIScriptRelay::mCurrentScript = nullptr;

		AIScriptRelay& AIScriptRelay::instance()
		{
			static AIScriptRelay instance;
			return instance;
		}


		void AIScriptRelay::lock(AIScript *script)
		{
			if (!isLocked())
			{
				mCurrentScript = script;
			}
		}


		void AIScriptRelay::unlock(AIScript *script)
		{
			if (mCurrentScript == script)
				mCurrentScript = nullptr;
		}


		void AIScriptRelay::bindToLua(AIScript *script) const
		{
			lua_register(script->mLuaState, "ai_seek", cpp_seek);
			lua_register(script->mLuaState, "ai_flee", cpp_flee);
			lua_register(script->mLuaState, "ai_arrive", cpp_arrive);
			lua_register(script->mLuaState, "ai_pursuit", cpp_pursuit);
			lua_register(script->mLuaState, "ai_wander", cpp_wander);

			lua_register(script->mLuaState, "ai_nearestEntityPos", cpp_nearestEntityPos);
			lua_register(script->mLuaState, "ai_nearestEntityId", cpp_nearestEntityId);
			lua_register(script->mLuaState, "ai_leastDenseSectorPos", cpp_leastDenseSector);
		}

		
		void AIScriptRelay::script_update()
		{
			lua_getglobal(mCurrentScript->mLuaState, "update");

			if (!lua_isfunction(mCurrentScript->mLuaState, -1))
			{
				std::cout << "No function \"update\" defined in script" << std::endl;
				return;
			}

			lua_call(mCurrentScript->mLuaState, 0, 0);
		}


		String AIScriptRelay::getTopString(lua_State *lua)
		{
			int n = lua_gettop(lua);

			if (n != 1)
			{
				std::cout << "LuaCpp : Wrong number of arguments" << std::endl;
				return "";
			}

			if (!lua_isstring(lua, 1))
			{
				std::cout << "LuaCpp : Invalid argument" << std::endl;
				return "";
			}

			return lua_tostring(lua, 1);
		}
	};
};