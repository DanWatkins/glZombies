//=======================================================================================================================|
// Created 2014.02.07 by Daniel L. Watkins
//
// Copyright (C) 2013-2014 Daniel L. Watkins
// This file is licensed under the MIT License.
//=======================================================================================================================|

#include "AIScriptRelay.h"
#include "AIScript.h"

namespace glz
{
	namespace world
	{
		AIScript *AIScriptRelay::mCurrentScript = NULL;

		/**
		 * _EntityScriptRelay stuff
		 */
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
				mCurrentScript = NULL;
		}


		void AIScriptRelay::bindToLua(AIScript *script)
		{
			lua_register(script->mLuaState, "ai_seek", cpp_seek);
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


		Int AIScriptRelay::cpp_seek(lua_State *lua)
		{
			int n = lua_gettop(lua);

			if (n != 2)
			{
				std::cout << "Lua: Wrong number of arguments for setEntityName" << std::endl;
				return 0;
			}

			if (!lua_isnumber(lua, 1)  ||  !lua_isnumber(lua, 2))
				return 0;

			mCurrentScript->mSteeringBehaviors->seek(Vec2d(lua_tonumber(lua, 1), lua_tonumber(lua, 1))); 

			return 0;
		}
	};
};